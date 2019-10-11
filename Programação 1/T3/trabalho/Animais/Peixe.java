package teste;
public class Peixe extends Animais {
    private String caracteristica;
    Peixe(String nome, String cor, String ambiente, int comprimento, double velocidade, String c){
        super(nome,cor,ambiente,comprimento,velocidade,0);
        this.caracteristica = c;
    }
    public void setCaracteristica(String caracteristica){
        this.caracteristica = caracteristica;
    }
    public String getCaracteristica(){
        return this.caracteristica;
    }
    
    public void dados( ){
        super.dados();
        System.out.println("Caracteristica: " + getCaracteristica() + "\n" );
    } 
}
