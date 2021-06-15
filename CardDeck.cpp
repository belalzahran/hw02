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

static const string rankString[] = 
{
	"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

static const string suitString[] = 
{
	"Clubs","Diamonds", "Hearts", "Spades"
};


/********************************************************************
 * Constructor CardDeck: class CardDeck
 * ------------------------------------------------------------------
 * This creates a default instance of the class
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * <none>
 *
 * POST-CONDITIONS
 * this function creates a deck of cards (size = 52)
 ********************************************************************/
CardDeck::CardDeck()
{
	int count;
	count = 0;

	// loop through the array and initialize all the values
	for(int suit = CLUBS; suit<= SPADES; suit++)
	{
		for(int rank = ACE; rank <= KING; rank++)
		{

			Deck[count].number = count + 1;
			Deck[count].suit = suitType(suit);
			Deck[count].rank = rankType(rank);

			count++;
		}
	}
}

/********************************************************************
 * Destructor CardDeck: class CardDeck
 * ------------------------------------------------------------------
 * This creates a destructs the deck
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * <none>
 *
 * POST-CONDITIONS
 * the object will be destructed automatically
 ********************************************************************/
CardDeck::~CardDeck()
{

};


/********************************************************************
 * Method PerfectShuffe: class CardDeck
 * ------------------------------------------------------------------
 * This method will perform a perfuct shuffle on the deck of cards
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * initialized deck of cards
 *
 * POST-CONDITIONS
 * deck of cards will be shuffled
 ********************************************************************/
 
void CardDeck::PerfectShuffle()
{
	const int HALF_DECK = DECK_SIZE / 2;

	Cards lowerHalfArray[HALF_DECK];
	Cards upperHalfArray[HALF_DECK];

	// create a seperate array of cards 1-26
	for(int i = 0; i< HALF_DECK;i++)
	{
		lowerHalfArray[i]= Deck[i];
	}
	// create a seperate array of cards 27-52
	for(int j = 0;j< HALF_DECK;j++)
	{
		upperHalfArray[j]= Deck[j+26];
	}

	int count1 = 0;
	int count2 = 0;
	int l = 0;
	bool swap = true;

	// loop through upper deck half
	while(l < DECK_SIZE)
	{
		// loop through the smaller array and insert the correct cards to deck
		if(swap)
		{
			Deck[count2] = lowerHalfArray[count1];
			count1++;
		}

		swap = !swap;
		count2++;
		l++;
	}

	count1 = 0;
	count2 = 0;
	l = 0;
	swap = false;


	// loop through lower deck half
	while(l < DECK_SIZE)
	{
		// loop through the smaller array and insert the correct cards to deck
		if(swap)
		{
			Deck[count2] = upperHalfArray[count1];
			count1++;
		}

		swap = !swap;
		count2++;
		l++;
	}
}



/********************************************************************
 * Method PrintDeck: class CardDeck
 * ------------------------------------------------------------------
 * This method will print out the deck of cards
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * <none>
 *
 * POST-CONDITIONS
 * Deck of cards will be printed
 ********************************************************************/
 
void CardDeck::PrintDeck() const
{
	// print out the deck by looping through it
	for (int count = 0; count < DECK_SIZE; count++)
	{
		cout << "#" << Deck[count].number << ". " << rankString[Deck[count].rank] << " of " << suitString[Deck[count].suit] << endl;
	}

	cout << "\n";
}



/********************************************************************
 * Method GetRank: class CardDeck
 * ------------------------------------------------------------------
 * This method will return the rank of the card in a deck
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * a deck or card
 *
 * POST-CONDITIONS
 * rank of card will be returned
 ********************************************************************/

int CardDeck::GetRank( int count) const
{
	return rankType(Deck[count].rank);
}

/********************************************************************
 * Method GetSuit: class CardDeck
 * ------------------------------------------------------------------
 * This method will return the suit of the card in a deck
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * a deck or a card
 *
 * POST-CONDITIONS
 * suit of card will be returned
 ********************************************************************/
 
int CardDeck::GetSuit( int count) const
{
	return suitType(Deck[count].suit);
}


/********************************************************************
 * Method operator ==: class CardDeck
 * ------------------------------------------------------------------
 * This method is an overloaded version of the operator ==. THe 
 * purpose of this method is to compare a deck to another deck to see
 * if they are equal
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * two decks to be compared
 *
 * POST-CONDITIONS
 * a boolean to represent whether two decks are equal or not
 ********************************************************************/
bool operator ==(const CardDeck &myDeck, const CardDeck &originalDeck)
{
	int count = 0;
	bool same = true;

	// loop through the entire deck to check if all cards are in the same positions in both decks
	while (count < DECK_SIZE && same)
	{
		if( myDeck.GetRank(count) != originalDeck.GetRank(count) &&  myDeck.GetSuit(count) != originalDeck.GetSuit(count) )
			same = !same;

		count++;
	}
	return same;
}

