#include "Display.h"
#include <iostream>
#include <conio.h> // getch()
using namespace std;

Display::Display() {}

void Display::run() {
    game.startGame(); 
    while (true) {
        game.display();  
        char input = _getch(); // 讀取玩家輸入,不需要按 Enter
        if (input == 27) break; // 按 Esc 退出
        game.processInput(input);  
        if (game.checkGameOver()) break;
    }
    cout << "\n\nGAME OVER!!\n\n\n";
}
