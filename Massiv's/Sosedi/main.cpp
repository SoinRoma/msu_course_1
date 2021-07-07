//Каждый элемент массива заменить на полусумму соседей (кроме первого и последнего)
#include<stdlib.h>
#include<stdio.h>
int main(){

    int n;    //n-размерность
    float *Mas, t1 = 0, t2 = 0;  //t1 t2 -переменные

    scanf("%d", &n);//считываем размерность
    printf( "%d\n", n);
    Mas = (float*)malloc(n*sizeof(float));
    for (int i = 0; i < n; i++){ //заполняем массив
        scanf("%f", &Mas[i]);
    }
    for (int i = 0; i < n - 1; i++){
        t1 = t2;
        t2 = (Mas[i] + Mas[i + 2]) / (2); //полусумма крайних
        if (i>0)    //проверка на сбрасывание,чтобы считывался со старого элемента массива а не нового
            Mas[i] = t1;
    }
    for (int i = 0; i < n; i++) //вывод нового массива
        printf("%f\n", Mas[i]);

    return 0;
}