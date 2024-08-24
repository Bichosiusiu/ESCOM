//Titulo:Pelicula
//descripcion:Hacer un programa donde se pueda crear objetos de generos de peliculas y que cada 
//objeto herede atributos de clases pasadas, hacer metodos de compra de boletos y de impresion de
//datos asi como recaudacion
//fecha:28/11/2023
//version:2.5
//autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel, Mendoza Segura Fernando
package Practica5;
import java.sql.Time;

public class Pelicula extends Cine{// clase pelicula que se extiende de cine
    protected Time duracion;
    protected Time horario;
    protected String director;
    protected double precio;
    protected String peli;
    protected int entradasVendidas;
    
    //constructor de pelicula que hereda los atributos de cine 
    public Pelicula(Time duracion, Time horario,String director, double precio,String nombre, String ubicacion,String peli){ 
        super(nombre,ubicacion);
        this.duracion=duracion;
        this.horario=horario;
        this.director=director;
        this.precio=precio;
        this.peli=peli;
        this.entradasVendidas=0;
    }
    //metodos getter
    @Override
    public String getNombre() {
        return super.getNombre();
    }
    @Override
    public String getUbicacion() {
        return super.getUbicacion();
    }
    public String getDirector() {
        return director;
    }
    public Time getDuracion() {
        return duracion;
    }
    public Time getHorario() {
        return horario;
    }
    public double getPrecio() {
        return precio;
    }
    public String getPeli() {
        return peli;
    }
    //metodos setter
    @Override
    public void setNombre(String nombre) {
        super.setNombre(nombre);
    }
    @Override
    public void setUbicacion(String ubicacion) {
        super.setUbicacion(ubicacion);
    }
    public void setDirector(String director) {
        this.director = director;
    }
    public void setDuracion(Time duracion) {
        this.duracion = duracion;
    }
    public void setHorario(Time horario) {
        this.horario = horario;
    }
    public void setPrecio(double precio) {
        this.precio = precio;
    }
    public void setPeli(String peli) {
        this.peli = peli;
    }
    public int getEntradasVendidas() {
        return entradasVendidas;
    }
    public void setEntradasVendidas(int entradasVendidas) {
        this.entradasVendidas = entradasVendidas;
    }
    //metodo para vender entrada en pelicula
    public void venderEntrada(double precioEntrada){
        if(precioEntrada==precio){//si el precio de entrada y el precio son el mismo
        System.out.println("Entrada vendida en :"+precioEntrada);//la entrada se vende en tal precio
        }else if(precioEntrada<precio){//si es menor
        System.out.println("Cantidad insuficiente de dinero");//no le alcanza
        }else{
            System.out.println("Su cambio es "+(precioEntrada-precio));//si es mayor,devuelve cambio
        }
    }
    //metodo para comprar entrada
    public void comprarEntradas(int boletos){
        entradasVendidas+=boletos;//se aumenta el numero de boletos a las entradas vendidas
    }
    //metodo para la recaudacion
    public double recaudacion(){
        return entradasVendidas*precio;//retorna el precio por el numero de entradas vendidas y con eso se calcula la recaudacion
    }
}
