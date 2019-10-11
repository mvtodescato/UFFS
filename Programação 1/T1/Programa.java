/*PROGRAMA DE MATHEUS VINICIUS TODESCATO
Obs: Desculpe a falta de acento, meu teclado esta com problema :D
*/
package programa;
import java.util.Scanner;
public class Programa {
    public static void main(String[] args) {
        int x;
         Scanner scanner = new Scanner(System.in);
         Medicamento medicamento = new Medicamento();
         System.out.println("\t\t\tBEM VINDO\n");
         System.out.println("CADASTRO LABORATORIO:\n");
         System.out.println("Razao Social: ");
         medicamento.laboratorio.razaoSocial = scanner.nextLine();
         System.out.println("Nome Fantasia: ");
         medicamento.laboratorio.nomeFantasia = scanner.nextLine();
         System.out.println("Inscriçao Estadual: ");
         medicamento.laboratorio.inscricaoE = scanner.nextLine();
         System.out.println("Endereço: ");
         medicamento.laboratorio.endereco = scanner.nextLine();
         System.out.println("CNPJ: ");
         medicamento.laboratorio.cnpj = scanner.nextLine();
         System.out.println("Numero do Telefone: ");
         medicamento.laboratorio.telefone = scanner.nextInt();
         do{
             System.out.println("\t\tMENU - " + medicamento.laboratorio.nomeFantasia + "\n");
             System.out.println("[1] = Cadastrar Medicamento\n");
             System.out.println("[2] = Ajustar Preço\n");
             System.out.println("[3] = Mostrar Medicamento\n");
             System.out.println("[4] = Compra Medicamento\n");
             System.out.println("[5] = Vender Medicamento\n");
             System.out.println("[0] = SAIR\n");
             System.out.println("\nDigite sua opçao: ");
             x = scanner.nextInt();
             //Tentei procurar algo para limpar a tela, porem nao encontrei nenhuma funçao eficiente
             switch(x){
                 case 1:
                     scanner.nextLine();
                     System.out.println("Nome: ");
                     medicamento.nome = scanner.nextLine();
                     System.out.println("Preço de venda: ");
                     medicamento.precoVenda = scanner.nextDouble();
                     System.out.println("Quantidade de estoque: ");
                     medicamento.qtdEstoque = scanner.nextInt();
                     System.out.println("Receita obrigatoria? (true or false) ");
                     medicamento.receitaObrigatoria = scanner.nextBoolean();
                     System.out.println("Data de Validade: \n");
                     System.out.println("Dia: ");
                     medicamento.data.dia = scanner.nextInt();
                     System.out.println("Mes: ");
                     medicamento.data.mes = scanner.nextInt();
                     System.out.println("Ano: ");
                     medicamento.data.ano = scanner.nextInt();
                     break;
                 case 2:
                     System.out.println("Voce deseja aumentar ou diminuir o preço? [1] Aumentar [2] Diminuir\n");
                     x = scanner.nextInt();
                     if(x==1){
                        System.out.println("Quanto voce deseja aumentar? (Em porcentagem)");
                        double porcentagem = scanner.nextDouble();
                        porcentagem = (porcentagem / 100) + 1;
                        medicamento.reajustarPreco(porcentagem, 1);
                     }
                     else if(x == 2){
                        System.out.println("Quanto voce deseja diminuir? (Em porcentagem)");
                        double porcentagem = scanner.nextDouble();
                        porcentagem = 1 - (porcentagem / 100);
                        medicamento.reajustarPreco(porcentagem, 1);
                    }
                     break;
                 case 3:
                     medicamento.mostra();
                     break;
                 case 4:
                     System.out.println("Quantos medicamentos foi comprado? ");
                     medicamento.comprar(scanner.nextInt());
                     break;
                 case 5:
                     if(medicamento.receitaObrigatoria){
                        System.out.println("VENDA COM RECEITA OBRIGATORIA");
                        System.out.println("Enter para aceitar\n"); 
                        scanner.nextLine();
                        scanner.nextLine();
                     }
                     System.out.println("Quantos medicamentos foram vendidos? ");
                     medicamento.venda(scanner.nextInt());
                     break;
                 default:
                     System.out.println("Numero invalido\n");
                   
                    }
         }while(x != 0);
}
}
