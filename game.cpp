#include <iostream>
#include <limits>
#include "card.h"
#include "deck.h"

#define BANK 21

char menu();
void game();
char deal();

int prettyPrintDeck(Deck);

int main()
{
	char c = menu();
	
	switch(c)
	{
		case 'p':
			game();
			break;
		case 'q':
		default:
			break;
	}

	return 0;
}

char menu()
{
	bool isValid = false;
	char choice(0);

	do
	{
		std::cout << "Let\'s play Blackjack!\n";
		std::cout << "Menu:\n";
		std::cout << "\n\n\n";
		std::cout << "(p)lay\n";
		std::cout << "(q)uit\n" << std::endl;
		std::cout << "==> ";

		std::cin >> choice;
		
		//clear out cin
		if(std::cin.bad())
			std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(),'\n' );
		
		switch(choice)
		{
			case 'p':
			case 'q':
				isValid = true;
				break;
			default:
				break;
		}
	}while( !isValid );

	return choice;
}

void game()
{
	Deck deck;		//the main deck
	Deck dealer;		//for keeping track of the dealer's hand
	Deck player;		//for keeping track of the player's hand
	
	player.clearDeck();	//clear the player's hand
	dealer.clearDeck();	//clear the dealer's hand
	deck.shuffle();		//shuffle the deck
	int gameVal = 0;
	
	bool player_turn = true;
	
	//game loop
	do 
	{
		std::cout << "\n\n\n";
		
		std::cout << "You have:\n";
		int pVal = prettyPrintDeck(player);
		
		std::cout << "\nThe deck has a value of " << pVal;
		
		//exit cases
		if(gameVal == BANK)
		{
			std::cout << "Winner!\n";
			break;
		}else if(gameVal > BANK)
		{
			std::cout << "Loser!\n";
			break;
		}
		
		char action = deal();
		switch(action)
		{
			case 'h':
			{
				Card next = deck.draw();
				player.putCard(next);
			}
				break;
			case 'o':
				player_turn = false;
				break;
			default:
				break;
		}
	}while(gameVal <= BANK && player_turn);
}

char deal()
{
	bool isValid = false;
	char choice(0);

	do
	{
		std::cout << "\n\n\nPlease select an action:\n\n";
		std::cout << "(h)it me!\n";
		std::cout << "h(o)ld\n" << std::endl;
		std::cout << "==> ";

		std::cin >> choice;
		
		//clear out cin after reading character
		//this lets the user enter as many chars as they want, and only the first will be considered
		if(std::cin.bad())
			std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(),'\n' );
		
		switch(choice)
		{
			case 'h':
			case 'o':
				isValid = true;
				break;
			default:
				break;
		}
	}while( !isValid );

	return choice;
}

int prettyPrintDeck(Deck d)
{
	int sumValue = 0;
	int nAces = 0;
	const int FACE_VALUE = 10;
	
	deque<Card> cardDeck = d.getDeck();
	for(int index = 0; index < cardDeck.size(); index++)
	{
		switch( cardDeck.at(index).getRank() )
		{
			case NUM01:
				std::cout << "A 1 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM02:
				std::cout << "A 2 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM03:
				std::cout << "A 3 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM04:
				std::cout << "A 4 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM05:
				std::cout << "A 5 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM06:
				std::cout << "A 6 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM07:
				std::cout << "A 7 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM08:
				std::cout << "An 8 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case NUM09:
				std::cout << "A 9 of ";
				sumValue += static_cast<int>(cardDeck.at(index).getRank());
				break;
			case ACE:
				std::cout << "An Ace of ";
				nAces++;
				break;
			case JACK:
				std::cout << "A Jack of ";
				sumValue += FACE_VALUE;
				break;
			case QUEEN:
				std::cout << "A Queen of ";
				sumValue += FACE_VALUE;
				break;
			case KING:
				std::cout << "A King of ";
				sumValue += FACE_VALUE;
				break;
			default:
				std::cout << "A very weird card, which shouldn't even exist.";
				break;
		}
		
		switch( cardDeck.at(index).getSuit() )
		{
			case HEART:
				std::cout << "Hearts";
				break;
			case SPADE:
				std::cout << "Spades";
				break;
			case CLUB:
				std::cout << "Clubs";
				break;
			case DIAMOND:
				std::cout << "Diamonds";
				break;
			default:
				std::cout << "Some weird suit that shouldn't exist in a regular card deck.";
				break;
		}
		if(index < cardDeck.size() - 1)
			std::cout << ",";
		else
			std::cout << ".";
		std::cout << "\n";
	}
	
	#define ACE_HIGH 11
	#define ACE_LOW 1
	for(int counter = 0; counter < nAces; counter++)
	{
		if( sumValue + ACE_HIGH > BANK )
			sumValue += ACE_LOW;
		else
			sumValue += ACE_HIGH;
	}
	
	return sumValue;
}
