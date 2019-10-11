package main2;
class soma {
    static int somar(int vetor[],int x) throws Exception{
        int res = 0;
        if(x<1 || x>5){
            throw new IntervaloInvalido();
        }
        for(int i=0;i<x;i++){
             res += vetor[i];
        }
        if(res == 0){
            throw new Resultado0();
        }
        return res;
    }
}
