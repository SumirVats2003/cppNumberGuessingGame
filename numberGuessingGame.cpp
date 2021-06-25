#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


// Variables
int theNum;
int guess;
int guesses;
bool win = false;
int chances = 0;


// Difficulty deciding function
void difficulty(int choice)
{
    while (true)
    {
       if (choice == 1)
       {
          // easy
          guesses = 15;
          break;
       }
       else if (choice == 2)
       {
          // medium
          guesses = 10;
          break;
       }
       else if (choice == 3)
       {
          // hard
          guesses = 5;
          break;
       }
       else if (choice == 4)
       {
          // God Mode
          guesses = 2;
          break;
       }
       else
       {
          cout << "Enter a valid input" << endl;
          cout << "Enter difficulty: ";
          cin >> choice;
       }
    }
}


// The game Function
void playGame()
{

    cout << "You have " << guesses << " chances to win" << endl;
    theNum = rand() % 101;

    while (guesses != 0)
    {
       cout << "Guess the Number: ";
       cin >> guess;

       if (guesses != 1)
       {
          chances++;
          if (guess == theNum)
          {
             cout << "You win" << endl;
             win = true;
             cout << "You took " << chances << " chances to win the game" << endl;
             break;
          }
          if (guess > theNum)
          {
             if (guess - theNum >= 25)
             {
                cout << "You have gone big! Try something smaller" << endl;
             }
             else if (guess - theNum <= 10)
             {
                cout << "You are getting closer!!" << endl;
             }
             else
             {
                cout << "Keep trying" << endl;
             }
          }

          else
          {
             if (theNum - guess >= 25)
             {
                cout << "That's small! Try something larger" << endl;
             }
             else if (theNum - guess <= 10)
             {
                cout << "You are getting closer!!" << endl;
             }
             else
             {
                cout << "Keep trying" << endl;
             }
          }
       }

       //cout << theNum;
       guesses--;
    }
}


// The main function
int main()
{
    srand(time(NULL));
    system("color 5E");

    cout << "Play number guessing game" << endl;
    cout << "You have to guess a number in the range 0 to 100" << endl;

    cout << "Enter difficulty level" << endl;
    cout << "Easy (1)" << endl;
    cout << "Medium (2)" << endl;
    cout << "Hard (3)" << endl;
    cout << "God Mode (4)" << endl;
    cout << "Enter choice: ";

    int diff;
    cin >> diff;
    difficulty(diff);

    char toPlay = 'y';

    while (toPlay == 'y')
    {
       playGame();

       if (win)
       {
          cout << "You guessed that right" << endl;
       }
       else
       {
          cout << "You lose, The number was: " << theNum << endl;
       }

       cout << "Play again?(y/n): ";
       cin >> toPlay;

       if (toPlay == 'y')
       {
          cout << "Enter difficulty: ";
          cin >> diff;
          difficulty(diff);
       }
    }
    system("pause");
    return 0;
}
