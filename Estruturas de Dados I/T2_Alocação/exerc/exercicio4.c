#include <stdio.h>
#include <stdlib.h>
int * uniao(int *v1, int n1, int *v2, int n2){
    int i,j=0;
    int * v3 = calloc(n1 + n2, (n1 + n2) * sizeof(int));
    for(i=0;i<n1;i++){
        *(v3+i) = *(v1+i);
    }
    for(i=n1;i<n2+n1;i++){
        *(v3+i) = *(v2+j);
        j++;
    }
    return v3;
}
int main(){
    int v1[4] = {11, 13, 45, 7}, v2[6] = {24, 4, 16, 81, 10, 12},*v3;
    int n1=4,n2=6,i;
    v3 = uniao(v1,n1,v2,n2);
    for(i=0;i<10;i++){
        printf("Vetor 3, posição %d : %d\n",i,*(v3+i));
    }
    free(v3);
}
