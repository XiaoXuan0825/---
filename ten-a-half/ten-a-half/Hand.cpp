#include "Hand.h"

Hand::Hand() {}

void Hand::addCard(const Card& card) {
    cards.push_back(card);
}

std::vector<Card> Hand::getCards() const {
    return cards;
}

double Hand::getValue() const {
    double value = 0.0;
    bool hasAce = false;

    for (const auto& card : cards) {
        if (card.rank >= 2 && card.rank <= 10) {
            value += card.rank;
        }
        else if (card.rank >= 11 && card.rank <= 13) {
            value += 0.5; // Jack, Queen, King are worth 0.5
        }
        else {
            hasAce = true;
            value += 1; // Assume Ace as 1 initially
        }
    }

    // Adjust Ace value if necessary
    if (hasAce && value <= 11) {
        value += 0.5;
    }

    return value;
}

void Hand::clear() {
    cards.clear();
}
