/*Programa de implementaçao da arvore AVL. Codigo feito com base no materia do canal "Linguagem C Programação Descomplicada"
do Youtube e do site geekforgeeks.com e feito no Windows(acredito que apenas o system("cls") mude*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TpNodo{
	int chave;
	int altura;
	struct TpNodo *dir, *esq;
}TpNodo;

int alt(TpNodo *a){
	if(a == NULL)
		return -1;
	return a->altura;
}

int balance(TpNodo *nodo){
    if(abs(alt(nodo->esq) - alt(nodo->dir)) >= 2){
        return 1;
    }
    else{
        return 0;
    }
}

int max(int a, int b){
	if(a>b)
        return a;
	else
        return b;
}

void *RightRight(TpNodo *nodo){
	TpNodo *aux = nodo->dir;
	nodo->dir = aux->esq;
	aux->esq = nodo;
	nodo->altura = max(alt(nodo->esq), alt(nodo->dir) + 1);
	aux->altura = max(nodo->altura, alt(aux->dir) + 1);
	nodo = aux;
	return nodo;
}

void *LeftLeft(TpNodo *nodo){
	TpNodo *aux = nodo->esq;
	nodo->esq = aux->dir;
	aux->dir = nodo;
	nodo->altura = max(alt(nodo->esq), alt(nodo->dir) + 1);
	aux->altura = max(alt(aux->esq), (nodo->altura) + 1);
	nodo = aux;
	return nodo;
}

void *RightLeft(TpNodo *nodo){
	nodo->esq = RightRight(nodo->esq);
	nodo = LeftLeft(nodo);
	return nodo;
}

void *LeftRight(TpNodo *nodo){
	nodo->dir = LeftLeft(nodo->dir);
	nodo = RightRight(nodo);
	return nodo;
}

void imprime(TpNodo *nodo, int n){
	if(nodo != NULL){
        imprime(nodo->dir, n+1);
		printf("Chave: %d\t Nivel: %d\tAltura: %d\n",nodo->chave,n,nodo->altura);
		imprime(nodo->esq, n+1);
	}
}
void *add(TpNodo *nodo, int num){
	if(nodo == NULL){
		nodo = (TpNodo *)calloc(1,sizeof(TpNodo));
		printf("Elemento inserido com sucesso\n");
		nodo->chave = num;
		return nodo;
	}
	if(num < nodo->chave){
		if(nodo->esq = add(nodo->esq, num)){
			if(balance(nodo)){
				if(num < nodo->esq->chave)
					nodo = LeftLeft(nodo);
				else
					nodo = RightLeft(nodo);
			}
		}
	}
	else if(num > nodo->chave){
		if(nodo->dir = add(nodo->dir, num)){
			if(balance(nodo)){// " "
				if(num > nodo->dir->chave)
					nodo = RightRight(nodo);
				else
					nodo = LeftRight(nodo);
			}
		}
	}
	else{
		printf("Elemento ja foi inserido\n");
	}
	nodo->altura = max(alt(nodo->esq), alt(nodo->dir)) + 1;
	return nodo;
}
void main(void){
	TpNodo *arv = (TpNodo *)calloc(1,sizeof(TpNodo));
	arv = NULL;
	int x, num;
	do{
		printf("\t\t MENU\n");
		printf("[1] - Inserir\n");
		printf("[2] - Imprimir\n");
		printf("[0] - SAIR\n");
		scanf("%d", &x);
		switch(x){
			case 1:
				printf("Digite o numero: ");
				scanf("%d", &num);
				arv = add(arv, num);
				printf("Pressione qualquer tecla para sair\n");
				getchar();
				getchar();
				system("cls");
				break;
			case 2:
				printf("\t\tAVL:\n");
				imprime(arv, 0);
				printf("Pressione qualquer tecla para sair\n");
				getchar();
				getchar();
				system("cls");
				break;
            case 0:
                break;
			default:
				printf("Opçao invalida\n");
				printf("Pressione qualquer tecla para sair\n");
				getchar();
				getchar();
				system("cls");
				break;
		}
		system("cls");
	}while(x != 0);
}
