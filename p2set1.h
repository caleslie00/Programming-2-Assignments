#include <cstddef>
    
template <typename T>
struct Set {        
    T* data;
    int size;        
    int count;
};

template <typename T>
void initialize(Set<T>& s) //initializes teh set to our starting size with the proper count
{
    s.data = new T[2];
    s.size = 2;
    s.count = 0;
}
template <typename T>
void destroy(Set<T>& s) //destroys the set by deallocating the memory and resetting the size/count
{
    delete [] s.data;
    s.data = NULL;
    s.size = 0;
    s.count = 0;
}
template <typename T>
bool isEmpty(Set<T> s) //returns if the set is empty or not by using the count of how many values are in the set
{
    return s.count == 0;
}
template <typename T>
bool contains(Set<T> s, T value) //determines if the set contains value or not by going through the array
{
    for(int i = 0; i < s.count; i++)
        if(s.data[i] == value)
            return true;
    return false;
}
template <typename T>
void insert(Set<T>& s, T value)//inserts a value to the end and reallocates the array with twice the memory if it is full
{
    if(!contains(s, value))
    {
        s.count++;
        if(s.count > s.size)
        {
            T* temp = new T[s.size*2];
            for(int i = 0; i < s.size; i++)
                temp[i] = s.data[i];
            delete [] s.data; 
            s.data = temp;
            s.size *= 2;
        }
        s.data[s.count-1] = value;
    }
}
template <typename T>
void remove(Set<T>& s, T value)///removes value from the set by going through the array until value is found
{
    int i = 0;
    while(s.data[i] != value)
    {
        i++;
    }
    s.count--;
    s.data[i] = s.data[s.count];
}
template <typename T>
int  getSize(Set<T> s) //returns the count as it is the size
{
    return s.count;
}