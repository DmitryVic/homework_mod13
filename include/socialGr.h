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
    bool regUser(User* user);                       // Добавление юзеров в граф (регистрация)

};



