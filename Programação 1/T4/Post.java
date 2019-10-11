package blog;
public class Post {
    
    private String titulo;
    //data
    private String conteudo;
    private int like=0,dislike=0;
    public static int qtdPosts = 0;
    public void setTitulo(String t){
        this.titulo = t;
    }
    public void setConteudo(String cont){
        this.conteudo = cont;
    }
    public String getTitulo(){
        return this.titulo;
    }
    public String getConteudo(){
        return this.conteudo;
    }
    public int getLike(){
        return this.like;
              
    }
    public int getDislike(){
        return this.dislike;
    }
    public void mostrar(){
        System.out.println("\t\tPost\n");
        System.out.println("\t**" + this.titulo + "**");
        System.out.println(conteudo);
        System.out.println("Likes: " + this.like + "\tDislikes: " + this.dislike + "\n\n");
    }
    public void like(int like){
        this.like += like;
    }
    public void dislike(int dislike){
        this.dislike += dislike;
    }
    
}
