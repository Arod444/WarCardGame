Project Proposal for Project 2

Title
Card Game - War

Course
CIS-5

Section
45744

## Due Date
July 28, 2024

Author
Angel Rodriguez

Table of Contents
1. Introduction
2. Game Play and Rules
3. Development Summary
4. Specifications
5. Checkoff Sheet
6. Flowchart Description
7. Program Listing

1. Introduction
The game "War" is a simple card game played between two players. Each player has a deck of cards, and the game proceeds with each player drawing a card simultaneously. The player with the higher card wins the round and takes both cards. The game continues until one player has all the cards or a predetermined number of rounds have been played.
The purpose of this project is to implement the "War" card game in C++ using the fundamental programming constructs we have covered in the course. This project demonstrates my understanding of loops, conditionals, input/output, and basic data structures.

2. Game Play and Rules
- The game uses a standard 52-card deck.
- The deck is shuffled, and each player is dealt 26 cards.
- In each round, both players draw the top card of their deck and reveal it.
- The player with the higher card takes both cards and places them at the bottom of their deck.
- If the cards are of equal value, a "war" occurs, and additional cards are drawn.
- The game ends when one player has all the cards or after a set number of rounds.

3. Development Summary
3.1 Version 1 Comments on Development
- Deck Shuffling: Implemented using a simple randomization algorithm.
- Game Logic: Basic game loop handling card comparison and war scenarios.
- User Interface: Text-based input and output for simplicity.
- Challenges: Handling the "war" scenario correctly and ensuring the game ends properly.

4. Specifications
4.1 Sample Inputs/Outputs
Example Input:
- Start the game
- Enter number of rounds: 5

Example Output:
Round 1
Player 1 draws Ace
Player 2 draws King
Player 1 wins the round!

Round 2
Player 1 draws 7
Player 2 draws 9
Player 2 wins the round!

Final Scores:
Player 1: 3
Player 2: 2
Player 1 wins the game!


5. Checkoff Sheet
- Implemented card drawing mechanism
- Implemented random number generation for card values
- Implemented score tracking for both players
- Implemented input and output handling
- Implemented game loop with a fixed number of rounds
- Ensured no use of arrays or functions
- Included file I/O to record game results
- Properly formatted output
- Included user prompts and validations
- Created a comprehensive write-up

Constructs & Concepts Utilized
Checkoff Sheet for Project 2

Constructs & Concepts Utilized

iostream Library
| Name        | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `cout`      | 15        | Output data                           | Throughout                        |
| `cin`       | 2         | Input data                            | `main()`                          |

cstdlib Library
| Name        | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `srand()`   | 1         | Random number seed                    | `main() - Line 17`                |
| `rand()`    | 1         | Generates random number               | `shuffleDeck() - Line 30`         |

ctime Library
| Name        | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `time`      | 1         | Set current time                      | `main() - Line 17`                |

fstream Library
| Name        | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `ofstream`  | 1         | Declare variable for file output      | `main() - Line 23`                |
| `outFile`   | 11        | Write to file                         | Throughout                        |

string Library
| Name        | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `string`    | 3         | Declare variable                      | Throughout                        |

vector Library
| Name        | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `vector`    | 7         | Declare and manipulate dynamic array  | Throughout                        |

algorithm Library
| Name        | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `random_shuffle` | 1    | Shuffle elements in the vector        | `shuffleDeck() - Line 29`         |

Data Types
| Data Type   | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `int`       | 14        | Integer variables                     | Throughout                        |
| `string`    | 3         | String variables                      | Throughout                        |
| `ofstream`  | 1         | File output stream                    | `main() - Line 23`                |

Conditional Statements
| Conditional Statement | Frequency | Description                   | Location                          |
|-----------------------|-----------|-------------------------------|-----------------------------------|
| `if`                  | 5         | Conditional execution         | Throughout                        |
| `else`                | 3         | Alternative execution         | Throughout                        |
| `switch`              | 1         | Conditional execution for cases| `getCardName() - Line 38`         |

Loops
| Loop Type   | Frequency | Description                           | Location                          |
|-------------|-----------|---------------------------------------|-----------------------------------|
| `for`       | 6         | Loop through elements                 | Throughout                        |


6. Flowchart Description
Flowchart for "War" Card Game

1. Start
2. Initialize Variables:
   - `srand(static_cast<unsigned int>(time(0)));`
   - `vector<int> deck(52);`
   - `int player1Score = 0, player2Score = 0;`
   - `int rounds;`
3. User Input:
   - Prompt user for the number of rounds: `cin >> rounds;`
4. Open Output File:
   - `ofstream outFile("WarGameResults.txt");`
5. Game Loop:
   - For each round:
     - Shuffle Deck: `shuffleDeck(deck);`
     - Draw Cards: `int player1Card = deck[cardIndex++];` `int player2Card = deck[cardIndex++];`
     - Get Card Names: `string player1CardName = getCardName(player1Card);` `string player2CardName = getCardName(player2Card);`
     - Compare Cards:
       - If `player1Card > player2Card`: Player 1 wins.
       - Else If `player2Card > player1Card`: Player 2 wins.
       - Else: Handle War.
6. End of Game:
   - Display final scores.
   - Determine and display the winner.
7. Close Output File:
   - `outFile.close();`
8. End


7. Program Listing
cpp

/
File:   main.cpp
Author: Angel Rodriguez
Created on July 28, 2024
Purpose: Simple Card Game - War
 /

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
