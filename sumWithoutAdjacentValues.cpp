#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
//#include "p2queue.h"
//#include "p2stack.h"
//#include "p2priorityqueue.h"
//#include "p2map.h"
//#include "p2set.h"

using namespace std;

bool sumWithout(bool summed, int A[], int s, int index, int size)
{
	if(summed || s == 0) //base case: check if we already reached the sum or if we are now at the sum
		return true;
	if(index >= size) //make sure we are still in the list
		return false;
	return sumWithout(summed, A, s-A[index], index+2, size) || sumWithout(summed, A, s, index+1, size); //return both cases of using the current number and not the next or using the next number and not the current
}

int main()
{
	int values, currVal, sum; //number of values, the current value, the sum we are trying to reach
	cout << "How many values? ";
	cin >> values;
	int* nums = new int[values]; //dynamically allocate the array
	cout << "Enter numbers: ";
	for(int i = 0; i < values; i++) //add all values to the array
	{
		cin >> nums[i];
	}
	cout << "Enter sum: ";
	cin >> sum;
	cout << endl;
	cout << ((sumWithout(false, nums, sum, 0, values)) ? "Yes, there is a " : "No, there is no ") << "subset that sums to " << sum << "."; //correctly outputs the results
	delete [] nums; //delete allocated array
}