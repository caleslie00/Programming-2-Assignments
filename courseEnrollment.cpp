#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "p2priorityqueue.h"

using namespace std;

int main()
{
	PriorityQueue<int, int> pq32; //different pqueues for each of the courses
	PriorityQueue<int, int> pq52;
	PriorityQueue<int, int> pq65;
	string str; //name of the initial file
	ifstream fin; //the inputfile variable

	initialize(pq32); //initializing them
	initialize(pq52);
	initialize(pq65);

	cout << "Enter the name of your file: ";
	cin >> str;

	fin.open(str.c_str());

	string course; //course name to compare with
	int student, priority; //the students number, the priority of this student
	while(fin >> course) //puts all students into their correct course(pqueue) with their priority assigned
	{
		getline(fin, str);
		stringstream ss(str);
		ss >> student;
		ss >> priority;
		if(course == "CS332")
		{
			push(pq32, student, priority);
		}
		else if(course == "CS352")
		{
			push(pq52, student, priority);
		}
		else
		{
			push(pq65, student, priority);
		}
	}
	ofstream fout;
	fout.open("CS332");
	while(!isEmpty(pq32)) //puts students from  course CS332 in their file in the correct priority
	{
		fout << pop(pq32) << "\n";
	}
	fout.close();
	fout.open("CS352");
	while(!isEmpty(pq52)) //puts students from  course CS352 in their file in the correct priority
	{
		fout << pop(pq52) << "\n";
	}
	fout.close();
	fout.open("CS365");
	while(!isEmpty(pq65)) //puts students from  course CS365 in their file in the correct priority
	{
		fout << pop(pq65) << "\n";
	}
	fout.close();
	destroy(pq32);
	destroy(pq52);
	destroy(pq65);
}