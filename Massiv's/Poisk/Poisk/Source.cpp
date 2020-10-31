//Элементы массива не убывают. Двоичным поиском определить первую позицию, где в этот массив можно вставить данное число х 
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int n = 0, first, i, end, mid;       //n-размерность first-первый элемент end-последний mid- середина
		float x, *Mas;                        // х -число которое нужно поставить
		FILE *Int = fopen(argv[1], "r");          //два файла один для ввода другой для вывода
		FILE *Out = fopen(argv[2], "w");
		if (Int == NULL)                 //проверка на пустоту
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Int, "%f", &x) == 1)    //наше число, которое нужно вставить
			{
				if (fscanf(Int, "%d", &n) == 1)   //размерность
				{
					n++;
					Mas = (float*)malloc(n*sizeof(float));
					for (i = 1; i < n; i++)    // заполняем массив
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
				else
					fprintf(Out, "0");
			}
			else
				fprintf(Out, "0");
			fclose(Int);     //закрытие файлов
			fclose(Out);
		}
	}
	return 0;
}
