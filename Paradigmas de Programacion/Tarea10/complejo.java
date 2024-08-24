package Tarea10_Complejo;

public class complejo {

    private double real;
    private double img;

    public complejo(double real, double img){
        this.real=real;
        this.img=img;
    }
    public double getreal(){
        return real;
    }
    public double getimg(){
        return img;
    }
    public complejo getsuma(complejo nuevo){
        complejo suma=new complejo(real+nuevo.getreal(), img+nuevo.getimg());
        return suma;
    }
    public boolean comparar(complejo nuevo){
        boolean igualdad=false;
        if(real==nuevo.getreal()&&img==nuevo.getimg()){
            igualdad=true;
        }
        return igualdad;
    }

}
