#include "Deck.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

Deck::Deck() {
    for (int s = SPADE; s <= CLUB; ++s) {
        for (int r = ACE; r <= KING; ++r) {
            Card card = { static_cast<CardRank>(r), static_cast<CardSuit>(s), r <= TEN ? r : 0.5 };
            cards.push_back(card);
            cards.push_back(card);
            cards.push_back(card);
            cards.push_back(card);
        }
    }
}

void Deck::shuffle() {
    srand(time(0));
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::draw() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

int Deck::size() const {
    return cards.size();
}
