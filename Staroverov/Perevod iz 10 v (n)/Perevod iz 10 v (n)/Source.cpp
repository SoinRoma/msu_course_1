#include<stdlib.h>
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int S = 0, b = 1, x, n, ch = 0;//x-число n-система счисления
	scanf("%d", &x);
	scanf("%d", &n);
	while (x != 0)
	{
		S = S + ((x%n)*b);
		b = b * 10;
		x = x / n;
		ch = ch + 1;   //сколько чисел
	}
	printf("Chislo %d %d\n", S, ch);
	getchar();
	getchar();
	return 0;
}