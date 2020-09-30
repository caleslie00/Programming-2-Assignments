#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
//#include "p2queue.h"
//#include "p2stack.h"
//#include "p2priorityqueue.h"
//#include "p2map.h"
//#include "p2set.h"

using namespace std;

int fib(int n)
{
	if(n == 0 || n == 1) //checks for either of the base cases
		return n;
	return fib(n-1) + fib(n-2); //if not a base case return both parts of the fibonacci number
}

int main()
{
	cout << "This porgram calculates the number in the fibonacci sequence." << endl;
	cout << "which place in the sequence do you  want to calculate? ";
	int calcFib;
	cin >> calcFib;

	cout << endl << "Fibonacci(" << calcFib << ") is " << fib(calcFib); //calls fib in the correctly output
}