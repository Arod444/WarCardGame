/*
 * File:   main.cpp
 * Author: Angel rodriguez 
 * Created on July 28, 2024
 * Purpose: Simple Card Game - War
 */

// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function Prototypes
void shuffleDeck(vector<int>& deck);
void playRound(vector<int>& deck, int& player1Score, int& player2Score, ofstream& outFile);
string getCardName(int card);
void handleWar(vector<int>& deck, int& player1Score, int& player2Score, ofstream& outFile);
void updateScores(int card1, int card2, int& player1Score, int& player2Score, ofstream& outFile);
void sortPlayers(vector<string>& players, vector<int>& scores);
int searchPlayer(const vector<string>& players, const string& name);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<int> deck(52);
    for (int i = 0; i < 52; ++i) {
        deck[i] = i % 13 + 1;
    }

    shuffleDeck(deck);

    int player1Score = 0, player2Score = 0;
    int rounds;
    cout << "Enter the number of rounds to play: ";
    cin >> rounds;

    ofstream outFile("WarGameResults.txt");

    for (int i = 0; i < rounds; ++i) {
        playRound(deck, player1Score, player2Score, outFile);
    }

    outFile.close();

    return 0;
}

void shuffleDeck(vector<int>& deck) {
    random_shuffle(deck.begin(), deck.end());
}

void playRound(vector<int>& deck, int& player1Score, int& player2Score, ofstream& outFile) {
    static int cardIndex = 0;
    int player1Card = deck[cardIndex++];
    int player2Card = deck[cardIndex++];

    string player1CardName = getCardName(player1Card);
    string player2CardName = getCardName(player2Card);

    cout << "Player 1 draws " << player1CardName << endl;
    cout << "Player 2 draws " << player2CardName << endl;
    outFile << "Player 1 draws " << player1CardName << endl;
    outFile << "Player 2 draws " << player2CardName << endl;

    if (player1Card > player2Card) {
        cout << "Player 1 wins the round!" << endl << endl;
        outFile << "Player 1 wins the round!" << endl << endl;
        player1Score++;
    } else if (player2Card > player1Card) {
        cout << "Player 2 wins the round!" << endl << endl;
        outFile << "Player 2 wins the round!" << endl << endl;
        player2Score++;
    } else {
        handleWar(deck, player1Score, player2Score, outFile);
    }
}

string getCardName(int card) {
    switch(card) {
        case 1: return "Ace";
        case 11: return "Jack";
        case 12: return "Queen";
        case 13: return "King";
        default: return to_string(card);
    }
}

void handleWar(vector<int>& deck, int& player1Score, int& player2Score, ofstream& outFile) {
    static int cardIndex = 0;
    int warCardsCount = 3; // Number of face-down cards in a war scenario

    cout << "War!" << endl;
    outFile << "War!" << endl;

    if (cardIndex + warCardsCount * 2 + 2 > deck.size()) {
        cout << "Not enough cards left for war. Ending the game." << endl;
        outFile << "Not enough cards left for war. Ending the game." << endl;
        return;
    }

    vector<int> player1WarCards(warCardsCount), player2WarCards(warCardsCount);
    for (int i = 0; i < warCardsCount; ++i) {
        player1WarCards[i] = deck[cardIndex++];
        player2WarCards[i] = deck[cardIndex++];
    }

    int player1WarCard = deck[cardIndex++];
    int player2WarCard = deck[cardIndex++];

    cout << "Player 1's war card: " << getCardName(player1WarCard) << endl;
    cout << "Player 2's war card: " << getCardName(player2WarCard) << endl;
    outFile << "Player 1's war card: " << getCardName(player1WarCard) << endl;
    outFile << "Player 2's war card: " << getCardName(player2WarCard) << endl;

    updateScores(player1WarCard, player2WarCard, player1Score, player2Score, outFile);
}

void updateScores(int card1, int card2, int& player1Score, int& player2Score, ofstream& outFile) {
    if (card1 > card2) {
        player1Score += 2;
        cout << "Player 1 wins the war round!" << endl << endl;
        outFile << "Player 1 wins the war round!" << endl << endl;
    } else if (card2 > card1) {
        player2Score += 2;
        cout << "Player 2 wins the war round!" << endl << endl;
        outFile << "Player 2 wins the war round!" << endl << endl;
    } else {
        cout << "War round is a tie!" << endl << endl;
        outFile << "War round is a tie!" << endl << endl;
    }
}

void sortPlayers(vector<string>& players, vector<int>& scores) {
    // Implement sorting algorithm
    for (size_t i = 0; i < players.size() - 1; ++i) {
        for (size_t j = 0; j < players.size() - i - 1; ++j) {
            if (scores[j] < scores[j + 1]) {
                swap(scores[j], scores[j + 1]);
                swap(players[j], players[j + 1]);
            }
        }
    }
}

int searchPlayer(const vector<string>& players, const string& name) {
    // Implement search algorithm
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i] == name) {
            return i;
        }
    }
    return -1; // Not found
}
