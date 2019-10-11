package blog;
public class Review extends Post implements Aval{
    private String marca;
    private int estrelas;
    public void setMarca(String marca){
        this.marca = marca;
    }
    public void setEstrelas(int e){
        this.estrelas = e;
    }
    public void avaliac(int stars){
        this.setEstrelas(stars);
    }
    public void mostrar(){
        System.out.println("\t\tReview\n");
        System.out.println("\t**" + this.getTitulo() + "**");
        System.out.println(this.getConteudo());
        System.out.println("Marca: " + this.marca);
        System.out.println("Estrelas: " + this.estrelas);
        System.out.println("Likes: " + this.getLike() + "\tDislikes: " + this.getDislike() + "\n\n");
   }
}
