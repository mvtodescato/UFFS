#include <stdio.h>
#include <stdlib.h>
int main(){
int a,i;
    printf("Quantos valores deseja alocar?\n");
    scanf("%d", &a);
    int * p = (int *)calloc(a, sizeof(int));
    for(i=0;i<a;i++){
        printf("Digite o valor da posição %d\n",i);
        scanf("%d",(p + i));
    }
    for(i=0;i<a;i++){
        printf("Valor:%d\tPosição: %d\n",*(p+i), p+i);
    }
    free(p);
}
