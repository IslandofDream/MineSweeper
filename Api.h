#pragma once
#include <Windows.h>



class Api
{
	int BLACk = 0;
	int Dark_blue = 1;
	int Dark_green = 2;
	int Dark_sky_blue = 3;
	int Dark_red = 4;
	int Dark_voilet = 5;
	int Dark_yellow = 6;
	int Gray = 7;
	int Dark_gray = 8;
	int Blue = 9;
	int green = 10;
	int Sky_blue = 11;
	int red = 12;
	int voilet = 13;
	int yellow = 14;
	int White = 15;
	int x;
	int y;
	int color;

public :
	Api();
	~Api();
	int gotoxy(int x, int y);
	void SetColor(int color, int bgcolr);
	void SetCursor(bool visible);

};

