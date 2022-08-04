//Подмножества числа
#include<stdio.h>
int main(){
    int  n, v;
    scanf( "%d", &n);
    if (n == 0){    //если нет элементов, то закрытие файла
        printf("0");
    }
    for (int i = 0; i < (1 << n); i++){
        for (int j = n - 1; j >= 0; j--){
            v = i &(1 << j);
            if (v != 0)
                printf("%d ", j + 1);  //вывод подмножеств
            else
                printf("0 ");
            }
            printf("\n");
        }
    return 0;
}