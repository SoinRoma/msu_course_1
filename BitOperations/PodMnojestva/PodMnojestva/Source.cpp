//Подмножества числа 
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char *argv[])
{
	//if (argc >1)
	//{
	int  n, i, j, v;
	FILE *Int = fopen("Int.txt", "r");  //один файл для ввода, другой для вывода
	FILE *Out = fopen("Out.txt", "w");
	if (Int == NULL)     //проверка на пустоту файла
	{
		fprintf(Out, "0");
	}
	if (fscanf(Int, "%d", &n) == 1)
	{
		if (n == 0)    //если нет элементов, то закрытие файла
		{
			fprintf(Out, "0");
		}
		for (i = 0; i < (1 << n); i++)
		{
			for (j = n - 1; j >= 0; j--)
			{
				v = i &(1 << j);
				if (v != 0)
					fprintf(Out, "%d ", j + 1);  //вывод подмножеств
				else
					fprintf(Out, "0 ");
			}
			fprintf(Out, "\n");
		}
	}
	else
		fprintf(Out, "0");
	fclose(Int);   //закрытие файлов
	fclose(Out);
	//}
	return 0;
}