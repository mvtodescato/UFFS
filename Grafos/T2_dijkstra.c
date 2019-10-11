#include <stdio.h>
int main(){
    int matriz[7][7]={{0,7,0,5,0,0,0},
                  {7,0,8,9,7,0,0},
                  {0,8,0,0,5,0,0},
                  {5,9,0,0,15,6,0},
                  {0,7,5,15,0,8,9},
                  {0,0,0,6,8,0,11},
                  {0,0,0,0,9,11,0}};

    int i, j,anterior[7] = {0,0,0,0,0,0,0},dist[7] = {0,10000,10000,10000,10000,10000,10000},cont_fechados = 0,abertos[7] = {0,0,0,0,0,0,0};//fechados= 1, abertos = 0
    int aux = 1000000,contador=0;
    do{
        aux = 1000000;
        for(i=0;i<7;i++){
            if(abertos[i] == 0){
                if(dist[i]<aux){
                    aux = i;
                }
            }
        }
        abertos[aux] = 1;
        for(j=0;j<7;j++){
            if(matriz[aux][j]>0){
                if(abertos[j] == 0){
                    if(dist[aux] + matriz[aux][j] < dist[j]){
                        dist[j] = dist[aux] + matriz[aux][j];
                        anterior[j] = aux;
                    }
                }else{
                    continue;
                }
            }
        }
        contador++;
    }while(contador < 7);

    for(i=0;i<7;i++){
		printf("d%d: %d\t",i,dist[i]);
	}
	printf("\n");
	for(i=0;i<7;i++){
		printf("Vertice anterior %d: %d\t",i,anterior[i]);
	}
	printf("\n");
	printf("Melhor caminho: 6/");
	int a=6;
	while(a!=0){
        printf("%d/",anterior[a]);
        a=anterior[a];
    }

}
