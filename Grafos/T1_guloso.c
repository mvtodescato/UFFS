#include <stdio.h>
#include<stdlib.h>
void ad(){
    int i=0, j,cont, aux=100000,caminho[5], menor, distancia = 0,a;
    int matriz[5][5]={0,30,-15,0,20,-30,0,-10,50,0,15,10,0,5,-10,0,50,-5,0,-30,-20,0,10,30,0};
    for(cont=0;cont<5;cont++){
        aux = 100000;
        for(j=0;j<5;j++){

            if(matriz[i][j]<aux && matriz[i][j] > 0){
                aux = matriz[i][j];
                menor = j;
            }
        }
        if (cont<4){
            distancia += matriz[i][menor];
        }

        caminho[cont] = i + 1;
        i= menor;


    }
    printf("Ad 1: \nDistancia: %d\n",distancia);
    for(i=0;i<5;i++){
        printf("%d\t", caminho[i]);
    }
    printf("\n\n");
}

void ad2(){
    int i=0, j,cont, aux=100000,caminho[7], menor,distancia = 0;
    int matriz[7][7]={0,2,0,6,12,0,0,-2,0,1,0,0,5,0,0,-1,0,0,0,0,40,-6,0,0,0,0,4,0,-12,0,0,0,0,0,30,0,-5,0,-4,0,0,8,0,0,-40,0,-30,-8,0};
    for(cont=0;cont<7;cont++){
        aux = 100000;
        for(j=0;j<7;j++){

            if(matriz[i][j]<aux && matriz[i][j] > 0){
                aux = matriz[i][j];
                menor = j;
            }
        }
        distancia = distancia + matriz[i][menor];
        caminho[cont] = i + 1;
        i = menor;
        if(caminho [cont] == 7){
            break;
        }


    }
    printf("Ad 2: \nDistancia: %d\n",distancia);
    for(i=0;i<cont + 1;i++){
        printf("%d\t", caminho[i]);
    }
    printf("\n\n");
}
void inc2(){
    int i=0, j,cont, aux=100000,caminho[7], menor,aux2, distancia = 0;
    int matriz[7][9]={2,6,12,0,0,0,0,0,0,-2,0,0,1,5,0,0,0,0,0,0,0,-1,0,0,0,40,0,0,-6,0,0,0,4,0,0,0,0,0,12,0,0,0,30,0,0,0,0,0,0,-5,-4,0,0,8,0,0,0,0,0,0,-30,-40,-8};
    for(cont=0;cont<7;cont++){
        aux = 100000;
        for(j=0;j<9;j++){
            if(matriz[i][j]<aux && matriz[i][j] > 0){
                aux = matriz[i][j];
                menor = j;
            }
        }
        caminho[cont] = i + 1;
        if(caminho [cont] == 7){
            break;
        }
        for(aux2 = 0; aux2 < 7; aux2 ++){
            if(aux2 == i){
                continue;
            }
            else{
                if(matriz[aux2][menor] != 0){
                    i = aux2;

                }

            }
        }
        distancia += (matriz[i][menor] * -1);


    }
    printf("Inc 2:\nDistancia: %d\n",distancia);
    for(i=0;i<cont + 1;i++){
        printf("%d\t", caminho[i]);
    }
    printf("\n\n");
}
void inc1(){
    int i=0, j,cont, aux=100000,caminho[5], menor,aux2,distancia= 0;
    int matriz[5][8]={20,30,0,0,-15,0,0,0,0,-30,50,-10,0,0,0,0,0,0,0,10,15,-10,5,0,0,0,50,0,0,0,-5,-30,-20,0,0,0,0,10,0,30};
    for(cont=0;cont<5;cont++){
        aux = 100000;
        for(j=0;j<8;j++){
            if(matriz[i][j]<aux && matriz[i][j] > 0){
                aux = matriz[i][j];
                menor = j;
            }
        }
        caminho[cont] = i + 1;
        if (cont<4){
            distancia += matriz[i][menor];
        }
        for(aux2 = 0; aux2 < 5; aux2 ++){
            if(aux2 == i){
                continue;
            }
            else{
                if(matriz[aux2][menor] != 0){
                    i = aux2;
                    break;

                }

            }
        }



    }
    printf("Inc 1: \nDistancia: %d\n",distancia);
    for(i=0;i<cont;i++){
        printf("%d\t", caminho[i]);
    }
    printf("\n\n");
}


int main(void){
    ad();
    ad2();
    inc1();
    inc2();
}
