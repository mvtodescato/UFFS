package bodega;
public class Bebida {
    String nome;
    int teor, quant,estoque;
    double preco;
    Bebida(String nm,int teor,int quant, double preco){
        this.nome = nm;
        this.teor = teor;
        this.preco = preco;
        this.estoque = quant;
    }
    boolean confereEstoque(int quant){
        if(quant>this.estoque){
            return true;
        }
        else
            return false;
    }
    void vender(int qt){
        if(this.confereEstoque(qt)){
            System.out.println("ESTOQUE INSUFICIENTE\n");
        }
        else{
            this.estoque -= qt;
        }
        
    }   
    void mostrar(){
        System.out.println("Nome: " + this.nome + "\n");
        System.out.println("Teor Alcoolico: " + this.teor + "\n");
        System.out.println("Preço: " + this.preco + "\n");
        System.out.println("Quantidade em Estoque: " + this.estoque + "\n");
    }
    
    void compra(int quant){
        estoque+= quant;
    }
}
