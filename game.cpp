#include <iostream>
#include "card.h"
#include "deck.h"

char menu();
void game();

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
	int gameVal = 0;
	do 
	{
		std::cout << "\n\n\n";
		if(gameVal == 21)
		{
			std::cout << "Winner!\n";
			break;
		}
		
		std::cout << "You have:\n";
		for(int index = 0; index < player.getDeck().size(); index++)
		{
			
		}
	}while(gameVal <= 21);
}

char deal()
{
	bool isValid = false;
	char choice(0);

	do
	{
		std::cout << "(p)lay\n";
		std::cout << "(q)uit\n" << std::endl;
		std::cout << "==> ";

		std::cin >> choice;
		
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
