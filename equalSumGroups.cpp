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

bool equalGroups(int A[], int size, int index, int fiveSum, int threeSum)
{
	if(index >= size) //base case: all values have been added to a list
		return fiveSum == threeSum;
	if(A[index] % 5 == 0) //add to the five group exclusively
		return equalGroups(A, size, index+1, fiveSum+A[index], threeSum);
	else if(A[index] % 3 == 0) //add to the three group exclusively
		return equalGroups(A, size, index+1, fiveSum, threeSum+A[index]);
	return equalGroups(A, size, index+1, fiveSum+A[index], threeSum) || equalGroups(A, size, index+1, fiveSum, threeSum+A[index]); //does not fit in either, so we have to test adding it to both
}
int main()
{
	int values, currVal; //number of values, the current value
	cout << "How many values? ";
	cin >> values;
	int* nums = new int[values]; //dynamically allocate the array
	cout << "Enter numbers: ";
	for(int i = 0; i < values; i++) //add all values to the array
	{
		cin >> nums[i];
	}
	cout << ((equalGroups(nums, values, 0, 0, 0)) ? "Yes, there are " : "No, there are not ") << "two equal subgroups.";
	delete [] nums; //delete allocated array
}