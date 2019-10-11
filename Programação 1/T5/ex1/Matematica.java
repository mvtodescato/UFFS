package main;
import java.util.*;
public class Matematica {
    public double soma (double a, double b) throws Exception{
        if(a == 0 || b == 0){
            throw new Valor0();
        }
        if(a + b == 0){
            throw new Resultado0();
        }
        return a + b;
    }
    public double subtracao(double a, double b) throws Exception{
        if(a == 0 || b == 0){
            throw new Valor0();
        }
        if(a - b == 0){
            throw new Resultado0();
        }
        return a - b;
    }
    public double div(double a, double b) throws Exception{
        if(a == 0 || b == 0){
            throw new Valor0();
        }
        if(a / b == 0){
            throw new Resultado0();
        }
        return a / b;
    }
    public double mult(double a, double b) throws Exception{
        if(a == 0 || b == 0){
            throw new Valor0();
        }
        if(a * b == 0){
            throw new Resultado0();
        }
        return a * b;
    }
}
