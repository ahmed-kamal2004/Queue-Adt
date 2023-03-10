#include<iostream>
#include"Queue_list.h"
#include"Circular_Queue.h"
#include<string>
using namespace std;
int main() {
	//Circular_Queue<int>Q1;
	Queue_list<int>Q1;
	Q1.dequeue();
	Q1.enqueue(4);
	Q1.enqueue(4);
	Q1.enqueue(4);
	Q1.enqueue(4);
	Q1.dequeue();
	Q1.dequeue();
	Q1.enqueue(3);

	Q1.enqueue(1);
	Q1.enqueue(2);
	Q1.enqueue(3);
	Q1.dequeue();
	Q1.dequeue();
	Q1.enqueue(4);

}