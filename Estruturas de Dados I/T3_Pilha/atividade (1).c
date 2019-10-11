#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

typedef struct _produto{
int cod;
char nome[TAM];
float preco;
}tp_produto;

typedef struct _pilha{
	tp_produto *info;
	int topo;
}tp_pilha;

int verifica_vazia(tp_pilha *pilha){
    if(pilha->topo == 0){
        return 1;
    }
    else
        return 0;
}
int verifica_cheia(tp_pilha *pilha,int i){
    if(pilha->topo == i){
        return 1;
    }
    else
        return 0;
}
void cadastrar_produto(tp_pilha *pilha,int i){
	pilha->info+=pilha->topo;
	printf("CODIGO: ");
	scanf("%d", &pilha->info->cod);
	__fpurge(stdin);
	printf("NOME: ");
	fgets(pilha->info->nome, TAM, stdin);
	__fpurge(stdin);
	printf("PREÇO: ");
	scanf("%f", &pilha->info->preco);
	pilha->info-=pilha->topo;
}
void retirar_produto(tp_pilha *pilha){
    pilha->topo-=1;
}
void imprimir(tp_pilha *pilha){
	int i;

        for(i=pilha->topo-1;i>=0;i--){
			pilha->info+=i;
			printf("PRODUTO[%d]:\n",i);
			printf("\t\tCodigo:%d\n",pilha->info->cod);
			printf("\t\tNome:%s",pilha->info->nome);
			printf("\t\tPreço: R$%.2f\n",pilha->info->preco);
			pilha->info-=i;
	}
	printf("Digite qualquer tecla para sair");
	getchar();
	getchar();
}



int main(){
	int i;
	printf("Quantos produtos deseja cadastrar?\n");
	scanf("%d",&i);
	system("clear");
    tp_pilha *p = (tp_pilha *) malloc(sizeof(tp_pilha));
    p->info =(tp_produto *) malloc (i*sizeof(tp_produto));
    int a;
    p->topo = 0;
    do{
    printf("\t\tMENU\n");
    printf("[1] - Cadastrar produto\n");
    printf("[2] - Excluir ultimo produto\n");
    printf("[3] - Listar produtos\n");
    printf("[0] - SAIR\n");
    scanf("%d", &a);
    system("clear");
    switch(a){
    case 1:
        if(verifica_cheia(p,i)){
            printf("Pilha Cheia\n");
            printf("Digite qualquer tecla para sair");
            getchar();
            getchar();
            break;
        }
        else{
            cadastrar_produto(p,i);
            p->topo ++;
        }
        break;
    case 2:
        retirar_produto(p);
        break;
    case 3:
        if(verifica_vazia(p)){
            printf("Sem produtos para listar\n");
            printf("Digite qualquer tecla para sair");
            getchar();
            getchar();
            break;
        }
        else{
            imprimir(p);
            break;
        }
    }
    system("clear");
    }while(a!=0);



}

