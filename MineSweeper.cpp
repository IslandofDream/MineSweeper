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
		cout << "������ : 201711384 ���ؿ�" << endl;
		cout << "1. �� ����" << endl;
		cout << "2. �̾� �ϱ�" << endl;
		cout << "3. ���� ��Ģ" << endl;
		cout << "4. ����" << endl;
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
			cout << "�÷��� ���ּż� �����մϴ�." << endl;
			exit(0);
			break;
		default:
			cout << "1~4 ������ ���ڸ� ����ּ���." << endl;
			Sleep(1000);
			break;
		}

	}

}

void MineSweeper::help()
{	
	a->SetColor(13, 11);
	cout << "�� ������ ���� ã�� �Դϴ�. " << endl;
	cout << "������ ��ǥ�� ���ڰ� �ִ� ����� ���ؼ� ��� ����� ���°� �Դϴ�." << endl;
	cout << "���ӻ� ���ڰ� ���� ��Ͽ��� ���ڰ� ������ �ֽ��ϴ�." << endl;
	cout << "�� ���ڴ� ��Ͽ� ������ �ִ� ������ ������ ��Ÿ���ϴ�." << endl;
	cout << "W,A,S,D�� ���� �� �� ������ Q�� ���ؼ� ���� ���� ������ �� �� �ֽ��ϴ�." << endl;
	a->SetColor(7, 0);
	system("pause");
	play();
}

void MineSweeper::create()
{
	while (true) {

		remove("load_map.txt"); // ������ �̹Ƿ� ���� ������ �����
		remove("load_con.txt");
		remove("record.txt");
		int m_count = 0;
		int mine; // ���� ����
		int x_mine; // ���� ���� ����
		int y_mine;
		cout << "������ ���� ���θ� �Է����ּ���. : ";
		cin >> n;

		if (!cin) {
			cout << "���ڸ� �Է����ּ���." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		cout << "������ ���� ���θ� �Է����ּ���. : ";
		cin >> m;

		if (!cin) {
			cout << "���ڸ� �Է����ּ���." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		cout << "���̵��� �Է����ּ���." << endl;
		cout << "1. ��(���� ���� ��ü 10%)" << endl;
		cout << "2. ��(���� ���� ��ü 20%)" << endl;
		cout << "3. ��(���� ���� ��ü 30%)" << endl;

		char dif; //���̵� ����

		dif = _getch();
		system("cls");


		if (dif == '1') {
			if (n * m < 10) {
				cout << "���ο� ������ ���� 10�� �ѵ��� �������ּ���." << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "�� ������......" << endl;
			mine = n * m * 0.1; //���� ����
		}

		else if (dif == '2') {
			if (n * m < 5) {
				cout << "���ο� ������ ���� 5�� �ѵ��� �������ּ���." << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "�� ������......" << endl;
			mine = n * m * 0.2; //���� ����
		}

		else if (dif == '3') {
			if (n * m < 3) {
				cout << "���ο� ������ ���� 3�� �ѵ��� �������ּ���." << endl;
				system("pause");
				system("cls");
				continue;
			}
			cout << "�� ������......" << endl;
			mine = n * m * 0.3; //���� ����
		}
		else {
			cout << "�߸��� �Է��Դϴ�!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		dynamic(n, m);// �����Ҵ�

		// �� ���� ����(���Ͽ� ������ �����)

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
		}// ���� Ȱ�� ���� �߰� ���� 

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
		}// ���� ���� ���� ��Ʈ ���� ä��� ����

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
			cerr << "������ ������ ������ �����ϴ�." << endl;
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
						}// �ۼ��ڰ� ���α׷��� ���� �Ŀ� ������ �ߴ� �ؽ�Ʈ ���Ϸ� �̾��ϱ� �� ��� �Ҹ��ڿ� ���ؼ� ��ȯ�� map �迭���� �ٽ� �����Ҵ�
						fin >> map[i][j];
					}

				}
			}
			fin.close();
		} // ���� �д� ���� (�̹� ������ ���� ��ġ �� ��Ʈ�� ������ map)

		fin.open("load_con.txt");
		if (!fin.is_open()) {
			cerr << "���� ���� �Ұ�" << endl;
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
		} // ���� �д� ���� �̾ �� p_map / b_map�� replay�ÿ��� �̿�Ǳ⶧���� ��� ����

		fin.open("record.txt");
		if (!fin.is_open()) {
			cerr << "���� ���� �Ұ�" << endl;
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

		remove("load_map.txt"); //���� ���ϵ��� ������
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
			cout << "��";
			a->SetColor(7, 0);

			switch (r_key)
			{
			case 'w':
			case 'W':
				if (p.y == 0) {
					// ���Ϳ� �������� ����
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



			}//vector�� �����ϸ� �ȵǹǷ� control �Լ��� ����������� 

			if (lose) {
				cursor = true; // ���÷��� �ٽ� ���� ���� �ϵ���
				record.clear();// ���÷��� ���� ���� ���� 
				play();
			}// �й� ���ǹ�

			gamewin(map, b_map, n, m);// ��� �κ��� �巯������ Ȯ��

			if (win) {

				win_result(map, b_map, n, m);

				cursor = true; // ���÷��� �ٽ� ���� ���� �ϵ���
				record.clear();// ���÷��� ���� ���� ���� 
				play(); // �ٽ� ���� �޴���
			}//�¸� ���ǹ�

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
{ //��� �Լ��� ���ؼ� �ڵ� ��ħ ��� ���� 
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
				cout << "��";
			}
			else {
				cout << p_map[i][j] << " ";
			}
		}
		cout << endl;
	}// �� ��� �κ� char �迭�� �ٸ��� Ư�����ڸ� ����Ѵ�. 
}

