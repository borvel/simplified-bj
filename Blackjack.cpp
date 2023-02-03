#include "Blackjack.h"
#include "Cards.h"
#include "Io.h"
#include <iostream>
constexpr int g_maximum_score{ 21 };
constexpr int g_minimum_dealer_score{ 17 };
void play_blackjack(const Deck& deck)
{
	
	int dealer_score{};
	int player_score{};

	std::cout << "Dealer gets: ";
	print_card(deck[0]);
	std::cout << '\n';

	dealer_score += get_card_value(deck[0]);
	std::cout << "Total dealer score: " << dealer_score << '\n';

	std::cout << "You get: ";
	print_card(deck[1]);
	print_card(deck[2]);
	std::cout << '\n';

	player_score = player_score + get_card_value(deck[1]) + get_card_value(deck[2]);
	std::cout << "Total player score: " << player_score << '\n';

	int player_card_count = 2;
	while (player_score < g_maximum_score)
	{
		std::cout << "Hit or stand? (H/S) ";
		char choice{};
		std::cin >> choice;
		if (choice == 'H')
		{
			++player_card_count;
			player_score += get_card_value(deck[player_card_count]);
			std::cout << "You get: ";
			print_card(deck[player_card_count]);
			std::cout << '\n';
			std::cout << "Total player score: " << player_score << '\n';
		}
		else if (choice == 'S')
		{
			break;
		}
	}

	bool win{ false };
	if (player_score == g_maximum_score)
	{
		std::cout << "Congrats, you win!\n";
	}
	else if (player_score > g_maximum_score)
	{
		std::cout << "Sorry, you bust!\n";
	}
	else if (player_score < g_maximum_score)
	{
		int dealer_card_count{ player_card_count};
		while (dealer_score < 17)
		{
			++dealer_card_count;
			dealer_score += get_card_value(deck[dealer_card_count]);
			std::cout << "Dealer gets: ";
			print_card(deck[dealer_card_count]);
			std::cout << '\n';
			std::cout << "Total dealer score: " << dealer_score << '\n';

			if (dealer_score > g_maximum_score)
			{
				win = true;
				std::cout << "Congrats, you win!";
				break;
			}
		}
		if (player_score > dealer_score && !win)
		{
			std::cout << "Congrats, you win!";
		}
		else if(!win)
		{
			std::cout << "Sorry, you lose!";
		}
		

		
	}


}