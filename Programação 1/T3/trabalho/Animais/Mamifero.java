package teste;
public class Mamifero extends Animais{
    String alimento;
    public Mamifero(String nome, String cor, String ambiente, int comprimento, double velocidade, int patas,String alimento){
        super(nome,cor,ambiente,comprimento,velocidade,patas);
        this.alimento = alimento;
    }
    public void setAlimento(String alim){
        this.alimento = alim;    
    }
    public String getAlimento(){
        return this.alimento;
    }
    public void dados(){
        super.dados();
        System.out.println("Alimento: "+ getAlimento() + "\n");
    }
}
