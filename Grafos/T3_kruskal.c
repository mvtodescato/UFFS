#include <stdio.h>
int muda_raiz(int a,int b,int vet[]){
    int i;
    for(i=0;i<9;i++){
        if(vet[i] == a){
            vet[i] = b;
        }
    }
}
int main(){
	int matriz[8][11]={{0,3,3,4,0,0,0,0,0,0,0},
					   {0,3,0,0,0,0,0,0,0,0,0},
					   {0,0,0,4,0,0,0,0,8,8,0},
					   {0,0,3,0,0,0,0,0,0,0,8},
					   {0,0,0,0,0,7,7,0,8,0,0},
					   {0,0,0,0,4,0,0,7,0,8,8},
					   {2,0,0,0,4,7,0,0,0,0,0},
					   {2,0,0,0,0,0,7,7,0,0,0}};

	int vetor_estado[8]={0,0,0,0,0,0,0,0};
	int vetor_arvore[8]={-1,-1,-1,-1,-1,-1,-1,-1};
	int par_vertices[14],i,j,v1=-1,v2=-1,cont_pares = 0,aux,custo=0;

	for(j=0;j<11 && cont_pares<14;j++){
		for(i=0;i<8;i++){
			if(matriz[i][j] > 0 && v1 == -1){
				v1 = i;
				continue;
			}
			if(matriz[i][j] > 0){
				v2 = i;
				continue;
			}
		}
		if(vetor_arvore[v2] == -1){
			if(vetor_arvore[v1] == -1){
                custo+=matriz[v2][j];
				vetor_arvore[v1] = v2;
				vetor_arvore[v2] -= 1;
				par_vertices[cont_pares]= v2;
				cont_pares ++;
				par_vertices[cont_pares]= v1;
				cont_pares ++;

			}
			else{
				if(vetor_arvore[v1]<-1){
					vetor_arvore[v2] = v1;
					vetor_arvore[v1] -= 1;
					par_vertices[cont_pares] = v1;
					cont_pares ++;
					par_vertices[cont_pares] = v2;
					cont_pares ++;
					custo+=matriz[v1][j];
				}
				else{
					vetor_arvore[v2] = vetor_arvore[v1];
					vetor_arvore[vetor_arvore[v1]] -= 1;
					par_vertices[cont_pares] = v1;
					cont_pares ++;
					par_vertices[cont_pares] = v2;
					cont_pares ++;
					custo+=matriz[v1][j];
				}
			}
		}
		else{
            if(vetor_arvore[v1] == vetor_arvore[v2] || vetor_arvore[v1] == v2 || vetor_arvore[v2] == v1){

            }
			else if(vetor_arvore[v1] == -1){
				vetor_arvore[v1] = vetor_arvore[v2];
				vetor_arvore[vetor_arvore[v2]] -= 1;
				par_vertices[cont_pares]= v2;
				cont_pares ++;
				par_vertices[cont_pares]= v1;
				cont_pares ++;
				custo+=matriz[v1][j];
			}
			else{
				if(vetor_arvore[v2]<-1 && vetor_arvore[v1]<-1){
					if(abs(vetor_arvore[v1])>abs(vetor_arvore[v2])){
						vetor_arvore[v1]+=vetor_arvore[v2];
						muda_raiz(v2,v1,vetor_arvore);
						par_vertices[cont_pares]= v1;
						cont_pares ++;
						par_vertices[cont_pares]= v2;
						cont_pares ++;
						custo+=matriz[v1][j];
					}
					else{
						vetor_arvore[v2]+=vetor_arvore[v1];
						muda_raiz(v1,v2,vetor_arvore);
						par_vertices[cont_pares]= v2;
						cont_pares ++;
						par_vertices[cont_pares]= v1;
						cont_pares ++;
						custo+=matriz[v1][j];
					}
				}
				else if(vetor_arvore[v1]<-1){
					vetor_arvore[v1]+=vetor_arvore[v2];
					muda_raiz(vetor_arvore[v2],v1,vetor_arvore);
					par_vertices[cont_pares]= v1;
					cont_pares ++;
					par_vertices[cont_pares]= v2;
					cont_pares ++;
					custo+=matriz[v1][j];
				}
				else{
					if(abs(vetor_arvore[vetor_arvore[v1]]) > abs(vetor_arvore[vetor_arvore[v2]])){
						vetor_arvore[vetor_arvore[v1]]+=vetor_arvore[vetor_arvore[v2]];
						muda_raiz(vetor_arvore[v2],vetor_arvore[v1],vetor_arvore);
						par_vertices[cont_pares]= v1;
						cont_pares ++;
						par_vertices[cont_pares]= v2;
						cont_pares ++;
						custo+=matriz[v1][j];
					}
					else{
						vetor_arvore[vetor_arvore[v2]]+=vetor_arvore[vetor_arvore[v1]];
						vetor_arvore[vetor_arvore[v1]] = vetor_arvore[v2];
						muda_raiz(vetor_arvore[v1],vetor_arvore[v2],vetor_arvore);
						par_vertices[cont_pares]= v2;
						cont_pares ++;
						par_vertices[cont_pares]= v1;
						cont_pares ++;
						custo+=matriz[v1][j];
					}

				}
			}

		}
		v1 = -1;
		v2 = -1;
	}
	for(i=0;i<8;i++){
        printf("V%d = %d   ",i,vetor_arvore[i]);
	}
	printf("\nCusto: %d",custo);
	printf("\nPares: \n");
	for(i=0;i<14;i+=2){
        printf("(%d,%d) ", par_vertices[i],par_vertices[i+1]);
	}
}
