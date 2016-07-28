#include "card.h"
#include "deck.h"
#include <chrono>
#include <random>
#include <algorithm>
#include <iostream>

//typedefs, for convenience

//default constructor
Deck::Deck()
{
	fillDeck();

	sorted = true;
}

//for the purposes of this 'basic' implementation, I'm putting in a fisher-yates shuffle (the Knuth variant in particular)
void Deck::shuffle()
{
	if(!sorted)
		sortDeck();
	
	//a generator from a seed
	std::mt19937 gen( std::chrono::high_resolution_clock::now().time_since_epoch().count() );
	
	for(int ind = cards.size()-1; ind > 0; ind--)
	{
		//a distributor from the generator
		std::uniform_int_distribution<int> distro(0,ind);
		
		int swap = distro(gen);
		Card c = cards.at(swap);
		cards.at(swap) = cards.at(ind);
		cards.at(ind) = c;
	}
	
	sorted = false;
}

//draw a card
Card Deck::draw()
{
	Card ret = cards.front();
	cards.pop_front();
	return ret;
}

//by-choice getCard
Card Deck::getCard(int ind)
{
	return cards.at(ind);
}

void Deck::putCard( Card c )
{
	cards.push_back( c );
	sorted = false;
}

void Deck::sortDeck()
{
	struct {
		bool operator()(Card a, Card b)
		{
			return a.getSuit() < b.getSuit();
		}
	} suitLess;
	
	struct {
		bool operator()(Card a, Card b)
		{
			return a.getRank() < b.getRank();
		}
	} rankLess;
	
	//first sort by suit
	std::sort(cards.begin(),cards.end(), suitLess);
	
	//then sort by rank
	std::sort( cards.begin(),cards.begin()+13,rankLess );
	std::sort( cards.begin()+13,cards.begin()+26, rankLess );
	std::sort( cards.begin()+26,cards.begin()+39, rankLess );
	std::sort( cards.begin()+39,cards.end(), rankLess );
	
	if(!sorted)
		sorted = true;
}

std::deque<Card> Deck::getDeck()
{
	return cards;
}

void Deck::fillDeck()
{
	//we need to generate a full deck.
	//so by this point in the function, the vector<Card> object should be default-constructed.
	//sooooo, perhaps something like this?
	std::deque<Rank> ranks = { NUM01,NUM02,NUM03,NUM04,NUM05,NUM06,NUM07,NUM08,NUM09,ACE,JACK,QUEEN,KING };

	int index000 = 0;
	//#define macros are still so ewww, but in this case, the reduction in source length is so worth it
	#define ITERATE(x) for(index000 = 0; index000 < ranks.size(); x,index000++)
	
	ITERATE( cards.push_back( Card::getHeart(   ranks.at(index000) ) ) );
	ITERATE( cards.push_back( Card::getSpade(   ranks.at(index000) ) ) );
	ITERATE( cards.push_back( Card::getClub(    ranks.at(index000) ) ) );
	ITERATE( cards.push_back( Card::getDiamond( ranks.at(index000) ) ) );

	#undef ITERATE
}

void Deck::clearDeck()
{
	cards.clear();
}
