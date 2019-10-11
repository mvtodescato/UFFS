package programa;
public class Medicamento{
	String nome;
	dataValidade data = new dataValidade();
	double precoVenda;
	Laboratorio laboratorio = new Laboratorio();
	boolean receitaObrigatoria;
	int qtdEstoque;
void mostra(){ 
    System.out.println("Nome: " + this.nome);
    System.out.printf("Preço de Venda: %.02f\n", this.precoVenda);
    System.out.println("Quantidade de Estoque: " + this.qtdEstoque);
    System.out.println("Data de Validade : ");
    this.data.formata();
    System.out.println("Receita obrigatoria: " + this.receitaObrigatoria);
}
void reajustarPreco(double a, int op){
    if(op == 1)
        this.precoVenda *= a;
    else
        this.precoVenda *= a;
}
void comprar(int a){
    this.qtdEstoque += a;
}
void venda(int a){
    this.qtdEstoque -= a;  
}
}