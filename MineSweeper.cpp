#include "MineSweeper.h"



MineSweeper::~MineSweeper()
{
	
	for (int i = 0; i < n; i++) {
		delete[] map[i];
		delete[] p_map[i];
		delete[] b_map[i];
	}
	delete[] map;
	delete[] p_map;
	delete[] b_map;

}


void MineSweeper::play()
{
	while (true)
	{
		system("cls");
		cout << "제작자 : 201711384 김준우" << endl;
		cout << "1. 새 게임" << endl;
		cout << "2. 이어 하기" << endl;
		cout << "3. 게임 규칙" << endl;
		cout << "4. 종료" << endl;
		char choice;
		choice = _getch();

		system("cls");
		switch (choice) {


		case '1':
			create();
			break;
		case '2':
			load();
			break;
		case '3':
			help();
			break;
		case '4':
			MineSweeper::~MineSweeper();
			cout << "플레이 해주셔서 감사합니다." << endl;
			exit(0);
			break;
		default:
			cout << "1~4 사이의 숫자만 골라주세요." << endl;
			Sleep(1000);
			break;
		}

	}

}

void MineSweeper::help()
{	
	a->SetColor(13, 11);
	cout << "본 게임은 지뢰 찾기 입니다. " << endl;
	cout << "게임의 목표는 지뢰가 있는 블록을 피해서 모든 블록을 여는것 입니다." << endl;
	cout << "게임상 지뢰가 없는 블록에는 숫자가 쓰여져 있습니다." << endl;
	cout << "이 숫자는 블록에 인접해 있는 지뢰의 개수를 나타냅니다." << endl;
	cout << "W,A,S,D로 조작 할 수 있으며 Q를 통해서 게임 도중 저장을 할 수 있습니다." << endl;
	a->SetColor(7, 0);
	system("pause");
	play();
}

