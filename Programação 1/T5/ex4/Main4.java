package main4;
public class Main4 extends Exception {
    public static void main(String[] args) {
        int vetor[];
        int i=0;
        vetor = new int[3];
        vetor[0] = 2;
        vetor[1] = 3;
        vetor[2] = 4;
        try{
            for(i=0;i<4;i++){
                System.out.println("Valor: " + vetor[i]);
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Falha no acesso ao vetor! Posição " + i +" não existe");
        }
    }
    
}
