#include <iostream>
#include <string>
#include "user.h"
#include "socialGr.h"
using namespace std;



int main(int argc, char const *argv[])
{
    socialGraph* socialGr = new socialGraph(); // Создание графа пользователей
    // Регистрация пользователей
    User* marina = new User("Mari");
    User* oleg = new User("Oleg");
    User* daria = new User("Daria");
    User* dmitry = new User("Dmitry");
    User* kostia = new User("Kostia");
    User* maxim = new User("Maxim");

    socialGr->regUser(marina);
    socialGr->regUser(oleg);    
    socialGr->regUser(daria);
    socialGr->regUser(dmitry);
    socialGr->regUser(kostia);
    socialGr->regUser(maxim);
    

    socialGr->addFriend(marina, oleg);
    socialGr->addFriend(oleg, daria);
    socialGr->addFriend(daria, dmitry);
    socialGr->addFriend(dmitry, kostia);
    socialGr->addFriend(kostia, maxim);

    socialGr->friendBFS_Gr(); // Поиск в ширину по графу
    // Вывод всех пар со знакомством по рукопожатию 3   
    
    
    delete socialGr; // Освобождение памяти      
    //Пользователей удалит деструктор графа!!!

    

    return 0;
}
