package controladordeestoque;
import java.io.*;
import java.util.*;
import javax.swing.JOptionPane;
public class ControladordeEstoque implements Serializable {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
         Scanner scanner = new Scanner(System.in);
         List<produtosFalta> faltas = new ArrayList<>();
         List<produtosComprados> comprados = new ArrayList<>();
         int aux;
         int op,i;
         int quantFaltas = 0;
         int quantComprados = 0;
         try{
             FileInputStream inFile = new FileInputStream("file.ser");
             ObjectInputStream os = new ObjectInputStream(inFile);
             faltas = (List<produtosFalta>)os.readObject();
             comprados = (List<produtosComprados>)os.readObject();
             quantFaltas = (int) os.readObject();
             quantComprados = (int) os.readObject();
             
         }catch(FileNotFoundException e){
             System.out.println("Bem vindo!");
         }
         ButtonHandler captura = new ButtonHandler();
         captura.janela();
         do{
             if(tabela.x>=0){
                 produtosFalta a = faltas.get(tabela.x);
                 String nm = a.nome;
                 produtosComprados k = new produtosComprados(nm);
                 comprados.add(k);
                 faltas.remove(a);
                 quantFaltas --;
                 tabela.x=-1;
                 quantComprados ++;
             }
             System.out.println();
             switch(captura.op){
                 case 1:
                        String dados = JOptionPane.showInputDialog(null,"NOME DO PRODUTO:","PRODUTO EM FALTA", JOptionPane.QUESTION_MESSAGE);
                     
                     String nome = dados;
                     produtosFalta f = new produtosFalta(nome);
                     faltas.add(f);
                     quantFaltas++;
                     captura.op = 0;
                     break;
                 case 2:
                     List lista = new ArrayList();
                     for(i=0; i<quantFaltas; i++){
                         produtosFalta b = faltas.get(i);
                         lista.add(b.nome);
                     }
                     String[] strings = (String[]) lista.toArray (new String[lista.size()]);
                     tabela tab = new tabela(strings);
                     botaoVoltar b = new botaoVoltar(tab.painel,tab.janela);
                     captura.op = 0;
                     break;
                 case 3:
                     List lista2 = new ArrayList();
                     for(i=0; i<quantComprados; i++){
                         produtosComprados h = comprados.get(i);
                         lista2.add(h.nome);
                     }
                     String[] string = (String[]) lista2.toArray (new String[lista2.size()]);
                     tabela2 tb = new tabela2(string,comprados);
                     botaoVoltar bot = new botaoVoltar(tb.painel,tb.janela);
                     captura.op = 0;
                     break;
                 case 4:
                     FileOutputStream outFile = new FileOutputStream("file.ser");
                     ObjectOutputStream os = new ObjectOutputStream(outFile);
                     os.writeObject(faltas);
                     os.writeObject(comprados);
                     os.writeObject(quantFaltas);
                     os.writeObject(quantComprados);
                     break;


                }
         }while(captura.op != 4);
         captura.frame.hide();
    }
    
}
