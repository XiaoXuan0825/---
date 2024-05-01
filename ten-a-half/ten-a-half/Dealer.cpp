#include "Dealer.h"

Dealer::Dealer() {}

void Dealer::receiveCard(const Card& card) {
    hand.addCard(card);
}

std::vector<Card> Dealer::getHand() const {
    return hand.getCards();
}

double Dealer::getHandValue() const {
    return hand.getValue();
}

void Dealer::clearHand() {
    hand.clear();
}

void Dealer::bet(double amount) {}
