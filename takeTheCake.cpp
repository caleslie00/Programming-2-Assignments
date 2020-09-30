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

int maxLayers(int A[], int s, int i, int top)
{
	if(i >= s) //base case: we are at the end of the list or past the end
		return 0;
	int takeIndex = 0;
	if(A[i] <= top) //if this layer can be added to the cake, create a branch where we add it
	{
		takeIndex = 1 + maxLayers(A, s, i+1, A[i]);
	}
	int skipIndex = maxLayers(A, s, i+1, top); //create a branch where we do not add this layer
	return (takeIndex > skipIndex) ? takeIndex : skipIndex; //take whichever can add on more layers and pass it upward
}

int main()
{
	int layers[30] = {0}; //the array of layers
	cout << "Cake sizes: ";
	string str;
	getline(cin, str);
	stringstream ss(str);
	int layer, size = 0;
	while(ss >> layer) //read in each value to the array
	{
		layers[size] = layer;
		size++;
	}
	cout << endl << endl;
	cout << "You can build a cake with " << maxLayers(layers, size, 0, 45) << " layers."; //correctly output the results
}