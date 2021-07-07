//Во входном файле задана ДНФ. Найти ДНФ, получающуюся из нее применением всех возможных операций обобщенного склеивания (начало алгоритма Блейка).
//В выходном файле строки, соответствующие ЭК, должны быть упорядочены лексикографически.
#include<stdio.h>
#include<stdlib.h>

int SmejniyVector(char *a, char *b, int n){
    int flag = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i] && a[i] != '*' && b[i] != '*')
            flag++;
        if (flag == 2)
            break;
    }
    if (flag != 2)
        return 1;
    else
        return 0;
}

int OdinakovieString(char **str, int n, int m){
    int flag = 0;
    for (int i = 0; i < m - 1; i++){
        for (int j = 0; j < n; j++){
            if (str[m - 1][j] != str[i][j]){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            flag = 2;
            break;
        }
        flag = 0;
    }
    if (flag == 2)
        return 1;
    else
        return 0;
}

void SwapLinesAandB(char **a, int A, int B, int colum)  //меняем линии местами
{
    char temp;
    for (int i = 0; i < colum; i++){
        temp = a[A][i];
        a[A][i] = a[B][i];
        a[B][i] = temp;
    }
}

int Skleyka(char **String, int A, int B, int n, int m){  //функция для обобщенного склеивания

    int flag = 0;
    for (int i = 0; i < n; i++){
        if (String[A][i] == String[B][i]){
            String[m][i] = String[A][i];
            continue;
        }
        if (String[A][i] != String[B][i] && String[B][i] == '*'){
            String[m][i] = String[A][i];
            continue;
        }
        if (String[A][i] != String[B][i] && String[A][i] == '*'){
            String[m][i] = String[B][i];
            continue;
        }
        String[m][i] = '*';
        flag = 1;
    }
    String[m][n] = '\0';
    return flag;
}

void Sortirovka(char **a, int line, int colum){
    int k = 0;
    for (int i = 0; i < line; i++){
        for (int j = 0; j < line; j++){
            for (int q = 0; q < colum; q++){
                if (((a[i][q] - '0' >= 0 && a[j][q] - '0' < 0) || (a[i][q] == '0' && a[j][q] == '1'))){
                    k = 0;
                    break;
                }
                if (((a[i][q] - '0' < 0 && a[j][q] - '0' >= 0) || (a[i][q] == '1' && a[j][q] == '0'))){
                    k = 1;
                    break;
                }
            }
            if (k == 0)
                SwapLinesAandB(a, i, j, colum);
            k = 0;
        }
    }
}

int main(){
    int n, m, max = 1, Support = 0, SPS = 0; //n-количество переменных m-число конъюнкций     Support - переменная для смежных векторов  SPS значение склейки
    char **String;
    FILE *Int = fopen("Int.txt", "r");  //один файл для ввода,другой для вывода
    FILE *Out = fopen("Out.txt", "w");
    if (Int == NULL){  //проверка на пустоту
        fprintf(Out, "0");
    }
    else{
        fscanf(Int, "%d", &n);  //вводим данные
        fscanf(Int, "%d", &m);
        for (int i = 0; i < n; i++){
            max = max * 3;  //переполнение
        }
        max = max - m;
        String = (char**)malloc((m + max + 10)*sizeof(char*));  //запоняем массив и прописываем какие конъюнкции
        for (int i = 0; i < m + max; i++){
            String[i] = (char*)malloc((n + 1)*sizeof(char));
        }
        for (int i = 0; i < m; i++){
            fscanf(Int, "%s", String[i]);
        }
        for (int i = 0; i < m; i++){
            for (int j = i + 1; j < m; j++){
                Support = SmejniyVector(String[i], String[j], n);
                if (Support == 1){
                    SPS = Skleyka(String, i, j, n, m);
                    if (SPS == 1){
                        m++;
                        Support = OdinakovieString(String, n, m);
                        if (Support == 1)
                            m--;
                    }
                }
            }
        }
        fprintf(Out, "%d ", n);  //вывод сколько теперь перемменых после склейки
        SPS = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (String[i][j] != '*'){
                    SPS++;
                    break;
                }
            }
        }
        fprintf(Out, "%d\n", SPS);// вывод числа конъюнкций после склейки
        Sortirovka(String, m, n);
        SPS = 0;// вызываем функцию сортировки чтобы было  упорядочено лексикографически.
        for (int i = 0; i < m; i++){   //вывод полученных конъюнкций после склейки
            SPS = 0;
            for (int j = 0; j < n; j++){
                if (String[i][j] != '*'){
                    SPS = 1;
                    break;
                }
            }
            if (SPS == 1)
                fprintf(Out, "%s\n", String[i]);   //вывод самих конъюнкций
        }
    }
    fclose(Int);  //закрытие файлов
    fclose(Out);
    return 0;
}
