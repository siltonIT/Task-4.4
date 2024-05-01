#include "CardDeck.h"

std::ostream& operator<< (std::ostream& os, const CardDeck& deck) {
	for(size_t i = 0; i < deck.m_size; ++i) {
		switch(deck.m_cards[i].m_suit) {
			case Suit::Clubs: 
				os << "Clubs" << ' ';
				break;
			case Suit::Hearts:
				os << "Hearts" << ' ';
				break;
			case Suit::Spades:
				os << "Spades" << ' ';
				break;
			case Suit::Diamonds:
				os << "Diamonds" << ' ';
				break;
		}

		switch(static_cast<HightDignity>(deck.m_cards[i].m_dignity)) {
			case HightDignity::Jack:
				os << "Jack" << '\n';
				break;
			case HightDignity::Queen:
				os << "Queen" << '\n';
				break;
			case HightDignity::King:
				os << "King" << '\n';
				break;
			case HightDignity::Ace:
				os << "Ace" << '\n';
				break;
			default:
				os << deck.m_cards[i].m_dignity << '\n';
				break;
		}
	}

	return os;
}

std::istream& operator>> (std::istream& is, CardDeck& deck) {
	size_t suit = 0;
	size_t dignity = 0;

	for(size_t i = 0; i < deck.m_capacity; ++i) {
		is >> suit >> dignity;
		deck.m_cards[i] = Card(static_cast<Suit>(suit), dignity);
		++deck.m_size;
	}
	
	return is;
}

CardDeck operator+ (const CardDeck& deck1, const CardDeck& deck2) {
	CardDeck res(deck1);

	for(size_t i = 0; i < deck2.m_size; ++i)
		res += deck2.m_cards[i];

	return res;
}

CardDeck operator- (const CardDeck& deck1, const CardDeck& deck2) {
	CardDeck res(deck1);

	for(size_t i = 0; i < deck2.m_size; ++i) 
		res -= deck2.m_cards[i];

	return res;
}

CardDeck operator/ (const CardDeck& deck1, const CardDeck& deck2) {
	CardDeck res(deck1);

	for(size_t i = 0; i < deck2.m_size; ++i)
		if(!res.is_uniq(deck2.m_cards[i]))
			res -= deck2.m_cards[i];

	return res;
}

CardDeck::CardDeck(): m_capacity(def_capacity), m_size(0), m_cards(new Card[m_capacity]) {}

CardDeck::CardDeck(size_t capacity): m_capacity(capacity), m_size(0), m_cards(new Card[m_capacity]) {}

CardDeck::CardDeck(const CardDeck& other): m_capacity(other.m_capacity), m_size(other.m_size), m_cards(new Card[m_capacity]) {
	std::copy(m_cards, other.m_cards, m_size);
}

CardDeck& CardDeck::operator= (CardDeck other) {
	swap(other);
	return *this;
}

CardDeck::CardDeck(CardDeck&& other) noexcept : m_capacity(other.m_capacity), m_size(other.m_size), m_cards(other.m_cards) {
	other.m_cards = nullptr;
	other.m_capacity = other.m_size = 0;
}

CardDeck& CardDeck::operator= (CardDeck&& other) noexcept {
	CardDeck move(std::move(other));
	swap(move);
	return *this;
}

void CardDeck::swap(CardDeck& other) noexcept {
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_cards, other.m_cards);
	std::swap(m_size, other.m_size);
}

CardDeck::~CardDeck() {
	delete[] m_cards;
}

CardDeck& CardDeck::operator+= (const Card& card) {
	if(!is_uniq(card))
		return *this;
	
	if(m_size >= m_capacity)
		resize();

	m_cards[m_size] = card;
	++m_size;
	return *this;
}

CardDeck& CardDeck::operator-= (const Card& key) {
	for(size_t i = 0; i < m_size; ++i) {
		if(m_cards[i] == key) {
			for(; i < m_size - 1; ++i)
				m_cards[i] = m_cards[i + 1];

			--m_size;
			return *this;
		}
	}

	return *this;
}

size_t CardDeck::capacity() const {
	return m_capacity;
}

size_t CardDeck::size() const { 
	return m_size;
}

bool CardDeck::is_uniq(const Card& key) {
	for(size_t i = 0; i < m_size; ++i)
		if(m_cards[i] == key)
			return false;

	return true;
}

void CardDeck::resize() {
	size_t capacity = m_capacity;
	Card* cards = new Card[capacity];

	std::copy(cards, m_cards, m_size);
	
	delete[] m_cards;
	m_cards = cards;
	m_capacity = capacity;
}
