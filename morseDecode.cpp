#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	string codes[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "Enter Morse words, one per line:\n";

	string line;
	getline(cin, line);//retrieves the whole line

	string final = ""; // final string

	while(line != "Quit") //makes sure we are still supposed to keep reading the lines
	{
		stringstream ss(line);
		string word;
		while(ss >> word)//handles finding out which letter the morse corresponds to
		{
			int i = 0;
			while(i < 26)
			{
				if(word == codes[i])
					final = final + alpha[i];
				i++;
			}
		}
		final = final + " ";
		getline(cin, line);
	}

	cout << "\n" << final;
}