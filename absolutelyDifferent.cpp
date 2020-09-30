#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	cout << "Enter list: ";

	int testNums[50] = {0}, entNums[50], size = 0; //array of calc'd nums, array of entered nums, size of the array
	stringstream ss; // string stream used for entering numbers
	string line; // the line used for inputting
	int curr; //the current int we are looking at

	getline(cin, line);
	ss << line;
	while(ss >> curr)//puts all entered ints in an array and counts the size of our list
	{
		entNums[size] = curr;
		size++;
	}

	int first = entNums[0]; //the first num in the list
	int lowestWrong = 51;//used to find the lowest wrong number or know if there isn't one
	for(int i = 1; i < size; i++) //adds all calc'd numbers to a list in ascending order without any duplicates
	{
		int second = entNums[i];
		int test = first - second; //calculates our test number
		if(test < 1) //makes sure the test number is positive
		{
			test *= -1;
		}

		if(testNums[test-1] == 0 && test <= size-1) //adds test to the list at the index where it's supposed to be if that index is open and test fits in the list
		{
			testNums[test-1] = test;
		}

		first = second;
	}

	bool cont = true;//continues loop
	for(int i = 0; i < size-1 && cont; i++)//loop determines lowest wrong number or if all values are present
	{
		if(testNums[i] == 0)
		{
			lowestWrong = i+1;
			cont = false;
		}
	}

	if(lowestWrong == 51)//outputs according to lowest wrong
	{
		cout << "Good sequence.";
	}
	else
	{
		cout << "Bad sequence: missing " << lowestWrong << ".";
	}
}