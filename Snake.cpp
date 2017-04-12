#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include"Snake.h"
using namespace std;
Snake::Snake()
{
	length = 6;
	direction = 75;
	bodyX[1] = 7;
	bodyY[1] = 9;
	for (int i = 2; i <= 8; i++)
	{
		bodyX[i] = bodyX[1] + i - 1;
		bodyY[i] = 9;
	}
}
void Snake::LocateSnake(int x[], int y[],int &size)
{
	for (int i = 1; i <= length; i++)
	{
		x[i] = bodyX[i];
		y[i] = bodyY[i];
	}
	size = length;
}
void Snake::LocateGift(int x, int y)
{
	giftX = x;
	giftY = y;
	EatenGift = false;
}
int Snake::SnakeDirection()
{
	return direction;
}
int Snake::SnakeDead()
{
	if ((bodyY[1] == 0) || (bodyY[1] == 21)) return 1;
	if ((bodyX[1] == 0) || (bodyX[1] == 21)) return 1;
	for (int i = 1; i <= length; i++)
		for (int j = 1; j <= length; j++)
		{
			if ((i != j) && (bodyX[i] == bodyX[j]) && (bodyY[i] == bodyY[j]))
				return 2;
		}
	return 0;
}
void Snake::SnakeMove(int direct)
{
	int TailX, TailY;
	srand(time(0));
	direction = direct;
	TailX = bodyX[length];
	TailY = bodyY[length];
	for (int i = length; i >= 2; i--)
	{
		bodyX[i] = bodyX[i - 1];
		bodyY[i] = bodyY[i - 1];
	}
	switch (direction)
	{
	case 72:
		bodyX[1] += MoveX.up;
		bodyY[1] += MoveY.up;
		break;
	case 80:
		bodyX[1] += MoveX.down;
		bodyY[1] += MoveY.down;
		break;
	case 75:
		bodyX[1] += MoveX.left;
		bodyY[1] += MoveY.left;
		break;
	case 77:
		bodyX[1] += MoveX.right;
		bodyY[1] += MoveY.right;
		break;
	}
	if ((bodyX[1] == giftX) && (bodyY[1] == giftY))
	{
		length++;
		bodyX[length] = TailX;
		bodyY[length] = TailY;
		EatenGift = true;
	}
}
bool Snake::ReceiveGift()
{
	return EatenGift;
}
int Snake::TargetDistance()
{
	return fabs((double)(bodyX[1] - giftX)) + fabs((double)(bodyY[1] - giftY));
}