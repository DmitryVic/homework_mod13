#pragma once
#include "user.h"


class Queue
{ 
private:
    class Node  
        {  
        public:
            Node(User* user) : _userPtr(user), m_next(nullptr) {} 
            User* _userPtr;   // значение которая хранит нода
            Node *m_next; // указатель на следующий элемент
            Node *m_prev; // указатель на предыдущий элемент
        };    
    Node* mQ_front; // начало очереди
    Node* mQ_rear; // конец очереди
public:
    Queue() : mQ_front(nullptr), mQ_rear(nullptr)
    { 
    }
    ~Queue(){
        // Удаляем все узлы, но не трогаем User
        while (mQ_front != nullptr) {
            deQueue(); // Вызываем существующий метод для удаления узлов
        }
    }
    //Добавление элемента в конец очереди enQueue
    void enQueue(User* user);
    // Удаление элемента с начала очереди deQueue
    void deQueue();
    //Просмотр элемента начала очереди peek
    User* peek () const;
    
    //Отключить копирование/перемещение очереди
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;
};