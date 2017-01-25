#ifndef DECK_H
#define DECK_H

#include <deque>

class Deck
{
	private:
		std::deque<Card> cards;	//the 'deck' part of the deck
		bool sorted;		//is the deck sorted?
	public:
		Deck();			//c'tor
		void fillDeck();	//fill the deck
		void clearDeck();	//clear the deck
		void shuffle();		//shuffle the deck
		Card draw();		//draw a random card
		Card getCard( int );	//retrieve a card from the deck
		void putCard( Card );	//put a card in the deck
		void prettyPrint();	//pretty printing!
		void sortDeck();	//sort the deck
		std::deque<Card> getDeck();
		int getValue();		//returns the value of the cards in the deck.
};

#endif //DECK_H