#include <iostream>

#define size_t unsigned int 

enum class Suit { Diamonds = 1, Hearts,	 Spades, Clubs, };

enum class HightDignity { Jack = 11, Queen, King, Ace };

struct Card {
	Suit m_suit;
	
	size_t m_dignity;

	Card() = delete;

	Card(Suit, size_t);
};
