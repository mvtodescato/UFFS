// Programa ponto flutuante
// Fazer um programa para converter um valor de entrada (terminal) para um valor padrão IEEE754 codificado em binário no terminal.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	int aux1,cont;
	char bin[35] = "0 00000000 00000000000000000000000";
    float num;
	printf("Digite o valor que sera transformado: ");
	scanf("%f", &num);
	if(num != 0){
		if(num < 0){
			bin[0] = '1';
			num *= -1;
		}
		else
			bin[0] = '0';
		if(num >= 1){
			for(cont = 0 ; num >= 2; cont++){
				num /= 2;
			}
		}
		else if(num < 1){
			for(cont = 0 ; num < 1; cont--)
				num *= 2;
		}
		num --; cont += 127;
		for(aux1 = 9; cont > 0; aux1--){
			int resto = cont % 2;
			bin[aux1] = resto+'0';
			cont /= 2;
		}
		for(aux1 = 11; num != 0; aux1++){
			num *= 2;
			if(num >= 1){
				bin[aux1] = '1';
				num--;
			}
			else
				bin[aux1] = '0';
		}
	}
	printf("\nEm valor padrão IEEE754 codificado em binário é:\n\n");
	puts(bin);
    return 0;
}