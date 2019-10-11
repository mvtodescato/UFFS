#include <stdio.h>
typedef struct{
    int valor, fita, estado;
}INST;
void printar(int vetor[],int estado,int cont, int tam){
    int i;
    if(estado<7){
        printf("(q%d,(",estado);
    }
    else if(estado == 7){
        printf("(qsim, (");
    }
    else{
        printf("(qnao, (");
    }
    for(i=0;i<=cont;i++){
        printf("%d",vetor[i]);
    }
    printf(",");
    if(cont+1<tam){
        for(i=cont+1;i<tam;i++){
            printf("%d",vetor[i]);
        }
    }
    else{
        printf("3");
    }
    printf("))");
    if(estado<7){
        printf(" ->  ");
    }
}
int main(){
	INST matriz_func[6][4];
    int i,j,linha=0,cont=0,aux;       //0,1 são valores convencionais, 2 representa o inicial, 3 representa o espaço em branco
    FILE *fp;
    fp = fopen("matriz.txt", "r");
    rewind(fp);
    for(i=0;i<6;i++){
        for(j=0;j<4;j++){
            fscanf (fp, "%d", &matriz_func[i][j].valor);
            fscanf (fp, "%d", &matriz_func[i][j].fita);
            fscanf (fp, "%d", &matriz_func[i][j].estado);
        }
    }
	int nVet;
	int aux2;
	printf("Qual o tamanho da entrada?\n");
	scanf("%d", &nVet);
	int vet[nVet+4];
	printf("Entre com os valores separados: \n");
	vet[0] = 2;
	for(i=1;i<=nVet;i++){
        scanf("%d",&vet[i]);
	}
	for(i=nVet+1;i<nVet+4;i++){
        vet[i] = 3;
	}

    while(linha<7){
        printar(vet,linha,cont,nVet+1);
        aux2 = linha;
        aux = vet[cont];
        vet[cont] = matriz_func[linha][vet[cont]].valor;
        cont += matriz_func[linha][vet[cont]].fita;
        linha = matriz_func[linha][aux].estado;
        if(aux2 == 3 & aux == 1 || aux2 == 4 & aux == 0){
            cont -= 2;
        }

    }
    printar(vet,linha,cont,nVet+1);
}
