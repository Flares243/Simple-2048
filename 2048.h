#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <io.h>
using namespace std;
#pragma warning (disable:4996)
#define C 4
#define D 4

void FirstRoll(int a[D][C], int d, int c);
void UpdateRoll(int a[D][C], int d, int c);
int Dem(int n);
void RefreshScreen(int a[D][C], int d, int c);
void RandomNum(int a[D][C], int emp[D], int d, int c, int &dir);
void left(int a[D][C], int b[C], int emp[D], int d, int c, int &dir);
void right(int a[D][C], int b[C], int emp[D], int d, int c, int &dir);
void up(int a[D][C], int b[C], int emp[D], int d, int c, int &dir);
void down(int a[D][C], int b[C], int emp[D], int d, int c, int &dir);

void FirstRoll(int a[D][C], int d, int c)
{
	int m = 0, r;

	for (int i = 0; i < d; i++) {
		for (int e = 0; e < c; e++) {
			r = rand() % 9 + 1;

			if (m >= 0 && m < 2 && i == 3 && (e == c - 1 || e == c - 2)) {
				a[i][e] = 2;
				m++;
			}
			else if (r == 1 && m < 2) {
				a[i][e] = 2;
				m++;
			}
			else {
				a[i][e] = 0;
			}

			if (a[i][e] == 0) {
				cout << "| ";
			}
			else {
				printf("|%d", a[i][e]);
			}

			if (e < c - 1) {
				cout << "\t";
			}
		}

		if (i < d - 1) {
			cout << "\n\n";
		}
	}
}

void UpdateRoll(int a[D][C], int d, int c)
{
	for (int i = 0; i < d; i++) {
		for (int e = 0; e < c; e++) {
			if (a[i][e] == 0) {
				cout << "| ";
			}
			else {
				printf("|%d", a[i][e]);
			}

			if (e < c - 1) {
				cout << "\t";
			}
		}

		if (i < d - 1) {
			cout << "\n\n";
		}
	}
}

int Dem(int n)
{
	int d = 0;

	do
	{
		n /= 10;
		d++;
	} while (n != 0);

	return d;
}

void RefreshScreen(int a[D][C], int d, int c)
{
	COORD coord;
	coord.X = 0;
	coord.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	for (int i = 0; i < d; i++) {
		for (int e = 0; e < c; e++) {
			for (int p = 0; p < Dem(a[i][e]) + 7; p++) {
				cout << "          ";
			}
		}

		if (i < d - 1) {
			cout << "\n";
		}
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void RandomNum(int a[D][C], int emp[D], int d, int c, int &dir)
{
	int S = 0, n;
	n = 0;

	for (int i = 0; i < c; i++) {
		S += emp[i];
	}

	if (dir == 0) {			//Left
		if (S > 1) {
			do
			{
				for (int e = 0; e < d; e++) {
					if (emp[e] > 0) {
						for (int j = c - 1; j > c - emp[e] - 1; j--) {
							if (a[e][j] == 0) {
								if (rand() % 10 == 1) {
									if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
										a[e][j] = 4;
									}
									else {
										a[e][j] = 2;
									}
									n++;
									break;
								}
							}
						}
					}

					if (n > 0) {
						break;
					}
				}
			} while (n < 1);
		}
		else if (S == 1) {
			for (int e = 0; e < d; e++) {
				if (emp[e] > 0) {
					if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
						a[e][c - 1] = 4;
					}
					else {
						a[e][c - 1] = 2;
					}

					break;
				}
			}
		}
		else {
			cout << "\n\n\n\tGame Over\n";
			getch();
			exit(0);
		}
	}
	else if (dir == 1) {	//Right
		if (S > 1) {
			do
			{
				for (int e = 0; e < d; e++) {
					if (emp[e] > 0) {
						for (int j = 0; j < emp[e]; j++) {
							if (a[e][j] == 0) {
								if (rand() % 10 == 1) {
									if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
										a[e][j] = 4;
									}
									else {
										a[e][j] = 2;
									}
									n++;
									break;
								}
							}
						}
					}

					if (n > 0) {
						break;
					}
				}
			} while (n < 1);
		}
		else if (S == 1) {
			for (int e = 0; e < d; e++) {
				if (emp[e] > 0) {
					if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
						a[e][0] = 4;
					}
					else {
						a[e][0] = 2;
					}

					break;
				}
			}
		}
		else {
			cout << "\n\n\n\tGame Over\n";
			getch();
			exit(0);
		}
	}
	else if (dir == 2) {	//Up
		if (S > 1) {
			do
			{
				for (int e = 0; e < c; e++) {
					if (emp[e] > 0) {
						for (int j = d - 1; j > d - emp[e] - 1; j--) {
							if (a[j][e] == 0) {
								if (rand() % 10 == 1) {
									if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
										a[j][e] = 4;
									}
									else {
										a[j][e] = 2;
									}
									n++;
									break;
								}
							}
						}
					}

					if (n > 0) {
						break;
					}
				}
			} while (n < 1);
		}
		else if (S == 1) {
			for (int e = 0; e < c; e++) {
				if (emp[e] > 0) {
					if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
						a[d - 1][e] = 4;
					}
					else {
						a[d - 1][e] = 2;
					}

					break;
				}
			}
		}
		else {
			cout << "\n\n\n\tGame Over\n";
			getch();
			exit(0);
		}
	}
	else if (dir == 3) {	//Down
		if (S > 1) {
			do
			{
				for (int e = 0; e < c; e++) {
					if (emp[e] > 0) {
						for (int j = 0; j < emp[e]; j++) {
							if (a[j][e] == 0) {
								if (rand() % 10 == 1) {
									if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
										a[j][e] = 4;
									}
									else {
										a[j][e] = 2;
									}
									n++;
									break;
								}
							}
						}
					}

					if (n > 0) {
						break;
					}
				}
			} while (n < 1);
		}
		else if (S == 1) {
			for (int e = 0; e < c; e++) {
				if (emp[e] > 0) {
					if (rand() % 8 + 1 == 1 || rand() % 8 + 1 == 2) {
						a[0][e] = 4;
					}
					else {
						a[0][e] = 2;
					}

					break;
				}
			}
		}
		else {
			cout << "\n\n\n\tGame Over\n";
			getch();
			exit(0);
		}
	}

	for (int r = 0; r < c; r++) {
		emp[r] = 0;
	}

	dir = 0;
}

