//Элементы массива не убывают. Двоичным поиском определить первую позицию, где в этот массив можно вставить данное число х
#include<stdlib.h>
#include<stdio.h>
int main(){
        int n = 0, first, i, end, mid;       //n-размерность first-первый элемент end-последний mid- середина
        float x, *Mas;                        // х -число которое нужно поставить

        scanf("%f", &x);    //наше число, которое нужно вставить
        scanf("%d", &n);  //размерность

        n++;
        Mas = (float*)malloc(n*sizeof(float));
        for (i = 1; i < n; i++){    // заполняем массив
            scanf("%f", &Mas[i]);
        }
        first = 0;
        end = n - 1;
        mid = (first + end) / 2;      //находим середину
        while ((end - first) != 1){
            if (x>Mas[mid])
                first = mid;
            else
                end = mid;

            mid = (first + end) / 2;

        }
        if (x >= Mas[mid])           //выводим либо first либо end
            printf("%d", end);
        else
            printf("%d", first);
    return 0;
}
