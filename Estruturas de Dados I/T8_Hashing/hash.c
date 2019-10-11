#include <stdio.h>
#include<stdlib.h>
 
#define MAX 8
typedef struct nodo{ 
      int key;
      struct nodo *next;
}nodo;

 
int calcula(int x){ 
    return (x % MAX);
}

void push(int n, nodo *hash_table[]){
    int l;
    nodo *novo;

    if(procura(n, hash_table) != -1){ 
        printf("Esse numero ja existe!\n");
        printf("Digite qualquer tecla para sair\n");
        getchar();
	getchar();
        return;
    }
    else{
	novo = malloc(sizeof(struct nodo));	
    	l = calcula(n);  
    	novo->key = n;  
    	novo->next = hash_table[l]; 
    	hash_table[l] = novo;
    }
}

int procura(int num, nodo *hash_table[]){
    int n;
    nodo *aux;
    n = calcula(num); 

    aux = hash_table[n]; 

    while(aux != NULL){
        if(aux->key == num) 
            return n;            

        aux = aux->next; 
    }

    return -1;
}

void display(nodo *hash_table[]){
    int i;
    nodo *aux;
    for(i = 0; i < MAX; i++){ 
        printf("\n[%d] ", i);
        if(hash_table[i] != NULL){
            aux = hash_table[i];

            while(aux != NULL){ 
                printf("%d -> ", aux->key);
                aux = aux->next; 
            }
            
            printf("NULL");
        }   

    }

    printf("\n\tDigite qualquer tecla para voltar: ");
    getchar();
    getchar();
}

void linha(int i, nodo *hash_table[]){
    nodo *aux;
        
    system("clear");

    if(i != -1){ 
        printf("Elemento se encontra na linha: %d\n", i);
        printf("\n[%d] ", i);
        aux = hash_table[i];
        
        while(aux != NULL){
            printf("%d -> ", aux->key);
            aux = aux->next;
        }

        printf("NULL");
        printf("\n\nDigite qualquer tecla para sair\n");
        getchar();
	getchar();
    }

    else{ 
        printf("Não encontrado\n");
        printf("Digite qualquer tecla para sair\n");
        getchar();
	getchar();
    }
}

int main(void){
    nodo *hash_table[MAX];  
    int i, num, x,n; 
    for(i = 0; i < MAX; i++) 
        hash_table[i] = NULL;

   do{
        system("clear");
        printf("\t\tTABELA HASH\n\n");   
        printf("1 - Inserir elemento na tabela\n");
        printf("2 - Procurar um elemento\n");
        printf("3 - Mostrar a tabela hash\n");
        printf("4 - Sair\n");
        scanf("%d",&x);
        
        switch(x){
            case 1: 
                system("clear");
                printf("Valor: ");
                scanf("%d", &n);
                push(n, hash_table);
                break;
           
            case 2: 
                system("clear");
                printf("Deseja buscar qual elemento? ");
                scanf("%d", &num);
                i = procura(num, hash_table);
                linha(i, hash_table); 
                break;

            case 3: 
		system("clear");
                display(hash_table);
                break;
        }
	system("clear");
    }while(x!=4); 
}
