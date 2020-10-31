#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sort(int*m, int n)
{
	int i, j, t;
	for (i = 0; i < n;i++)
	for (j = 0; j < n;j++)
	if (m[j - 1]>m[j])
	{
		t = m[j - 1];
		m[j - 1] = m[j];
		m[j] = t;
	}
}
int main(void)
{
	int *m, n = 10, i;
	m = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		m[i] = rand() % n;
	sort(m, n);
	if (n<=10)
	for (i = 0; i < n; i++)
		printf("%d ", m[i]);
	for (i = 1; i < n; i++)
	if (m[i - 1]>m[i])
		printf("m[%d]>m[%d]:%d>%d\n", i - 1, i, m[i - 1], m[i]);
	printf("End\n");
	getchar();
	free(m);
}