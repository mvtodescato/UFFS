#include "types.h"      //necessaria para as variaveis
#include "user.h"       //função para print e chamada do sistema

#define STDOUT 1
#define FILHOS 4

int main(){
    int pid, i, x = 0, fim[FILHOS];
    int aux=0;

    for (i = 0; i < FILHOS; i++){
        if(i <1)
            pid = fork(10);
        else if(i <2)
           pid = fork(30);
        else if(i<3)
            pid = fork(50);
        else
            pid = fork(80);

        if(pid == 0){
            for(;;){ 
                aux = 1;
                aux = aux + 1;
                aux = aux -2;
            }
        }
    }

    while(1){
        pid = wait();
        if(pid < 0)break;
        fim[x] = pid;
        x++;
    }

    for(i = 0; i < FILHOS; i++){
        printf(STDOUT,"Filho %d Acabou\n", fim[i] );
    }

    exit();
}