
#include <bits/stdc++.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Array of words used for randomization
string arr[] = {"Hockey",  "Basketball", "Football", "Cricket", "Baseball",
                "Apples",  "Oranges",    "Bananas",  "Kiwi",    "Peach",
                "Cat",     "Dog",        "Parrot",   "Fish",    "Snakes",
                "Hyundai", "Honda",      "Mercedes", "Bentley", "Lexux",
                "Nike",    "Adidas",     "Gucci",    "Rayban",  "Versace"};

// main menu choice option
int option_counter_default;
// randomizing number
int y;
string randomString;
// Function for main menu
void menu_option();
// Character display - Hangman
void display(int misses);
// game play function
void game_play(int players);
// update_scores function - yet not used
void update_scores(int players, int player_scores[]);

// Main Menu
void menu_option() {
  cout << "\t\tWelcome to Hangman Game !!!" << endl;
  cout << "****************************************" << endl;
  cout << "Done by: Omar, Natalie, Toufiq, Shashank, Gian Carlo" << endl;
  cout << "-------------------------------------\n";
  cout << "|\t\t\t\t|\n";
  cout << "|\t\t\t\t0\t\t\n";
  cout << "|\t\t\t   /|\\\n";
  cout << "|\t\t\t  / | \\\n";
  cout << "|\t\t\t\t|\n";
  cout << "|\t\t\t   / \\\n";
  cout << "|\t\t\t  /	  \\\n";
  cout << "|\n";
  cout << "||-------------------------------------||\n";
  cout << "||-------------------------------------||\n";
  cout << "\t\t\t1) 1 Player\n";
  cout << "\t\t\t2) 2 Players\n";
  cout << "\t\t\t3) Rule Book\n";
  cout << "\t\t\t4) Exit\n";
  cout << "||-------------------------------------||\n";
  cout << "||-------------------------------------||\n";
  cout << "Your Option: ";
  cin >> option_counter_default;
  // Clear Screen
  system("clear");
  switch (option_counter_default) {
  case 1:
    // game_play function with method overload - arg - 1
    game_play(1);
    break;

  case 2:
    // game_play function with method overload - arg - 2
    game_play(2);
    break;

  case 3:
    // get back to main menu
    int back;

    // loop through menu option unless 1 is entered
    while (back != 1) {
      cout << "Rules: \n";
      cout << "7 misses - GAME OVER!! \n";
      cout << "Get the correct word and win\n";
      cout << "Go back press 1\n";
      cin >> back;
      if (back == 1) {
        system("clear");
        menu_option();
      }
    }
    break;

  case 4:
    // Exit option
    system("clear");
    cout << "-----------------------------\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\tSEE YOU LATER\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "-----------------------------\n";
    break;
  }
}
// function with player number as parameter either 1 or 2
void game_play(int players) {
  char guess;
  int misses = 0;
  // randomizing numbers from  0 to 25
  y = (rand() % 25);
  randomString = arr[y];
  // changing the random generated string into uppercase with transform function
  transform(randomString.begin(), randomString.end(), randomString.begin(),
            ::toupper);

  // Initializing string to push the answer when user enters the right character
  string answer = "";
  // Initializing string to push the answer when user enters the wrong character
  string incorrect = "";
  // Iterate through the random string generated
  for (int i = 0; i < randomString.size(); i++) {
    // push number of - characters in the randomString in order to show the
    // number of char in thus string
    answer.push_back('-');
  }
  // When 1 is pass through players as arg
  if (players == 1) {
    cout << "You have chosen to play single player mode\n\n";
    cout << "The word has " << randomString.size() << " letters\n";
    cout << "You have 7 misses before you lose\n";
    // Loop through unless misses reaches 7
    while (misses < 7) {
      bool found = false;
      cout << "-------------------------------------" << endl;
      cout << "\t\tCORRECT CHARACTERS\t\t\t\t" << endl;
      cout << endl;
      cout << "\t\t\t\t" << answer << endl;
      cout << endl;
      cout << endl;
      cout << "-------------------------------------" << endl;
      cout << "\t\tINCORRECT CHARACTERS\t\t\t\t " << endl;
      cout << endl;
      cout << "\t\t\t\t" << incorrect << endl;
      cout << endl;
      cout << endl;
      cout << "-------------------------------------" << endl;
      // Passing misses as arg to show misses in display funciton
      display(misses);
      cout << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << "\t\t\tYour Guess: ";
      cin >> guess;
      cout << endl;
      cout << "\n-------------------------------------\n";
      cout << endl;
      system("clear");
      // Change character entered into uppercase
      guess = toupper(guess);

      // Check if the entered guess is alphabet or not
      if (!isalpha(guess)) {
        cout << "Invalid input. Please enter a letter.\n";
        continue;
      }
      // Loop through the randomString
      for (int i = 0; i < randomString.size(); i++) {
        // Check if the user guess matches the randomString at index i :
        // [0,1,2,3,4,...]
        if (guess == randomString[i]) {
          // if true store the guess in the answer string at correct index[i]
          answer[i] = guess;
          // change the boolean found as true
          found = true;
        }
      }
      // if not true push guess to incorrect and increas misses by 1
      if (!found) {
        incorrect.push_back(guess);
        misses++;
        // if the misses reaches 6 player will loose and show them the correct
        // word
        if (misses == 6) {
          system("clear");
          cout << "-------------------------------------\n";
          cout << "\n";
          cout << "\n";
          cout << "\n";
          cout << "\t\t\tYOU LOSE\n";
          cout << "\t\t\tCORRECT WORD: \n";
          cout << "\t\t\t" << randomString << " \n";
          cout << "\n";
          cout << "\n";
          cout << "-------------------------------------\n";
          cout << "-------------------------------------\n";
          cout << "|\t\t\t\t|\n";
          cout << "|\t\t\t\t0\t\t Life: " << 7 - misses << "\n";
          cout << "|\t\t\t   /|\\\n";
          cout << "|\t\t\t  / | \\\n";
          cout << "|\t\t\t\t|\n";
          cout << "|\t\t\t   / \\\n";
          cout << "|\t\t\t  /	  \\\n";
          cout << "|\n";
          cout << "||-------------------------------------||\n";
          cout << "||-------------------------------------||\n";
          cout << "\t\t\tGAME OVER!!!\n";
          break;
        }
        // else if the guess answer matches the randomString generated use wins
      } else {
        if (answer == randomString) {
          system("clear");
          cout << "-----------------------------\n";
          cout << "\n";
          cout << "\n";
          cout << "\n";
          cout << "\n";
          cout << "\t\t\tYOU WIN\n";
          cout << "\n";
          cout << "\n";
          cout << "\n";
          cout << "-----------------------------\n";
          break;
        }
      }
    }
  }
  // when players has argument 2
  if (players == 2) {
    // number of rounds declared as 1
    int round = 1;
    // initializing player_names[] array with 2 items as two players
    string player_names[2];
    // storing scores of two players
    int player_scores[2] = {0, 0};
    cout << "You have chosen to play two player mode\n\n";
    cout << "Player 1 enter your name: ";
    cin >> player_names[0];
    cout << "Player 2 enter your name: ";
    cin >> player_names[1];

    cout << "Player : " << player_names[0] << endl;
    cout << "Score  : " << player_scores[0] << endl;
    cout << "Player : " << player_names[1] << endl;
    cout << "Score  : " << player_scores[1] << endl;

    // loop 4 times as each player should get 2 turns
    for (int game = 0; game < 4; game++) {
      cout << endl;
      cout << "Round : " << round << endl;
      // game % 2 determines whether the player is 0 or 1 i.e. player 1 or
      // player 2
      cout << player_names[game % 2] << " it's your turn!!\n";
      cout << "\nThe word has " << randomString.size() << " letters\n";
      cout << "You have 7 misses before you lose\n";

      // if the misses reaches 6 player will loose and show them the correct
      // word
      while (misses < 7) {
        bool found = false;

        cout << "-------------------------------------" << endl;
        cout << "\t\tCORRECT CHARACTERS\t\t\t\t" << endl;
        cout << endl;
        cout << "\t\t\t\t" << answer << endl;
        cout << endl;
        cout << endl;
        cout << "-------------------------------------" << endl;
        cout << "\t\tINCORRECT CHARACTERS\t\t\t\t " << endl;
        cout << endl;
        cout << "\t\t\t\t" << incorrect << endl;
        cout << endl;
        cout << endl;
        cout << "-------------------------------------" << endl;
        display(misses);
        cout << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\t\t\tYour Guess: ";
        cin >> guess;
        cout << endl;
        cout << "\n-------------------------------------\n";
        cout << endl;
        system("clear");
        guess = toupper(guess);

        // Check if the entered guess is alphabet or not
        if (!isalpha(guess)) {
          cout << "Invalid input. Please enter a letter.\n";
          continue;
        }
        // Boolean declaration
        bool is_correct = false;
        // Iterate through randomString
        for (int i = 0; i < randomString.size(); i++) {
          // Check if the user guess matches the randomString at index i :
          // [0,1,2,3,4,...]
          if (guess == randomString[i]) {
            // if true store the guess in the answer string at correct index[i]
            answer[i] = guess;
            found = true;
            is_correct = true;
          }
        }
        // if not true push back guess into incorrect string
        if (!is_correct) {
          incorrect.push_back(guess);
          // increment misses by 1
          misses++;
          // if misses equals 6 player looses and generated randomString is
          // displayed
          if (misses == 6) {
            system("clear");
            cout << "-------------------------------------\n";
            cout << "|\t\t\t\t|\n";
            cout << "|\t\t\t\t0\t\t Life: " << 7 - misses << "\n";
            cout << "|\t\t\t   /|\\\n";
            cout << "|\t\t\t  / | \\\n";
            cout << "|\t\t\t\t|\n";
            cout << "|\t\t\t   / \\\n";
            cout << "|\t\t\t  /	  \\\n";
            cout << "|\n";
            cout << "||-------------------------------------||\n";
            cout << "||-------------------------------------||\n";
            cout << "-------------------------------------\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\t\t\tCORRECT WORD: \n";
            cout << "\t\t\t" << randomString << " \n";
            cout << "\n";
            cout << "\n";
            cout << "-------------------------------------\n";

            break;

          } else {
            cout << "WRONG!!!\n";
          }
        } else {
          if (answer == randomString) {
            cout << "\nCORRECT!!! ";
            cout << "\nCorrect Word: " << answer << endl;
            // increment player_scores of the player playing when he guesses
            // correct.
            player_scores[game % 2]++;
            round++;
            break;
          }
        }
      }
      // reset for next round
      char guess;
      misses = 0;
      y = (rand() % 25);
      randomString = arr[y];
      transform(randomString.begin(), randomString.end(), randomString.begin(),
                ::toupper);

      answer = "";
      incorrect = "";
      for (int i = 0; i < randomString.size(); i++) {
        answer.push_back('-');
      }
      // condition to win loose or draw
      if (player_scores[0] > player_scores[1] && game == 3) {
        cout << player_names[0] << " WINS" << endl;
      } else if (player_scores[1] > player_scores[0] && game == 3) {
        cout << player_names[1] << " WINS" << endl;
      }
      if (player_scores[0] == player_scores[1] && game == 3) {
        cout << "Its a Tie!" << endl;
      }

      cout << "Player " << player_names[0] << " - score : " << player_scores[0]
           << endl;
      cout << "Player " << player_names[1] << " - score : " << player_scores[1]
           << endl;
    }
    // update_scores(players, player_scores);
  }
}
// void update_scores(int players, int player_scores[]) {

