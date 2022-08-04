#include<stdio.h>
#include<stdlib.h>

void SortSliyanie(int *Mas,int first, int end)     //функция сортировки
{
    int mid,i,j;
    int *Mas2;
    if (first == end)
        return;
    mid = (first + end) / 2; // середина
    SortSliyanie(Mas, first, mid); // вызов саму себя,пока не останется один элемент
    SortSliyanie(Mas, mid + 1, end);
    i = first;  // первая половина
    j = mid + 1; // вторая
    Mas2 = (int*)malloc(end*sizeof(int)); // второй массив
    for (int k = 0; k <end - first + 1; k++){ // для всех элементов дополнительного массива
        if ((j > end) || ((i <= mid) && (Mas[i] < Mas[j]))){ //если верно то с одной части массива сортируется в новый маасив
            Mas2[k] = Mas[i];
            i++;
        }
        else{  // иначе другая половина
            Mas2[k] = Mas[j];
            j++;
        }
    }
    for (int k = 0; k < end - first + 1; k++) // полученный массив переписываем в первый массив
        Mas[first + k] = Mas2[k];
}

int main(){
    int n;
    int *Mas;

    scanf( "%d", &n);
    Mas = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)   // заполняем массив
        scanf( "%d", &Mas[i]);

    printf( "%d\n", n);  //вывод размерности массива
    SortSliyanie(Mas, 0, n - 1); // Вызыв Функции
    for (int i = 0; i < n; i++) // Вывод отсортированного массива
        printf( " %d ", Mas[i]);

    return 0;
}
