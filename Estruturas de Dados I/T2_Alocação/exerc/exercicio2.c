#include <stdio.h>
#include <stdlib.h>
typedef struct{
char nome[50];
char endereco[100];
int matricula;
} ESTUDANTE;
int main(){
    int a,i;
    printf("Quantos estudantes deseja cadastrar?\n");
    scanf("%d",&a);
    system("clear");
    ESTUDANTE * p = (int *)calloc(a, sizeof(ESTUDANTE));
    for(i=0;i<a;i++){
        printf("Estudante %d\n",i+1);
        __fpurge(stdin);
        printf("Nome: ");
        fgets((p+i)->nome,50,stdin);
        printf("Endereço: ");
        fgets((p+i)->endereco,100,stdin);
        __fpurge(stdin);
        printf("Matricula: ");
        scanf("%d",&(p+i)->matricula);
        __fpurge(stdin);
        system("clear");
    }
    printf("\t\t\tRelatório de estudantes cadastrados:\n\n");
    for(i=0;i<a;i++){
    printf("Estudante %d:\nNome: %sEndereço: %sMatricula: %d\n\n",i+1,(p+i)->nome,(p+i)->endereco,(p+i)->matricula);
    }
    free(p);
}
