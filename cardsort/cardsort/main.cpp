/*Tests different algorithms for sorting cards*/
#include "tabletop.h"

int main() {
	deck deck1;
	cout << "Initial Deck:" << endl;
	deck1.display();
	deck1.shuffle();
	cout << "Shuffled Deck:" << endl;
	deck1.display();
	tabletop ourtable;
	for (int i = 0; i < DECKSIZE; i++) {
		ourtable.addcard(deck1.pop());
	}
	cout << "Cards in piles on tabletop: " << endl;
	ourtable.printtable();
	deck sorted_deck;
	sorted_deck.shuffle();
	for (int i = 0; i < 52; i++) {
		sorted_deck[i] = ourtable.pop_top_card();
	}
	cout << "Cards sorted off tabletop back into deck" << endl;
	sorted_deck.display();
	return 0;
}