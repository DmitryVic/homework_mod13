#include <iostream>
#include "socialGr.h"
#include "user.h"

socialGraph::socialGraph(/* args */)
{
}

socialGraph::~socialGraph()
{
    size_t userListGrSize = this->adjacencyLists.size();
    for (size_t i = 0; i < userListGrSize; i++)
    {
       delete this->adjacencyLists[i].first;                      //удалили всех пользователей из соц сети
    }
    this->adjacencyLists.clear();                           // очистили все данные
}

// Добавление юзеров в граф (регистрация)
bool socialGraph::regUser(User* user){

}