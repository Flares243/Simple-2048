#include "2048.h"

int main()
{
	char select;
	int a[D][C], b[C], emp[D] = { 0 }, d, c, dir;
	d = 4;
	c = 4;

	srand(time(0));

	FirstRoll(a, d, c);

	cout << "\n\n\n\n\n\n\tA - Move Left";
	cout << "\n\tD - Move Right";
	cout << "\n\tW - Move Up";
	cout << "\n\tS - Move Down";
	cout << "\n\tX - Exit";

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