#include <cstddef>

template <typename T>
struct Node {
   T value;
   Node<T>* next;
};

template <typename T>
struct Stack {
   Node<T>* top;
};

template <typename T>
void initialize(Stack<T>& s)
{
	s.top = NULL;
}
template <typename T>
void destroy(Stack<T>& s)
{
	Node<T>* walker = s.top;
	while(walker != NULL) //walk through normally and delete all the nodes using the previous
	{
		Node<T>* prev = walker;
		walker = walker->next;
		delete prev;
	}
	s.top = NULL; //set the top to null
}
template <typename T>
bool isEmpty(Stack<T> s)
{
	return s.top == NULL;
}
template <typename T>
void push(Stack<T>& s,T data) //adds to the front by setting the pointer of the one we add to the previous top and the top to the one we are adding
{
	Node<T>* add = new Node<T>;
	add->value = data;
	add->next = s.top;
	s.top = add;
}
template <typename T>
T    pop(Stack<T>& s) //removes it by setting the top to the next value while holding what we need to delete with prev
{
	T temp = s.top->value;
	Node<T>* prev = s.top;
	s.top = s.top->next;
	delete prev;
	return temp;
}