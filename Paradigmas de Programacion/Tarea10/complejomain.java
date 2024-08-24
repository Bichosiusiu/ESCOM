package Tarea10_Complejo;
import java.util.Scanner;
public class complejomain {
    public static void main(String[] args){
        complejo numero1,numero2,suma;
        boolean i=true;
        Scanner scanner = new Scanner(System.in);
        while(i!=false){
            System.out.println("Escoge que quieres hacer con los numeros complejos:");
            System.out.println("1) Sumar numeros complejos");
            System.out.println("2) Comparar numeros complejos");
            System.out.println("3) Salir");
            int decision=scanner.nextInt();
            switch (decision) {
                case 1:
                    System.out.println("Escribe el primer numero complejo: ");
                    System.out.println("Escribe la parte real: ");
                    double x=scanner.nextDouble();
                    System.out.println("Escribe la parte imaginaria: ");
                    double y=scanner.nextDouble();
                    System.out.println("Escribe el segundo numero complejo: ");
                    System.out.println("Escribe la parte real: ");
                    double z=scanner.nextDouble();
                    System.out.println("Escribe la parte imaginaria: ");
                    double w=scanner.nextDouble();
                    numero1=new complejo(x, y);
                    numero2=new complejo(z,w);
                    suma=numero1.getsuma(numero2);
                    if(suma.getimg()<0){
                    System.out.println("La suma es "+suma.getreal()+suma.getimg()+"i");
                    }else{
                    System.out.println("La suma es "+suma.getreal()+"+"+suma.getimg()+"i");
                    }break;
                case 2:
                    System.out.println("Escribe el primer numero complejo: ");
                    System.out.println("Escribe la parte real: ");
                     x=scanner.nextDouble();
                    System.out.println("Escribe la parte imaginaria: ");
                     y=scanner.nextDouble();
                    System.out.println("Escribe el segundo numero complejo: ");
                    System.out.println("Escribe la parte real: ");
                     z=scanner.nextDouble();
                    System.out.println("Escribe la parte imaginaria: ");
                     w=scanner.nextDouble();
                    numero1=new complejo(x, y);
                    numero2=new complejo(z,w);
                    boolean comp=numero1.comparar(numero2);
                    if(comp==true){
                        System.out.println("Los numeros complejos son iguales.");
                    }
                    else{
                        System.out.println("Los numeros complejos son diferentes.");
                    }
                    break;
                case 3:
                    i=false;
                    break;
                default:
                    System.out.println("Opcion Invalida");
                    break;
            }
               
        }
    scanner.close();
    }
    
}