void MineSweeper::create()
{
	while (true) {

		remove("load_map.txt"); // 새게임 이므로 이전 게임은 사라짐
		remove("load_con.txt");
		remove("record.txt");
		int m_count = 0;
		int mine; // 지뢰 개수
		int x_mine; // 랜덤 생성 지뢰
		int y_mine;
		cout << "생성될 맵의 가로를 입력해주세요. : ";
		cin >> n;

		if (!cin) {
			cout << "숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		cout << "생성될 맵의 세로를 입력해주세요. : ";
		cin >> m;

		if (!cin) {
			cout << "숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		cout << "난이도를 입력해주세요." << endl;
		cout << "1. 하(지뢰 갯수 전체 10%)" << endl;
		cout << "2. 중(지뢰 갯수 전체 20%)" << endl;
		cout << "3. 상(지뢰 갯수 전체 30%)" << endl;

		char dif; //난이도 설정

		dif = _getch();
		system("cls");


		if (dif == '1') {
			if (n * m < 10) {
				cout << "가로와 세로의 곱이 10을 넘도록 설정해주세요." << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "맵 생성중......" << endl;
			mine = n * m * 0.1; //지뢰 개수
		}

		else if (dif == '2') {
			if (n * m < 5) {
				cout << "가로와 세로의 곱이 5를 넘도록 설정해주세요." << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "맵 생성중......" << endl;
			mine = n * m * 0.2; //지뢰 개수
		}

		else if (dif == '3') {
			if (n * m < 3) {
				cout << "가로와 세로의 곱이 3을 넘도록 설정해주세요." << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "맵 생성중......" << endl;
			mine = n * m * 0.3; //지뢰 개수
		}
		else {
			cout << "잘못된 입력입니다!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		dynamic(n, m);// 동적할당

		// 맵 세개 생성(파일용 실제용 백업용)

		while (true) {
			srand((unsigned int)time(NULL));
			x_mine = rand() % n;
			y_mine = rand() % m;
			if (map[x_mine][y_mine] == '*') {
				continue;
			}
			else {
				map[x_mine][y_mine] = '*';
				m_count++;
			}
			if (m_count == mine) { break; }
		}// 난수 활용 지뢰 추가 과정 

		int n_hint;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				n_hint = 0;
				if (map[i][j] == '*') {
					continue;
				}
				if (hint(n, m, i, j - 1)) {
					if (map[i][j - 1] == '*') {
						n_hint++;
					}
				}

				if (hint(n, m, i, j + 1)) {
					if (map[i][j + 1] == '*') {
						n_hint++;
					}
				}

				if (hint(n, m, i + 1, j)) {
					if (map[i + 1][j] == '*') {
						n_hint++;
					}
				}

				if (hint(n, m, i - 1, j)) {
					if (map[i - 1][j] == '*') {
						n_hint++;
					}
				}

				if (hint(n, m, i - 1, j - 1)) {
					if (map[i - 1][j - 1] == '*') {
						n_hint++;
					}
				}

				if (hint(n, m, i - 1, j + 1)) {
					if (map[i - 1][j + 1] == '*') {
						n_hint++;
					}
				}

				if (hint(n, m, i + 1, j - 1)) {
					if (map[i + 1][j - 1] == '*') {
						n_hint++;
					}
				}

				if (hint(n, m, i + 1, j + 1)) {
					if (map[i + 1][j + 1] == '*') {
						n_hint++;
					}
				}

				map[i][j] = n_hint + '0';
			}
		}// 지뢰 개수 주위 힌트 숫자 채우는 과정

		if (cursor) {
			p.x = 0;
			p.y = 0;
			cursor = false;
		}
		playing();

	} //while

}  //create



void MineSweeper::load()
{

	while (true) {
		ifstream fin("load_map.txt");
		if (!fin.is_open()) {
			cerr << "이전에 진행한 게임이 없습니다." << endl;
			system("pause");
			play();

		}
		else {
			fin >> n >> m;
			while (!fin.eof()) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (l_dynamic) {
							dynamic(n, m);
						}// 작성자가 프로그램을 종료 후에 예전에 했던 텍스트 파일로 이어하기 할 경우 소멸자에 의해서 반환된 map 배열들을 다시 동적할당
						fin >> map[i][j];
					}

				}
			}
			fin.close();
		} // 파일 읽는 과정 (이미 이전에 지뢰 배치 및 힌트가 생성된 map)

		fin.open("load_con.txt");
		if (!fin.is_open()) {
			cerr << "파일 실행 불가" << endl;
		}
		else {
			fin >> n >> m;

			while (!fin.eof()) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						fin >> p_map[i][j];
					}

				}
			}
			fin.close();
		} // 파일 읽는 과정 이어서 할 p_map / b_map은 replay시에만 이용되기때문에 백업 안함

		fin.open("record.txt");
		if (!fin.is_open()) {
			cerr << "파일 실행 불가" << endl;
		}
		else {
			fin >> p.x >> p.y;

			while (!fin.eof()) {
				char r_key;
				fin >> r_key;
				record.push_back(r_key);
			}
			fin.close();
		}

		remove("load_map.txt"); //이전 파일들은 지워줌
		remove("load_con.txt");
		remove("record.txt");

		playing();
	}//while

}//load

void MineSweeper::replay()
{

	while (true) {

		for (it = record.begin(); it != record.end(); it++) {
			Sleep(400);
			char r_key = *it;

			system("cls");

			lose = false;
			win = true;

			print_map(b_map, n, m);


			if (cursor) {
				p.x = 0;
				p.y = 0;
				cursor = false;
			}

			a->gotoxy(p.x, p.y);
			a->SetColor(2, 0);
			cout << "√";
			a->SetColor(7, 0);

			switch (r_key)
			{
			case 'w':
			case 'W':
				if (p.y == 0) {
					// 벡터에 저장하지 않음
					break;
				}

				p.y--;
				break;

			case 's':
			case 'S':
				if (p.y == n - 1) {

					break;
				}
				p.y++;
				break;

			case 'a':
			case 'A':
				if (p.x == 0) {

					break;
				}
				p.x -= 2;
				break;

			case 'd':
			case 'D':
				if (p.x == (m - 1) * 2) {

					break;
				}
				p.x += 2;
				break;

			case 'j':
			case 'J':
				if (map[p.y][p.x / 2] == '*') {
					gamelose(map, b_map, n, m);
					lose = true;

					break;
				}
				else {
					if (b_map[p.y][p.x / 2] == 'o') {
						open(map, b_map, n, m, p.x / 2, p.y);

						break;
					}
				}
				break;



			}//vector에 저장하면 안되므로 control 함수는 사용하지않음 

			if (lose) {
				cursor = true; // 리플레이 다시 실행 가능 하도록
				record.clear();// 리플레이 이후 벡터 비우기 
				play();
			}// 패배 조건문

			gamewin(map, b_map, n, m);// 모든 부분이 드러났는지 확인

			if (win) {

				win_result(map, b_map, n, m);

				cursor = true; // 리플레이 다시 실행 가능 하도록
				record.clear();// 리플레이 이후 벡터 비우기 
				play(); // 다시 메인 메뉴로
			}//승리 조건문

		}//for

	}//while

}// replay

