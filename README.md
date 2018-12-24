# Ace of Spades
### A C++ program for testing a practical card sorting algorithm
#### The idea for this program originates from a blog post at http://www.timl.id.au/?p=23

## Is there an algorithm which is human friendly and can keep a low fundamental complexity?

Computers can sort a deck of cards in a variety of different ways, most of which are impossible to perform in a sensible way on a tabletop with a real deck of cards. The quick algorithms-- mergesort and quicksort-- involve essentially splitting the deck into individual cards and reassembling them into a sorted deck. Slow algorithms like insertion, bubble, and selection sort make more sense to the average person, but are simply too slow to implement in a computer. 

Let's go through the steps of the algorithm before we explain the implementation.

### 1. Dealing O(n)
- Take the top card of the shuffled deck and place it on the left side of the table.  
- Take the next card, if it is larger than the card we just placed, put it in its own pile to the right of the first card.              
- For each card after, place it on the pile with the smallest top card which is still larger than it. If it is the largest card, make a new pile. You should have 6-12 piles by the end of this process.

### 2. Collecting O(logn)
- The leftmost pile's top card should be 0 (the ace of spades), pick up this card.         
- Search for the 2 of spades, 3 of spades, etc.                                      
- The next highest card should be on the top of one of the decks

### 3. Reorganizing the piles
This is where the magic happens. __A human can scan the tabletop rather quickly and deduce which topcard is next to draw. For a computer to do this would require a sequential search of the piles and inspection of their top card.__

Instead, we will store the piles in a min heap based on their top card. This allows the program to search the piles in O(logn) time. 
After finding and removing the lowest card, its pile must be reinserted in the heap with the new top card as its key in order for the pile to be in the right place in the heap

The tabletop is modeled as a map of vectors (a heap of piles). Maps are implemented as heaps in C++ which have __O(1) removal time__ and the __O(logn) insertion time__. Each key/value pair in the map has the pile's top card as its key, and the whole pile as its value. 

When a card is removed from the top of a pile, the pile is removed from the map and reinserted with its top card as the key/value pair's new key.
This ensures the 0th index of the tabletop heap (the root of the heap) will always contain the pile that has the next smallest card! Popping the 0th index of the tabletop 52 times will give you the integers 0-52 in ascending order.

### Caveats
- When dealing in the real world, we are performing a N^2 operation. For N cards, we must compare each card to at most N piles on the table before inserting. A computer can "deal" in n(logn) steps by inserting N cards into the heap in logn steps.

## Next steps
The next steps for Ace of Spades involve analyzing its runtime against quicksort, mergesort, insertion sort, and selection sort.
We are also working to analyze how a set's randomness correlates to the total number of piles we have on our table after dealing.
