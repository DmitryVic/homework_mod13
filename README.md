# Домашнее заждание - модуль 13

**Студент** - Зайкин Дмитрий

**Группа** - CPLUS-68

---
## ЗАДАЧА:

Дан граф социальных связей определенного круга людей. Нужно найти все пары знакомств через три рукопожатия. Реализуйте этот алгоритм на языке C++. 
Языком графов это можно описать так: найдите все пары вершин, минимальное расстояние между которыми не превосходит 3.

---
`socialGraph* socialGr = new socialGraph();` - создание графа пользователей

`User* marina = new User("Mari");` - создание пользователей
`User* oleg = new User("Oleg");`

`socialGr->regUser(marina);` -  создание вершины (регистрация пользователей)
`socialGr->regUser(oleg);`

`socialGr->addFriend(marina, oleg);` - добавление ребра (дружба пользователей)

`socialGr->friendBFS_Gr();` — запуск **BFS** для поиска и вывода всех пар знакомств через три рукопожатия без повторений. То есть `пользователь -> друг -> знакомый -> знакомый -> знакомый`. Для того чтобы поменять диапазон добавления пар, заменить условие `if (nextLevel >= 1 && nextLevel <= 3)` в методе `friendPairs` класса `socialGraph`.

В **main.cpp** создан граф следующего вида:
```
Mari - Oleg - Daria - Dmitry - Kostia - Maxim
```

Вывод:
```bash
Mari -> Oleg
Mari -> Daria
Mari -> Dmitry
Oleg -> Daria
Oleg -> Dmitry
Oleg -> Kostia
Daria -> Dmitry
Daria -> Kostia
Daria -> Maxim
Dmitry -> Kostia
Dmitry -> Maxim
Kostia -> Maxim
Всего пар друзей трех рукопожатий: 12
```