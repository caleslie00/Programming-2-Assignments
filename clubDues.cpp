#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
//#include "p2queue.h"
//#include "p2stack.h"
//#include "p2priorityqueue.h"
//#include "p2map.h"
#include "p2set.h"

using namespace std;

int main()
{
	string wholeName; //used to hold the full name of people and to get rid of the filler words before the list of people
	int pastNames = 0, presentNames = 0, past = 0, present = 0; //used to cound all the names on the past list, used to count all the names on the present list, used to count how many members recieve a discount, used to count how many members are signing up for the first time
	ifstream fin;

	Set<string> previous;

	initialize(previous);

	fin.open("8A_past.txt");
	fin >> wholeName >> wholeName >> pastNames; //these two lines clear out the filler words in the file while still recording the number of members in the list
	getline(fin, wholeName);
	for(int i = 0; i < pastNames; i++) //goes through the past members list and adds all past members to the set
	{
		getline(fin, wholeName);
		insert(previous, wholeName);
	}
	fin.close();
	fin.open("8A_new.txt");
	fin >> wholeName >> wholeName >> presentNames; //these two lines clear out the filler words in the file while still recording the number of members in the list
	getline(fin, wholeName);
	for(int i = 0; i < presentNames; i++) //goes through the signup list and determines if each of the names has signed
	{
		getline(fin, wholeName);
		(contains(previous, wholeName)) ? past++ : present++;
	}
	fin.close();
	cout << "Old Member Dues: $" << past*62 << endl; //these correctly output how much each type of member(past or present) we are expecting and the total output
	cout << "New Member Dues: $" << present*80 << endl;
	cout << "Total expected:  $" << past*62 + present*80 << endl << endl;
	cout << "Two-year membership: " << pastNames+present; //outputs the total number of unique members over the past two years

	destroy(previous);
}