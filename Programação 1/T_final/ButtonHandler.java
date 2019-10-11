
package controladordeestoque;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.*;
import java.awt.*; 

public class ButtonHandler implements ActionListener {
	private JButton botao1, botao2, botao3, botao4;
	public JPanel p;
        int op = 0;
        public JFrame frame;
	public void janela(){
        frame = new JFrame();
    	botao1 = new JButton("Cadastrar Faltas");
		botao2 = new JButton("Mostrar Faltas");
		botao3 = new JButton("Mostrar Compras");
		botao4 = new JButton("Sair");

		p = new JPanel();
		p.setLayout(new GridLayout(2,2));
		frame.add(p);

		    //REGISTRA O EVENTO
        botao1.addActionListener(this);
        frame.getContentPane().add(p);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800,800);
        frame.setVisible(true);
            //REGISTRA O EVENTO
        botao2.addActionListener(this);
        frame.getContentPane().add(p);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800,800);
        frame.setVisible(true);
            //REGISTRA O EVENTO
        botao3.addActionListener(this);
        frame.getContentPane().add(p);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800,800);
        frame.setVisible(true);
            //REGISTRA O EVENTO
        botao4.addActionListener(this);
        frame.getContentPane().add(p);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800,800);
        frame.setVisible(true);
        p.add(botao1);
        botao1.setFont( new Font( "Arial", Font.PLAIN, 20 ) );
        p.add(botao2);
        botao2.setFont( new Font( "Arial", Font.PLAIN, 20 ) );
        p.add(botao3);
        botao3.setFont( new Font( "Arial", Font.PLAIN, 20 ) );
        p.add(botao4);
        botao4.setFont( new Font( "Arial", Font.PLAIN, 20 ) );
	}
    @Override
    
	public void actionPerformed(ActionEvent evento) {
		if(evento.getSource() == botao1){
				op = 1; 
                                System.out.println(op);
                }
		if(evento.getSource() == botao2)
			op = 2;

		if(evento.getSource() == botao3)
				op = 3;

		if(evento.getSource() == botao4)
				op = 4;
                

	}
        public int vop(){
            return op;
        }
}
