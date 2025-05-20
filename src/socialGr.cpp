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

void socialGraph::friendBFS_Gr(){
    if (this->adjacencyLists.size() == 0){
        std::cout << "Граф пустой" << std::endl;
        return; 
    }
    std::vector<std::pair<User*, User*>> friendPairs; // вектор пар друзей 3 уровня
    Queue queue; // очередь для обхода в ширину
    int HandsomeCount = 0; // счетчик рукопожатий
    //запускаем обход в ширину проверяя 1, 2, 3 уровень друзей и добавляя их в friendPairs если их там нету
    for (size_t i = 1; i < this->adjacencyLists.size(); i++){
        queue.enQueue(this->adjacencyLists[0].first); // добавляем в очередь юзера
        while (queue.peek() != nullptr) // пока очередь не пуста
        {
            User* user = queue.peek(); // получаем первого юзера из очереди
            queue.deQueue(); // удаляем его из очереди
            HandsomeCount++; // увеличиваем счетчик рукопожатий
            //Добавляем всех друзей в очередь и в вектор пар друзей
            for (size_t j = 0; j < this->adjacencyLists.size(); j++)
            {
                for (size_t k = 0; k < this->adjacencyLists[j].second.size(); k++)
                {
                    if (this->adjacencyLists[j].second[k] != nullptr) // если друг не пустой
                    {
                        queue.enQueue(this->adjacencyLists[j].second[k]); // добавляем его в очередь
                        // проверяем есть ли пара друзей в векторе пар друзей
                        bool found = false;
                        for (size_t l = 0; l < friendPairs.size(); l++)
                        {
                            if ((friendPairs[l].first == user && friendPairs[l].second == this->adjacencyLists[j].second[k]) || 
                                (friendPairs[l].first == this->adjacencyLists[j].second[k] && friendPairs[l].second == user))
                            {
                                found = true; // нашли пару друзей
                                break;
                            }
                        }
                        if (!found) // если не нашли, то добавляем пару друзей в вектор пар друзей
                        {
                            friendPairs.push_back({user, this->adjacencyLists[j].second[k]});
                        }
                    }
                }
                
            }
            // Проверяем количество рукопожатий
            if (HandsomeCount == 3) // если 3 рукопожатия, то выходим из цикла
            {
                break;
            }
        }
        HandsomeCount = 0; // обнуляем счетчик рукопожатий
    }
    


    
    // Вывод всех пар со знакомством по рукопожатию 1 , 2, 3 
    for (size_t i = 0; i < friendPairs.size(); i++)
    {
        std::cout << friendPairs[i].first->getName() << " -> " << friendPairs[i].second->getName() << std::endl;
    }
    std::cout << "Всего пар со знакомством по рукопожатию 3: " << friendPairs.size() << std::endl;
  
}