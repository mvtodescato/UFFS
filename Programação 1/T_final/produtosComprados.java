package controladordeestoque;
import java.io.Serializable;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
public class produtosComprados implements Serializable {
    public String nome;
    String formatodDate ;
    //data
    produtosComprados(String nome){
        this.nome = nome;
        Date date = new Date();
        DateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        formatodDate = formato.format(date);
    }
}
