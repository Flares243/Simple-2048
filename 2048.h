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

void FirstRoll(int a[][], int d, int c, int &emp)
{
	int m = 0;

	for (int i = 0; i < d; i++) {
		for (int e = 0; e < c; e++) {
			if (rand() % 16 == 1 && m < 2) {
				a[i][e] = 2;
				m++;
			}
			else {
				a[i][e] = 0;
				emp++;
			}

			printf("%d\t", a[i][e]);
		}
		cout << "\n";
	}
}

void UpdateRoll(int a[][], int d, int c)
{
	for (int i = 0; i < d; i++) {
		for (int e = 0; e < c; e++) {
			printf("%d\t", a[i][e]);
		}
		cout << "\n";
	}
}

void Left(int a[][], int d, int c)
{
	
}