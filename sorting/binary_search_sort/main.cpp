#include<stdlib.h>
#include<stdio.h>
int main(){
    int n, first, end, temp, mid;
    int *Mas;

    scanf("%d", &n);
    Mas = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){  //заполняем массив
        scanf("%d", &Mas[i]);
    }
    printf("%d\n", n);  //вывод размерности массива
    first = 0;  //первый элемент
    end = n - 1;  //последний элемент
    for (int j = 0; j < n; j++){ //цикл решения задачи
                for (int i = 0; i < n;){
                    if ((end - first) == 1){  //проверка если между первым и последним элементом есть элементы
                        if (Mas[i] > Mas[first]){  //если элемент массива больше первого
                            temp = Mas[end];
                            Mas[end] = Mas[i];
                            Mas[i] = temp;
                            i++;
                            end = n - 1;
                            first = 0;
                        }
                        else{
                            temp = Mas[first];
                            Mas[first] = Mas[i];
                            Mas[i] = temp;
                            i++;
                            end = n - 1;
                            first = 0;
                        }
                    }
                    mid = (first + end) / 2;   //середина
                    if (Mas[i] > Mas[mid]){
                        first = mid;
                    }
                    else{
                        end = mid;
                    }
                }
            }
            for (int i = 0; i < n; i++)    //вывод отсортированного массива
                printf("%d ", Mas[i]);
    return 0;
}