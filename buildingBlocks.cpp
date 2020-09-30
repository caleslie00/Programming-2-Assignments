#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
//#include "p2queue.h"
//#include "p2stack.h"
#include "p2priorityqueue.h"
//#include "p2map.h"
#include "p2set.h"

using namespace std;

int main()
{
	string line; //string for the initial line of primes
	int primes[10] = {0}, k; //array of given primes, the index of the value we are looking for

	PriorityQueue<int, int> list; //the list of numbers from lowest to highest(lower numbers will pop first)
	Set<int> listContained; //all values the list has contained

	initialize(list);
	initialize(listContained);

	cout << "Prime factors: "; //reads in the prime factors in one line to a string and then to a stringstream, then uses that stringstream to add all of them to an array
	getline(cin, line);
	stringstream ss(line);
	int size = 0;
	while (ss >> primes[size])
	{
		size++;
	}
	cout << "K: ";
	cin >> k;
	cout << endl;
	push(list, 1, -1); //make sure 1 starts our pq and set
	insert(listContained, 1);
	for(int i = 0; i < k-1; i++) //pops the lowest value in the pq and multiplies by all our prime numbers and adds them to the list if those numbers haven't already been in our list, up to k-1 values
	{
		int currNum = pop(list);
		for(int j = 0; j < size; j++)
		{
			if(!contains(listContained, currNum*primes[j]))
			{
				push(list, currNum*primes[j], -(currNum*primes[j]));
				insert(listContained, currNum*primes[j]);
			}
		}
	}
	cout << "Result: " << pop(list); //returns the final value, k
}
