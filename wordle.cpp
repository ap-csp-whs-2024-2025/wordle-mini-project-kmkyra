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


std::vector<int> createSecret() 
{
   std::vector<int> secret = {};
    int counter = 0;
    while (counter < 4)
    {
        int val = rand() % 10;
        secret.push_back(val);
        counter = counter + 1;
    }
    return secret;
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> user_guess) {
    int index = 0;
    std::vector<std::string> hint = {};
    while(index < 4)
    {
       if(user_guess[index] == secret[index]) 
       {
        hint.push_back("O");
       }
       else
       {
        hint.push_back("X");
       } 
       index = index + 1;
    }
   
    return hint;    // replace this with your code
//loop 4 times: if item 1 of secret matches item 1 of guess, 
//pushback O, else pushback x.... index +1
}

bool winGame(std::vector<int> secret, std::vector<int> user_guess) 
{
    
    int index = 0;
    while(index < 4)
    {
        if(user_guess[index] != secret[index])
        {
            return false;     
        }  
        index = index + 1;
    }
    return true;
}

int main()
{
    // Seeding the random number generator
    // Uncomment the code when you are finished testing your program
    // and want to have the program run for real
     srand(time(0));
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {-1, -1, -1, -1};
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
            //user_guess.push_back(input);    // can also do append(guess, input);
            user_guess[counter] = input;
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
