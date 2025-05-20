#pragma once
#include <vector>
#include <utility>
#include "user.h"


class socialGraph
{
private:
    std::vector<std::pair<User*, std::vector<User*>>> adjacencyLists;       // спискоr смежности в графе
public:
    socialGraph(/* args */);
    ~socialGraph();
     // Добавление юзеров в граф (регистрация)
    bool regUser(User* user);
    // добавить двух пользователей
    bool addFriend(User* user1, User* user2);
    // Пользователи друзья ?
    bool TwoUserItsFriend(User* user1, User* user2);

    //основной метод домашнего задания - поиск в ширину -> вывод всех пар со знакомством по рукопожатию 3
    void friendBFS_Gr();
};



