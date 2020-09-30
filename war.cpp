#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "p2queue2.h"
//#include "p2stack.h"
//#include "p2priorityqueue.h"
#include "p2map.h"
//#include "p2set.h"

using namespace std;

//pushes all values from both of the hold queues into the queue of the most recent winner
void pushAllInto(Queue<int>& into, Queue<int>& firstHold, Queue<int>& secondHold)
{
	while(!isEmpty(firstHold))
	{
		push(into, pop(firstHold));
	}
	while(!isEmpty(secondHold))
	{
		push(into, pop(secondHold));
	}
}

//correctly does war between the two players as well as keeps track of the number of battles
void doWar(int& b, Queue<int>& p1, Queue<int>& p2, Queue<int>& h1, Queue<int>& h2)
{
	if(b > 5000 || isEmpty(p1) || isEmpty(p2)) //makes sure nobody has won yet
	{
		return;
	}
	b++;
	int c1 = pop(p1);
	int c2 = pop(p2);
	push(h1, c1);
	push(h2, c2);
	if(c1 > c2) //player1 wins
	{
		pushAllInto(p1, h1, h2);
	}
	else if(c1 < c2) //player2 wins
	{
		pushAllInto(p2, h2, h1);
	}
	else //tie
	{
		for(int i = 0; i < 3; i++)//pop 3 and add them to the hold queues
		{
			if(!isEmpty(p1))
				push(h1, pop(p1));
			if(!isEmpty(p2))
				push(h2, pop(p2));
		}
		doWar(b, p1, p2, h1, h2); //doWar with the decks again because it's regular at this point
	}
}

int main()
{
	Queue<int> player1; //player1's cards
	Queue<int> player2; //player2's cards
	Queue<int> hold1; //holds player1's cards between battles
	Queue<int> hold2; //holds player2's cards between battles

	initialize(player1);
	initialize(player2);
	initialize(hold1);
	initialize(hold2);

	Map<string, int> priority; //holds number "currency" for each card(K=13, ect)
	initialize(priority);

	assign(priority, (string)"2", 2);
	assign(priority, (string)"3", 3);
	assign(priority, (string)"4", 4);
	assign(priority, (string)"5", 5);
	assign(priority, (string)"6", 6);
	assign(priority, (string)"7", 7);
	assign(priority, (string)"8", 8);
	assign(priority, (string)"9", 9);
	assign(priority, (string)"10", 10);
	assign(priority, (string)"J", 11);
	assign(priority, (string)"Q", 12);
	assign(priority, (string)"K", 13);
	assign(priority, (string)"A", 14);
	ifstream fin;
	fin.open("player1");
	string str;
	getline(fin, str);
	stringstream ss1(str);
	while(ss1 >> str) //push all cards into player1
	{
		push(player1, lookup(priority, str));
	}
	fin.close();
	fin.open("player2");
	getline(fin, str);
	stringstream ss2(str);
	while(ss2 >> str) //push all cards into player2
	{
		push(player2, lookup(priority, str));
	}
	fin.close();
	int battles = 0;
	while((battles < 5000) && (!isEmpty(player1)) && (!isEmpty(player2))) //do war until a winner is found or too many battles have been completed
	{
		doWar(battles, player1, player2, hold1, hold2);
	}
	if(battles >= 5000) //output a tie
	{
		cout << "Nobody wins.";
	}
	else //output a win
	{
		cout << ((isEmpty(player2)) ? ("Player 1 wins after ") : ("Player 2 wins after ")) << battles << " battles.";
	}
	
	destroy(player1);
	destroy(player2);
	destroy(hold1);
	destroy(hold2);
	destroy(priority);
}