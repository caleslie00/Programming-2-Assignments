#include <cstddef>

 const int HEAPSIZE = 128;

template <typename T>
struct Heap {
   T  data[HEAPSIZE];
   int size;
};

template <typename T>   
void initialize(Heap<T>& h)
{
	h.size = 0;
}
template <typename T>
void destroy(Heap<T>& h)
{
	h.size = 0;
}
template <typename T>
void put(Heap<T>& h, T val)
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
T    get(Heap<T>& h)
{
	T save = h.data[1];
	h.data[1] = h.data[h.size];
	h.size--;
	int k = 1;
	while(k*2+1 <= h.size && h.data[k] > (h.data[k*2] <= h.data[k*2+1]) ? h.data[k*2] : h.data[k*2+1])
	{
		// T temp = h.data[k];
		// int nextK = (h.data[k*2] < h.data[k*2+1]) ? k*2 : k*2+1;
		// h.data[k] = h.data[nextK];
		// h.data[nextK] = temp;
		// k = nextK;
		if(h.data[k*2] <= h.data[k*2+1])
		{
			T temp = h.data[k];
			h.data[k] = h.data[k*2];
			h.data[k*2] = temp;
			k = k*2;
		}
		else
		{
			T temp = h.data[k];
			h.data[k] = h.data[(k*2) + 1];
			h.data[(k*2) + 1] = temp;
			k = (k*2) + 1;
		}
	}
	if(k*2 == h.size && h.data[k] > h.data[k*2])
	{
		T temp = h.data[k];
		h.data[k] = h.data[k*2];
		h.data[k*2] = temp;
	}
	return save;
}
template <typename T>
bool isEmpty(Heap<T> h)
{
	return h.size == 0;
}