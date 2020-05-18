/*
Program: CSCI340 Number 5
Use: The Josephus Problem 
Programmer: Michal Kowalczyk
ZID: Z1843873
Due: 10/11/2018
*/



#include "/home/cs340/progs/18f/p5/prog5.h"
#include <list>
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::list;
using std::string;

/***************************************************************
   FUNCTION: init_vals(list<string> &, args&)

   USE: To create a list of players with unique ID's, and to set when we remove a player, and how often we print the list.

   ARGUMENTS: L - list of values of type string, to hold the names of the players
	      in - an args struct, to hold the values of M, N, and K, inputted by the user
***************************************************************/


void init_vals(list <string>& L, args& in)
{
	cout << "How many players do we have : ";
	cin >> in.N;
	cout << "\nRemove every which person? : ";
	cin >> in.M;
	cout << "\nPrint out every which elimination? : ";
	cin >> in.K;
	cout << std::endl;
	L.resize(in.N);

	std::generate(L.begin(), L.end(), SEQ(in.N)); //calls our custom defined function SEQ()
}

/***************************************************************
   Function: print_list(const list <string>&, const unsigned&)

   USE: to print out the players left in the game, and to also print out which round of removals we are at.

   ARGUMENTS: L - the list of players to print out
              cnt - the current round of removal we are at.
***************************************************************/


void print_list(const list <string>& L, const unsigned& cnt)
{
int counter = 0;
	if (cnt == 0)
		cout <<  "The initial list of players: \n";
	else 
		cout << "After removing the " << cnt << "th person: \n" << "-----------------------------\n";

	for (list<string>::const_iterator it = L.begin(); it != L.end(); it++) //this is to print the contents , make a method 
	{
		cout << *it << " ";
		counter++;
		if (counter  == 12)
			{
			cout << std::endl;
			counter = 0;
			}
	}
cout << std::endl << std::endl;
}

// The assignement has print_list() loop within itself, but then the assignment also says
// to keep calling print_list() until only one left...

int main()
{
	list <string> players;
	args in;
	int j, i = 0;
	unsigned count = 0;

	init_vals(players, in);
	print_list(players, count);

	while (players.size() != 1)
        	{
        		j = ( i + in.M - 1) % players.size(); // finds the person to remove
        		i = j; // start the counting from the last position
			list<string>::const_iterator p = players.begin();
        		advance(p, j); //changes p to point to the jth value in the list
        		players.erase(p); //remove the j'th person
        		count++; // this keeps track of how many people we have removed.

       			if ((count % in.K) == 0 || players.size() == 1)
                		{
                	//	cout << "After removing the " << count << "th person: \n";
			//	cout << "-----------------------------\n"; 
                		print_list(players, count);
				}
		}

	return 0;
}
