#include "card.h"

Card::Card() {	}

Card::Card(Suit s, Rank r): suit(s), rank(r)
{	}

Card Card::getHeart( Rank rank )
{
	return Card( HEART, rank );
}

Card Card::getSpade( Rank rank )
{
	return Card( SPADE, rank );
}

Card Card::getClub( Rank rank )
{
	return Card( CLUB, rank );
}

Card Card::getDiamond( Rank rank )
{
	return Card( DIAMOND, rank );
}

Card Card::getCard( Suit suit, Rank rank )
{
	return Card( suit, rank );
}

Suit Card::getSuit()
{
	return suit;
}

Rank Card::getRank()
{
	return rank;
}

/*bool operator==(const Card& lhs, const Card& rhs)
{
	return (lhs.getSuit() == rhs.getSuit() && lhs.getRank() == rhs.getRank());
}

bool operator!=(const Card& lhs, const Card& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const Card& lhs, const Card& rhs)
{
	return ()
}*/