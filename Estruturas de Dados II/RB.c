#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo{
	int key, cor;
	struct nodo *left, *right, *pater; 
}nodo;

nodo *insere(nodo *raiz, nodo *father, int valor){
	if(raiz == NULL){ // A insersão ocorrerá sempre aqui, seja em folha ou em raiz
		raiz = (nodo *)calloc(1, sizeof(nodo));
		raiz->key = valor;
		raiz->cor = 1;
		raiz->pater = father; 
		return raiz;
	}	
	if(valor < raiz->key) raiz->left = insere(raiz->left, raiz, valor); // adiciona na esquerda	
	else if(valor > raiz->key) raiz->right = insere(raiz->right, raiz, valor); // adiciona na direita		
	else printf("Este elemento já existe!\n");	
	return raiz;
}

nodo *fixup(nodo *raiz, int valor){
	nodo *sup2, *titio, *vovo, *sup = raiz;
	while(sup->key != valor){ // enquanto os valores forem diferentes
		if(sup->key > valor) sup = sup->left; // percorre a esquerda		 			
		else sup = sup->right; // percorre a direita
	}
	if((sup == raiz) || (sup->pater->cor == 0))
		return raiz;
	vovo = sup->pater->pater;
	if(vovo->key > valor) titio = vovo->right; // percorre a direita
	else titio = vovo->left; // percorre a esquerda
	if((titio != NULL) && (titio->cor == 1)){ //Case 1, Tio é redi
		do{ // fazer enquanto existir case 1 na arvore
			titio->cor = sup->pater->cor = 0; // muda cor do pai e do tio
			vovo->cor = 1; // muda a cor do vo
			if((vovo->pater != NULL) && (vovo->pater->cor == 1)){ //Altera os ponteiros e verifica de novo
				sup = vovo; // auxiliar e o vo
				valor = sup->key; // valor e o valor do auxiliar
				vovo = vovo->pater->pater; 
				if(vovo->key > valor) titio = vovo->right; // tio fica a direita do vo
				else titio = vovo->left; // fica a esquerda do vo
			}else return raiz; // se nao retorna a raiz
		}while((titio != NULL) && (titio->cor == 1)); // Verifica se há outras Cases 1 na Arvore
	}		
	if((sup->pater)->key < valor && (sup->pater)->key < vovo->key || (sup->pater)->key > valor && (sup->pater)->key > vovo->key){ //Case 2, Tio é preto e o nodo é do lado oposto do pai
		sup2 = sup->pater;
		sup->pater = sup2->pater;
		sup2->pater = sup;
		if(vovo->key > valor){ // Caso esteja na esquerda
			vovo->left = sup; 
			sup->left = sup2;
			sup2->right = NULL;
		}
		else{
			vovo->right = sup; // Caso esteja na direita
			sup->right = sup2;
			sup2->left = NULL;
		}
		sup = sup2;
		valor = sup->key;
	}
	sup = sup->pater; //Se chegar é case 3
	sup->pater = vovo->pater; 
	sup->cor = 0; 
	vovo->cor = 1; // muda as cores que devem ser mudadas 
	vovo->pater = sup;
	if(vovo->key > valor){ 
		sup->right = vovo; // aqui faz a rotação pra direita
		vovo->left = NULL; // se necessário
	}
	else{
		sup->left = vovo; // se não faz pra esquerda
		vovo->right = NULL;
	}
	if(sup->pater != NULL){
		if(sup->pater->key > valor) sup->pater->left = sup;
		else sup->pater->right = sup;
	}
	else return sup;
	return raiz;
}

void imprime(nodo *raiz, int n){ //Mesma coisa da AVL
	if(raiz != NULL){ //Até chegar nas folhas
		if(raiz->cor) printf("Key: %2.d Cor Redi ", raiz->key); // Se for vermelho
		else printf("Key: %2.d Cor Blequi ", raiz->key); // se for preto
		printf("Nivel: %d\n", n); // Através da recursão é possivel saber o nivel
		imprime(raiz->left, n+1); // Imprime primeiro a esquerda
		imprime(raiz->right, n+1); // depois a direita -- está em Pré order
	}
}

int main(){
	nodo *arvore = NULL;
	int x, valor;
	do{
		system("clear");
		printf("\nO que deseja fazer?\n\n");
		printf("1- Inserir elemento\n");
		printf("2- Exibir elementos\n");
		printf("0- Sair do programa\n");
		scanf("%d", &x);
		if(x == 1){
			printf("Digite o valor que voce deseja incerir\n");
			scanf("%d", &valor);
			arvore = insere(arvore, NULL, valor);
			arvore = fixup(arvore, valor);
			arvore->cor = 0;
		}
		else{
			imprime(arvore, 0);
		}
	}while(x != 0);
}
