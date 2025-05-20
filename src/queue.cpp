#include "queue.h"

//Добавление элемента в конец очереди enQueue
void Queue::enQueue(User* user){
    Queue::Node* temp = new Node (user); 

	if (mQ_rear == nullptr) { // пустая очередь
		mQ_front = mQ_rear = temp; 
		return; 
	} 
    temp->m_prev    = mQ_rear;
	mQ_rear->m_next = temp; 
	mQ_rear = temp;
}
// Удаление элемента с начала очереди deQueue
void Queue::deQueue(){
	if (mQ_front == nullptr) 
		return; 
	// удаляем первый узел в очереди
	Queue::Node* temp = mQ_front; // Сохраняем указатель на текущий «фронт»
	mQ_front = mQ_front->m_next; // Сдвигаем «фронт» на следующий узел
	// Если после сдвига очередь стала пустой — больше нет ни front, ни rear
	if (mQ_front == nullptr) 
		mQ_rear = nullptr; 
    else {
        // А если очередь не пуста — новый front не должен иметь «prev»
        // обнуляем предыдущий у нового фронта
        mQ_front->m_prev = nullptr;
    }
	delete temp; 
}
//Просмотр элемента начала очереди peek
User* Queue::peek() const{
	if (mQ_front == nullptr) 
		return nullptr; 
	return mQ_front->_userPtr;
}