/*
    Mantém registros de usuários, sessões ativas e valida autenticação.

    Persistência via arquivo binário.
*/

#include <string>
#include <vector>
#include <chrono>
struct user{
    std::string username;
    std::string password;
};

class UserManager{

    private:
        size_t max_username_len = 100;
        size_t max_password_len = 100;
        std::string user_file_path = "users.bin";
        std::string log_file_path = "users_log.txt";
        std::vector<user> users;
        std::string timeToString(std::chrono::system_clock::time_point time);
    public:
        UserManager();
        void addUser(user user);
        void removeUser(std::string username);
        void updateUser(user user);
        void getUser(user user);
        void saveUsers();
        void loadUsers();
        user getUserByUsername(std::string username);
        bool userExists(std::string username);
        std::vector<user> getUsers();
        void printUsers();
};


