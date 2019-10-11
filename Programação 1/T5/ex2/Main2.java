package main2;
import java.util.*;
public class Main2 {
    public static void main(String[] args) {
        int vetor[];
        int res;
        vetor = new int[5];
        Scanner scanner = new Scanner(System.in);
        vetor[0] = scanner.nextInt();
        vetor[1] = scanner.nextInt();
        vetor[2] = scanner.nextInt();
        vetor[3] = scanner.nextInt();
        vetor[4] = scanner.nextInt();
        System.out.println("Somar quantas posição dos vetores?");
        int p = scanner.nextInt();
        try{
            res = soma.somar(vetor, p);
            System.out.println("Resultado: " + res);
        }catch(Resultado0 e){
            System.out.println("Vetor com valores 0!!");
        }catch(IntervaloInvalido e){
            System.out.println("Valor invalido do intervalo!");
        }catch(Exception e){
            System.out.println("ERRO!");
        }
        
        
        
    }
    
}
