#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 100

typedef struct produto{
	int codigo;
	char nome[TAM];
	float preco;
}tp_produto;

typedef struct nodo{
	tp_produto produto;
	struct nodo *prox;
}tp_nodo;

tp_nodo *push(tp_nodo *p){
		tp_nodo *n = (tp_nodo *) malloc(sizeof(tp_nodo));
		n->prox = p;
		printf("Código: ");
		scanf("%d",&n->produto.codigo);
		__fpurge(stdin);
		printf("Nome: ");
		fgets(n->produto.nome,TAM,stdin);
		__fpurge(stdin);
		printf("Preço: ");
		scanf("%f",&n->produto.preco);
		return n;
}
void display(tp_nodo *p){
	tp_nodo *a;
	for(a=p; a!=NULL;a = a->prox){
		printf("CODIGO: %d\n",a->produto.codigo);
		printf("\t\tNOME: %s",a->produto.nome);
		printf("\t\tPREÇO: R$%.2f\n",a->produto.preco);
		
	}
}
tp_nodo *pop(tp_nodo *p){
	int x;
	printf("Qual produto deseja excluir?(código)\n");
	scanf("%d", &x);
	tp_nodo *a,*ant;
	a=p;
	if(p->produto.codigo == x && p->prox == NULL){
		free(p);
		return NULL;
	}
	else{
		for(; p!=NULL;p = p->prox){
			if(p->produto.codigo == x){
				if(p==a){
					a=p->prox;
					free(p);
				}
				else{
					ant->prox=p->prox;
					free(p);
				}
			}
			
			else
				ant=p;
			
		}
		return a;
	}
}
int main(){
	tp_nodo *p= NULL;
	int a;
	do{
		printf("\t\tMENU\n");
		printf("[1] - Inserir um produto\n");
		printf("[2] - Excluir um produto\n");
		printf("[3] - Listar elementos\n");
		printf("[0] - SAIR\n");
		scanf("%d", &a);
		system("clear");
		switch(a){
			case 1:
				p=push(p);
				system("clear");
				break;
			case 2:
				if(p==NULL){
					printf("Não existe nada cadastrado\n");
					getchar();
					getchar();
					system("clear");
				}
				else{
					p=pop(p);
					getchar();
					getchar();
					system("clear");
				}
				break;
			case 3:
				display(p);
				getchar();
				getchar();
				system("clear");
				break;
		}
	}while(a!=0);
	
	return 0;
}
