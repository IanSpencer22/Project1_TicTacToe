// Project1_TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>



char board[3][3];

char currentTurn = 'X';
const char empty = ' ';
char winner = '.';
std::mutex mtx;

std::condition_variable cond;




/*
Checks if Game won and sets winner if the game is won

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


/*
Checks if game is still going
*/
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


/*
Checks if spot is still going
*/
bool isSpotTaken(int x, int y) {
    if (board[x][y] == empty)
        return false;
    return true;
}



/*
Prints current board
*/
void printBoard() {
    std::cout << "\n-------------";
    for (int i = 0; i < 3; i++) {
        std::cout << "\n| ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
    }
    std::cout << "\n-------------\n";
}



/*
main thread for both players
*/
void players(char player) {
    std::unique_lock<std::mutex> lock(mtx);
    srand(time(NULL));
    bool placed = false;

    while (isGameStillGoing()) {
        cond.wait(lock, [&] { return player == currentTurn; });
        if (!isGameStillGoing())
            break;
        placed = false;
        while (!placed) {
            int x = rand() % 3;
            int y = rand() % 3;
            if (!isSpotTaken(x, y)) {
                board[x][y] = player;
                placed = true;
            }
        }

        printBoard();
        switch (currentTurn)
        {
        case 'X':
            currentTurn = 'O';
            break;
        case 'O':
            currentTurn = 'X';
            break;

        }
        cond.notify_all();
    }


}



int main()
{
    std::thread first(players, 'X');
    std::thread second(players, 'O');



    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = empty;
        }
    }

    std::cout << "\nInside main:\n\nThread Tic-Tac-Toe\n";

    first.join();
    second.join();

    std::cout << "\n\nPlayers complete: Game Over\n";
    if (winner == 'X' || winner == 'O')
        std::cout << "Congrats! Thread " << winner << " wins!\n\n";
    else
        std::cout << "Neither thread wins. Draw.\n\n";

    std::cout << "main complete";

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
