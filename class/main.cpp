//main
#include <iostream>
#include <conio.h>
#include "DisplayTimer.h"
using namespace std;

int main()
{

	while (1)
	{
		char ch;
		system("cls");                        //清屏
		New2048 s;
		DisplayTimer timer;                     //計時器
		cout << "遊戲開始！" << endl;
		timer.start();  // 開始計時
		s.make_frame();                       //列印框架
		s.creat_num();
		s.creat_num();                        //產生兩個隨機數
		s.display_num();                      //顯示數字
		while (1)
		{
			ch = _getch();                   //如果不是VS的，_getch應該改成getch
			if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
				ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
				break;
		}
	p:		switch (ch)
	{
	case 's':
	case 'S':
	{
		while (s.cheak())
		{
			s.DownMove();             //下移
			s.clean();                //清理
			s.display_num();          //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;
		}
	}break;
	case 'd':
	case 'D':
	{
		while (s.cheak())
		{
			s.RightMove();                //右移
			s.clean();                    //清理
			s.display_num();              //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;
		}
	}break;
	case 'a':
	case 'A':
	{
		while (s.cheak())
		{
			s.LeftMove();              //左移
			s.clean();                 //清理
			s.display_num();           //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;
		}
	}break;
	case 'w':
	case 'W':
	{
		while (s.cheak())
		{
			s.UpMove();               //上移
			s.clean();                //清理
			s.display_num();          //顯示數字
			while (1)
			{
				ch = _getch();
				if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
					ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
					break;
			}
			goto p;

		}
	}break;
	default:
		break;
	}                            //退出switch，遊戲結束
			timer.stop();  // 停止計時
			system("cls");               //清屏
			cout << "                         Failed" << endl;
			cout << "               PLAY AGAIN ? YES(Y) : NO(N)" << endl;
			cout << "遊戲時間: " << timer.elapsedSeconds() << " 秒" << endl;  //顯示遊戲時間
			while (1)
			{
				ch = _getch();
				if (ch == 'y' || ch == 'n' || ch == 'Y' || ch == 'N')
					break;
			}
			if (ch == 'y' || ch == 'Y')          //Y繼續
				continue;
			else                                 //否則退出
				break;
	}
	return 0;
}
