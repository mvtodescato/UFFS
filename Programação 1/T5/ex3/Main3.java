package main3;
import java.util.*;
public class Main3 extends Exception {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Numero de posições do vetor: ");
        int x = scanner.nextInt();
        int vetor[];
        try{
            vetor = new int [x];
            System.out.println("Vetor construído com sucesso!");
        }catch(NegativeArraySizeException e){
            System.out.println("Valor invalido! Criando vetor com 1 posição!");
            vetor = new int [1];
            vetor[0] = 1;
            System.out.println("Valor: " + vetor[0]);
        }
    }
    
}
