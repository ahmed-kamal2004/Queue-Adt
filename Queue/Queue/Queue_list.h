#include"Node.h"
#include"Queue_Interface.h"
#include<iostream>
using namespace std;
#pragma once
template<typename T>
class Queue_list:public Queue_Interface<T>{
private:
	Node<T>* Front;
	Node<T>* Rear;
public:
	virtual bool isEmpty() const{

		return !Front && !Rear;
	}
	virtual bool enqueue(const T& item) {
		Node<T>* New = new Node<T>;
		New->SetData(item);
		New->SetNext(nullptr);
		if (this->isEmpty()) {
			this->Front = this->Rear = New;
			return true;
		}
		Rear->SetNext(New);
		Rear = New;
		return true;

	}
	virtual bool dequeue() {
		if (this->isEmpty())
			return false;
		if (this->Front == this->Rear)
		{
			delete this->Front;
			this->Rear = this->Front = nullptr;
			return true;
		}
		Node<T>* deleter = this->Front;
		this->Front = this->Front->GetNext();
		delete deleter;
		return true;
	}
	virtual T peekFront()const {
		if (this->isEmpty())
			return NULL;
		return this->Front->GetData();
	}

	~Queue_list() {
		T x = this->peekFront();
		while (x) {
			this->dequeue();
			cout << x << " ";
			x = this->peekFront();
		}
		cout << endl;

	}

};