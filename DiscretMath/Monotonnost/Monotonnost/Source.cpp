//Во входном файле задана функция вектором своих значений. Монотонна ли она?
// метод путем сравнения соседних наборов
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#pragma warning (disable:4996)

int main(int argc, char * argv[])
{
	int k, n, i, j, p, flag = 1;   //  flag=1 изначально монотонная
	char *String;         //Строковый массив
	//FILE *Int = fopen("Int.txt" , "r");  //один файл для ввода,другой для вывода
	//FILE *Out = fopen("Out.txt" , "w");
	FILE *Int = fopen(argv[1], "r");  //один файл для ввода,другой для вывода
	FILE *Out = fopen(argv[2], "w");
	if (Int == NULL)  //проверка на пустоту
	{
		fprintf(Out, "0");
	}
	else
	{
		fscanf(Int, "%d", &k);//вводим наше число
		fscanf(Int, "%d", &n);  //вводим степень
		//p = 1 << n;  //возведение в степень
		String = (char*)malloc((p + 1)*sizeof(char));   //память под массив строк (p+1) потому что у строки есть конец
		fscanf(Int, "%s", String);
		for (i = 0; i < p - 1; i++)
		{
			for (j = i + 1; j < p; j++)   //второй цикл будет искать соседний и сравнивать
			{
				if ((i & j) == i && String[i] - '0' > String[j] - '0') 
// i является подмаской j и нарушается монотонность  При помощи конъюнуции определяем какие можно сравнивать а какие нет и дальше смотрим на значение наборов
				{                   //из чара в инт
					flag = 0; 
					break;
				}
			}
		}
		if (flag == 0)     //не монотонная
			fprintf(Out, "0");
		else               //монотонная
			fprintf(Out, "1");

		fclose(Int);  //закрытие файлов
		fclose(Out);
	}
	return 0;
}