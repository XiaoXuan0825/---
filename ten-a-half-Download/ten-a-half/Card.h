#ifndef CARD_H
#define CARD_H

// 花色
enum CardSuit { SPADE, DIAMOND, HEART, CLUB };

// 點數
enum CardRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

// 牌結構
struct Card {
    CardRank rank;
    CardSuit suit;
    double value;
};

#endif // CARD_H
