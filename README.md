# Ace of Spades
###A C++ program for testing a practical card sorting algorithm
####The idea for this program originates from a blog post at http://www.timl.id.au/?p=23 and much of the information below is paraphased because Tim did such a good job of explaining the algorithm.

Computers can sort a deck of cards in a variety of different ways, most of which are impossible to perform in a sensible way on a tabletop with a real deck of cards. The quick algorithms-- mergesort and quicksort-- involve essentially splitting the deck into individual cards and reassembling them into a sorted deck. Slow algorithms like insertion, bubble, and selection sort make more sense to the average person, but are simply too slow to implement in a computer. 

Is there an algorithm which is human friendly and can keep a low fundamental complexity?

Let's go through the steps of the algorithm before we explain the implementation.

###1. Dealing
-Take the top card of the shuffled deck and place it on the left side of the table.
-Take the next card, if it is larger than the card we just placed, put it in its own pile to the right of the first card.
-For each card after, place it on the pile with the smallest top card which is still larger than it. If it is the largest card, make a new pile. You should have 6-12 piles by the end of this process.

###2. Collecting
-The leftmost pile's top card should be 0 (the ace of spades), pick up this card.
-Search for the 2 of spades, 3 of spades, etc.
-The next highest card should be on the top of one of the decks

###3. Reorganizing the piles
This is where the magic happens. A human can scan the tabletop rather quickly and deduce which topcard is next to draw. For a computer to do this would require a sequential search of the piles and inspection of their top card. Instead, we will store the piles in a min heap based on their top card. This allows the program to search the piles in O(logn) time. To do this, the pile must be removed from the table after the top card is drawn and reinserted with the new top card as its defining value in the min heap.

Ace of Spades is implemented as a map.
The tabletop is modeled as a map of vectors. Maps are implemented as heaps in C++, which allows the program to take advantage of the O(1) pop time and the O(logn) push time as described in step 3. Each vector is a "pile" of cards. Each key/value pair in the map has the "pile" as its value and the pile's top card as its key. When a card is removed from the top of the pile, the pile is removed from the map and reinserted with its top card as the key/value pair's new key.
This ensures the 0th index of the tabletop heap (the root of the heap) will always contain the pile that has the next smallest card! Popping the 0th index of the tabletop 52 times will give you the integers 0-52 in ascending order.

##Next steps
The next steps for Ace of Spades involve analyzing its runtime against quicksort, mergeseort, insertion sort, and selection sort.
We are also working to analyze how a set's randomness correllates to the total number of piles we have on our table after dealing.
