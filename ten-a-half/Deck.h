#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include<iostream>
using namespace std;

class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card draw();
    int size() const;
};

#endif // DECK_H
