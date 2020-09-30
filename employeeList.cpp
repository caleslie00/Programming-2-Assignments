#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream fin; //input string
	string filename; //the files name

	//these two arrays are parallel
	string names[1000]; //list of names
	int empNum[1000]; //list of numbers

	cout << "Input file: ";
	cin >> filename;

	fin.open(filename.c_str());

	int i = 0;

	if(fin.is_open()) //makes sure the file is open
	{
		string x1, x2;
		int val;

		while (fin >> x1 && fin >> x2 && fin >> val) //makes sure we still have values to draw from the list
		{
			names[i] = x1 + " " + x2;
			empNum[i] = val;
			i++;
		}
		for(int k = 0; k < i; k++)//sorts both lists at the same time for output
		{
			int indexMin = k;
			for(int j = k; j < i; j++)
			{
				if(empNum[j] < empNum[indexMin])
				{
					indexMin = j;
				}
			}
			//swap min with the current value in both parallel arrays
			int curr = empNum[k];
			empNum[k] = empNum[indexMin];
			empNum[indexMin] = curr;

			string str = names[k];
			names[k] = names[indexMin];
			names[indexMin] = str;
		}
	}
	ofstream fout;
	string out;

	cout << "Output file: ";
	cin >> out;

	fout.open(out.c_str());

	if(fout.is_open()) //puts output strinsg and numbers into the file passed
	{
		for(int j = 0; j < i; j++)
		{
			if(empNum[j] < 10)
			 	fout << "0" << empNum[j] << " " << names[j] << "\n";
			else
				fout << empNum[j] << " " << names[j] << "\n";
		}
	}
	fin.close();
	fout.close();
}