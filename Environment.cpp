#include<iostream>
#include<Windows.h>
#include"Environment.h"
using namespace std;
enum Things{ Wall = -1, Empty = 0, Snake = 1, SnakeHead = 2, Gift = 3 };
Things condition;
Environment::Environment()
{
	for (int i = 0; i <= 21; i++)
	{
		board[0][i] = Wall;
		board[21][i] = Wall;
		board[i][0] = Wall;
		board[i][21] = Wall;
	}
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			board[i][j] = Empty;
}
void Environment::SetGift(int x, int y)
{
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			board[i][j] = Empty;
	board[x][y] = Gift;
	giftX = x;
	giftY = y;
}
int Environment::EnvironmentState(int x, int y)
{
	return board[x][y];
}
void Environment::Set(int x[], int y[], int size)
{
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			board[i][j] = Empty;
	board[giftX][giftY] = Gift;
	for (int i = 2; i <= size; i++)
		board[x[i]][y[i]] = Snake;
	board[x[1]][y[1]] = SnakeHead;
}
void Environment::Print()
{
	system("cls");
	for (int y = 0; y <= 21; y++)
	{
		for (int x = 0; x <= 21; x++)
		{
			switch (board[x][y])
			{
			case Wall:
				cout << "█";
				break;
			case SnakeHead:
				cout << "●";
				break;
			case Snake:
				cout << "◆";
				break;
			case Empty:
				cout << "  ";
				break;
			case Gift:
				cout << "★";
			}
		}
		cout << endl;
	}
}