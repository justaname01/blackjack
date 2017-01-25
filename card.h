#ifndef CARD_H
#define CARD_H	//include guard

enum Suit{
	HEART,SPADE,CLUB,DIAMOND
};
enum Rank{
	NIL,NUM01,NUM02,NUM03,NUM04,NUM05,NUM06,NUM07,NUM08,NUM09,ACE,JACK,QUEEN,KING
};

class Card
{
	private:
		Suit suit;
		Rank rank;
		Card();
		Card(Suit,Rank);
	public:
		static Card getHeart( Rank );
		static Card getSpade( Rank );
		static Card getClub( Rank );
		static Card getDiamond( Rank );
		static Card getCard( Suit, Rank );
		Suit getSuit() const;
		Rank getRank() const;

		//relational operators
		bool operator==(const Card&);
		bool operator!=(const Card&);
		bool operator>(const Card&);
		bool operator<(const Card&);
		bool operator>=(const Card&);
		bool operator<=(const Card&);
};

#endif
