package programa;
import java.util.*;
public class PublicacaoSemanal extends Publicacao{
    private double taxaEntrega;

        public PublicacaoSemanal(String nomeEditora, String cnpj, String nome, double precoExemplar){
            super(nomeEditora, cnpj, nome, precoExemplar);
            this.taxaEntrega = 0;
        }
        public void taxaEntrega(){
            this.taxaEntrega = this.getPrecoExemplar()*2.6;
        }
        public void valorAnuidade(){
            this.valorAnuidade =  getPrecoExemplar()*52 ;
        }
        public void imprimirDados(){
            System.out.println("Nome: " + getNome() + "\nPreço do exemplar: " + getPrecoExemplar() + "\nValor da anuidade: " + this.valorAnuidade + "\nTaxa de entrega: " + this.taxaEntrega + "\n\nEditora: " + getNomeEditora() + "\nCNPJ: " + getCnpjEditora() + "\n");
    }
}
