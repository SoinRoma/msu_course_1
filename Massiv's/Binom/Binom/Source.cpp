//Бином Получить массив биномиальных коэффициентов для степени n n, последовательно вычисляя строки треугольника Паскаля
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
int main(int argc,char *argv[])
{
	//if (argc > 1)
	//{
		int *Mas;    //массив
		int n, i, j;    //n-размерность
		FILE *Int = fopen("Int.txt", "r");  //два файла один для ввода другой для вывода
		FILE *Out = fopen("Out.txt", "w");
		if (Int == NULL)   //проверка на пустоту
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Int, "%d", &n) == 1)
			{
				if (n == 0)
				{
					fprintf(Out, "0"); //если n=0 то ошибка
				}
				fprintf(Out, "%d\n", n + 1);  //вывод количество коэффицентов (на один больше)
				Mas = (int*)malloc(n*sizeof(int));   //заполнение массива
				for (i = 1; i <= n; i++)
					Mas[i] = 0;
				Mas[0] = 1;     //первый элемент =1
				for (j = 1; j <= n; j++)
				{
					for (i = j; i >= 1; i--)
						Mas[i] = Mas[i - 1] + Mas[i];
				}
				for (i = 0; i <= n; i++)                // вывод коэффицентов
					fprintf(Out, "%d\t", Mas[i]);
			}
			else
				fprintf(Out, "0");
		}
		fclose(Int);   //закрытие файлов
		fclose(Out);
	//}
		return 0;
}
