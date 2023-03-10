#pragma once
template<typename T>
class Queue_Interface {
public:
	virtual bool isEmpty()const = 0;
	virtual bool enqueue(const T&item) = 0;//adds
	virtual bool dequeue() = 0;//removes
	virtual T peekFront()const = 0;//get the fornt item
};