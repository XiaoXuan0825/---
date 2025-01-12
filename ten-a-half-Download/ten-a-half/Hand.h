#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>
#include<iostream>
using namespace std;

class Hand {
private:
    vector<Card> cards;

public:
    Hand();
    void addCard(const Card& card);
    vector<Card> getCards() const;
    double getValue() const;
    void clear();
};

#endif // HAND_H
