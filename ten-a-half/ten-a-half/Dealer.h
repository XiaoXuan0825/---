#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"

class Dealer {
private:
    Hand hand;

public:
    Dealer();
    void receiveCard(const Card& card);
    vector<Card> getHand() const;
    double getHandValue() const;
    void clearHand();
    void bet(double amount);
};

#endif // DEALER_H
