package programa;
import java.util.*;
public class Programa {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite seu nome: ");
        String nome = scanner.nextLine();
        System.out.println("Digite o preço: ");
        double preco = scanner.nextDouble();
        PublicacaoSemanal pS = new PublicacaoSemanal("Rocco", "1111111111", nome, preco);
        pS.valorAnuidade();
        pS.taxaEntrega();
        pS.imprimirDados();
        }
}
