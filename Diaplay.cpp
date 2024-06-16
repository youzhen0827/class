#include "Display.h"
#include <iostream>
#include <conio.h> // getch()
using namespace std;

Display::Display() {}

void Display::run() {
    game.startGame(); 
    while (true) {
        game.display();  
        char input = _getch(); // Ū�����a��J,���ݭn�� Enter
        if (input == 27) break; // �� Esc �h�X
        game.processInput(input);  
        if (game.checkGameOver()) break;
    }
    cout << "\n\nGAME OVER!!\n\n\n";
}
