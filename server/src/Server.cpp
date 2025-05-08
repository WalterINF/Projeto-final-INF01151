#include <iostream>
#include "UserManager.h"

//para rodar (em /server/build):
//$: make
//$: ./SyncBoxServer

int main() {
    std::cout << "SyncBox Server" << std::endl;
    UserManager userManager = UserManager();
    userManager.addUser({"teste", "teste"});
    userManager.addUser({"teste2", "teste2"});
    userManager.addUser({"teste3", "teste3"});
    userManager.removeUser("teste");
    userManager.removeUser("teste2");
    userManager.printUsers();
    return 0;
}
