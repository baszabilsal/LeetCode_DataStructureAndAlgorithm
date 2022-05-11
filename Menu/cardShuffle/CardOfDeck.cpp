
#include <bits/stdc++.h>
#include "CardOfDeck.h"
using namespace std;

DeckOfCard::DeckOfCard()
{
    for (int i = 0; i < totalTypeOfCard; i++)
    {
        for (int j = 0; j < totalNumber; j++)
        {
            deck[i][j] = 0;
        }
    }
    srand(time(0));
}
void DeckOfCard::shuffle()
{
    int row = 0;
    int column = 0;
    for (int card = 1; card <= totalCard; card++)
    {
        do
        {
            row = rand() % totalTypeOfCard;
            column = rand() % totalNumber;
        } while (deck[row][column] != 0);
        deck[row][column] = card;
    }
}
string DeckOfCard::getTypeOfCardName(int type)
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
void DeckOfCard::print()
{
    for (int i = 0; i < totalTypeOfCard; i++)
    {
        cout << setw(10) << getTypeOfCardName(i) << setw(10);
        for (int j = 0; j < totalNumber; j++)
        {
            cout << deck[i][j] << setw(4);
        }
        cout << endl;
    }
    cout << "\n\n";
}
string DeckOfCard::getNumberName(int number)
{
    string name = "";
    switch (number)
    {
    case 0:
        name = "King";
        break;
    case 1:
        name = "Ace";
        break;
    case 2:
        name = "Two";
        break;
    case 3:
        name = "Three";
        break;
    case 4:
        name = "Four";
        break;
    case 5:
        name = "Five";
        break;
    case 6:
        name = "Six";
        break;
    case 7:
        name = "Seven";
        break;
    case 8:
        name = "Eight";
        break;
    case 9:
        name = "Nine";
        break;
    case 10:
        name = "Ten";
        break;
    case 11:
        name = "Jack";
        break;
    case 12:
        name = "Deuce";
        break;
    }
    return name;
}
string DeckOfCard::getCardName(int value)
{
    int number = value % 13;
    int typeOfDCard = (value / 13) % 4;
    string typeName = getTypeOfCardName(typeOfDCard);
    string cardName = getNumberName(number);
    return cardName + " of " + typeName;
}
void DeckOfCard::dealCard()
{
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------Normal shuffle deck card--------------------------------------" << endl;
    // print();
    shuffle();
    // print();
    int count = 0;
    for (int i = 0; i < totalTypeOfCard; i++)
    {
        for (int j = 0; j < totalNumber; j++)
        {
            count++;
            cout << setw(20) << getCardName(deck[i][j]);
            if (count % 2 == 0)
            {
                cout << endl;
            }
        }
    }
}
