
package bodega;
import java.util.*;
public class Bodega {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Clientes> cachaceiros = new ArrayList<>();
        System.out.println("\t\tBEM VINDO\n");
        System.out.println("Digite o nome da bodega e o CNPJ:\n");
        Empresa bodega = new Empresa(scanner.nextLine(),scanner.nextLine());
        String m = "Matheus";
        String p = "Pedro";
        String j = "Joao";
        Funcionarios f1 = new Funcionarios(m,18,bodega.qntFuncionarios);
        bodega.Contrata(f1);
        Funcionarios f2 = new Funcionarios(p,19,bodega.qntFuncionarios);
        bodega.Contrata(f2);
        Funcionarios f3 = new Funcionarios(j,21,bodega.qntFuncionarios);
        bodega.Contrata(f3);
        System.out.println("\t\tCADASTRAR BEBIDA\n");
        System.out.println("Nome: ");
        String nome = scanner.nextLine();
        System.out.println("Teor alcoolico: ");
        int teor = scanner.nextInt();
        System.out.println("Preço: ");
        double preco = scanner.nextDouble();
        System.out.println("Quantidade de Estoque: ");
        int quant = scanner.nextInt();
        Bebida bebida = new Bebida(nome,teor,quant,preco);
        int op;
        do{
          System.out.println(bodega.nome);
          System.out.println("[1] - Cadastrar Cliente\n");
          System.out.println("[2] - Vender Bebida\n");
          System.out.println("[3] - Comprar Bebida\n");
          System.out.println("[4] - Contratar Bodegueiro\n");
          System.out.println("[5] - Mostrar Bodegueiros\n");
          System.out.println("[6] - Mostrar Bebida\n");
          System.out.println("[0] - SAIR\n");
          op = scanner.nextInt();
          switch(op){
              case 1:
                  scanner.nextLine();
                  System.out.println("Nome: ");
                  String n = scanner.nextLine();
                  System.out.println("CPF: ");
                  String CPF = scanner.nextLine();
                  System.out.println("Pode comprar fiado: [Sim]-True \t [Nao]-False\n");
                  boolean fiado = scanner.nextBoolean();
                  Clientes c1 = new Clientes(n,CPF,fiado);
                  cachaceiros.add(c1);
                  break;
              case 2:
                  System.out.println("Quantos bebidas foram vendidas?\n");
                  int venda = scanner.nextInt();
                  bebida.vender(venda);
                  break;
              case 3:
                  System.out.println("Quantas bebidas foram compradas?\n");
                  int vd = scanner.nextInt();
                  bebida.compra(vd);
                  break;
              case 4:
                  scanner.nextLine();
                  System.out.println("Nome: ");
                  String Nome = scanner.nextLine();
                  System.out.println("Idade: ");
                  int id = scanner.nextInt();
                  Funcionarios f = new Funcionarios(Nome,id,bodega.qntFuncionarios);
                  bodega.Contrata(f);
                  break;
              case 5:
                  for(int i = 0; i < bodega.qntFuncionarios; i++) {
                    Funcionarios a = bodega.bodegueiros.get(i);
                    a = bodega.bodegueiros.get(i);
                    bodega.mostraFuncionarios(a);
                  }
                  break;
              case 6:
                  bebida.mostrar();
                  break;
              case 0:
                  scanner.nextLine();
                  break;
          }
        }while(op!=0);
        
        
    }
    
}
