// Project1_TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex> 

int board[3][3];

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
    int spot1;
    int spot2;
    int spot3;

    for (int i = 0; i < 3; i++) {
        spot1 = board[i][0];
        spot2 = board[i][1];
        spot3 = board[i][2];
        
        if (spot1 != -1 || spot2 != -1 || spot3 != -1)
            if (spot1 == spot2 && spot2 == spot3)
                return true;
    }
    for (int i = 0; i < 3; i++) {
        spot1 = board[0][i];
        spot2 = board[1][i];
        spot3 = board[2][i];

        if (spot1 != -1 || spot2 != -1 || spot3 != -1)
            if (spot1 == spot2 && spot2 == spot3)
                return true;
    }
    spot1 = board[0][0];
    spot2 = board[1][1];
    spot3 = board[2][2];
    if (spot1 != -1 || spot2 != -1 || spot3 != -1)
        if (spot1 == spot2 && spot2 == spot3)
            return true;
    spot1 = board[0][2];
    spot2 = board[1][1];
    spot3 = board[2][0];
    if (spot1 != -1 || spot2 != -1 || spot3 != -1)
        if (spot1 == spot2 && spot2 == spot3)
            return true;


    return false;
}

bool isGameStillGoing() {
    if(!isGameWon())
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == -1)
                    return true;
            }
        }
    return false;
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
            board[i][j] = -1;
        }
    }

    std::cout << "\n Inside main";

    first.join();
    second.join();

    std::cout << "\nplayers complete";
    std::cout << "\nmain complete";


    for (int i = 0; i < 3; i++) {
        std::cout << "\n";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        
    }
    

    std::cout << "\n" << isGameStillGoing();

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
