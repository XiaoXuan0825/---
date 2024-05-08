#include "Player.h"

Player::Player(double startingMoney) : money(startingMoney) {}

void Player::receiveCard(const Card& card) {
    hand.push_back(card);
}

double Player::getHandValue() const {
    double total = 0;
    for (const auto& card : hand) {
        total += card.value;
    }
    return total;
}

void Player::clearHand() {
    hand.clear();
}

bool Player::hasMoney(double amount) const {
    return money >= amount;
}

void Player::bet(double amount) {
    money -= amount;
}

void Player::win(double amount) {
    money += amount;
}

double Player::getMoney() const {
    return money;
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}
