package blog;
import java.util.*;
public class Blog {
    public static void main(String[] args) {
        List<Post> publicacoes = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int op;
        int l;
        do{
          System.out.println("\t\t BLOG\t\n");
          System.out.println("[1] - Novo post de noticia\n");
          System.out.println("[2] - Nova resenha de produto\n");
          System.out.println("[3] - Novo post de outros assuntos\n");
          System.out.println("[4] - Listar todas as postagens\n");
          System.out.println("[5] - Curtir uma postagem\n");
          System.out.println("[6] - Nao curtir uma postagem\n");
          System.out.println("[0] - SAIR\n");
          op = scanner.nextInt();
          for (l=0; l<50; l++){
                         System.out.println();
                      }
          switch(op){
              case 1:
                  News n = new News();
                  readData(n);
                  Post.qtdPosts ++;
                  publicacoes.add(n);
                  break;
              case 2:
                  Review r = new Review();
                  readData(r);
                  Post.qtdPosts ++;
                  publicacoes.add(r);
                  break;
              case 3:
                  Post p = new Post();
                  readData(p);
                  Post.qtdPosts ++;
                  publicacoes.add(p);
                  break;
              case 4:
                  for(int i=0; i<Post.qtdPosts; i++){
                      System.out.println("Post numero: " + i);
                      Post a = publicacoes.get(i);
                      a.mostrar();
                  }
                  System.out.println("Digite qualquer tecla para sair\n\n\n");
                  scanner.nextLine();
                  scanner.nextLine();
                  break;
              case 5:
                  System.out.println("Numero da publicaçao: ");
                  int x = scanner.nextInt();
                  Post b = publicacoes.get(x);
                  b.like(1);
                  break;
              case 6:
                  System.out.println("Numero da publicaçao: ");
                  int h = scanner.nextInt();
                  Post c = publicacoes.get(h);
                  c.dislike(1);
                  break;
            }
          for (l=0; l<50; l++){
                         System.out.println();
                      }
        }while(op != 0);
}
    public static void readData(Post p){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Titulo: ");
        String titulo = scanner.nextLine();
        System.out.println("Conteudo: ");
        String conteudo = scanner.nextLine();
        p.setTitulo(titulo);
        p.setConteudo(conteudo);
        if(p instanceof Review){
            System.out.println("Marca: ");
            String marca = scanner.nextLine();
            System.out.println("Numero de estrelas (0 a 10) : ");
            int estrelas = scanner.nextInt();
            ((Review) p).setMarca(marca);
            ((Review) p).avaliac(estrelas);
        }
        else if(p instanceof News){
            System.out.println("Fonte: ");
            String fonte = scanner.nextLine();
            ((News) p).setFonte(fonte);
        }
            
    }
}