bool MineSweeper::hint(int n, int m, int x, int y)
{ // 
	if (x >= 0 && x < n) {
		if (y >= 0 && y < m) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

void MineSweeper::open(char** map, char** p_map, int n, int m, int x, int y)
{ //재귀 함수를 통해서 자동 펼침 기능 제공 
	if (map[y][x] - '0' > 0 && map[y][x] - '0' <= 9) {
		p_map[y][x] = map[y][x];
		
	}
	else if (map[y][x] - '0' == 0) {
		p_map[y][x] = '0';
		if (hint(n, m, y - 1, x - 1)) {
			if (p_map[y - 1][x - 1] != '0') {
				open(map, p_map, n, m, x - 1, y - 1);
			}
		}

		if (hint(n, m, y - 1, x)) {
			if (p_map[y - 1][x] != '0') {
				open(map, p_map, n, m, x, y - 1);
			}
		}


		if (hint(n, m, y - 1, x + 1)) {
			if (p_map[y - 1][x + 1] != '0') {
				open(map, p_map, n, m, x + 1, y - 1);
			}
		}

		if (hint(n, m, y, x - 1)) {
			if (p_map[y][x - 1] != '0') {
				open(map, p_map, n, m, x - 1, y);
			}
		}

		if (hint(n, m, y, x + 1)) {
			if (p_map[y][x + 1] != '0') {
				open(map, p_map, n, m, x + 1, y);
			}
		}

		if (hint(n, m, y + 1, x - 1)) {
			if (p_map[y + 1][x - 1] != '0') {
				open(map, p_map, n, m, x - 1, y + 1);
			}
		}

		if (hint(n, m, y + 1, x)) {
			if (p_map[y + 1][x] != '0') {
				open(map, p_map, n, m, x, y + 1);
			}
		}

		if (hint(n, m, y + 1, x + 1)) {
			if (p_map[y + 1][x + 1] != '0') {
				open(map, p_map, n, m, x + 1,  y + 1);
			}
		}

	}
}

void MineSweeper::print_map(char** p_map, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (p_map[i][j] == 'o') {
				cout << "▣";
			}
			else {
				cout << p_map[i][j] << " ";
			}
		}
		cout << endl;
	}// 맵 출력 부분 char 배열과 다르게 특수문자를 사용한다. 
}

void MineSweeper::gamelose(char** map, char** p_map, int n, int m)
{
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') {
				a->SetColor(12, 0);
				cout << "⊙"; // 지뢰 모양 바꿈 char에는 *저장 출력은 다른 모양
				a->SetColor(7, 0); // 원래 색으로 변함 // 지뢰 모양 바꿀수 있음 char에는 *저장 출력은 다른 모양
			}
			else if (p_map[i][j] == 'o') {
				cout << "▣";
			}
			else {
				cout << p_map[i][j] << " ";
			}
		}
		cout << endl;
	}
	remove("load_map.txt"); //게임이 종료 되었으므로 파일들을 지워줌
	remove("load_con.txt");
	remove("record.txt");
	a->gotoxy(n + 10, m / 2);
	a->SetColor(15, 4);
	cout << "패배!" << endl;
	a->SetColor(7, 0);
	a->gotoxy(0, m + 1);
	system("pause");
}

void MineSweeper::gamewin(char** map, char** p_map, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '*') {
				if (p_map[i][j] == 'o') {
					win = false;
				}
			}
		}
	}// 맵이 모두 열렸는지 검사
}

