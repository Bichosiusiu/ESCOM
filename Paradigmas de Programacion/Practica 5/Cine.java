//Titulo:Cine
//descripcion:Hacer un programa donde se pueda crear objetos de generos de peliculas y que cada 
//objeto herede atributos de clases pasadas, hacer metodos de compra de boletos y de impresion de
//datos asi como recaudacion
//fecha:28/11/2023
//version:2.5
//autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel, Mendoza Segura Fernando
package Practica5;
public class Cine {//clase cine, clase padre de todas
    protected String nombre;
    protected String ubicacion;

    public Cine(String nombre, String ubicacion){//constructor
        this.nombre=nombre;
        this.ubicacion=ubicacion;
    }
    //metodos getter
    public String getNombre() {
        return nombre;
    }
    public String getUbicacion() {
        return ubicacion;
    }
    //metodos setter
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setUbicacion(String ubicacion) {
        this.ubicacion = ubicacion;
    }
    //metodo para vender entrada en cine
    public void venderEntrada(double precioEntrada){
        System.out.println("Entrada Vendida con exito");//vende la entrada con exito
    }
}
