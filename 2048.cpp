#include "D:\2048.h"

int main()
{
	srand(time(0));
	int a[4][4] ;
	int d = 4, c = 4;
	char c;
	cout << "\n WELCOM TO GAME 2048";
	cout << "\n======================";
	cout << "\n A - Move Left";
	cout << "\n D - Move Right";
	cout << "\n W - Move Up";
	cout << "\n S - Move Down";
	cout << "\n X - Exit";
	
	while(1) {
		cout << "\n Enter selection: ";
		cin >> c;

		switch (c)
		{
			case 'A':
			case 'a': {

				break;	
			}

			case 'D':
			case 'd': {

				break;	
			}

			case 'S':
			case 's': {

				break;	
			}

			case 'W':
			case 'w': {

				break;	
			}

			case 'X':
			case 'x': {
				exit(0);
				break;
			}

			default: printf("Khong co nut %c", c) ;

		}
	}

	return 0;
}