void MineSweeper::win_result(char** map, char** p_map, int n, int m)
{
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') {
				a->SetColor(4, 0);
				cout << "⊙"; // 지뢰 모양 바꿈 char에는 *저장 출력은 다른 모양
				a->SetColor(7, 0); // 원래 색으로 변함
			}
			else {
				cout << p_map[i][j] << " ";
			}
		}
		cout << endl;
	}
	a->gotoxy(p.x, p.y);
	a->SetColor(2, 0);
	cout << "√";
	a->SetColor(7, 0);


	a->gotoxy(n + 10, m / 2 );
	a->SetColor(15, 9);
	cout << "축하합니다! 승리!" << endl;
	a->SetColor(7, 0);
	a->gotoxy(0, m + 1);
	system("pause");
}

void MineSweeper::control(char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
		if (p.y == 0) {
			break;
		}
		p.y--;
		record.push_back(key);
		break;

	case 's':
	case 'S':
		if (p.y == n - 1) {
			break;
		}
		p.y++;
		record.push_back(key);
		break;

	case 'a':
	case 'A':
		if (p.x == 0) {
			break;
		}
		p.x -= 2;
		record.push_back(key);
		break;

	case 'd':
	case 'D':
		if (p.x == (m - 1) * 2) {
			break;
		}
		p.x += 2;
		record.push_back(key);
		break;

	case 'j':
	case 'J':
		record.push_back(key);
		if (map[p.y][p.x / 2] == '*') {
			gamelose(map, p_map, n, m);
			lose = true;
			break;
		}
		else {
			if (p_map[p.y][p.x / 2] == 'o') {
				open(map, p_map, n, m, p.x / 2, p.y);
				break;
			}
		}

		break;

	case 'q':
	case 'Q':
		//q는 벡터에 저장하지 않음 
		ofstream fout("load_map.txt");
		if (!fout.is_open()) {
			cerr << "파일 실행 불가" << endl;
		}
		else {
			fout << n << " " << m << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					fout << map[i][j];
				}
				fout << endl;
			}
			fout.close();
		} // 파일에 넣는 과정 char ** map 이 map.txt에 들어감

		fout.open("load_con.txt");
		if (!fout.is_open()) {
			cerr << "파일 실행 불가" << endl;
		}
		else {
			fout << n << " " << m << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					fout << p_map[i][j];
				}
				fout << endl;
			}
			fout.close();
		} // 중간까지 한 파일을 txt 파일에 넣음

		fout.open("record.txt");
		if (!fout.is_open()) {
			cerr << "파일 실행 불가" << endl;
		}
		else {
			fout << p.x << " " << p.y << endl;
			for (it = record.begin(); it != record.end(); it++) {
				char r_key = *it;
				fout << r_key;
			}
			fout.close();
		} // 키보드 기록

		record.clear();
		play();
		break;


	}//switch key
}

void MineSweeper::dynamic(int n , int m) 
{
	map = new char* [n];
	b_map = new char* [n];
	p_map = new char* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new char[m];
		b_map[i] = new char[m];
		p_map[i] = new char[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = 'o';
			b_map[i][j] = 'o';
			p_map[i][j] = 'o';
		}
	}
	l_dynamic = false;
}

void MineSweeper::playing()
{
	char key;
	while (true) {
		system("cls");

		lose = false;
		win = true;

		print_map(p_map, n, m);
		// 중간에 진행 중단한 부분 출력

		a->gotoxy(n + 23, m / 2 - 1);
		cout << "W : 위쪽 이동";
		a->gotoxy(n + 10, m / 2);
		cout << "A : 왼쪽 이동, S 아래쪽 이동, D 오른쪽 이동";
		a->gotoxy(n + 13, m / 2 + 1);
		cout << "J : 지뢰 확인 버튼, Q : 저장 및 종료";
		//좌표를 옮겨서 도움말을 출력

		a->gotoxy(p.x, p.y);

		a->SetColor(2, 0);
		cout << "√";
		a->SetColor(7, 0);
		key = _getch();

		control(key);

		gamewin(map, p_map, n, m);

		if (lose) {
			cursor = true; //replay 전에 cursor의 위치를 돌려주기 위함
			replay();
			play();
		}//패배

		else if (win) {
			win_result(map, p_map, n, m);

			cursor = true; //replay 전 cursor 위치 초기화를 위해서
			replay();
			remove("load_map.txt"); //파일을 지워줌
			remove("load_con.txt");
			remove("record.txt");
			play(); // 다시 메인 메뉴로
		}//승리 조건문

	}// key while

}



	









