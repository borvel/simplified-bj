#include "Io.h"
#include "Cards.h"
#include <iostream>

void print_card(const Cards::Card card)
{
	using enum Cards::CardRanks;
	switch (card.rank)
	{
	case rank_2:
		std::cout << "2"; 
		break;
	case rank_3:
		std::cout << "3";
		break;
	case rank_4:
		std::cout << "4";
		break;
	case rank_5:
		std::cout << "5";
		break;
	case rank_6:
		std::cout << "6";
		break;
	case rank_7:
		std::cout << "7";
		break;
	case rank_8:
		std::cout << "8";
		break;
	case rank_9:
		std::cout << "9";
		break;
	case rank_10:
		std::cout << "T";
		break;
	case rank_jack:
		std::cout << "J";
		break;
	case rank_queen:
		std::cout << "Q";
		break;
	case rank_king:
		std::cout << "K";
		break;
	case rank_ace:
		std::cout << "A";
		break;
	default:
		std::cout << '?';
		break;
	}

	using enum Cards::CardSuits;
	switch (card.suit)
	{
	case clubs:
		std::cout << "C";
		break;
	case diamonds:
		std::cout << "D";
		break;
	case hearts:
		std::cout << "H";
		break;
	case spades:
		std::cout << "S";
		break;
	default:
		std::cout << '?';
		break;
	}
	std::cout << ' ';
}

void print_deck(const Deck& deck)
{
	for (auto card : deck)
	{
		print_card(card);
	}
}