#include <cstddef>

 const int HEAPSIZE = 128;

template <typename T>
struct Heap {
   T  data[HEAPSIZE];
   int size;
};

template <typename T>   
void initialize(Heap<T>& h) //initializes the list by setting the size to 0 
{
	h.size = 0;
}
template <typename T>
void destroy(Heap<T>& h) //destroys the list by setting the size to 0, meaning we don't look at any of the values whether they're there or not
{
	h.size = 0;
}
template <typename T>
void put(Heap<T>& h, T val) //put the value into the heap and then bubble it up until it's in it's correct spot
{
	h.size++;
	h.data[h.size] = val;
	int k = h.size;
	while(k > 1 && val < h.data[k/2])
	{
		h.data[k] = h.data[k/2];
		h.data[k/2] = val;
		k /= 2;
	}
}
template <typename T>
T    get(Heap<T>& h) //gets the value fron the top of the heap, the brings the value from the end of the array/heap and heapifys the heap so that it's in it's correct spot
{
	T save = h.data[1];
	h.data[1] = h.data[h.size];
	h.size--;
	int k = 1;
	while(k*2+1 <= h.size && h.data[k] > (h.data[k*2] <= h.data[k*2+1] ? h.data[k*2] : h.data[k*2+1]))
	{
		T temp = h.data[k];
		int nextK = (h.data[k*2] < h.data[k*2+1] ? k*2 : k*2+1);
		h.data[k] = h.data[nextK];
		h.data[nextK] = temp;
		k = nextK;
	}
	if(k*2 == h.size && h.data[k] > h.data[k*2])
	{
		T temp = h.data[k];
		h.data[k] = h.data[k*2];
		h.data[k*2] = temp;
		k = k*2;
	}
	return save;
}
template <typename T>
bool isEmpty(Heap<T> h) //if the array is empty returns true, otherwise false.
{
	return h.size == 0;
}