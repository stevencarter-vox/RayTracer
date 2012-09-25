#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Shapes.h"

class Node
{
public:
	Node()
	{
		next = NULL;
		previous = NULL;
		P = 0;
		Item = Shapes();
	};

	Node(float p, Shapes item)
	{
		next = NULL;
		previous = NULL;
		P = p;
		Item = item;
	};

	Node* next;
	Node* previous;
	float P;
	Shapes Item;
	friend class PriorityQueue;
};

class PriorityQueue
{
public:
	PriorityQueue()
	{
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->previous = head;
		Size = 0;
	};

	void addItem(float p, Shapes item)
	{
		Node* Current = head->next;
		Node* newNode = new Node(p, item);
		Size++;
		if(head->next == tail)
		{
			newNode->next = tail;
			newNode->previous = tail->previous;
			tail->previous->next = newNode;
			tail->previous = newNode;				
		}
		else
		{
			while(p >= Current->P)
			{
				if(Current->next == tail)
				{
					break;
				}
				Current = Current->next;
			}
			newNode->next = Current;
			newNode->previous = Current->previous;
			Current->previous->next = newNode;
			Current->previous = newNode;
		}
	};

	Shapes getItem()
	{
		if(head->next != tail)
		{
			Shapes ret = head->next->Item;
			Node* temp = head->next;
			head->next = temp->next;
			temp->next->previous = head;
			temp->next = NULL;
			temp->previous = NULL;
			delete temp;
			Size--;
			return ret;
		}
		else
		{
			return Shapes();
		}
	};

	int size()
	{
		return Size;
	};

	Node* head;
	Node* tail;
private:
	int Size;
};

#endif