//   if (players == 2) {

//     cout << "The final scores are:\n";
//     cout << "Player 1: " << player_scores[0] << endl;
//     cout << "Player 2: " << player_scores[1] << endl;

//     if (player_scores[0] > player_scores[1]) {
//       cout << "Player 1 wins!!\n";
//     } else if (player_scores[1] > player_scores[0]) {
//       cout << "Player 2 wins!!\n";
//     }
//     if (player_scores[0] == player_scores[1] && game == 4) {
//       cout << "Its a Tie!" << endl;
//     }
//     system("clear");
//   }
// }

// display funtion when player guesses wrong
void display(int misses) {
  switch (misses) {

  case 0:
    cout << "----------------------------------------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t\t\t Life: " << 6 - misses << endl;
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "||-------------------------------------||\n";
    cout << "||-------------------------------------||\n";

    break;

  case 1:
    cout << "-----------------------------------------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t\t0\t\t Life: " << 6 - misses << "\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "||-------------------------------------||\n";
    cout << "||-------------------------------------||\n";

    break;

  case 2:
    cout << "-----------------------------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t\t0\t\t Life: " << 6 - misses << "\n";
    cout << "|\t\t\t    |\n";
    cout << "|\t\t\t    | \n";
    cout << "|\t\t\t\t|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "||-------------------------------------||\n";

    break;

  case 3:
    cout << "-----------------------------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t\t0\t\t Life: " << 6 - misses << "\n";
    cout << "|\t\t\t   /|\n";
    cout << "|\t\t\t  / | \n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t   \n";
    cout << "|\t\t\t    \n";
    cout << "|\n";
    cout << "||-------------------------------------||\n";
    cout << "||-------------------------------------||\n";

    break;

  case 4:
    cout << "-----------------------------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t\t0\t\t Life: " << 6 - misses << "\n";
    cout << "|\t\t\t   /|\\\n";
    cout << "|\t\t\t  / | \\\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t    \n";
    cout << "|\t\t\t  	  \n";
    cout << "|\n";
    cout << "||-------------------------------------||\n";
    cout << "||-------------------------------------||\n";

    break;

  case 5:
    cout << "-----------------------------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t\t0\t\t Life: " << 6 - misses << "\n";
    cout << "|\t\t\t   /|\\\n";
    cout << "|\t\t\t  / | \\\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t   / \n";
    cout << "|\t\t\t  /	  \n";
    cout << "|\n";
    cout << "||-------------------------------------||\n";
    cout << "||-------------------------------------||\n";

    break;

  case 6:
    cout << "-----------------------------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t\t0\t\t Life: " << 0 << "\n";
    cout << "|\t\t\t   /|\\\n";
    cout << "|\t\t\t  / | \\\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t\t\t   / \\\n";
    cout << "|\t\t\t  /	  \\\n";
    cout << "|\n";
    cout << "||-------------------------------------||\n";
    cout << "||-------------------------------------||\n";
    break;
  }
}
int main() {
  // generates the starting point of the series of pseudo random integers
  // time(nullptr) uses computers time to generate the seed - dynamic seed
  srand(time(nullptr));
  char again;
  menu_option();
  do {
    cout << "Press 1 to go back to main menu or 2 to exit: ";
    cin >> y;
    if (y == 1) {
      system("clear");
      menu_option();
    } else {
      exit(0);
    }
  } while (again == 'Y' || again == 'N');
}
