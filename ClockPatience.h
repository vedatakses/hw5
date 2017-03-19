//
// Created by VeraxMedax on 19/03/2017.
//

#ifndef _CLOCKPATIENCE_H_
#define _CLOCKPATIENCE_H_

#include "Deck.h"

using namespace std;

class ClockPatience {
private:
    Card piles[13][4];
    Card *openedCards;
    Card *kings;
    int openedCardsIndex;
    int openedKingsIndex;
    bool isWon = false;

    bool isGameOver(Card card);
    void placeCard(Card& card);
    void swap(Card& first, Card& second);
    bool isKing(Card& card);

public:
    ClockPatience();
    ~ClockPatience();

    void pileCards();
    void startGame();

    bool isGameWon();
    int getRankIndex(string rank);
    int getSuitIndex(string suit);

};

#endif //_CLOCKPATIENCE_H_
