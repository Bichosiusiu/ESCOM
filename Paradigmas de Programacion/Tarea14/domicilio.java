package Tarea14_Persona;

public class domicilio {
    private String calle;
    private int numero;

    public domicilio(int numero,String calle){
        this.numero=numero;
        this.calle=calle;
    }
    public String getCalle() {
        return calle;
    }
    public int getNumero() {
        return numero;
    }
    public void imprimedom(){
        System.out.println("El numero es: "+numero);
        System.out.println("La calle es: "+calle);
    }
}
