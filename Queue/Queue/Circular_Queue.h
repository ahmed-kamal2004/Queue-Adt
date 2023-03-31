#include"Queue_Interface.h"
#include<iostream>
using namespace std;
#pragma once
#define Max 50
template<class T>
class Circular_Queue :public Queue_Interface<T>{
private:
	T items[Max];
	int count;
	int Front;
	int Back;
public:
	Circular_Queue() {
		Front = 0;
		Back = 0;
	}
	bool isEmpty()const {
		return this->Back==this->Front;
	}
	bool isFull()const{
		return (this->Back + 1) % Max==this->Back;
	}
	T peekFront()const {
		if (this->isEmpty())
			return NULL;
		return this->items[this->Front];
	}
	bool dequeue() {
		if (this->isEmpty())
			return false;
		count--;
		this->Front = (this->Front + 1) % Max;
		return true;
	}
	bool enqueue(const T& item) {
		if (this->isFull())
			return false;
		this->Back = (this->Back + 1) % Max;
		count++;
		this->items[this->Back] = item;
		return true;
	}
	~Circular_Queue() {
		T x = this->peekFront();
		while (x) {
			this->dequeue();
			cout << x << " ";
			x = this->peekFront();
		}
		cout << endl;

	}
};
