//Бином Получить массив биномиальных коэффициентов для степени n n, последовательно вычисляя строки треугольника Паскаля
#include <stdlib.h>
#include <stdio.h>
int main(){

    int *Mas; //массив
    int n;    //n-размерность

    scanf("%d", &n);
    if (n == 0){
        printf("0"); //если n=0 то ошибка
    }
    printf("%d\n", n + 1);  //вывод количество коэффицентов (на один больше)
    Mas = (int*)malloc(n*sizeof(int));   //заполнение массива
    for (int i = 1; i <= n; i++) {
        Mas[i] = 0;
    }
    Mas[0] = 1;     //первый элемент =1
    for (int j = 1; j <= n; j++){
        for (int i = j; i >= 1; i--)
            Mas[i] = Mas[i - 1] + Mas[i];
    }
    for (int i = 0; i <= n; i++)                // вывод коэффицентов
        printf( "%d\t", Mas[i]);

    return 0;
}
