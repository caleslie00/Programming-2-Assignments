const int SIZE = 5;
	
template <typename T>
struct Queue {
   T   data[SIZE];
   int head;
   int tail;
};

template <typename T>	
void initialize(Queue<T>& q)
{
	q.head = 0;
	q.tail = 0;
}
template <typename T>
void destroy(Queue<T>& q)
{
	q.head = 0;
	q.tail = 0;
}
template <typename T>
int  getSize(Queue<T> q)
{
	return (q.head <= q.tail) ? q.tail - q.head : (5-q.head)+q.tail;
}
template <typename T>
bool isEmpty(Queue<T> q)
{
	return q.head == q.tail;
}
template <typename T>
void push(Queue<T>& q, T var)
{
	q.data[q.tail] = var;
	q.tail++;
	if(q.tail > 4)
	{
		q.tail = 0;
	}
}
template <typename T>
T    pop(Queue<T>& q)
{
	q.head++;
	if(q.head > 4)
	{
		q.head = 0;
		return q.data[4];
	}
	return q.data[q.head-1];
}