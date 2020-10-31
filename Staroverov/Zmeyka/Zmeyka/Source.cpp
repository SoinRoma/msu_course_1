#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int main()
{
	int i, j, k = 1, n;
	int **M;
	printf("Vvedite chislo ");
	scanf("%d", &n);
	M = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++)
		M[i] = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			for (j = 0; j < n; j++)
			{
				M[i][j] = k;
				k++;
			}
		}
		else
		{
			for (j = n - 1; j >= 0; j--)
			{
				M[i][j] = k;
				k++;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", M[i][j]);
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}