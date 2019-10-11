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
		(l->first)->next = novo;
		novo->prev = l->first;
		novo->next = NULL;
		l->first = novo;
	}
	return l;

}
void selection(tpLista *l){
	tpNodo *percorre1, *percorre2,*menor,*troca,*aux;
	for(percorre1=l->first ; percorre1!=NULL ; percorre1=percorre1->prev){
		troca=percorre1;
		menor=percorre1;
		for(percorre2 = percorre1; percorre2!=NULL ; percorre2=percorre2->prev){
			if(percorre2->produto.codigo < menor->produto.codigo){
				menor = percorre2;
			}
		}
		if(troca->produto.codigo != menor->produto.codigo){
			if(troca == l->first && menor == l->last){
				if(menor == troca->prev){
					menor->next = NULL;
					menor->prev = troca;
					troca->prev = NULL;
					troca->next = menor;
					l->first = menor;
					l->last = troca;
				}
				else{
					menor->next->prev=troca;
					troca->prev->next = menor;
					menor->prev = troca->prev;
					troca->next = menor->next;
					menor->next=NULL;
					troca->prev=NULL;
					l->first = menor;
					l->last = troca;
				}
			}
			else if(troca == l->first){
				if(menor == troca->prev){
					troca->prev = menor->prev;
					troca->next = menor;
					menor->next = NULL;
					menor->prev = troca;
					l->first = menor;
				}
				else {
					menor->next->prev = troca;
					troca->prev->next = menor;
					menor->prev->next = troca;
					aux = menor->prev;
					menor->prev = troca->prev;
					troca->prev = aux;
					troca->next = menor->next;
					l->first = menor;
					menor->next = NULL;
				}
			}
			else if(menor == l->last){
				if(menor == troca->prev){
					troca->next->prev = menor;
					menor->next = troca->next;
					menor->prev = troca;
					troca->next = menor;
					troca->prev = NULL;
				}
				else{
					troca->next->prev = menor;
					troca->prev->next = menor;
					menor->next->prev = troca;
					aux=troca->next;
					troca->next = menor->next;
					menor->next = aux;
					menor->prev = troca->prev;
					troca->prev = NULL;
				}
			}
			else{
				if(menor == troca->prev){
					troca->next->prev = menor;
					menor->prev->next = troca;
					menor->next = troca->next;
					troca->next = menor;
					troca->prev = menor->prev;
					menor->prev = troca;
				}
				else{
					troca->next->prev = menor;
					troca->prev->next = menor;
					menor->prev->next = troca;
					menor->next->prev = troca;
					aux = troca->next;
					troca->next = menor->next;
					menor->next = aux;
					aux = troca->prev;
					troca->prev = menor->prev;
					menor->prev = aux;
				}
			}
		}
		percorre1 = menor;
	}
		
					
					
					
					
				
			
					
}

void insertion (tpLista *l){
	tpNodo *percorre1, *percorre2,*troca,*aux,*aux2;
	int cont = 0;
	for(percorre1=l->first->prev ; percorre1!=NULL ; percorre1=percorre1->prev){
		troca=percorre1;
		printf("percorre1 = %d\n", percorre1->produto.codigo);
		printf("next d percorre1 = %d\n", percorre1->next->produto.codigo);
		for(percorre2 = percorre1->next; percorre2!=NULL ; percorre2=percorre2->next){
			if(percorre2 == l->first){
				if(percorre2->produto.codigo >= troca->produto.codigo){
					aux2 = percorre2;
					cont++;
				}
			}
			else if(percorre2->produto.codigo >= troca->produto.codigo && percorre2->next->produto.codigo<=troca->produto.codigo){
				aux2 = percorre2;
				cont++;
			}
		}
		if(cont!=0){
			if(aux2 == l->first){
					if(troca == l->last){
						aux2->next = troca;
						troca->next->prev = troca->prev;
						troca->prev = aux2;
						troca->next = NULL;
						l->first = troca;
						break;
						
					}
					else{
						aux2->next = troca;
						troca->prev->next = troca->next;
						troca->next->prev = troca->prev;
						troca->prev = aux2;
						troca->next = NULL;
						l->first = troca;
						break;
						
					}
			}
			else if(troca == l->last){
						aux = troca->next;
						troca->next = aux2->next;
						aux2->next->prev = troca;
						aux2->next = troca;
						aux->prev = troca->prev;
						troca->prev = aux2;
						break;
					}
			else{
						aux = troca->next;
						troca->next = aux2->next;
						aux2->next->prev = troca;
						aux2->next = troca;
						aux->prev = troca->prev;
						troca->prev->next = aux;
						troca->prev = aux2;
						break;
					}
				
			}
			cont = 0;
		}
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
		for( ; nodo!=NULL ; nodo=nodo->prev){
			if(nodo->produto.codigo==codigo){
				if(nodo == l->first){
					l->first = nodo->prev;
					nodo->prev->next=NULL;
					l->nItens--;
					free(nodo);
				}
				else if(nodo == l->last){
					l->last=nodo->next;
					nodo->next->prev=NULL;
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
		for(x=l->first ; x!=NULL ; x=x->prev){
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
		printf("[4] - Ordenar usando Selection\n");
		printf("[5] - Ordenar com Insertion\n");
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
			case 4:
				selection(x);
				break;
			case 5:
				insertion(x);
				break;
		}
	}while(a!=0);
	
	return 0;
}
