#include <array>
#ifndef CARDS_H
#define CARDS_H



namespace Cards {
	enum CardSuits
	{
		clubs,
		diamonds,
		hearts,
		spades,

		max_suits
	};

	enum CardRanks
	{
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,
		rank_ace,

		max_rank
	};

	struct Card
	{
		CardRanks rank;
		CardSuits suit;
	};
}

using Deck = std::array<Cards::Card, 52>;
Deck create_deck();
void shuffle_deck(Deck& deck);
int get_card_value(Cards::Card card);
#endif
