#ifndef CARD_H
#define CARD_H

// ���
enum CardSuit { SPADE, DIAMOND, HEART, CLUB };

// �I��
enum CardRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

// �P���c
struct Card {
    CardRank rank;
    CardSuit suit;
    double value;
};

#endif // CARD_H
