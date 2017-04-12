#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include"Snake.h"
#include"Environment.h"
#include"Game.h"
using namespace std;
int main()
{
	Game Game1;
	while (true)
	{
		Game1.Play();
		if (Game1.End())
		{
			Game1.Show();
			break;
		}
	}
	system("pause");
	return 0;
}