#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

void GoTo(SHORT posX, SHORT posY )
{
	COORD coord;
	coord.X = posX;
	coord.Y = posY;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Dem(int a[4][4], int n)
{
	int dem = 0;
	while (n >= 21)
	{
		n /= 10;
			dem++;
	}
	for (int i = 0; i < dem + 21; i++)
	{
		cout << " ";
	}
	GoTo(0, 0);
}

int main()
{
	int a[4][4],n;
	GoTo(0 , 0);
	Dem(a, n);
	_getch();
	return 0;


}