#include "2048.h"

int main()
{
	char select;
	int a[D][C], b[C], emp[D] = { 0 }, d, c, dir;
	d = 4;
	c = 4;

	COORD coord;
	coord.X = 0;
	coord.Y = 0;

	srand(time(0));

	FirstRoll(a, d, c);

	cout << "\n\n\n A - Move Left";
	cout << "\n D - Move Right";
	cout << "\n W - Move Up";
	cout << "\n S - Move Down";
	cout << "\n X - Exit";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	while (1) {
		select = getch();

		switch (select)
		{
			case 'A':
			case 'a':
			{
				RefreshScreen(a, d, c);
				left(a, b, emp, d, c, dir);
				RandomNum(a, emp, d, c, dir);
				UpdateRoll(a, d, c);
				break;
			}

			case 'D':
			case 'd':
			{
				RefreshScreen(a, d, c);
				right(a, b, emp, d, c, dir);
				RandomNum(a, emp, d, c, dir);
				UpdateRoll(a, d, c);
				break;
			}

			case 'S':
			case 's':
			{
				RefreshScreen(a, d, c);
				down(a, b, emp, d, c, dir);
				RandomNum(a, emp, d, c, dir);
				UpdateRoll(a, d, c);
				break;
			}

			case 'W':
			case 'w':
			{
				RefreshScreen(a, d, c);
				up(a, b, emp, d, c, dir);
				RandomNum(a, emp, d, c, dir);
				UpdateRoll(a, d, c);
				break;
			}

			case 'X':
			case 'x':
			{
				exit(0);
				break;
			}
		}
	}

	return 0;
}
