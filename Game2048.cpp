#include "Game2048.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

// 初始化遊戲
Game2048::Game2048() {
    srand(static_cast<unsigned>(time(nullptr)));
    memset(board, 0, sizeof(board));
    memset(tempBoard, 0, sizeof(tempBoard));
}

//添加兩個初始塊
void Game2048::startGame() {
    int i1 = rand() % 4;
    int j1 = rand() % 4;
    int i2, j2;

    do {
        i2 = rand() % 4;
        j2 = rand() % 4;
    } while (i1 == i2 && j1 == j2);

    board[i1][j1] = 2;
    board[i2][j2] = 4;
}

void Game2048::upMove() {
    move(0);
}

void Game2048::downMove() {
    move(1);
}

void Game2048::leftMove() {
    move(2);
}

void Game2048::rightMove() {
    move(3);
}

// 添加新的塊
void Game2048::addBlock() {
    int li, ri;
    while (true) {
        li = rand() % 4;
        ri = rand() % 4;
        if (board[li][ri] == 0) {
            board[li][ri] =pow(2, li % 2 + 1);
            break;
        }
    }
}

// 遊戲版
void Game2048::display() const {
    cout << "\n\t\t                    Game: 2048";
    cout << "\n\n";
    cout << "\t\t\t\t  ┌───┬───┬───┬───┐\n";
    for (int i = 0; i < 4; ++i) {
        cout << "\t\t\t\t  │";
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0)
                cout << "   │";
            else
                cout << setw(3) << board[i][j] << "│";
        }
        cout << "\n";
        if (i < 3)
            cout << "\t\t\t\t  ├───┼───┼───┼───┤\n";
    }
    cout << "\t\t\t\t  └───┴───┴───┴───┘\n";

    cout << "\n\n\t\t\t\tW:↑   A:←   S:↓   D:→\n";
}

// 檢查是否結束
bool Game2048::isGameOver() const {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (board[i][j] == 0 ||
                (i < 3 && board[i][j] == board[i + 1][j]) ||
                (j < 3 && board[i][j] == board[i][j + 1]))
                return false;
    return true;
}

// 檢查是否有移動
bool Game2048::hasMoved() const {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (tempBoard[i][j] != board[i][j])
                return true;
    return false;
}

// 通用的移動函數
void Game2048::move(int direction) {
    copyBoard();
    if (direction == 0) { // up
        for (int j = 0; j < 4; ++j) {
            int li = 0;
            for (int i = 1; i < 4; ++i) {
                if (board[i][j] != 0) {
                    if (board[li][j] == board[i][j]) {
                        board[li][j] *= 2;
                        board[i][j] = 0;
                    }
                    else if (board[li][j] == 0) {
                        board[li][j] = board[i][j];
                        board[i][j] = 0;
                    }
                    else {
                        board[++li][j] = board[i][j];
                        if (li != i) board[i][j] = 0;
                    }
                }
            }
        }
    }
    else if (direction == 1) { // down
        for (int j = 0; j < 4; ++j) {
            int li = 3;
            for (int i = 2; i >= 0; --i) {
                if (board[i][j] != 0) {
                    if (board[li][j] == board[i][j]) {
                        board[li][j] *= 2;
                        board[i][j] = 0;
                    }
                    else if (board[li][j] == 0) {
                        board[li][j] = board[i][j];
                        board[i][j] = 0;
                    }
                    else {
                        board[--li][j] = board[i][j];
                        if (li != i) board[i][j] = 0;
                    }
                }
            }
        }
    }
    else if (direction == 2) { // left
        for (int i = 0; i < 4; ++i) {
            int ri = 0;
            for (int j = 1; j < 4; ++j) {
                if (board[i][j] != 0) {
                    if (board[i][ri] == board[i][j]) {
                        board[i][ri] *= 2;
                        board[i][j] = 0;
                    }
                    else if (board[i][ri] == 0) {
                        board[i][ri] = board[i][j];
                        board[i][j] = 0;
                    }
                    else {
                        board[i][++ri] = board[i][j];
                        if (ri != j) board[i][j] = 0;
                    }
                }
            }
        }
    }
    else if (direction == 3) { // right
        for (int i = 0; i < 4; ++i) {
            int ri = 3;
            for (int j = 2; j >= 0; --j) {
                if (board[i][j] != 0) {
                    if (board[i][ri] == board[i][j]) {
                        board[i][ri] *= 2;
                        board[i][j] = 0;
                    }
                    else if (board[i][ri] == 0) {
                        board[i][ri] = board[i][j];
                        board[i][j] = 0;
                    }
                    else {
                        board[i][--ri] = board[i][j];
                        if (ri != j) board[i][j] = 0;
                    }
                }
            }
        }
    }
}

// 複製遊戲版到臨時版
void Game2048::copyBoard() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            tempBoard[i][j] = board[i][j];
}

// 比較當前版和臨時版,檢查是否有變化
bool Game2048::compareBoard() const {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (tempBoard[i][j] != board[i][j])
                return true;
    return false;
}

// 處理玩家輸入
void Game2048::processInput(char input) {
    switch (input) {
    case 'w':
    case 'W':
        upMove();
        break;
    case 's':
    case 'S':
        downMove();
        break;
    case 'a':
    case 'A':
        leftMove();
        break;
    case 'd':
    case 'D':
        rightMove();
        break;
    default:
        break;
    }
    if (hasMoved()) addBlock();
}

// 檢查遊戲是否結束
bool Game2048::checkGameOver() {
    return isGameOver();
}

