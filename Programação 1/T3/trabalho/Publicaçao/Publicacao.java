package programa;
    import java.util.*;
    public class Publicacao{
        private String nome;
        private double precoExemplar;
        protected double valorAnuidade;
        private Editora editora = new Editora();

        public Publicacao(String nomeEditora, String cnpjEditora, String nome, double precoExemplar){
                this.nome = nome;
                this.precoExemplar = precoExemplar;
                this.valorAnuidade = 0;
                this.editora.setCnpj(cnpjEditora);
                this.editora.setNome(nomeEditora);
        }

        public void valorAnuidade(){
                this.valorAnuidade = this.precoExemplar*12;
        }

        public void setValorAnuidade(double valorAnuidade){
                this.valorAnuidade = valorAnuidade;
        }
        public double getValorAnuidade(){
                return this.valorAnuidade;
        }
        public String getCnpjEditora(){
                return editora.getCnpj();
        }

        public String getNome(){
                return this.nome;
        }

        public double getPrecoExemplar(){
                return this.precoExemplar;
        }

        public String getNomeEditora(){
                return editora.getNome();
        }
        
        public void imprimirDados(){
               System.out.println("Nome: " + this.nome + "\nPreço do exemplar: " + this.precoExemplar + "\nValor da anuidade: " + this.valorAnuidade + "\n\nEditora: " + editora.getNome() + "\nCNPJ: " + editora.getCnpj());
        }

        
}

