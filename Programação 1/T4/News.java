package blog;
public class News extends Post {
    private String fonte;
    public void setFonte(String fonte){
        this.fonte = fonte;
    }
    public void mostrar(){
        System.out.println("\t\tNews\n");
        System.out.println("\t**" + this.getTitulo() + "**");
        System.out.println(this.getConteudo());
        System.out.println("Fonte: " + this.fonte);
        System.out.println("Likes: " + this.getLike() + "\tDislikes: " + this.getDislike() + "\n\n");
    }
}
