#pragma once
#include "Api.h"
#include <vector>;
#include <conio.h>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class MineSweeper
{

private:
	struct Player
	{
		int x, y;
	};

	int n, m; //���� , ����
	char** map; // ���� ��
	char** p_map; // �÷��̿� ��
	char** b_map; // ���÷��̿� ��� ��
	vector<char> record;
	
	vector<char>::iterator it;
	Player p;
	Api* a = new Api();
	bool lose;
	bool win;
	bool cursor = true; // cursor ��ġ �ʱ�ȭ�� ���� ����
	bool l_dynamic = true; // �����Ҵ� ���� �Ǵ�

public:
	MineSweeper()=default;
	~MineSweeper();
	void play();
	void help();
	void create();
	void load();
	void replay();
	bool hint(int n, int m, int x, int y);
	void open(char** map, char** f_map, int n, int m, int x, int y);
	void print_map(char** p_map, int n, int m);
	void gamelose(char** map, char** p_map, int n, int m);
	void gamewin(char** map, char** p_map, int n, int m);
	void win_result(char** map, char** p_map, int n, int m);
	void control(char ch);
	void dynamic(int n, int m);
	void playing();
	
	


};



