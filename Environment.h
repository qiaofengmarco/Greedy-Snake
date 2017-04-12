#pragma once
#include<iostream>
using namespace std;
class Environment
{
public:
	Environment();
	void Print();
	void Set(int [], int [], int);
	void SetGift(int, int);
	int EnvironmentState(int, int);
private:
	int board[22][22],giftX,giftY;
};