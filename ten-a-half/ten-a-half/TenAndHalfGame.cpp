#include "TenAndHalfGame.h"
#include <iostream>
#include <cstdlib> // For rand()

TenAndHalfGame::TenAndHalfGame() {}

void TenAndHalfGame::displayCard(const Card& card) {
    string ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    string suits[] = { "黑桃", "菱形", "愛心", "梅花" };

    if (card.rank == 10) {
        cout << "10" << suits[card.suit] << " ";
    }
    else {
        cout << ranks[card.rank - 1] << suits[card.suit] << " ";
    }
}

void TenAndHalfGame::displayGameInfo() {
    cout << "Your hand: ";
    for (const auto& card : player.getHand()) {
        displayCard(card);
    }
    cout << std::endl;
    cout << "Dealer's hand: ";
    for (const auto& card : dealer.getHand()) {
        displayCard(card);
    }
    cout << std::endl;
    cout << "The number of cards in your hand: " << player.getHand().size() << endl;
}
int counter=0;

void TenAndHalfGame::start() {
    if(counter==0)cout << "Your current balance: $" << player.getMoney() << endl;
    while (true) {
        if (player.getMoney() <= 0) {
            cout << "You have no money left to play! Get loser!" << endl;
            cout << "When you gambling the house will always wins!" << endl;
            break;
        }

        // 初始化牌組並洗牌
        deck = Deck();
        deck.shuffle();
        
        if (counter > 0) {
            char choice;
            cout << "Deck shuffled? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                // 初始化牌組並洗牌
                deck = Deck();
                deck.shuffle();
                // 告知玩家已重新洗牌
                cout << "Deck shuffled." << std::endl;
            }
            else {
                break;
            }
        }

        // 下注
        double bet;
        cout << "Enter your bet (minimum $10): ";
        cin >> bet;

        if (bet < 10 || !player.hasMoney(bet)) {
            cout << "Invalid bet amount!" << endl;
            continue;
        }

        player.bet(bet);
        dealer.bet(bet);

        // 發牌給玩家和莊家
        player.receiveCard(deck.draw());
        dealer.receiveCard(deck.draw());

        // 顯示玩家的手牌和莊家的第一張牌
        displayGameInfo();

        // 玩家回合
        while (player.getHandValue() < 10.5) {
            char choice;
            cout << "Do you want to draw another card? (y/n): ";
            cin >> choice;

            if (choice == 'y') {
                player.receiveCard(deck.draw());
                cout << "Your hand: ";
                for (const auto& card : player.getHand()) {
                    displayCard(card);
                }
                cout << endl;
                cout << "You draw a card. Current total: " << player.getHandValue() << endl;
                cout << "The number of cards in your hand: " << player.getHand().size() << endl;
            }
            else {
                break;
            }
        }

        // 玩家爆牌或達到五張時結算
        double payoutMultiplier = 1.0;
        if (player.getHandValue() > 10.5) {
            cout << "Busted! You lose." << endl;
        }
        else {
            if (player.getHand().size() == 5) {
                if (player.getHandValue() == 10.5) {
                    cout << "Big-Dragon! You win!" << endl;
                    payoutMultiplier = 5.0;
                }
                else {
                    cout << "Dragon! You win!" << endl;
                    payoutMultiplier = 3.0;
                }
            }
            else if (player.getHandValue() == 10.5) {
                cout << "Ten-A-Half! You win!" << endl;
                payoutMultiplier = 2.0;
            }
            else {
                cout << "You didn't get 10.5. Let's see who is the winner." << endl;
            }

            // 莊家回合
            if (player.getHandValue() <= 10.5) {
                while (dealer.getHandValue() < 6 || (dealer.getHandValue() < 8 && rand() % 100 < 80) ||
                    (dealer.getHandValue() < 9 && rand() % 100 < 50) ||
                    (dealer.getHandValue() < 10 && rand() % 100 < 10)) {
                    Card drawnCard = deck.draw();
                    dealer.receiveCard(drawnCard);
                    cout << "Dealer draws a card: ";
                    displayCard(drawnCard);
                    cout << ". Current total: " << dealer.getHandValue() << endl;
                }
            }

            // 比較雙方牌組
            if (dealer.getHandValue() > 10.5 || (player.getHandValue() <= 10.5 && player.getHandValue() > dealer.getHandValue())) {
                cout << "Oh~Wow~! You win~!" << endl;
                player.win(bet * (payoutMultiplier+1)); // Winning bet plus the original bet
            }
            else if (player.getHandValue() < dealer.getHandValue()) {
                cout << "I win,haha. You are loser." << endl;
            }
            else {
                cout << "draw?Oh~Just assume that you win." << endl;
                player.win(bet * 2); // Refund the bet
            }
        }

        // 清空手牌
        player.clearHand();
        dealer.clearHand();

        // 問用戶是否繼續玩
        char playAgain;
        cout << "Your current balance: $" << player.getMoney() << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y') {
            continue;
            counter++;
        }
        else {
            break;
        }
    }

    cout << "Thanks for playing!off work!" << endl;
}


