#include <stdio.h>
int acha_menor(int aux, int dist[], int abertos[]){
    int i;
    int aux2 = 1000000;
        for(i=0;i<8;i++){
            if(abertos[i] == 0){
                if(aux2 > dist[i]){
                    aux = i;
                    aux2 = dist[i];
                }
            }
        }
        return aux;
}
int main(){
    int matriz[8][8]={{0,2,0,6,5,0,0,0},
                  {2,0,7,7,0,0,0,0},
                  {0,7,0,0,6,2,0,0},
                  {6,7,0,0,0,0,0,0},
                  {5,0,6,0,0,0,4,5},
                  {0,0,2,0,0,0,4,6},
                  {0,0,0,0,4,4,0,1},
                  {0,0,0,0,5,6,1,0}};

    int i, j,anterior[8] = {0,0,0,0,0,0,0,0},dist[8] = {0,10000,10000,10000,10000,10000,10000,10000},cont_fechados = 0,abertos[8] = {0,0,0,0,0,0,0,0};//fechados= 1, abertos = 0
    int aux = 1000000,contador=0;
    do{
        aux = 1000000;
        aux = acha_menor(aux,dist,abertos);
        abertos[aux] = 1;
        for(j=0;j<8;j++){
            if(matriz[aux][j]>0){
                if(abertos[j] == 0){
                    if(matriz[aux][j]< dist[j]){
                        dist[j] = matriz[aux][j];
                        anterior[j] = aux;
                    }
                }else{
                    continue;
                }
            }
        }
        contador++;
    }while(contador < 8);

    for(i=0;i<8;i++){
		printf("d%d: %d\t",i,dist[i]);
	}
	printf("\n");
	for(i=0;i<8;i++){
		printf("Vertice anterior %d: %d\t",i,anterior[i]);
	}
	printf("\n");
	printf("Arestas da arvore: ");
	for(i=1;i<8;i++){
        printf("(%d,%d)\t",i,anterior[i]);
	}

}
