#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "p2queue.h"
#include "p2stack.h"
#include "p2priorityqueue.h"

using namespace std;

void correctlyOrder(string rem, int &r, PriorityQueue<string, int> &o)//fixes the priority queue so that it is still correctly ordered when an animal is popped but it wasn't the most recent animal rescued
{
	r++;
	int pops = 0;
	while(!isEmpty(o) && pop(o) != rem ) //pops all animals until we find the one we need since they should all be the same
	{
		pops++;
	}
	string pet = ((rem == "dog") ? "cat" : "dog");
	for(int i = 0; i < pops; i++) //pushes the animals we removed from the list back where they should be at the front
	{
		push(o, pet, r);
	}
}

int main()
{
	Queue<string> dogs; //queue of dog names
	Queue<string> cats; //queue of cat names
	PriorityQueue<string, int> order; //priorityqueue of the order they arrived at the shelter


	initialize(dogs);
	initialize(cats);
	initialize(order);

	ifstream fin;
	fin.open("actions.txt"); //input file stream and output file stream
	ofstream fout;
	fout.open("adoptions.txt");

	string command, petType, name; //the entered command, the entered pet type, the entered pet name
	int resets = 0; //the number of times the order has been reset so we can keep the priority queue ordered correctly
	while(fin >> command) //while there are still commands to be input, continue inputting them
	{
		fin >> petType;
		if(command == "rescue") //if the command is to rescue, add the animal name to it's queue and it's type to the order
		{
			fin >> name;
			push(((petType == "dog") ? dogs : cats), name);
			push(order, petType, 0);
		}
		else //removes from dog if a dog was requested and the most recent dog entry from the dog priority queue, removes from cat if a cat was requested and the most recent cat entry from the priority queue, or returns the latest and removes it from it's respective animal list if either is entered
		{
			if(petType == "dog" && !isEmpty(dogs))
			{
				fout << pop(dogs) << endl;
				correctlyOrder("dog", resets, order);
			}
			else if(petType == "cat" && !isEmpty(cats))
			{
				fout << pop(cats) << endl;
				correctlyOrder("cat", resets, order);
			}
			else if(petType == "either" && !isEmpty(order))
			{
				fout << pop(((pop(order) == "dog") ? dogs : cats)) << endl;
			}
		}
	}

	destroy(dogs);
	destroy(cats);
	destroy(order);
}