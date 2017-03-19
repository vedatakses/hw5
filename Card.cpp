//
// Created by VeraxMedax on 17/03/2017.
//

#include <iostream>
#include "Card.h"

Card::Card() {

}

Card::Card(string s, string r) {
    suit = s;
    rank = r;
}

void Card::setSuit(string s) {
    suit = s;
}

string Card::getSuit() {
    return suit;
}

void Card::setRank(string r) {
    rank = r;
}

string Card::getRank() {
    return rank;
}

// == operator overloading for Card
bool Card::operator==(Card &card) {
    if (getSuit().compare(card.getSuit()) == 0
        && getRank().compare(card.getRank()) == 0) {
        return true;
    }
    return false;
}

Card& Card::operator=(Card &card) {
    this->suit = card.getSuit();
    this->rank = card.getRank();
    return *this;
}

// left shift operator overloading for Card
ostream &operator<<(ostream &out, Card &card) {
    out << "(" << card.getSuit() << ", " << card.getRank() << ")";
    return out;
}