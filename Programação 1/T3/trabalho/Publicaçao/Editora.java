package programa;
public class Editora {
   private String nome;
   private String cnpj;

    public Editora(){
        this.nome = null;
        this.cnpj = null;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCnpj(String cnpj){
        this.cnpj = cnpj;
    }

    public String getNome(){
        return this.nome;
    }

    public String getCnpj(){
        return this.cnpj;
    }
 }
