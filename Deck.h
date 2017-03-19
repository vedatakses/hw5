//
// Created by VeraxMedax on 17/03/2017.
//

#ifndef _DECK_H_
#define _DECK_H_

#include "Card.h"

// Deck class to hold cards and indexes to deal cards randomly
class Deck {

private:
    int index = 0;
    Card cards[52];
    void swap(Card &c1, Card &c2);

public:
    Deck();
    void shuffle();
    Card &deal();
    int size();
};

// left shift operator overloading for Deck
ostream &operator<<(ostream &out, Deck &deck);

#endif //_DECK_H_
