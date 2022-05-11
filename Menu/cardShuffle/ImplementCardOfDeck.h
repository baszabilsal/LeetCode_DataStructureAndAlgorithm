#include <bits/stdc++.h>
using namespace std;
class ImplementDeckOfCard
{
public:
    static const int totalCard = 52;
    static const int totalNumber = 13;
    static const int totalTypeOfCard = 4;
    static const int totalCardForPoker = 5;
    int implementDeck[totalCard];
    ImplementDeckOfCard();
    void shuffle();
    void print();
    string getTypeOfCardName(int);
    void dealCard();
    string getCardName(int);
    string getNumberName(int);
    int getType(int);
    int getNumber(int);
    bool isRoyalStraightFlush(int *);
    bool isStraightFlush(int *);
    bool isFourOfAKind(int *);
    bool isNofAKind(int *, int);
    bool isFullHouse(int *);
    bool isFlush(int *);
    bool isStraight(int *);
    bool isThreeOfAKind(int *);
    vector<int> getNumberAtNofAKind(int *, int);
    bool isTwoPair(int *);
    bool isOnePair(int *);
    int getHighestCard(int *);
    string getPoint(int *);
    void showPoint(int *);
    void pokerGame();
    void testPokerGame();
};