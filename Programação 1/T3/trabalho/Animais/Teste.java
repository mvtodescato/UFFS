package teste;
import java.util.*;
public class Teste {
    public static void main(String[] args) {
        Animais a = new Animais("Camelo","Amarelo","Terra",150,2,4);
        Peixe p = new Peixe("Tubarao","Cinzento","Mar",300,1.5,"Barbatanas e Caudas");
        Mamifero m = new Mamifero("Urso-do-Canada","Vermelho","Terra",180, 0.5,4,"Mel");
        a.dados();
        p.dados();
        m.dados();
    }
}
        
  
