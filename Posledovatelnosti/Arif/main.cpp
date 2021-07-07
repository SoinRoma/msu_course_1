//Найти сумму и произведение чисел последовательности
#include<stdio.h>
int main(){
    double a=0.0, Sum=0.0, Pro=0.0;
    FILE *Int = fopen("Int.txt", "r");   //открываем один файл для ввода
    FILE *Out = fopen("Out.txt", "w");   // другой для вывода
    fscanf(Int, "%lf", &a);
    Sum = a;
    Pro = a;
    while (fscanf(Int, "%lf", &a) == 1){
        Sum = Sum + a; // Cумма
        Pro = Pro*a;  //Произведение
    }
    fprintf(Out, "Summa = %lf\n", Sum);
    fprintf(Out, "Proizvedenie = %lf",Pro);
    fclose(Int);  //закрытие
    fclose(Out);  //закрытие

    return 0;
}



