
package controladordeestoque;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.*;
import java.awt.*; 

public class botaoVoltar implements ActionListener{
    public JButton botao;
    int aux = 0;
    JFrame frame;
    botaoVoltar(JPanel painel,JFrame fr){
    frame=fr;
    botao = new JButton("VOLTAR");
    painel.add(botao);
    botao.addActionListener(this);
    }
    @Override
	public void actionPerformed(ActionEvent evento) {
		if(evento.getSource() == botao){
				frame.hide();            
                }
	}
}
