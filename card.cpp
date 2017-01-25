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

Suit Card::getSuit() const
{
	return suit;
}

Rank Card::getRank() const
{
	return rank;
}

bool Card::operator==(const Card& rhs)
{
	//base operator. Suits aren't counted in valuing the card.
	return getRank() == rhs.getRank();
}

bool Card::operator!=(const Card& rhs)
{
	//defined in terms of ==, to build upwards
	return !((*this) == rhs);
}

bool Card::operator>(const Card& rhs)
{
	//defined in terms of < and ==, so as to build upwards.
	return !(((*this) < rhs) || ((*this) == rhs));
}

bool Card::operator<(const Card& rhs)
{
	return getRank() < rhs.getRank();
}

bool Card::operator>=(const Card& rhs)
{
	//defined in terms of a base operator
	return !((*this) < rhs);
}

bool Card::operator<=(const Card& rhs)
{
	return ((*this) < rhs || (*this) == rhs);
}