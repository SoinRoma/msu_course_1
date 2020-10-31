//Каждый элемент массива заменить на полусумму соседей (кроме первого и последнего)
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char *argv[])
{
	//if (argc > 1)
	//{
		int n = 0, i;    //n-размерность
		float *Mas, t1 = 0, t2 = 0;  //t1 t2 -переменные
		FILE *Int = fopen("Int.txt", "r"); //открытие файлов
		FILE *Out = fopen("Out.txt", "w");
		if (Int == NULL)  //проверка на пустоту
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Int, "%d", &n) == 1)  //считываем размерность
			{
				fprintf(Out, "%d\n", n);
				Mas = (float*)malloc(n*sizeof(float));
				for (i = 0; i < n; i++) //заполняем массив
				{
					fscanf(Int, "%f", &Mas[i]);
				}
				for (i = 0; i < n - 1; i++)
				{
					t1 = t2;
					t2 = (Mas[i] + Mas[i + 2]) / (2); //полусумма крайних
					if (i>0)    //проверка на сбрасывание,чтобы считывался со старого элемента массива а не нового
					{
						Mas[i] = t1;
					}
				}
				for (i = 0; i < n; i++) //вывод нового массива
				{
					fprintf(Out, "%f\n", Mas[i]);
				}
			}
			else
				fprintf(Out, "0");
			fclose(Int);   //закрытие файлов
			fclose(Out);
		}
	//}
	return 0;
}