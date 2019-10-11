package teste;
public class Animais {
    private String nome;
    private int comprimento;
    private String cor;
    private String ambiente;
    private double velocidade;
    private int patas; 
    public Animais(String nome, String cor, String ambiente, int comprimento, double velocidade, int patas){
        this.nome = nome;
        this.comprimento = comprimento;
        this.cor = cor;
        this.ambiente = ambiente;
        this.velocidade = velocidade;
        this.patas = patas;
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public void setComprimento(int comprimento){
        this.comprimento = comprimento;
    }
    public void setPatas(int patas){
        this.patas = patas;
    }
    public void setCor(String cor){
        this.cor = cor;
    }
    public void setAmbiente(String ambiente){
        this.ambiente = ambiente;
    }
    public void setVelocidade(float velocidade){
        this.velocidade = velocidade;
    }
    public String getNome(){
        return this.nome;
    }
    public int getComprimento(){
        return this.comprimento;
    }
    public String getCor(){
        return this.nome;
    }
    public String getAmbiente(){
        return this.ambiente;
    }
    public int getPatas(){
        return this.patas;
    }
    public double getVelocidade(){
        return this.velocidade;
    }
    public void dados(){
        System.out.println("Animal: " + getNome() + "\n");
        System.out.println("Comprimento: " + getComprimento() + "\n");
        System.out.println("Patas: " + getPatas() + "\n");
        System.out.println("Cor: " + getCor() + "\n");
        System.out.println("Ambiente: " + getAmbiente() + "\n");
        System.out.println("Velocidade: " + getVelocidade() + "\n");        
    }
}
