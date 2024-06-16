#ifndef DISPLAY_H
#define DISPLAY_H

#include "Game2048.h"

class Display {
private:
	Game2048 game;
public:
	Display(); // 構造函數
	void run(); // 運行遊戲的主循環
};

#endif // DISPLAY_H
