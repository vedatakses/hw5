//
// Created by VeraxMedax on 19/03/2017.
//

#include "ClockPatience.h"

bool ClockPatience::isGameOver(Card card) {
    if (isKing(card)) {
        for (int i = 0; i < openedKingsIndex; i++) {
            if (kings[i] == card) {
                return false;
            }
        }
        kings[openedKingsIndex] = card;
        openedKingsIndex++;
    } else {
        for (int j = 0; j < openedCardsIndex; j++) {
            if (openedCards[j] == card) {
                return false;
            }
        }
        openedCards[openedCardsIndex] = card;
        openedCardsIndex++;
    }

    if (openedKingsIndex == 4) {
        cout << "Game over!" << endl;
        return true;
    }

    if (openedCardsIndex == 48) {
        isWon = true;
        cout << "Game won!" << endl;
        return true;
    }
    return false;
}

void ClockPatience::placeCard(Card& card) {
    if (isGameOver(card)) {
        return;
    }

    int rankIndex = getRankIndex(card.getRank());
    int suitIndex = getSuitIndex(card.getSuit());

    // swap all 4 cards and move each card one index front for rank's pile
    for (int i = 0; i < 3; i++) {
        Card temp = piles[rankIndex][i];
        piles[rankIndex][i] = piles[rankIndex][i+1];
        piles[rankIndex][i+1] = temp;
    }
    // swap all 4 cards and move each card one index front for 12th pile
    for (int j = 0; j < 3; j++) {
        Card temp = piles[12][j];
        piles[12][j] = piles[12][j+1];
        piles[12][j+1] = temp;
    }

    // replace the card at the bottom in piles with the new opened cards
    swap(piles[12][3], piles[rankIndex][3]);

    // continue game with new opened card
    placeCard(piles[rankIndex][3]);
}

void ClockPatience::swap(Card& first, Card& second) {
    Card ftemp = first;
    Card stemp = second;
    first = stemp;
    second = ftemp;
}

bool ClockPatience::isKing(Card& card) {
    return card.getRank().compare("K") == 0;
}

ClockPatience::ClockPatience() {
    openedCards = new Card[52];
    kings = new Card[4];

    openedCardsIndex = 0;
    openedKingsIndex = 0;
}

ClockPatience::~ClockPatience() {
    delete [] openedCards;
    delete [] kings;
}

void ClockPatience::pileCards() {
    Deck deck;
    deck.shuffle();

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            piles[i][j] = deck.deal();
        }
    }
}

int ClockPatience::getRankIndex(string rank) {
    for (int i = 0; i < 13; i++) {
        if (rank.compare(ranks[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int ClockPatience::getSuitIndex(string suit) {
    for (int i = 0; i < 4; i++) {
        if (suit.compare(suits[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void ClockPatience::startGame() {
    // First card at 13th row..
    Card& p = piles[12][0];
    placeCard(p);

    /*cout << endl << endl;
    cout << "Opened Cards Index" << endl;
    cout << openedCardsIndex << endl;

    cout << endl << endl;
    cout << "Opened Kings Index" << endl;
    cout << openedKingsIndex << endl;*/
}

bool ClockPatience::isGameWon() {
    return isWon;
};