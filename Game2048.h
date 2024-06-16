#ifndef GAME2048_H
#define GAME2048_H

class Game2048 {
public:
    Game2048();  //初始化遊戲
    void startGame();  //開始遊戲,放置初始遊戲
    void upMove();  
    void downMove();  
    void leftMove();  
    void rightMove();  
    void addBlock();  //添加一個新的數字
    void display() const;  //顯示遊戲畫面
    bool isGameOver() const;  //檢查遊戲是否結束
    bool hasMoved() const;  //檢查是否由移動
    void processInput(char input);  //處理玩家輸入
    bool checkGameOver();  //檢查是否遊戲結束

private:
    int board[4][4];
    int tempBoard[4][4]; //保存上一個狀態
    void move(int direction);
    void copyBoard();
    bool compareBoard() const;
};

#endif // GAME2048_H


