#include "TenAndHalfGame.h"
#include <iostream>
#include <cstdlib> // For rand()

TenAndHalfGame::TenAndHalfGame() {}

void TenAndHalfGame::displayCard(const Card& card) {
    string ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    string suits[] = { "�®�", "�٧�", "�R��", "����" };

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
    cout << "The number of cards in your hand: " << player.getHand().size() << endl << endl;
}
int counter=0;

void TenAndHalfGame::start() {
    if (counter == 0)cout << "Your current balance: $" << player.getMoney() << endl << endl;
    while (true) {
        if (player.getMoney() <= 0) {
            cout << "You have no money left to play! Get loser!" << endl << endl;
            cout << "When you gambling the house will always wins!" << endl << endl;
            break;
        }

        // ��l�ƵP�ըì~�P
        deck = Deck();
        deck.shuffle();
        
        if (counter > 0) {
            char choice;
            cout << "Deck shuffled? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                // ��l�ƵP�ըì~�P
                deck = Deck();
                deck.shuffle();
                // �i�����a�w���s�~�P
                cout << "Deck shuffled." << endl << endl;
                cout << " Start!" << endl << endl;
            }
            else {
                cout << "Start!" << endl << endl;
            }
        }

        // �U�`
        double bet;
        cout << "Enter your bet (minimum $10): ";
        cin >> bet;

        if (bet < 10 || !player.hasMoney(bet)) {
            cout << "Invalid bet amount!" << endl << endl;
            continue;
        }

        player.bet(bet);
        dealer.bet(bet);

        // �o�P�����a�M���a
        player.receiveCard(deck.draw());
        cout << endl;
        dealer.receiveCard(deck.draw());
        cout << endl;

        // ��ܪ��a����P�M���a���Ĥ@�i�P
        displayGameInfo();

        // ���a�^�X
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
                cout << endl ;
                cout << "You draw a card. Current total: " << player.getHandValue() << endl << endl;
                cout << "The number of cards in your hand: " << player.getHand().size() << endl << endl;
            }
            else {
                break;
            }
        }

        // ���a�z�P�ιF�줭�i�ɵ���
        double payoutMultiplier = 1.0;
        if (player.getHandValue() > 10.5) {
            cout << "Busted! You lose." << endl ;
            cout << "-----------------------" << endl<< endl;
            counter++;
        }
        else {
            if (player.getHand().size() == 5) {
                if (player.getHandValue() == 10.5) {
                    cout << "Big-Dragon! You win!" << endl ;
                    cout << "-----------------------" << endl << endl;
                    counter++;
                    payoutMultiplier = 5.0;
                }
                else if(player.getHandValue() < 10.5) {
                    cout << "Dragon! You win!" << endl;
                    cout << "-----------------------" << endl;
                    counter++;
                    payoutMultiplier = 3.0;
                }
                else if (player.getHandValue() > 10.5) {
                    cout << "Over 10.5! You lose!" << endl;
                    cout << "-----------------------" << endl << endl;
                    counter++;
                    payoutMultiplier = -3.0;
                }
            }
            else if (player.getHandValue() == 10.5) {
                cout << "Ten-A-Half! You win!" << endl;
                cout << "-----------------------" << endl << endl;
                counter++;
                payoutMultiplier = 2.0;
            }
            else {
                cout << "-----------------------" << endl;
                cout << "You didn't get 10.5. And now~~. It's my turn." << endl << endl;
            }

            // ���a�^�X
            if (player.getHandValue() < 10.5) {
                while (dealer.getHandValue() < 6 || (dealer.getHandValue() < 8 && rand() % 100 < 30) ||
                    (dealer.getHandValue() < 9 && rand() % 100 < 20) ||
                    (dealer.getHandValue() < 10 && rand() % 100 < 10)) {
                    Card drawnCard = deck.draw();
                    dealer.receiveCard(drawnCard);
                    cout << "Dealer draws a card: ";
                    displayCard(drawnCard);
                    cout << ". Current total: " << dealer.getHandValue() << endl << endl;
                    cout << "My draw a card. Current total: " << dealer.getHandValue() << endl << endl;
                }
                if (dealer.getHandValue() < 10.5) {
                    cout << "I finish drawing card. Let's see who is the winner." << endl << endl;
                }
                else {
                    cout << "Oh! busted. You win. " << endl << endl;
                    counter++;
                }
            }

            // �������P��
            if (dealer.getHandValue() > 10.5) {
                cout << "HaHa~! Today is your luck day~!" << endl;
                cout << "-----------------------" << endl << endl;
                counter++;
                player.win(bet* (payoutMultiplier + 1));
            }
            else if (dealer.getHandValue() > 10.5 || (player.getHandValue() <= 10.5 && player.getHandValue() > dealer.getHandValue())) {
                cout << "Oh~Wow~! You win~!" << endl;
                cout << "-----------------------" << endl << endl;
                counter++;
                player.win(bet * (payoutMultiplier + 1)); // Winning bet plus the original bet
            }
            else if (player.getHandValue() < dealer.getHandValue()) {
                cout << "I win,haha. You are loser." << endl;
                cout << "-----------------------" << endl << endl;
                counter++;
            }
            else {
                cout << "draw?Oh~Just assume that you win." << endl;
                cout << "-----------------------" << endl << endl;
                counter++;
                player.win(bet * 2); // Refund the bet
            }
        }

        // �M�Ť�P
        player.clearHand();
        dealer.clearHand();

        // �ݥΤ�O�_�~��
        char playAgain;
        cout << "Your current balance: $" << player.getMoney() << endl << endl;
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

    cout << "Thanks for playing!" << endl << endl;
}


