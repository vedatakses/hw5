//
// Created by VeraxMedax on 17/03/2017.
//

#include <iostream>
#include "Deck.h"

using namespace std;

Deck::Deck() {
    int count = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            cards[count].setRank(ranks[i]);
            cards[count].setSuit(suits[j]);
            count++;
        }
    }
}

void Deck::swap(Card &c1, Card &c2) {
    Card temp = c1;
    c1 = c2;
    c2 = temp;
}

void Deck::shuffle() {
    // Knut shuffle
    for (int i = 0; i < 52; i++) {
        int rCard = rand() % 52;
        swap(cards[i], cards[rCard]);
    }
}

Card& Deck::deal() {
    return cards[index++];
}

int Deck::size() {
    return sizeof(cards) / sizeof(cards[0]);
}

// left shift operator overloading for Deck
ostream &operator<<(ostream &out, Deck &deck) {
/*    for (int i = 0; i < 52; i++) {
        out << deck.getCard(i).getSuit() << "," << deck.getCard(i).getRank();
    }*/
    return out;
}