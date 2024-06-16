#ifndef GAME2048_H
#define GAME2048_H

class Game2048 {
public:
    Game2048();  //��l�ƹC��
    void startGame();  //�}�l�C��,��m��l�C��
    void upMove();  
    void downMove();  
    void leftMove();  
    void rightMove();  
    void addBlock();  //�K�[�@�ӷs���Ʀr
    void display() const;  //��ܹC���e��
    bool isGameOver() const;  //�ˬd�C���O�_����
    bool hasMoved() const;  //�ˬd�O�_�Ѳ���
    void processInput(char input);  //�B�z���a��J
    bool checkGameOver();  //�ˬd�O�_�C������

private:
    int board[4][4];
    int tempBoard[4][4]; //�O�s�W�@�Ӫ��A
    void move(int direction);
    void copyBoard();
    bool compareBoard() const;
};

#endif // GAME2048_H


