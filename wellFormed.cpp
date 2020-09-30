#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "p2stack.h"

using namespace std;

int main()
{
	Stack<char> s; //stack for keeping the openers
	string str; //the string we well be disecting
	bool wellFormed = true; //keeping track if the expression is well formed or not

	initialize(s);

	cout << "Enter expression: ";
	cin >> str;

	for(int i = 0; str[i] != 0 && wellFormed; i++)//goes through the string until the end or until the expression is not well formed
	{
		if(str[i]=='(' || str[i]=='[')//adds openers to the stack
		{
			push(s, str[i]);
		}
		else if((str[i] == ')' || str[i] == ']') && !isEmpty(s))//checks to see if we have a closer while there are openers in need of closing
		{
			char test = pop(s);
			if((test == '(' && str[i] == ']') || (test == '[' && str[i] == ')'))//makes sure that the closer isn't in the wrong place
			{
				wellFormed = false;
			}
		}
		else
		{
			wellFormed = false;//for cases when it is an closer but the stack is empty, avoids removing from an empty stack
		}
	}

	cout << "Expression " << str << " is ";
	if(wellFormed && isEmpty(s)) //returns correclty based on if the expression is well formed or not
	{
		cout << "well-formed.";
	}
	else
	{
		cout << "not well-formed.";
	}
	destroy(s);
}