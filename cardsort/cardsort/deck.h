#pragma once
#define DECKSIZE 52
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <vector>
#include <time.h>
using namespace std;
class deck {
private:
	int cards[52];
	int size = 0;
public:
	deck() {
		for (int i = 0; i < DECKSIZE; i++){
			cards[i] = i;
			size++;
		}
	}
	void shuffle();
	int pop();
	void display();
	int& operator[](int i);
};

void deck::shuffle() {
	srand(time(NULL));
	int replace;
	int temp;
	for (int i = 0; i < DECKSIZE; i++) {
		replace = rand() % 52;
		temp = cards[i];
		cards[i] = cards[replace];
		cards[replace] = temp;
	}
	return;
}

void deck::display() {
	for (int i = 0; i < DECKSIZE; i++) {
		cout << cards[i] << " ";
	}
	cout << endl << "------------" << endl;
	return;
}

int deck::pop() {
	assert(size > 0);
	return cards[--size];
}

int& deck::operator[](int i) {
	return cards[i];
}