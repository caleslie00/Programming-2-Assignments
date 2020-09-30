#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include "p2heap.h"
using namespace std;

int main()
{
    Heap<int> T;
   initialize(T);
    int count = 30;
    int step = 3;
    for( int i = count; i > 0; i-- )
        put(T, i*step);
    for( int i = 1; i <= count; i++ )
    {
        for(int j = 1; j <= T.size; j++)
            cout << T.data[j] << ", ";
        cout << endl;
        int v = get(T);
        cout << v << " : " << i*step << endl;
        for(int j = 1; j <= T.size; j++)
            cout << T.data[j] << ", ";
        cout << endl;
    }
    string str;
    cin >> str;
    destroy(T);
}