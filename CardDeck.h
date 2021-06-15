#ifndef CARDDECK_H_
#define CARDDECK_H_


const int DECK_SIZE = 52;

class CardDeck{

public:
	
	CardDeck();

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
	~CardDeck();
 
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
 
	 void PerfectShuffle();
	 
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
 
	void PrintDeck() const;

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
 
	int GetRank(int count) const;

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
 
	int GetSuit(int count) const;

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
 
	friend bool operator ==(const CardDeck &myDeck, const CardDeck &originalDeck);

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
 
private:
	typedef enum
	{
			CLUBS, DIAMONDS, HEARTS, SPADES	
	}suitType;

	typedef enum
	{
		ACE, TWO , THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	}rankType;

	struct Cards
	{
		int number;
		suitType suit;
		rankType rank;	
	};

	Cards Deck[DECK_SIZE];

};


#endif