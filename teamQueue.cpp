#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
//#include "p2queue.h"
//#include "p2stack.h"
#include "p2priorityqueue.h"
#include "p2map.h"
//#include "p2set.h"

using namespace std;

int main()
{
	Map<string, int> teams; //holds each member in the string and their team in the number
	Map<int, int> teamPriority; //each teams number is held in the first int and assigned a priority in the second
	PriorityQueue<string, int> groupedLine; //the line which is grouped by the assigned priority of the team members
	initialize(teams);
	initialize(teamPriority);
	initialize(groupedLine);

	ifstream fin;
	fin.open("teams");
	int numTeams;
	fin >> numTeams;
	string filler;
	getline(fin, filler);//make sure all values are read in correctly
	for(int i = 0; i < numTeams; i ++) //read in all values and assign them to their team
	{
		string line, name;
		getline(fin, line);
		stringstream ss;
		ss << line;
		while(ss >> name)
		{
			assign(teams, name, i);
		}
	}
	fin.close();
	string currName;
	cin >> currName;
	while(currName != "END") //assigns each team a priority upon the first number of their team arriving then adds each member of that that to the priority queue upon arrival
	{
		if(!has_key(teamPriority, lookup(teams, currName)))
		{
			assign(teamPriority, lookup(teams, currName), numTeams);
			numTeams--;
		}
		push(groupedLine, currName, lookup(teamPriority, lookup(teams, currName)));
		cin >> currName;
	}
	ofstream fout;
	fout.open("grouped");
	while(!isEmpty(groupedLine)) //outputs correctly
	{
		fout << pop(groupedLine);
		fout << endl;
	}
	fout.close();

	destroy(teams);
	destroy(teamPriority);
	destroy(groupedLine);
}