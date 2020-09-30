#include <cstddef>

template <class T>
struct Queue {
    T*  data;	// array of values
    int size;	// size of data array
    int head;	// index from which the next value will be read (on Pop)
    int tail;	// index at which the next value will be written (on Push)
};

template <typename T>	
void initialize(Queue<T>& q) //initializes the array for the queue and the starting size and place for the head and tail
{
	q.data = new T[2];
	q.size = 2;
	q.head = q.tail = 0;
}
template <typename T>
void destroy(Queue<T>& q) //destroys the array by setting all the values to 0 and deallocating the array pointer
{
	q.size = q.head = q.tail = 0;
	delete [] q.data;
	q.data = NULL;
}
template <typename T>
int  getSize(Queue<T> q) //returns the size of the queue
{
	return (q.head < q.tail) ? q.tail - q.head : (q.size-q.head)+q.tail;
}
template <typename T>
bool isEmpty(Queue<T> q) //determines if the queue is empty or not and returns it
{
	return q.head == q.tail;
}
template <typename T>
T    pop(Queue<T>& q) //pops from the queue, wraps if it needs to
{
	q.head++;
	if(q.head >= q.size)
	{
		q.head = 0;
		return q.data[q.size-1];
	}
	return q.data[q.head-1];
}
template <typename T>
void push(Queue<T>& q, T var) //pushes a value to the end of the queue, reallocates the array with twice as much memory if the array is full after pushing the value
{
	q.data[q.tail] = var;
	q.tail++;
	if(q.tail >= q.size)
	{
		q.tail = 0;
	}
	int values = getSize(q);
	if(values >= q.size)
	{
		T* temp = new T[q.size*2];
		for(int i = 0; i < q.size; i++)
			temp[i] = pop(q);
		delete [] q.data; 
		q.data = temp;
		q.head = 0;
		q.tail = q.size;
		q.size *= 2;
	}
}