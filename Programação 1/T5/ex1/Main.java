package main;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Matematica mat = new Matematica();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Qual operação deseja realizar ?\n");
        System.out.println("[1] - soma\n");
        System.out.println("[2] - subtração\n");
        System.out.println("[3] - multiplicação\n");
        System.out.println("[4] - divisão\n");
        int op = scanner.nextInt();
        double a,b;
        double re;
        System.out.println("Digite os dois valores: ");
        a = scanner.nextDouble();
        b = scanner.nextDouble();
    try{
        switch(op){
            case 1:
                re = mat.soma(a, b);
                System.out.println("Resultado = " + re);
                break;
            case 2:
                re = mat.subtracao(a, b);
                System.out.println("Resultado = " + re);
                break;
            case 3:
                re = mat.mult(a, b);
                System.out.println("Resultado = " + re);
                break;
            case 4:
                re = mat.div(a, b);
                System.out.println("Resultado = " + re);
                break;      
        }
    }catch(Resultado0 e){
        System.out.println("Erro! Resultado 0\n");
    }catch(Valor0 e){
        System.out.println("Erro! Um dos valores informados é 0!\n");
    }catch(Exception e){
        System.out.println("Erro!!\n");
    }
    
    
        
    }
    
}