void left(int a[D][C], int b[C], int emp[D], int d, int c, int &dir)
{
	int t, x, m;
	dir = 0;

	for (int i = 0; i < d; i++) {
		t = 0;
		m = 0;
		x = 0;

		for (int r = 0; r < c; r++) {
			b[r] = 0;
		}

		for (int o = 0; o < c; o++) {
			if (a[i][o] != 0) {
				b[t] = a[i][o];
				t++;
				m = 1;
				a[i][o] = 0;
			}
		}

		if (t > 1) {
			for (int p = 0; p < t; p++) {
				if (b[p] == b[p + 1]) {
					b[p] *= 2;
					b[p + 1] = 0;
					p++;
				}
			}
		}
		else if (m == 1) {
			a[i][0] = b[0];
			emp[i] = 3;
			continue;
		}

		for (int j = 0; j < c; j++) {
			if (b[j] != 0) {
				a[i][x] = b[j];
				x++;
			}
			else {
				emp[i]++;
			}
		}
	}
}

void right(int a[D][C], int b[C], int emp[D], int d, int c, int &dir)
{
	int t, x, m;
	dir = 1;

	for (int i = 0; i < d; i++) {
		t = 0;
		m = 0;
		x = c - 1;

		for (int r = 0; r < c; r++) {
			b[r] = 0;
		}

		for (int o = d - 1; o >= 0; o--) {
			if (a[i][o] != 0) {
				b[t] = a[i][o];
				t++;
				m = 1;
				a[i][o] = 0;
			}
		}

		if (t > 1) {
			for (int p = 0; p < t; p++) {
				if (b[p] == b[p + 1]) {
					b[p] *= 2;
					b[p + 1] = 0;
					p++;
				}
			}
		}
		else if (m == 1) {
			a[i][c - 1] = b[0];
			emp[i] = 3;
			continue;
		}

		for (int j = 0; j < c; j++) {
			if (b[j] != 0) {
				a[i][x] = b[j];
				x--;
			}
			else {
				emp[i]++;
			}
		}
	}
}

void up(int a[D][C], int b[C], int emp[D], int d, int c, int &dir)
{
	int t, x, m;
	dir = 2;

	for (int i = 0; i < c; i++) {
		t = 0;
		m = 0;
		x = 0;

		for (int r = 0; r < d; r++) {
			b[r] = 0;
		}

		for (int o = 0; o < c; o++) {
			if (a[o][i] != 0) {
				b[t] = a[o][i];
				t++;
				m = 1;
				a[o][i] = 0;
			}
		}

		if (t > 1) {
			for (int p = 0; p < t; p++) {
				if (b[p] == b[p + 1]) {
					b[p] *= 2;
					b[p + 1] = 0;
					p++;
				}
			}
		}
		else if (m == 1) {
			a[0][i] = b[0];
			emp[i] = 3;
			continue;
		}

		for (int j = 0; j < d; j++) {
			if (b[j] != 0) {
				a[x][i] = b[j];
				x++;
			}
			else {
				emp[i]++;
			}
		}
	}
}

void down(int a[D][C], int b[C], int emp[D], int d, int c, int &dir)
{
	int t, x, m;
	dir = 3;

	for (int i = 0; i < c; i++) {
		t = 0;
		m = 0;
		x = d - 1;

		for (int r = 0; r < d; r++) {
			b[r] = 0;
		}

		for (int o = c - 1; o >= 0; o--) {
			if (a[o][i] != 0) {
				b[t] = a[o][i];
				t++;
				m = 1;
				a[o][i] = 0;
			}
		}

		if (t > 1) {
			for (int p = 0; p < t; p++) {
				if (b[p] == b[p + 1]) {
					b[p] *= 2;
					b[p + 1] = 0;
					p++;
				}
			}
		}
		else if (m == 1) {
			a[d - 1][i] = b[0];
			emp[i] = 3;
			continue;
		}

		for (int j = 0; j < d; j++) {
			if (b[j] != 0) {
				a[x][i] = b[j];
				x--;
			}
			else {
				emp[i]++;
			}
		}
	}
}