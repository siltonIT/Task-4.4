#include <iostream>
#include <algorithm>
#include <istream>
#include <ostream>
#include "Card.h"

#define size_t unsigned int
#define def_capacity 1

class CardDeck {
	friend std::ostream& operator<< (std::ostream&, const CardDeck&);
	
	friend std::istream& operator>> (std::istream&, CardDeck&);
	
	//обьденение множеств
	friend CardDeck operator+ (const CardDeck&, const CardDeck&);

	//пресечение множеств
	friend CardDeck operator/ (const CardDeck&, const CardDeck&);

	//вычитание множеств
	friend CardDeck operator- (const CardDeck&, const CardDeck&);

public: 
	CardDeck();
	
	CardDeck(size_t);

	CardDeck(const CardDeck&);

	CardDeck& operator= (CardDeck);

	CardDeck(CardDeck&&) noexcept;

	CardDeck& operator= (CardDeck&&) noexcept;

	~CardDeck();
                                     
	//swap для идиом copy and swap и move and swap                                                                                       
        void swap(CardDeck&) noexcept; 

	//добавление элемента
        CardDeck& operator+= (const Card&);                                                                                                                                         
                             
	//удаление элемента
        CardDeck& operator-= (const Card&);

	size_t capacity() const;

	size_t size() const;

private:
	void resize();

	bool is_uniq(const Card&) const;

	size_t m_capacity;
	size_t m_size;
	Card* m_cards;
};
