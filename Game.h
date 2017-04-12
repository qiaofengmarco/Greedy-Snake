#pragma once
#include<iostream>
#include"Snake.h"
#include"Environment.h"
using namespace std;
class Game
{
public:
	Game();
	void Play();
	bool End();
	void Show();
private:
	int bestScore, giftX, giftY, match;
};