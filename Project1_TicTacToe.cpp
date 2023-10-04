// Project1_TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex> 

char board[3][3];

const char empty = '.';
char winner = '.';
/*
void foo()
{
    std::cout << "\nwe in the foo now ";
}
void bar(int x) {


    std::cout << "\nwe in the bar now " << x;

}
*/


bool isGameWon() {
    //8 possible ways to win
    char spot1;
    char spot2;
    char spot3;
    

    for (int i = 0; i < 3; i++) {
        spot1 = board[i][0];
        spot2 = board[i][1];
        spot3 = board[i][2];
        
        if (spot1 != empty || spot2 != empty || spot3 != empty)
            if (spot1 == spot2 && spot2 == spot3){
                winner = spot1;
                return true;
            }

                
    }
    for (int i = 0; i < 3; i++) {
        spot1 = board[0][i];
        spot2 = board[1][i];
        spot3 = board[2][i];

        if (spot1 != empty || spot2 != empty || spot3 != empty)
            if (spot1 == spot2 && spot2 == spot3) {
                winner = spot1;
                return true;
            }

    }
    spot1 = board[0][0];
    spot2 = board[1][1];
    spot3 = board[2][2];
    if (spot1 != empty || spot2 != empty || spot3 != empty)
        if (spot1 == spot2 && spot2 == spot3) {
            winner = spot1;
            return true;
        }

    spot1 = board[0][2];
    spot2 = board[1][1];
    spot3 = board[2][0];
    if (spot1 != empty || spot2 != empty || spot3 != empty)
        if (spot1 == spot2 && spot2 == spot3) {
            winner = spot1;
            return true;
        }


    return false;
}

bool isGameStillGoing() {
    if(!isGameWon())
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == empty)
                    return true;
            }
        }
    return false;
}

bool isSpotTaken(int x, int y) {
    if (board[x][y] == empty)
        return false;
    return true;
}




void players(int x) {
    
    std::cout << "\nwe are in player " << x + 1;
    

}



int main()
{
    std::thread first(players, 0);
    std::thread second(players, 1);



    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = empty;
        }
    }

    std::cout << "\n Inside main";

    first.join();
    second.join();

    std::cout << "\nplayers complete";
    std::cout << "\nmain complete";
    board[2][0] = 'X';
    board[1][1] = 'X';
    board[0][2] = 'X';

    for (int i = 0; i < 3; i++) {
        std::cout << "\n";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        
    }
    std::cout << "\n" << isSpotTaken(2,0);
    std::cout << "\n" << isSpotTaken(0,0);
    std::cout << "\n" << isGameStillGoing();
    std::cout << "\n" << winner;

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
