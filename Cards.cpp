#include "Cards.h"
#include <array>
#include <algorithm>
#include <ctime>
#include <random>

Deck create_deck()
{
	Deck deck{};
	int count_ranks{};
	int count_suits{};
	for (auto& card : deck)
	{
		card.rank = static_cast<Cards::CardRanks>(count_ranks);
		card.suit = static_cast<Cards::CardSuits>(count_suits);
		++count_suits;
		if (count_suits == 4)
		{
			++count_ranks;
			count_suits = 0;
		}

	}
	return deck;
}

void shuffle_deck(Deck& deck)
{
	static std::mt19937 mt{ static_cast <std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

int get_card_value(Cards::Card card)
{
	using enum Cards::CardRanks;
	switch (card.rank)
	{
	case rank_2:     return 2;
	case rank_3:     return 3;
	case rank_4:     return 4;
	case rank_5:     return 5;
	case rank_6:     return 6;
	case rank_7:     return 7;
	case rank_8:     return 8;
	case rank_9:     return 9;
	case rank_10:    return 10;
	case rank_jack:  return 10;
	case rank_queen: return 10;
	case rank_king:  return 10;
	case rank_ace:   return 11;
	default: return 0;
	}
}