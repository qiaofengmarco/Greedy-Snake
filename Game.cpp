#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include"Snake.h"
#include"Environment.h"
#include"Game.h"
using namespace std;
Game::Game()
{
	match = 0;
	bestScore = 0;
}
bool Game::End()
{
	int yn;
	match++;
	cout << "Your longest snake's length is " << bestScore <<"."<< endl;
	cout << endl;
	cout << "Do you want to play again?" << endl;
	cout << "1.Yes" << endl;
	cout << "2.No" << endl;
	cin >> yn;
	while ((yn != 1) && (yn != 2))
	{
		cout << endl;
		cout << "Please enter 1 or 2.(1 for Yes, 2 for No)" << endl;
		cin >> yn;
	}
	return yn == 2 ? true : false;
}
void Game::Show()
{
	system("cls");
	cout << "In " << match <<(match>1?" games":" game")<< ", your longest snake's length is " << bestScore <<"."<< endl;
	cout << endl;
	cout << "Have fun!" << endl;
	cout << endl;
	cout << "Thank you very much for playing the game presented by SEU_Novice!" << endl;
	cout << endl;
	cout << "The End." << endl;
}
void Game::Play()
{
	Snake Snake1;
	Environment Environment1;
	int size, deadWay = 0, move = 0, score = 0, element1, key = 75, Speed = 33, GiftGet = 0, TargetDistance = 0;
	int x1[400], y1[400];
	bool dead = false;
	srand(time(0));
	system("cls");
	cout << "Are you ready for the challenge?" << endl;
	Sleep(1800);
	system("cls");
	cout << "Start!" << endl;
	Sleep(1800);
	system("cls");
	giftX = rand() % 16 + 3;
	giftY = rand() % 16 + 3;
	while (Environment1.EnvironmentState(giftX, giftY))
	{
		giftX = rand() % 16 + 3;
		giftY = rand() % 16 + 3;
	}
	Snake1.LocateGift(giftX, giftY);
	Environment1.SetGift(giftX, giftY);
	Snake1.LocateSnake(x1, y1, size);
	Environment1.Set(x1, y1, size);
	Environment1.Print();
	cout <<"Current Length : " << size << endl;
	while (true)
	{
		Sleep(Speed);
		if (_kbhit())
		{
			key = _getch();
			while (key == 224)
			{
				key = _getch();
			}
		}
		Snake1.SnakeMove(key);
		//move++;
		if (Snake1.ReceiveGift())
		{
			//TargetDistance = Snake1.TargetDistance();
			giftX = rand() % 16 + 3;
			giftY = rand() % 16 + 3;
			while (Environment1.EnvironmentState(giftX, giftY))
			{
				giftX = rand() % 16 + 3;
				giftY = rand() % 16 + 3;
			}
			Snake1.LocateGift(giftX, giftY);
			Environment1.SetGift(giftX, giftY);
			Snake1.LocateSnake(x1, y1, size);
			Environment1.Set(x1, y1, size);
			Environment1.Print();
			//GiftGet++;
			//element1 = rand() % 8 + GiftGet;
			//score += (element1 * 100) / ((move - TargetDistance < 10) ? 1 : (move - TargetDistance)/5);
			cout << "Current Length : " << size << endl;
			if (Speed > 13) Speed -= 2;
			//move = 0;
		}
		deadWay = Snake1.SnakeDead();
		if (deadWay)
		{
			system("cls");
			switch (deadWay)
			{
			case 1:
				cout << "Oh no! The snake bumps into the wall!" << endl;
				cout << "The snake is dead!" << endl;
				break;
			case 2:
				cout << "Oh no! The snake bites its own body!" << endl;
				cout << "The snake is dead!" << endl;
				break;
			}
			Sleep(1800);
			system("cls");
			bestScore = bestScore < size ? size : bestScore;
			break;
		}
		Snake1.LocateSnake(x1, y1, size);
		Environment1.Set(x1, y1, size);
		Environment1.Print();
		cout << "Current Length : " << size << endl;
	}
}