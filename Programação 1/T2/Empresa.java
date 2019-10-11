package bodega;
import java.util.*;

public class Empresa {
    String nome,CNPJ;
    List<Funcionarios> bodegueiros = new ArrayList<>();
    int qntFuncionarios = 0;
    Empresa(String nome, String CNPJ){
        this.CNPJ = CNPJ;
        this.nome = nome;
    }
    
    void Contrata(Funcionarios f1){
        this.qntFuncionarios ++;
        bodegueiros.add(f1);      
    }
    void mostraFuncionarios(Funcionarios f){
        System.out.println("Nome: " + f.nome + "\n");
        System.out.println("Idade: " + f.idade + "\n");
        System.out.println("Posiçao de entrada: " + (f.posicao) + 1  + "\n"); 
    }
}
