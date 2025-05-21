#pragma once
#include "user.h"

class Queue {
private:
    struct Node {
        User* user;
        int   level;    // уровень (глубина) в графе
        Node* next;
        Node* prev;
        Node(User* u, int lv) : user(u), level(lv), next(nullptr), prev(nullptr) {}
    };

    Node* mQ_front = nullptr;
    Node* mQ_rear  = nullptr;

public:
    Queue() = default;
    ~Queue() {
        while (mQ_front) deQueue();
    }

    
    //Добавление элемента в конец очереди enQueue
    void enQueue(User* u, int lv);

    //Просмотр головы и её уровня
    Node* peek() const;

    // Удаление элемента с начала очереди deQueue
    void deQueue();

    bool isEmpty() const;
};