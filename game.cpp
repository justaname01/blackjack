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
	std::cout << "\n";
}