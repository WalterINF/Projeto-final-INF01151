#include "UserManager.h"
#include <fstream>
#include <iostream>
#include <filesystem>


UserManager::UserManager(){
    if (!std::filesystem::exists(user_file_path)) {
        std::ofstream file(user_file_path, std::ios::binary);
        if (file.is_open()) {
            file.close();
        } else {
            std::cerr << "Error: Could not create user file: " << user_file_path << std::endl;
        }
    }
    if (!std::filesystem::exists(log_file_path)) {
        std::ofstream file(log_file_path);
        if (file.is_open()) {
            file.close();
        } else {
            std::cerr << "Error: Could not create log file: " << log_file_path << std::endl;
        }
    }
    loadUsers();
}

void UserManager::loadUsers(){
    users.clear();
    std::ifstream file(user_file_path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening user file for reading: " << user_file_path << std::endl;
        return;
    }

    user u;
    // Create buffers that are definitely large enough and include null terminator space
    std::vector<char> username_buffer(max_username_len + 1, '\0');
    std::vector<char> password_buffer(max_password_len + 1, '\0');

    while (file.read(username_buffer.data(), max_username_len)) {
        // Ensure null termination before assigning to std::string
        username_buffer[max_username_len] = '\0'; 
        u.username = username_buffer.data();

        if (file.read(password_buffer.data(), max_password_len)) {
            // Ensure null termination
            password_buffer[max_password_len] = '\0';
            u.password = password_buffer.data();
            users.push_back(u);
        } else {
            if (!file.eof()) {
                 std::cerr << "Error reading password from user file (or unexpected EOF)." << std::endl;
            }
            break; 
        }
    }
    file.close();
}

void UserManager::addUser(user user){
    if (userExists(user.username)) {
        std::cerr << "Error: User already exists: " << user.username << std::endl;
        return;
    }
    users.push_back(user);
    saveUsers();
    std::ofstream log_file(log_file_path, std::ios::app);
    if (log_file.is_open()) {
        log_file << "User " << user.username << " added at " << timeToString(std::chrono::system_clock::now()) << std::endl;
        log_file.close();
    }
}

std::string UserManager::timeToString(std::chrono::system_clock::time_point time){
    auto in_time_t = std::chrono::system_clock::to_time_t(time);
    return std::string(std::ctime(&in_time_t));
}

void UserManager::removeUser(std::string username){
    int position = 0;
    for (const auto& u : users) {
        if (u.username == username) {
            users.erase(users.begin() + position);
            break;
        }
        position++;
    }
    saveUsers();
    std::ofstream log_file(log_file_path, std::ios::app);
    if (log_file.is_open()) {
        log_file << "User " << username << " removed at " << timeToString(std::chrono::system_clock::now()) << std::endl;
        log_file.close();
    }
    return;
}

std::vector<user> UserManager::getUsers(){
    return users;
}

user UserManager::getUserByUsername(std::string username){
    for (const auto& u : users) {
        if (u.username == username) {
            return u;
        }
    }
    return user();
}   

bool UserManager::userExists(std::string username){
    for (const auto& u : users) {
        if (u.username == username) {
            return true;
        }
    }
    return false;
}

void UserManager::saveUsers() {
    std::ofstream file(user_file_path, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Error opening user file for writing: " << user_file_path << std::endl;
        return;
    }
    for (const auto& u : users) {
        std::string temp_username = u.username;
        temp_username.resize(max_username_len, '\0'); // Pad with nulls or truncate
        file.write(temp_username.c_str(), max_username_len);

        std::string temp_password = u.password;
        temp_password.resize(max_password_len, '\0'); // Pad with nulls or truncate
        file.write(temp_password.c_str(), max_password_len);
    }

    file.close();
}

void UserManager::printUsers(){
    for (const auto& u : users) {
        std::cout << u.username << " " << u.password << std::endl;
    }
}