void MineSweeper::gamelose(char** map, char** p_map, int n, int m)
{
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') {
				a->SetColor(12, 0);
				cout << "��"; // ���� ��� �ٲ� char���� *���� ����� �ٸ� ���
				a->SetColor(7, 0); // ���� ������ ���� // ���� ��� �ٲܼ� ���� char���� *���� ����� �ٸ� ���
			}
			else if (p_map[i][j] == 'o') {
				cout << "��";
			}
			else {
				cout << p_map[i][j] << " ";
			}
		}
		cout << endl;
	}
	remove("load_map.txt"); //������ ���� �Ǿ����Ƿ� ���ϵ��� ������
	remove("load_con.txt");
	remove("record.txt");
	a->gotoxy(n + 10, m / 2);
	a->SetColor(15, 4);
	cout << "�й�!" << endl;
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
	}// ���� ��� ���ȴ��� �˻�
}

void MineSweeper::win_result(char** map, char** p_map, int n, int m)
{
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') {
				a->SetColor(4, 0);
				cout << "��"; // ���� ��� �ٲ� char���� *���� ����� �ٸ� ���
				a->SetColor(7, 0); // ���� ������ ����
			}
			else {
				cout << p_map[i][j] << " ";
			}
		}
		cout << endl;
	}
	a->gotoxy(p.x, p.y);
	a->SetColor(2, 0);
	cout << "��";
	a->SetColor(7, 0);


	a->gotoxy(n + 10, m / 2 );
	a->SetColor(15, 9);
	cout << "�����մϴ�! �¸�!" << endl;
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
		//q�� ���Ϳ� �������� ���� 
		ofstream fout("load_map.txt");
		if (!fout.is_open()) {
			cerr << "���� ���� �Ұ�" << endl;
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
		} // ���Ͽ� �ִ� ���� char ** map �� map.txt�� ��

		fout.open("load_con.txt");
		if (!fout.is_open()) {
			cerr << "���� ���� �Ұ�" << endl;
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
		} // �߰����� �� ������ txt ���Ͽ� ����

		fout.open("record.txt");
		if (!fout.is_open()) {
			cerr << "���� ���� �Ұ�" << endl;
		}
		else {
			fout << p.x << " " << p.y << endl;
			for (it = record.begin(); it != record.end(); it++) {
				char r_key = *it;
				fout << r_key;
			}
			fout.close();
		} // Ű���� ���

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
		// �߰��� ���� �ߴ��� �κ� ���

		a->gotoxy(n + 23, m / 2 - 1);
		cout << "W : ���� �̵�";
		a->gotoxy(n + 10, m / 2);
		cout << "A : ���� �̵�, S �Ʒ��� �̵�, D ������ �̵�";
		a->gotoxy(n + 13, m / 2 + 1);
		cout << "J : ���� Ȯ�� ��ư, Q : ���� �� ����";
		//��ǥ�� �Űܼ� ������ ���

		a->gotoxy(p.x, p.y);

		a->SetColor(2, 0);
		cout << "��";
		a->SetColor(7, 0);
		key = _getch();

		control(key);

		gamewin(map, p_map, n, m);

		if (lose) {
			cursor = true; //replay ���� cursor�� ��ġ�� �����ֱ� ����
			replay();
			play();
		}//�й�

		else if (win) {
			win_result(map, p_map, n, m);

			cursor = true; //replay �� cursor ��ġ �ʱ�ȭ�� ���ؼ�
			replay();
			remove("load_map.txt"); //������ ������
			remove("load_con.txt");
			remove("record.txt");
			play(); // �ٽ� ���� �޴���
		}//�¸� ���ǹ�

	}// key while

}



	









