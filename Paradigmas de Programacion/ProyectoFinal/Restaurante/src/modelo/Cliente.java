package modelo;

public class Cliente extends Persona{//herencia de persona

    public Cliente() {
    }

    public Cliente(String nombre, String direccion, int edad) {//constructor de cliente
        super(nombre, direccion, edad);//instanciamos los atributos de persona para cliente
    }
    @Override
    public String imprimir(){
       return null;
    }
    
}
