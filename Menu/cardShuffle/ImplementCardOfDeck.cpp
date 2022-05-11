#include <bits/stdc++.h>

#include "ImplementCardOfDeck.h"
using namespace std;

ImplementDeckOfCard::ImplementDeckOfCard()
{
    for (int i = 0; i < totalCard; i++)
    {
        implementDeck[i] = i + 1;
    }
    srand(time(0));
}
void ImplementDeckOfCard::shuffle()
{
    int row = 0;
    int column = 0;
    for (int card = totalCard; card > 0; card--)
    {
        int slot = rand() % card;
        swap(implementDeck[slot], implementDeck[card]);
    }
}
string ImplementDeckOfCard::getTypeOfCardName(int type)
{
    string name = "";
    switch (type)
    {
    case 0:
        name = "Diamonds";
        break;
    case 1:
        name = "Clubs";
        break;
    case 2:
        name = "Hearts";
        break;
    case 3:
        name = "Spades";
        break;
    }
    return name;
}
void ImplementDeckOfCard::print()
{
    for (int i = 0; i < totalCard; i++)
    {
        cout << implementDeck[i] << " ";
        if (i % 13 == 12)
        {
            cout << endl;
        }
    }
    cout << "\n\n";
}
string ImplementDeckOfCard::getNumberName(int number)
{
    string name = "";
    switch (number)
    {
    case 0:
        name = "Two";
        break;
    case 1:
        name = "Three";
        break;
    case 2:
        name = "Four";
        break;
    case 3:
        name = "Five";
        break;
    case 4:
        name = "Six";
        break;
    case 5:
        name = "Seven";
        break;
    case 6:
        name = "Eight";
        break;
    case 7:
        name = "Nine";
        break;
    case 8:
        name = "Ten";
        break;
    case 9:
        name = "Jack";
        break;
    case 10:
        name = "Deuce";
        break;
    case 11:
        name = "King";
        break;
    case 12:
        name = "Ace";
        break;
    }
    return name;
}
int ImplementDeckOfCard::getNumber(int value)
{
    return value % 13;
}
string ImplementDeckOfCard::getCardName(int value)
{
    int number = getNumber(value);
    int typeOfDCard = (value / 13) % 4;
    string typeName = getTypeOfCardName(typeOfDCard);
    string cardName = getNumberName(number);
    return cardName + " of " + typeName;
}
void ImplementDeckOfCard::dealCard()
{
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------Implement shuffle deck card--------------------------------------" << endl;
    // print();
    shuffle();
    // print();
    int count = 0;
    for (int i = 0; i < totalCard; i++)
    {
        count++;
        cout << setw(20) << getCardName(implementDeck[i]);
        if (count % 2 == 0)
        {
            cout << endl;
        }
    }
}
#pragma endregion
#pragma region pokerGame
bool ImplementDeckOfCard::isRoyalStraightFlush(int *cards)
{
    return isStraightFlush(cards) && getHighestCard(cards) == 51;
}
bool ImplementDeckOfCard::isStraightFlush(int *cards)
{
    return isStraight(cards) && isFlush(cards);
}
bool ImplementDeckOfCard::isFourOfAKind(int *cards)
{
    return isNofAKind(cards, 4);
}
bool ImplementDeckOfCard::isTwoPair(int *cards)
{
    return getNumberAtNofAKind(cards, 2).size() == 2;
}
bool ImplementDeckOfCard::isThreeOfAKind(int *cards)
{
    return isNofAKind(cards, 3);
}
bool ImplementDeckOfCard::isOnePair(int *cards)
{
    return isNofAKind(cards, 2);
}
vector<int> ImplementDeckOfCard::getNumberAtNofAKind(int *cards, int n)
{
    vector<int> numbers;
    map<int, int> m;
    for (int i = 0; i < totalCardForPoker; i++)
    {
        m[cards[i] % totalNumber]++;
    }
    for (auto const &imap : m)
    {
        if (imap.second == n)
        {
            numbers.push_back(imap.first);
        }
    }
    return numbers;
}
bool ImplementDeckOfCard::isNofAKind(int *cards, int n)
{
    return getNumberAtNofAKind(cards, n).size() > 0;
}
bool ImplementDeckOfCard::isFullHouse(int *cards)
{
    return isNofAKind(cards, 3) && isNofAKind(cards, 2);
}
bool ImplementDeckOfCard::isFlush(int *cards)
{
    int firstType = cards[0] / 13;
    for (int i = 1; i < totalCardForPoker; i++)
    {
        if (firstType != (cards[i] / 13))
        {
            return false;
        }
    }
    return true;
}
bool ImplementDeckOfCard::isStraight(int *cards)
{
    for (int i = 0; i < totalCardForPoker; i++)
    {
        int min = i;
        for (int j = i + 1; j < totalCardForPoker; j++)
        {
            if (getNumber(cards[min]) > getNumber(cards[j]))
            {
                min = j;
            }
        }
        swap(cards[i], cards[min]);
        if (i > 0 && (getNumber(cards[i]) - getNumber(cards[i - 1]) != 1))
        {
            return false;
        }
    }
    return true;
}
int ImplementDeckOfCard::getHighestCard(int *cards)
{
    int max = 0;
    for (int i = 0; i < totalCardForPoker; i++)
    {
        if (getNumber(cards[max]) < getNumber(cards[i]))
        {
            max = i;
        }
    }
    return cards[max];
}
string ImplementDeckOfCard::getPoint(int *cards)
{
    string pointName = "";
    if (isRoyalStraightFlush(cards))
    {
        pointName = "royal straight flush";
    }
    else if (isStraightFlush(cards))
    {
        pointName = "straight flush";
    }
    else if (isFourOfAKind(cards))
    {
        pointName = "four of a " + getNumberName(getNumber(getNumberAtNofAKind(cards, 4)[0]));
    }
    else if (isFullHouse(cards))
    {
        pointName = "full house";
    }
    else if (isFlush(cards))
    {
        pointName = "flush";
    }
    else if (isStraight(cards))
    {
        pointName = "straight";
    }
    else if (isThreeOfAKind(cards))
    {
        pointName = "three of a " + getNumberName(getNumber(getNumberAtNofAKind(cards, 1)[0]));
    }
    else if (isTwoPair(cards))
    {
        vector<int> numbers = getNumberAtNofAKind(cards, 2);
        pointName = "two pair of " + getNumberName(getNumber(numbers[0])) + " and " + getNumberName(getNumber(numbers[1]));
    }
    else if (isOnePair(cards))
    {
        pointName = "a pair of a " + getNumberName(getNumber(getNumberAtNofAKind(cards, 2)[0]));
    }
    else
    {
        pointName = "high card of " + getCardName(getHighestCard(cards));
    }
    return pointName;
}
void ImplementDeckOfCard::showPoint(int *cards)
{
    for (int i = 0; i < totalCardForPoker; i++)
    {
        cout << setw(20) << getCardName(cards[i]);
        if ((i + 1) % 2 == 0)
        {
            cout << endl;
        }
    }
    cout << "\n\n";
    string point = getPoint(cards);
    cout << " The hand contains " + point << endl;
}
void ImplementDeckOfCard::pokerGame()
{
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------Poker Game--------------------------------------" << endl;
    shuffle();
    int cards[totalCardForPoker] = {0};
    for (int i = 0; i < totalCardForPoker; i++)
    {
        cards[i] = implementDeck[i];
    }
    showPoint(cards);
}
void ImplementDeckOfCard::testPokerGame()
{
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------Test Poker Game--------------------------------------" << endl;
    cout << "------------------------------------Case royal straight flush--------------------------------------" << endl;
    int cards[totalCardForPoker] = {47, 48, 49, 50, 51};
    showPoint(cards);
    cout << "------------------------------------Case straight flush--------------------------------------" << endl;
    int cards2[totalCardForPoker] = {1, 2, 3, 4, 5};
    showPoint(cards2);
    cout << "------------------------------------Case four of a kind--------------------------------------" << endl;
    int cards3[totalCardForPoker] = {1, 14, 27, 40, 52};
    showPoint(cards3);
    cout << "------------------------------------Case full house--------------------------------------" << endl;
    int cards4[totalCardForPoker] = {1, 14, 27, 39, 52};
    showPoint(cards4);
    cout << "------------------------------------Case straight-------------------------------------" << endl;
    int cards5[totalCardForPoker] = {14, 2, 3, 4, 5};
    showPoint(cards5);
    cout << "------------------------------------Case three of a kind--------------------------------------" << endl;
    int cards6[totalCardForPoker] = {1, 14, 27, 17, 18};
    showPoint(cards6);
    cout << "------------------------------------Case two pair--------------------------------------" << endl;
    int cards7[totalCardForPoker] = {1, 14, 16, 39, 52};
    showPoint(cards7);
    cout << "------------------------------------Case one pair--------------------------------------" << endl;
    int cards8[totalCardForPoker] = {1, 14, 16, 17, 18};
    showPoint(cards8);
    cout << "------------------------------------Case high card--------------------------------------" << endl;
    int cards9[totalCardForPoker] = {1, 2, 3, 13, 8};
    showPoint(cards9);
}
