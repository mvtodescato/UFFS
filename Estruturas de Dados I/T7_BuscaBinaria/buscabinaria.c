#include <stdio.h>

int buscabinaria(int v[], int n, int inf, int sup){
	int meio = (inf + sup) / 2;
	if(n == v[meio]){
		return meio;
	}
	else if(inf>=sup){
		return -1;
	}
	else{
		if(v[meio] > n){
			buscabinaria(v,n,inf,meio-1);
		}
		else {
			buscabinaria(v,n,meio+1,sup);
		}
	}
}
	





int main (){
	int v[10] = {1,2,3,4,5,6,7,8,9,10};
	int n, loc;
	printf("Qual numero deseja buscar?\n");
	scanf("%d", &n);
	loc = buscabinaria(v,n,0,9);
	if(loc == -1){
		printf("Não encontrado\n");
	}
	else{	
		printf("loc = %d\n", loc);
	}
}
