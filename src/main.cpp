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
    User* vova = new User("Vova");
    User* katya = new User("Katya");

    socialGr->regUser(marina);
    socialGr->regUser(oleg);    
    socialGr->regUser(daria);
    socialGr->regUser(dmitry);
    socialGr->regUser(kostia);
    socialGr->regUser(maxim);
    socialGr->regUser(vova);
    socialGr->regUser(katya);
    // Добавление друзей
    socialGr->addFriend(marina, oleg);
    socialGr->addFriend(marina, daria);
    socialGr->addFriend(oleg, dmitry);
    socialGr->addFriend(daria, dmitry);
    socialGr->addFriend(dmitry, kostia);
    socialGr->addFriend(dmitry, maxim);
    socialGr->addFriend(daria, maxim);
    socialGr->addFriend(maxim, vova);
    socialGr->addFriend(vova, katya);
    socialGr->addFriend(katya, oleg);
    socialGr->addFriend(kostia, oleg);
    socialGr->addFriend(kostia, daria);
    socialGr->addFriend(kostia, dmitry);
    socialGr->addFriend(kostia, maxim);

    socialGr->friendBFS_Gr(); // Поиск в ширину по графу
    // Вывод всех пар со знакомством по рукопожатию 3   
    
    
    delete socialGr; // Освобождение памяти      
    //Пользователей удалит деструктор графа!!!

    

    return 0;
}
