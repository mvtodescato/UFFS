package controladordeestoque;
import java.awt.event.*;
import java.util.List;
import javax.swing.*;
import javax.swing.event.*;
public class tabela2 implements ListSelectionListener {
private JList tabelaProdutos;
public JPanel painel;
public JFrame janela;
int x = -1;
private String listaNomes[];
List<produtosComprados> produtos;
public tabela2(String listaNomes[],List<produtosComprados> prod) {
produtos = prod;
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

    this.x = (tabelaProdutos.getSelectedIndex());
    produtosComprados p = produtos.get(this.x);
    JOptionPane.showMessageDialog(null, "Produto Comprado em:\n" + p.formatodDate);
    


}

} 