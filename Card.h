//
// Created by VeraxMedax on 17/03/2017.
//

#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include <string>
#include "Constants.h"

using namespace std;

// Card class that includes suit and rank of a card
class Card {

private:
    string suit;
    string rank;

public:
    Card();
    Card(string s, string r);
    void setSuit(string s);
    string getSuit();
    void setRank(string r);
    string getRank();
    Card& operator=(Card &card);
    bool operator==(Card &card);
};

// left shift operator overloading for Card
ostream &operator<<(ostream &out, Card &card);

#endif //_CARD_H_
