#include <iostream>
#include <vector>

#include "domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    std::vector<Domino> snake;
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers
    // on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...
    snake.push_back(dominoes[0]);
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 6; ++i) {
            if (snake[j].getValues().second == dominoes[i].getValues().first){
                snake.push_back(dominoes[i]);
                break;
            }
        }
    }

    for (int i = 0; i < 6; ++i) {
        std::cout << snake[i].getValues().first << " " << snake[i].getValues().second <<std::endl;
    }

    return 0;
}
