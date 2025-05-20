#pragma once
#include <vector>
#include <utility>
#include "user.h"


class socialGraph
{
private:
    std::vector<std::pair<User*, std::vector<User*>>> adjacencyLists;       // Матрица смежности графа юзеров
public:
    socialGraph(/* args */);
    ~socialGraph();
     // Добавление юзеров в граф (регистрация)
    bool regUser(User* user);
    // добавить двух пользователей
    bool addFriend(User* user1, User* user2);
    // Пользователи друзья ?
    bool TwoUserItsFriend(User* user1, User* user2);
};



