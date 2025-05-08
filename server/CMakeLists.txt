cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SyncBoxServer VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source files
set(SOURCES
    src/Server.cpp
    src/UserManager.cpp
)

# Add header files
set(HEADERS
    src/UserManager.h
    src/SyncManager.h
    src/FileManager.h
    src/CommunicationManager.h
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Find and link necessary packages (uncomment and modify as needed)
# find_package(Threads REQUIRED)
# target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Installation rules (optional)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# Enable testing (optional)
# enable_testing() 