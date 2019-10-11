package controladordeestoque;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
public class tabela implements ListSelectionListener {
private JList tabelaProdutos;
public JPanel painel;
public JFrame janela;
static int x = -1;
private String listaNomes[];
public tabela(String listaNomes[]) {
janela = new JFrame("Testando JList");
janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
janela.setSize(600, 600);
janela.setVisible(true);
painel = new JPanel();
janela.add(painel);
// cria uma lista com os itens de um array de nomes de cores
tabelaProdutos = new JList(listaNomes);
//tabelaProdutos.
tabelaProdutos.setVisibleRowCount(10);
// não permite seleções múltiplas
tabelaProdutos.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
// adicionado um JScrollPane contendo o JList para o painel
painel.add(new JScrollPane(tabelaProdutos));
// estabelece um tratador de eventos
tabelaProdutos.addListSelectionListener(this);
} 
public void valueChanged(ListSelectionEvent event)
{
int opcao = JOptionPane.showConfirmDialog(null ,"O PRODUTO FOI COMPRADO?", "COMPRADO?",JOptionPane.YES_NO_OPTION);
if (opcao == JOptionPane.YES_OPTION) {
    this.x = (tabelaProdutos.getSelectedIndex());
    
}
if (opcao == JOptionPane.NO_OPTION) {
 
}


}

} 