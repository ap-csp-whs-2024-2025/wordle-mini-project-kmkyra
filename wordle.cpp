/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector


std::vector<int> createSecret() {
   std::vector<int> secret;
    for(int i = 0; i < 4; i = i+1)
    {
        secret.push_back(std::rand());
    }
    return secret;    // replace this with your code
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    int index = 0;
    std::vector<std::string> hint;
    while(x<=4)
    {
       if(guess[index] = secret[index]) 
       {
        hint.push_back("O");
       }
       else
       {
        hint.push_back("X");
       } 
       index = index + 1;
    }
   
    return {"X", "X", "X", "X"};    // replace this with your code
//loop 4 times: if item 1 of secret matches item 1 of guess, 
//popback O, else popback x.... index +1
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {
    // Write this procedure here
    return false;    // replace this with your code
}

int main()
{
    // Seeding the random number generator
    // Uncomment the code when you are finished testing your program
    // and want to have the program run for real
    // srand(time(0));
    int random_num = rand() % 10;
    
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};    // an empty list

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        hint = {};    // reset the hint for the next guess
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            guess.push_back(input);    // can also do append(guess, input);
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
