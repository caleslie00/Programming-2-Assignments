#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
//#include "p2queue.h"
//#include "p2stack.h"
//#include "p2priorityqueue.h"
//#include "pm2ap.h"
//#include "p2set.h"

using namespace std;

template <typename V, typename R>
struct Node {
    V value;
    R priority;
    Node<V,R>* next;
    Node<V,R>* prev;    
};

template <typename V, typename R>
struct PriorityQueue {
    Node<V,R>* head;
};
template <typename V, typename R>
void initialize(PriorityQueue<V,R>& pq) //set up pq
{
	pq.head = NULL;
}
template <typename V, typename R>
void destroy(PriorityQueue<V,R>& pq) //destroys all nodes one by one and sets head node to NULL at the end
{
	Node<V,R>* walker = pq.head;
	pq.head->prev->next = NULL;
	while(walker != NULL)
	{
		walker = walker->next;
		delete pq.head;
		pq.head = walker;
	}
}
template <typename V, typename R>
bool isEmpty(PriorityQueue<V,R> pq) //checks to see if the pq is empty
{
	return pq.head == NULL;
}
template <typename V, typename R>
void push(PriorityQueue<V,R>& pq, V val, R pri) //adds the value to the priority queue with the given priority
{
	Node<V,R>* newNode = new Node<V,R>;
	newNode->value = val;
	newNode->priority = pri;
	if(pq.head == NULL) //if there is nothing in the list, make the head point to the newNode and it point to itself
	{
		pq.head = newNode;
		pq.head->next = pq.head;
		pq.head->prev = pq.head;
	}
	else if(pri > pq.head->priority) //if there is something in the list, these next three add the node accordingly, whether it's the largest, smallest, or an intermediate value
	{
		newNode->next = pq.head;
		newNode->prev = pq.head->prev;
		pq.head->prev->next = newNode;
		pq.head->prev = newNode;
		pq.head = newNode;
	}
	else if(pri <= pq.head->prev->priority)
	{
		newNode->next = pq.head;
		newNode->prev = pq.head->prev;
		pq.head->prev->next = newNode;
		pq.head->prev = newNode;
	}
	else
	{
		Node<V,R>* walker = pq.head->next;
		while(walker->priority >= pri)
			walker = walker->next;
		newNode->next = walker;
		newNode->prev = walker->prev;
		walker->prev->next = newNode;
		walker->next->prev = newNode;
	}
}
template <typename V, typename R>
V    pop(PriorityQueue<V,R>& pq) //pops the highest priority value from the list and resets all other nodes accordingly
{
	V ret = pq.head->value;
	Node<V,R>* temp = pq.head;
	if(pq.head == pq.head->next) //checks to see if there is only one value in the list
	{
		pq.head = NULL;
	}
	else //if there's more than one then this procedure is followed
	{
		pq.head->next->prev = pq.head->prev;
		pq.head->prev->next = pq.head->next;
		pq.head = pq.head->next;
	}
	delete temp;
	return ret;
}