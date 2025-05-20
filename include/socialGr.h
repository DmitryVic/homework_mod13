#pragma once
#include <vector>
#include "user.h"


class socialGraph
{
private:
    std::vector<User*> userListGr;                  // Юзеры в соц. сети / хранилище (Вершин)
    std::vector<std::vector<User*>> matrixSm;       // Матрица смежности графа юзеров
public:
    socialGraph(/* args */);
    ~socialGraph();
    bool regUser(User* user);                       // Добавление юзеров в граф (регистрация)

};



