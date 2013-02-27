#include "class_card.h"
using namespace cards;
using namespace std;

card::card (t_suit suit, t_rank rank)
{
	this->suit = suit;
	this->rank = rank;
}

string card::name ()
{
	return suit_name[suit] + ", " + rank;
}

t_suit card::getSuit ()
{
	return suit;
}

t_rank card::getRank ()
{
	return rank;
}