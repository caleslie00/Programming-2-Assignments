#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "p2queue.h"
//#include "p2stack.h"
#include "p2priorityqueue.h"
#include "p2map.h"
//#include "p2set.h"

using namespace std;

int main()
{
	Queue<string> contestants; //a queue of all contestants so we know all of them to put in the pq at the end
	Map<string, int> contestantVotes; //the contestant name followed by the votes they recieved
	Map<int, int> numVotes; //the numbers submitting votes and how many votes they've submitted
	PriorityQueue<string, int> results; //the final results will be put in here so we get the output in the correct order

	initialize(contestants);
	initialize(contestantVotes);
	initialize(numVotes);
	initialize(results);

	string contestant, fileName; //the current contestant name being inputted
	int currNum, numContestants, numSubmissions; //current number that submitted the vote, the number of contestants, the number of submissions
	float numValid = 0.0; //the number of valid votes, float so the output is decimal

	cout << "Enter filename containing list of contestants: ";
	cin >> fileName;
	ifstream fin;
	fin.open(fileName.c_str());
	fin >> numContestants;
	for (int i = 0; i < numContestants; i++) //reads in the contestants, pushes them to a queue, and adds them to the map containing all contestants and the amount of votes they recieved
	{
		fin >> contestant;
		push(contestants, contestant);
		assign(contestantVotes, contestant, 0);
	}
	fin.close();
	cout << "Enter filename containing list of votes: ";
	cin >> fileName;
	fin.open(fileName.c_str());
	fin >> numSubmissions;
	for(int i = 0; i < numSubmissions; i++) //adds the number to the map of numbers with an occurance of 0 if the number is not present. 
	{                                       //Always adds 1 to the occurance of that number, but only counts it as a valid vote if the number has been seen 4 or less times
		fin >> contestant;
		fin >> currNum;
		if(!has_key(numVotes, currNum))
			assign(numVotes, currNum, 0);
		assign(numVotes, currNum, lookup(numVotes, currNum)+1);
		if(lookup(numVotes, currNum) <= 4)
		{
			assign(contestantVotes, contestant, lookup(contestantVotes, contestant)+1);
			numValid++;
		}
	}
	while(!isEmpty(contestants))//while the queue has data, pop that data and add that name and the number of votes it recieved to the priority queue
	{
		contestant = pop(contestants);
		push(results, contestant, lookup(contestantVotes, contestant));
	}
	cout << "\nFinal rankings\n" << fixed;
	while(!isEmpty(results)) //while there are still values in the pq, pop them and return the values corresponding to that name in the contestant votes array
	{
		contestant = pop(results);
		cout << setprecision(1)  << float (lookup(contestantVotes, contestant) / numValid) * 100.0 << "% " << contestant << "\n";
	}
	fin.close();
	destroy(contestants);
	destroy(contestantVotes);
	destroy(numVotes);
	destroy(results);
}