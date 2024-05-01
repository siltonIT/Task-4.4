#include "Card.h"

Card::Card(): m_suit(Suit::Diamonds), m_dignity(2) {}

Card::Card(Suit suit, size_t dignity): m_suit(suit), m_dignity(dignity) {} 

bool Card::operator==(const Card& other) {
	return m_suit == other.m_suit && m_dignity == other.m_dignity;
}
