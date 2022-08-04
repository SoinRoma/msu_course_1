#include <stdio.h>

int main(){

    int  n,  p, n1, n2;

    scanf("%d", &n);
    for (int i = 1, t = 0; t < n; i++){
        p = 1;
        for (int j = 0; j < 8; j++){
            n1 = i&(1 << j);
            n2 = i&(1 << (15 - j));
            if (!(((n1 == 0) && (n2 == 0)) || ((n1 != 0) && (n2 != 0))))
                p = 0;
            }
            if (p == 1){
                printf("%d", i);
                printf("\n");
                t++;
            }
        }
    return 0;
}

