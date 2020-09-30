#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "p2queue.h"
#include "p2stack.h"
#include "p2priorityqueue.h"

using namespace std;

int main()
{
	string str; //string input for PUSH or POP
	int val; //value corresponding to each PUSH/POP
	bool isStack = true, isQueue = true, isPQ = true; // boolean variables for if the array is each of the ADTs
	int numTrue = 3; //number of the ADTs that are still true
	cout << "Command: ";
	cin >> str; 

	Queue<int> q; //respective queue, stack, and priority queue
	Stack<int> s;
	PriorityQueue<int, int> pq;

	initialize(q);
	initialize(s);
	initialize(pq);

	while(str != "END") //this while loop pushes or pops depending on entered command
	{
		cin >> val;
		if(str == "PUSH")
		{
			push(q, val);
			push(s, val);
			push(pq, val, val);
		}
		else if(str == "POP") //if a pop, it checks to see if all of the ADTs return what they are supposed to
		{
			if(isQueue && pop(q) != val)
			{
				isQueue = false;
				numTrue--;
			}
			if(isStack && pop(s) != val)
			{
				isStack = false;
				numTrue--;
			}
			if(isPQ && pop(pq) != val)
			{
				isPQ = false;
				numTrue--;
			}
		}
		cout << "Command: ";
		cin >> str;
	}
	cout << endl;
	if(numTrue > 1) //correctly outputs based on the results
	{
		cout << "The black box remains mysterious.";
	}
	else if(isQueue)
	{
		cout << "The black box holds a queue.";
	}
	else if(isStack)
	{
		cout << "The black box holds a stack.";
	}
	else if(isPQ)
	{
		cout << "The black box holds a priority queue.";
	}
	else
	{
		cout << "The black box holds something else.";
	}

	destroy(q);
	destroy(s);
	destroy(pq);
}
