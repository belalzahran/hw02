/*******************************************************************************
* AUTHOR     : Belal Zahran
* STUDENT ID : 1176978
* CLASS      : CS1C - MTWT: 3:00 - 5:20pm
* DUE DATE   : 6/15/2021 
*******************************************************************************/

#include "CardDeck.h"
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
* hw02 - Deck of Cards
*-------------------------------------------------------------------------------
* This program contains a class called CardDeck which represents a deck of cards.
 The program performs a perfect shuffle on the deck of cards and continues to do
 so untill the deck returns to its original configuration. then the program
 will output the number of shuffles that were required to do so.
*-------------------------------------------------------------------------------
* INPUT:
* 	<none>
*
* OUTPUT:
*  number of shuffles
*  the deck of cards
*******************************************************************************/

int main(){

	CardDeck myDeck;       // CALC & OUT - a card deck to be shuffled
	CardDeck originalDeck; // OUT        - a card deck
	int shuffleCount;      // CALC & OUT - the number of shuffles


	// OUTPUT CLASS HEADING

	cout << "*****************************************\n";
	cout << "   Programmed by: Belal Zahran\n";
	cout << "   Student ID   : 1176978\n";
	cout << "   CS1B         : MTWT: 3:00 - 5:20pm\n";
	cout << "   HW #2        : Deck of Cards\n";
	cout << "*****************************************\n";

	shuffleCount = 0;

	// do while loop to perform shuffles while counting
	do{
		
		if(shuffleCount == 0)
		{
			cout << "Original Deck Configuration: \n\n";
			myDeck.PrintDeck();
		}
		else if(shuffleCount == 1)
		{
			cout << "\nDeck Configuration After 1 Perfect Shuffle: \n\n";
			myDeck.PrintDeck();
		}
		else
		{
			cout << "Shuffle Number " << shuffleCount << "...\n";
		}

		// perform the shuffle
		myDeck.PerfectShuffle();
		// incerement the shuffle counter
		shuffleCount++;

	}while(!(myDeck == originalDeck ) );

	cout << "\nThe deck has been returned to its original configuration after " << shuffleCount << " shuffles.\n\n";

	// print the deck
	myDeck.PrintDeck();

	return 0;

}