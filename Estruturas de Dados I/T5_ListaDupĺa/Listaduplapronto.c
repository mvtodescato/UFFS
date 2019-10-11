#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct produto{
	int codigo;
	char nome[20];
	float preco;
} tpProduto;

typedef struct nodo{
	tpProduto produto;
	struct nodo *next;
	struct nodo *prev;
} tpNodo;

typedef struct lista{
	int nItens;
	tpNodo *first;
	tpNodo *last;
} tpLista;
tpLista *push(tpLista *l){
	tpNodo *novo = malloc(sizeof(tpNodo));
		l->nItens++;
		printf("Digite o código: ");
		scanf("%d", &novo->produto.codigo);
		printf("Digite o nome: ");
		__fpurge(stdin);
		fgets(novo->produto.nome, 20, stdin);
		printf("Digite o preço: ");
		scanf("%f", &novo->produto.preco);
	if(l->nItens==1){
		novo->next = NULL;
		novo->prev = NULL;		
		l->first = novo;
		l->last = novo;
	}
	else{
		(l->first)->prev = novo;
		novo->next = l->first;
		novo->prev = NULL;
		l->first = novo;
	}
	return l;

}

void pop(tpLista *l){ 
	int codigo;
	printf("Digite o codigo do produto a ser excluido: ");
	scanf("%d",&codigo);
	tpNodo *nodo = l->first;
	if(l->nItens==1){
		l->first=NULL;
		l->last=NULL;
		l->nItens--;
		free(nodo);
					
	}	
	else{
		for( ; nodo!=NULL ; nodo=nodo->next){
			if(nodo->produto.codigo==codigo){
				if(nodo == l->first){
					l->first = nodo->next;
					nodo->next->prev=NULL;
					l->nItens--;
					free(nodo);
				}
				else if(nodo == l->last){
					l->last=nodo->prev;
					nodo->prev->next=NULL;
					l->nItens--;
					free(nodo);
				}
				else{
					nodo->next->prev = nodo->prev;
					nodo->prev->next = nodo->next;
					free(nodo);
					l->nItens--;
				}
			}
	
		}
	}
}

void display(tpLista *l){
	tpNodo *x;
		for(x=l->first ; x!=NULL ; x=x->next){
			printf("Código: %d\n", x->produto.codigo);
			printf("Nome: %s", x->produto.nome);
			printf("Preço: %.2f\n\n", x->produto.preco);
		}
}

int main(){
	tpLista *x = (tpLista *) malloc(sizeof(tpLista));
	x->nItens=0;
	x->first = NULL;
	x->last = NULL;
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
				x=push(x);
				system("clear");
				break;
			case 2:
				if(x->nItens==0){
					printf("Não existe nada cadastrado\n");
					getchar();
					getchar();
					system("clear");
				}
				else{
					
					pop(x);
					getchar();
					getchar();
					system("clear");
				}
				break;
			case 3:
				if(x->nItens==0){
					printf("Não existe nada cadastrado\n");
					getchar();
					getchar();
					system("clear");
				}
				else{
					display(x);
					getchar();
					getchar();
					system("clear");
					break;
				}
		}
	}while(a!=0);
	
	return 0;
}
