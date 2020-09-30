#include<cstddef> // includes NULL definition

template <class T>
struct Stack {
   T*  data;	// array of values
   int size;	// size of array
   int top;	// index of value currently at top of Stack
};

template <class T>
void initialize(Stack<T>& s) //correctlly allocated the memory for our stack
{
	s.size = 2;
	s.top = 0;
	s.data = new T[2];
}
template <class T>
void destroy(Stack<T>& s) //destroys the stack by deleting the allocated memory
{
	delete [] s.data;
	s.data = NULL;
}
template <class T>
bool isEmpty(Stack<T> s) //tells if the stack is empty or not
{
	return s.top == 0;
}
template <class T>
void push(Stack<T>& s,T var) //makes sure the stack can hodl another value, if it can it adds it to the end, if not it doubles it's size and then adds it to the end
{
	if(s.top+1 > s.size)
	{
		T* temp = new T[s.size*2];
		for(int i = 0; i < s.size; i++)
			temp[i] = s.data[i];
		delete [] s.data; 
		s.data = temp;
		s.size *= 2;
	}
	s.data[s.top] = var;
	s.top++;
}
template <class T>
T    pop(Stack<T>& s) //returns the top value of the stack
{
	s.top--;
	return s.data[s.top];
}