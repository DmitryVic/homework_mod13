#include <iostream>
#include "socialGr.h"
#include "user.h"
#include "queue.h"


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


User* socialGraph::getUserForID(unsigned int ID){
    if (this->adjacencyLists.size() == 0){
    std::cout << "Пользователь не существует" << std::endl;
    return nullptr; 
    }
    for (size_t i = 0; i < adjacencyLists.size(); i++)
    {
        if (adjacencyLists[i].first->getID() == ID)
            return adjacencyLists[i].first;
    }
    return nullptr;
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


// предоставить  список друзей
std::vector<User*> socialGraph::getUserFriends(User* user){
    if (this->adjacencyLists.size() == 0){
        std::cout << "Пользователь не существует" << std::endl;
        return {}; 
        }
        for (size_t i = 0; i < adjacencyLists.size(); i++)
        {
            if (adjacencyLists[i].first == user)
                return adjacencyLists[i].second;
        }
        return {};

}


void socialGraph::friendBFS_Gr() {
    // граф пустой?
    if (adjacencyLists.empty()) {
        std::cout << "Граф пустой\n";
        return;
    }

    std::vector<std::pair<User*, User*>> friendPairs; // вектор пар друзей 3 уровня

    // Для каждого пользователя в графе запускаем отдельный BFS
    for (size_t idx = 0; idx < adjacencyLists.size(); ++idx) {
        User* start = adjacencyLists[idx].first;
        if (!start) continue;   // на всякий случай

        // -------- Инициализация BFS -------

        // Очередь для обхода в ширину. В каждом узле храним
        // и указатель на User, и глубину level (сколько рукопожатий)
        // Новая очередь и новый visited для каждого старта
        Queue queue;
        // Массив посещённых, чтобы не возвращаться в уже пройденные вершины
        std::vector<User*> visited;

        // Кладём в очередь начального пользователя на уровне 0 (рукопожатие = 0)
        queue.enQueue(start, 0);

        // цикл BFS пока есть в очереди вершины (пользователи)
        // и пока не достигли 3-го уровня
        while (!queue.isEmpty()) {
            // Берем юзера его уровень из начала очереди (не удаляя сразу)
            auto* node       = queue.peek();
            User*  user      = node->user;         
            int    userLevel = node->level;
            // убираем первого пользователя из очереди — сейчас обрабатываем
            queue.deQueue();

            // Пользователь уже был посещён? пропускаем
            bool already = false;
            // Перебираем всех посещённых пользователей и если нашли пропускаем все
            for (auto* v : visited) 
                if (v == user) { already = true; break; }
            if (already) continue;
            // Отмечаем как посещённый
            visited.push_back(user);

            // Получаем всех друзей (соседей) текущего узла
            std::vector<User*>  friendList = getUserFriends(user);

            // Перебираем каждого друга
            for (User* friendUser : friendList) {
                if (!friendUser) continue;

                // Если друг уже посещён то пропускаем
                bool seen = false;
                for (auto* v : visited) 
                    if (v == friendUser) { seen = true; break; }
                if (seen) continue;

                // Если мы ещё не дошли до уровня 3, можно пойти дальше
                if (userLevel < 3) {
                     // Кладём в очередь друга с уровнем +1
                    queue.enQueue(friendUser, userLevel + 1);

                    // на каком кол-ве рукопожатий оказался друг
                    int nextLevel = userLevel + 1;
                    
                    // добавляем только для 1 - 3 уровней 0 - это пользователь от которого идёт рукопожатие
                    // меняя условие nextLevel >= 1 && nextLevel <= 3 регулируем отдаленность
                    if (nextLevel >= 1 && nextLevel <= 3) {
                        // проверка дубликатов (не добавляли ли мы такую пару раньше)
                        bool found = false;
                        for (auto& pr : friendPairs) {
                            // проверяем и first и second в паре, так может оказаться на любом месте
                            if ((pr.first == start && pr.second == friendUser) ||
                                (pr.first == friendUser && pr.second == start)) {
                                found = true; 
                                break;
                            }
                        }
                        // Если это новая пара и не сам с юзер то добавляем
                        if (!found && start != friendUser) {
                            // меняем порядок по ID (уникальный номер)
                            if (start->getID() < friendUser->getID())
                                friendPairs.emplace_back(start, friendUser);// добавляем пару
                            else
                                friendPairs.emplace_back(friendUser, start);// добавляем пару другой порядок
                        }
                    }
                }
            }
        }
    }

    // Вывод всех пар
    for (auto& pr : friendPairs) {
        std::cout << pr.first->getName()
                  << " -> "
                  << pr.second->getName()
                  << std::endl;
    }
    std::cout << "Всего пар друзей трех рукопожатий: "
              << friendPairs.size() << std::endl;
}