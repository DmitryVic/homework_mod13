#include "queue.h"

//Добавление элемента в конец очереди enQueue
void Queue::enQueue(User* u, int lv) {
	Node* n = new Node(u, lv);
	if (!mQ_rear) {
		mQ_front = mQ_rear = n;
	} else {
		mQ_rear->next = n;
		n->prev       = mQ_rear;
		mQ_rear       = n;
	}
}

//Просмотр головы и её уровня
Queue::Node* Queue::peek() const {
	return mQ_front; 
}

// Удаление элемента с начала очереди deQueue
void Queue::deQueue() {
	if (!mQ_front) return;
	Node* tmp = mQ_front;
	mQ_front  = mQ_front->next;
	if (mQ_front) mQ_front->prev = nullptr;
	else          mQ_rear        = nullptr;
	delete tmp;
}

bool Queue::isEmpty() const {
	return mQ_front == nullptr;
}