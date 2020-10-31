//Сортировка бинарными вставками
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char* argv[])
{
		int n, i, j, first, end, temp, mid;
		int *Mas;
		FILE *Int = fopen("Int.txt", "r");  //один фал для ввода ,другой для вывода
		FILE *Out = fopen("Out.txt", "w");
		if (Int == NULL)   //провека файла на пустоту
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Int, "%d", &n) == 1)
			{
				fprintf(Out, "%d\n", n);  //вывод размерности массива
				Mas = (int*)malloc(n*sizeof(int));
				for (i = 0; i < n; i++)  //заполняем массив
				{
					fscanf(Int, "%d", &Mas[i]);
				}
				first = 0;  //первый элемент
				end = n - 1;  //последний элемент
				for (j = 0; j < n; j++)  //цикл решения задачи
				{
					for (i = 0; i < n;)
					{
						if ((end - first) == 1)  //проверка если между первым и последним элементом есть элементы
						{
							if (Mas[i] > Mas[first])   //если элемент массива больше первого
							{
								temp = Mas[end];
								Mas[end] = Mas[i];
								Mas[i] = temp;
								i++;
								end = n - 1;
								first = 0;
							}
							else                  //иначе
							{
								temp = Mas[first];
								Mas[first] = Mas[i];
								Mas[i] = temp;
								i++;
								end = n - 1;
								first = 0;
							}
						}
						mid = (first + end) / 2;   //середина
						if (Mas[i] > Mas[mid])
						{
							first = mid;
						}
						else
						{
							end = mid;
						}
					}
				}
				for (i = 0; i < n; i++)    //вывод отсортированного массива
					fprintf(Out, "%d\t", Mas[i]);
			}
			else
				fprintf(Out, "0");
		}
		fclose(Int);   //закрытие файлов
		fclose(Out);
	return 0;
}
























/*

if (fscanf(Int, "%f", &x) == 1)
{
	if (fscanf(Int, "%d", &n) == 1);
	{
		n++;
		Mas = (float*)malloc(n*sizeof(float));
		for (i = 1; i < n; i++)
		{
			fscanf(Int, "%f", &Mas[i]);
		}
		first = 0;
		end = n - 1;
		mid = (first + end) / 2;      //находим середину
		while ((end - first) != 1)
		{
			if (x>Mas[mid])
				first = mid;
			else
				end = mid;

			mid = (first + end) / 2;

		}
		if (x >= Mas[mid])           //выводим либо first либо end
			fprintf(Out, "%d", end);
		else
			fprintf(Out, "%d", first);
	}
}
fclose(Int);     //закрытие
fclose(Out);
		}/*/