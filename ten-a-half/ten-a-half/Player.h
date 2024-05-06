#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include<iostream>
using namespace std;

class Player {
private:
    double money;
    vector<Card> hand;

public:
    Player(double startingMoney = 100);
    void receiveCard(const Card& card);
    double getHandValue() const;
    void clearHand();
    bool hasMoney(double amount) const;
    void bet(double amount);
    void win(double amount);
    double getMoney() const;
    const vector<Card>& getHand() const;
};

#endif // PLAYER_H
