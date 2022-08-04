//Возведение числа в степень
#include<stdio.h>
int main(){

    int x, n, y=1;

    scanf("%d", &x);//вводим наше число
    scanf( "%d", &n); //вводим степень

    while (n){
        if (n & 1)
            y = y*x;
        n >>= 1;
        x = x*x;
    }
    printf("%d\n", y);  //полученное число

    return 0;
}