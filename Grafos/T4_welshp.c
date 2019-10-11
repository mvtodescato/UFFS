#include <stdio.h>
int main(){
    int matriz[11][11]={{0,1,0,0,0,0,0,1,0,0,0},
                        {1,0,0,1,0,0,0,0,0,0,0},
                        {0,0,0,1,0,0,0,0,0,0,0},
                        {0,1,1,0,0,0,0,0,1,0,1},
                        {0,0,0,0,0,1,0,0,0,0,1},
                        {0,0,0,0,1,0,1,0,0,0,0},
                        {0,0,0,0,0,1,0,1,0,0,1},
                        {1,0,0,0,0,0,1,0,1,1,1},
                        {0,0,0,1,0,0,0,1,0,1,0},
                        {0,0,0,0,0,0,0,1,1,0,1},
                        {0,0,0,1,1,0,1,1,0,1,0}};
    int cor_vet[11] = {0,0,0,0,0,0,0,0,0,0,0}, ordem_vet[11]={7,10,3,6,8,9,0,1,4,5,2};
    int i,j,aux=0,cont = 1,fail = 0;
    for(i=0;i<11;i++){
        if(cor_vet[ordem_vet[i]] == 0){
            cor_vet[ordem_vet[i]] = cont;
            for(j=i+1;j<11;j++){
                if(cor_vet[ordem_vet[j]] == 0){
                    for(aux=0;aux<11;aux++){
                        if(matriz[ordem_vet[j]][aux] == 1){
                            if(cor_vet[aux] == cont){
                                fail ++;
                            }
                        }
                    }
                    if(fail == 0){
                        cor_vet[ordem_vet[j]] = cont;
                    }
                    fail = 0;
                }
            }
            cont ++;
        }
    }
    for(i=0;i<11;i++){
        printf("Cor vet %d = %d\n",ordem_vet[i],cor_vet[ordem_vet[i]]);
    }

}
