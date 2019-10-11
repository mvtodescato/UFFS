#include <stdio.h>
#include <stdlib.h>
int main(){
    int a=1,i,j,aux=5;
    int * p = (int *)calloc(5, sizeof(int));
    for(i=0;i<=aux;i++){
        if(i==aux){
            aux+=5;
            int *p2 = realloc(p,aux * sizeof(int));
            p=p2;
            printf("Alocado\n");
            //tinha colocado um free no p2 porem causava um erro no programa
        }
        scanf("%d",(p + i));
        if(*(p+i)==0){
            for(j=0;j<i;j++){
            printf("Posição: %d\t Valor: %d\n",(p+j),*(p+j));

            }
        break;
        }
    }
    free(p);

}
