#pragma once
#include <iostream>
#include <stdlib.h>
#include "deck.h"
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <cassert>
typedef vector<int> Pile;
typedef map<int, Pile, less<int>> Tabletop;


using namespace std;

class tabletop {
	Tabletop ourtable;
public:
	//Adds a card to the table on top of a pile, or make a new pile with card as top
	void addcard(int n) {
		assert(n < 52 && n >= 0);
		int result = searchpile(n);
		//If a suitable pile is found, insert card on top
		if (result != -1) {
			//Copy pile at iterator location to a temp
			Pile temp_pile(ourtable[result]);
			//Erase the pile at the iterator location
			ourtable.erase(result);
			//Push the new card onto the top of the pile
			temp_pile.push_back(n);
			//Insert the pile back into the table, this reorganizes the tabletop
			ourtable.insert(std::make_pair(n, temp_pile));
		}
		else {
			Pile newpile;
			newpile.push_back(n);
			ourtable.insert(std::make_pair(n, newpile));
		}
	}

	//Finds which pile on the table to add the card to. -1 if we need a new pile
	int searchpile(int n) {
		Tabletop::iterator it;
		int result = -1;
		for (it = ourtable.begin(); it != ourtable.end(); it++)
		{
			if (n < it->first) {
				result = it->first;
				break;
			}
		}
		return result;
	}

	//Print the table, pile by pile
	void printtable() {
		for (Tabletop::iterator i = ourtable.begin(); i != ourtable.end(); i++) {
			for (Pile::iterator j = i->second.begin(); j != i->second.end(); j++) {
				cout << *j << " ";
			}
			cout << endl;
		}
		cout << "-----------------------" << endl;
	}

	//Pop the top card off the first pile, this will reorganize the tabletop
	int pop_top_card() {

		Tabletop::iterator i = ourtable.begin();
		Pile temp_pile(i->second);
		int result = i->first;
		ourtable.erase(i);
		//Do not reinsert if the pile is empty
		temp_pile.pop_back();
		if (temp_pile.size() == 0) {
			return result;
		}
		ourtable.insert(std::make_pair(temp_pile[temp_pile.size() - 1], temp_pile));
		return result;
	}
};