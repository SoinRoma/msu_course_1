#include<stdlib.h>
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int x = 0, b = 1, a, n;//a-число n-система счисления
	scanf("%d", &a);
	scanf("%d", &n);
	while (a != 0)
	{
		x = x + ((a%10)*b);
		b = b * n;
		a = a / n;
	}
	printf("Chislo %d\n", x);
	getchar();
	getchar();
	return 0;
}