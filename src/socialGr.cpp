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
    this->adjacencyLists.clear();                                 // очистили все данные
}

// Добавление юзеров в граф (регистрация)
bool socialGraph::regUser(User* user){
    this->adjacencyLists.push_back({user, {}});
    return true;
}

bool socialGraph::addFriend(User* user1, User* user2){
    if (TwoUserItsFriend(user1, user2))
        return false;
    
    size_t adjacencyListsSize = this->adjacencyLists.size();
    bool user1Complite = false;                                                 //пользователю 1 добавлен 2
    bool user2Complite = false;                                                 //пользователю 2 добавлен 1
    for (size_t i = 0; i < adjacencyListsSize; i++)
    {
        if (this->adjacencyLists[i].first == user1)
        {
            this->adjacencyLists[i].second.push_back(user2);                    //пользователю 1 добавлен 2
            user1Complite = true;
        }
        if (this->adjacencyLists[i].first == user2)
        {
            this->adjacencyLists[i].second.push_back(user1);                    //пользователю 2 добавлен 1
            user2Complite = true;
        }
        if (user1Complite && user2Complite)                                     // если добавлены оба, то смысла крутить цикл дальше уже нет
            return true;
    }
    return true;
}

bool socialGraph::TwoUserItsFriend(User* user1, User* user2){
    for (size_t i = 0; i < this->adjacencyLists.size(); i++)
    {
        if (this->adjacencyLists[i].first == user1)                             // если наткнулись на пользователя 1, то ищем перебором в его друзьях 2
        {
            for (size_t j = 0; j < this->adjacencyLists[i].second.size(); j++)
            {
                if (this->adjacencyLists[i].second[j] == user2)
                    return true;                                                //нашли
            } 
            return false;                                                       // выйти можем тут, у 2 нету смысла искать если у 1 не нашли
        } else if (this->adjacencyLists[i].first == user2)                      // Это не обязательно, но если вдруг 2 нашелся раньше, то ищем в его друзьях уже 1 друга
        {
            for (size_t j = 0; j < this->adjacencyLists[i].second.size(); j++)
            {
                if (this->adjacencyLists[i].second[j] == user1)
                    return true;                                                //нашли
            } 
            return false;                                                       // выйти можем тут, у 2 нету смысла искать если у 1 не нашли
        }
    }
    return false;                                                               //таких польхователей значит вообще нет
}