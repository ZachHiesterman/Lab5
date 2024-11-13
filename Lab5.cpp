#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class NumberGuessingGame
{
private:

    int maxAttempts;
    int tries;
    int num;

    vector<string> winMessages;
    vector<string> loseMessages;
    vector<string> againMessages;

public:

    NumberGuessingGame() : maxAttempts(20), tries(0)
    {
        srand(time(NULL));

        winMessages = {
            "Congratulations! You've won the game!",
            "Well done! You guessed the number correctly!",
            "Great job! You've cracked the number!",
            "Success! You are the winner!",
            "Amazing! You found the secret number!",
            "Nice work! The number is yours!",
            "Victory is yours! You guessed it!",
            "You did it! You win!",
            "Fantastic! You guessed the number in time!",
            "Hooray! You are the winner!"
        };

        loseMessages = {
            "Sorry, you've lost! The number was ",
            "Oops! You ran out of attempts. The number was ",
            "Game over! The number was ",
            "You couldn't guess it in time. The number was ",
            "You didn't win this time. The number was ",
            "Bad luck! The correct number was ",
            "Alas, you didn't guess correctly. The number was ",
            "Out of attempts! The number was ",
            "Unfortunately, you lost! The number was ",
            "You failed to guess the number. It was "
        };

        againMessages = {
            "Would you like to play again? 1 for yes, 2 for no: ",
            "Do you want to try again? 1 for yes, 2 for no: ",
            "Want to play another round? 1 for yes, 2 for no: ",
            "Play again? 1 for yes, 2 for no: ",
            "Another game? 1 for yes, 2 for no: ",
            "Do you want to play again? 1 for yes, 2 for no: ",
            "Try another game? 1 for yes, 2 for no: ",
            "Are you ready for another round? 1 for yes, 2 for no: ",
            "Want to have another go? 1 for yes, 2 for no: ",
            "Feeling lucky again? 1 for yes, 2 for no: "
        };
    }

    void playGame()
    {
        int playAgain;
        int wins = 0, loses = 0;

        do
        {
            int num = rand() % 100;
            int tries = 0;
            bool win = false;

            cout << "Welcome to the Number Guessing Game.\n";
            cout << "A random number  between 0 and 100 has been generated.\n";
            cout << "You have " << maxAttempts << " attempts to guess the number.\n";

            do
            {
                int guess;
                cout << "Enter your guess here: ";
                cin >> guess; 
                tries++;

                if (guess > num)
                    cout << "Your number is too high.\n";
                else if (guess < num)
                    cout << "You guess is to low.\n";
                else if (guess == num)
                {
                    win = true;
                    break;
                }
            } while (tries < maxAttempts);
            
            if (win) {
                int winMessageIndex = rand() % winMessages.size();
                cout << winMessages[winMessageIndex] << endl;
                wins++;
            } else {
                int loseMessageIndex = rand() % loseMessages.size();
                cout << loseMessages[loseMessageIndex] << num << endl;
                loses++;
            }
            int againMessageIndex = rand() % againMessages.size();
            cout << againMessages[againMessageIndex];
            cin >> playAgain;

            switch (playAgain)
            {
                case 1: playAgain = true;
                    break;
                case 2: playAgain = false;
                    break;
                default: cout << "Input error! Exiting program.\n";
                    playAgain = false;
                    break;
            }
        } while (playAgain == true);
        cout << "Thanks for playing here is your final score: ";
        cout << "Wins: " << wins << ". | " << "Loses: " << loses << ".";
    }
};

int main()
    {
    NumberGuessingGame game;
    game.playGame();

    return 0;
    }
    