#pragma once
#include<iostream>
using namespace std;
class Snake
{
public:
	Snake();
	void LocateSnake(int[], int[], int &);
	void LocateGift(int, int);
	int SnakeDead();
	void SnakeMove(int);
	bool ReceiveGift();
	int SnakeDirection();
	int TargetDistance();
private:
	int bodyX[400], bodyY[400];
	int length, direction, giftX, giftY;
	bool EatenGift = false;
	struct X
	{
		int left = -1, right = 1, up = 0, down = 0;
	};
	struct Y
	{
		int left = 0, right = 0, up = -1, down = 1;
	};
	X MoveX;
	Y MoveY;
};