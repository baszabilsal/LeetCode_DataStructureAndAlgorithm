#include <bits/stdc++.h>
using namespace std;
class DeckOfCard
{
public:
    static const int totalCard = 52;
    static const int totalNumber = 13;
    static const int totalTypeOfCard = 4;
    int deck[totalTypeOfCard][totalNumber];
    DeckOfCard();
    void shuffle();
    void print();
    string getTypeOfCardName(int);
    void dealCard();
    string getCardName(int);
    string getNumberName(int);
};