//Сортировка Слиянием
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

void SortSliyanie(int *Mas,int first, int end)     //функция сортировки
{
	int mid,i,j,k;
	int *Mas2;
	if (first == end)  
		return;
	mid = (first + end) / 2; // середина
	SortSliyanie(Mas, first, mid); // вызов саму себя,пока не останется один элемент
	SortSliyanie(Mas, mid + 1, end);
	i = first;  // первая половина
	j = mid + 1; // вторая
	Mas2 = (int*)malloc(end*sizeof(int)); // второй массив
	for (k = 0; k <end - first + 1; k++) // для всех элементов дополнительного массива
	{
		if ((j > end) || ((i <= mid) && (Mas[i] < Mas[j]))) //если верно то с одной части массива сортируется в новый маасив
		{
			Mas2[k] = Mas[i];
			i++;
		}
		else   // иначе другая половина
		{
			Mas2[k] = Mas[j];
			j++;
		}
	}
	for (k = 0; k < end - first + 1; k++) // полученный массив переписываем в первый массив
		Mas[first + k] = Mas2[k];
}
//===========================================================================
int main(int argc,char *argv[])
{
	//if (argc>1)
	//{
		int n, i;
		int *Mas;
		FILE *Intt = fopen("Intt.txt", "r"); //открытие одного файла для ввода другого для вывода
		FILE *Out = fopen("Out.txt", "w");
		if (Intt == NULL) //проверка на пустоту
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Intt, "%d", &n) == 1)
			{
				fprintf(Out, "%d", n);  //вывод размерности массива
				Mas = (int*)malloc(n*sizeof(int));
				for (i = 0; i < n; i++)   // заполняем массив
				{
					fscanf(Intt, "%d", &Mas[i]);
				}
				SortSliyanie(Mas, 0, n - 1); // Вызыв Функции
				fprintf(Out, "\n");
				for (i = 0; i < n; i++) // Вывод отсортированного массива
					fprintf(Out, " %d ", Mas[i]);
			}
			else    //если нету размерности
				fprintf(Out, "0");
		}
		fclose(Intt); //Закрытие
		fclose(Out);
	//}
	return 0;
}
