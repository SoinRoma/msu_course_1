#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int main()
{
	int i, j, k = 1, n, begin, end;
	int **M;
	printf("Vvedite chislo ");
	scanf("%d", &n);
	M = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++)
		M[i] = (int*)malloc(n*sizeof(int));
	begin = 0;
	end = n;
	while (begin < end)
	{
		for (j = begin; j < end; j++)
		{
			M[begin][j] = k;
			k++;
		}
		for (j = begin + 1; j < end; j++)
		{
			M[j][end - 1] = k;
			k++;
		}
		for (j = end-2; j >= begin; j--)
		{
			M[end-1][j] = k;
			k++;
		}
		for (j = end - 2; j > begin; j--)
		{
			M[j][begin] = k;
			k++;
		}
		begin++;
		end--;
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