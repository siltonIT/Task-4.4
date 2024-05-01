#include "Task.h"
#include "Card.h"

int main() {
	std::cout << "Write deck size" << std::endl;
	size_t deck_size = 0;
	std::cin >> deck_size;

	CardDeck deck1(deck_size);
	std::cout << "Write first deck: " << std::endl;
	std::cin >> deck1;

	std::cout << "Write second deck: " << std::endl;
	CardDeck deck2(deck_size);
	std::cin >> deck2;
	
	std::cout << "obfuscation: " << std::endl;
	std::cout << deck1 + deck2 << std::endl;
	
	std::cout << "intersection: " << std::endl;
	std::cout << deck1 / deck2 << std::endl;

	std::cout << "subtraction: " << std::endl;
	std::cout << deck1 - deck2 << std::endl;

	CardDeck res;
	res += Card(static_cast<Suit>(1), 2);
	std::cout << "Add one element: " << res << std::endl;

	res -= Card(static_cast<Suit>(1), 2);
	std::cout << "Removed one element" << res << std::endl;
}
