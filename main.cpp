#include "Blackjack.h"
#include "Io.h"



int main()
{
	auto deck{ create_deck() };
	shuffle_deck(deck);
	play_blackjack(deck);

}
