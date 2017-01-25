# blackjack
A toy problem to be run on the terminal.

### overview
This was a side project begun in the interest of making a game of blackjack. My biggest goal in designing this was to get a complete solution running as quickly as possible. Thus, this game runs on any terminal application.

### design
There are 3 entities in the code:

* Card
	* This is the base piece. It does not depend on any other entity in the program. Everything else builds up from it. it is responsible for representing a single card from a deck.
* Deck
	* A deck of cards is a particular case of a collection. Thus, deck primarily depends on Card and my personal favorite, all-purpose collection, the double-ended queue. In addition to holding all the cards, it has facilities for filling, shuffling, and sorting the cards.
* Game
	* The meat of the machine, so to speak. Game contains all the functionality necessary to run the game.
