#ifndef TENANDHALFGAME_H
#define TENANDHALFGAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class TenAndHalfGame {
private:
    Deck deck;
    Player player;
    Dealer dealer;

    void displayCard(const Card& card);
    void displayGameInfo();

public:
    TenAndHalfGame();
    void start();
};

#endif // TENANDHALFGAME_H
