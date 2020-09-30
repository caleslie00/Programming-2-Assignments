#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
//#include "p2queue.h"
//#include "p2stack.h"
//#include "p2priorityqueue.h"
#include "p2map.h"
//#include "p2set.h"

using namespace std;

string allFather(string startName, Map<string, string> sF) //uses the key value pairing in son father order to locate the first rather and return it
{
	string use = startName;
	while(has_key(sF, use))
	{
		use = lookup(sF, use);
	}
	return use;
}

int main()
{
	Map<string, string> fatherSon; //map with key-value in father-son order
	Map<string, string> sonFather; //mpa with key-value in son-father order

	initialize(fatherSon);
	initialize(sonFather);

	ifstream fin;
	ofstream fout;
	string fileName;
	cout << "Input file: ";
	cin >> fileName;
	fin.open(fileName.c_str());
	string father, son, currFather;
	while(fin >> father)//assings all values correctly in ttthe maps
	{
		fin >> son;
		assign(fatherSon, father, son);
		assign(sonFather, son, father);
	}
	currFather = allFather(father, sonFather); //sets currFather to the allFather
	string newFile = "fixed_" + fileName;
	fout.open(newFile.c_str());
	while(has_key(fatherSon, currFather) && fout.is_open()) //goes through the fatherSon map from the allFather all the way to the last son and prints them in the correct order
	{
		fout << currFather << " " << lookup(fatherSon, currFather) << endl;
		currFather = lookup(fatherSon, currFather);
	}
	fin.close();
	fout.close();
	destroy(fatherSon);
	destroy(sonFather);
	cout << "Ordering complete.";
}