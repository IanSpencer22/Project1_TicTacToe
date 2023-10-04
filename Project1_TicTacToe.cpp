// Project1_TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex> 

int board[3][3];


void foo()
{
    std::cout << "\nwe in the foo now ";
}
void bar(int x) {


    std::cout << "\nwe in the bar now " << x;

}

int main()
{
    std::thread first(foo);
    std::thread second(bar, 0);



    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = -1;
        }
    }

    std::cout << "\n Inside main";

    first.join();
    second.join();

    std::cout << "\nfoo() and bar complete";
    std::cout << "\nmain complete";

    for (int i = 0; i < 3; i++) {
        std::cout << "\n";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        t
    }
    



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
