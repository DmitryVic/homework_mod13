#include <iostream>
#include "socialGr.h"
#include "user.h"

socialGraph::socialGraph(/* args */)
{
}

socialGraph::~socialGraph()
{
    size_t userListGrSize = this->userListGr.size();
    for (size_t i = 0; i < userListGrSize; i++)
    {
       delete this->userListGr[i];                      //удалили всех пользователей из соц сети
    }
    this->userListGr.clear();                           // очистили все данные
    this->matrixSm.clear();                             // очистили все данные
}

// Добавление юзеров в граф (регистрация)
bool socialGraph::regUser(User* user){

}