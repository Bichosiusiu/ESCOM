//Titulo:Comedia
//descripcion:Hacer un programa donde se pueda crear objetos de generos de peliculas y que cada 
//objeto herede atributos de clases pasadas, hacer metodos de compra de boletos y de impresion de
//datos asi como recaudacion
//fecha:28/11/2023
//version:2.5
//autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel, Mendoza Segura Fernando
package Practica5;
import java.sql.Time;
public class Comedia extends Pelicula{//clase comedia con extension a pelicula
    private int numPP;
    private int numChistes;
    private double nivelFelicidad;

    //constructor con atributos heredados y no heredados de comedia
    public Comedia(String nombre,String ubicacion,String peli,Time duracion,Time horario,String director,double precio,int numPP,int numChistes,double nivelFelicidad){
        super(duracion, horario, director, precio, nombre, ubicacion,peli);
        this.numPP=numPP;
        this.numChistes=numChistes;
        this.nivelFelicidad=nivelFelicidad;
    }
    //metodos getter
    @Override
    public String getDirector() {
        return super.getDirector();
    }
    @Override
    public Time getDuracion() {
        return super.getDuracion();
    }
    @Override
    public Time getHorario() {
        return super.getHorario();
    }
    @Override
    public String getNombre() {
        return super.getNombre();
    }
    @Override
    public double getPrecio() {
        return super.getPrecio();
    }
    @Override
    public String getUbicacion() {
        return super.getUbicacion();
    }
    @Override
    public String getPeli() {
        return super.getPeli();
    }
    public double getNivelFelicidad() {
        return nivelFelicidad;
    }
    public int getNumChistes() {
        return numChistes;
    }
    public int getNumPP() {
        return numPP;
    }
    //metodos setter
    @Override
    public void setDirector(String director) {
        super.setDirector(director);
    }
    @Override
    public void setDuracion(Time duracion) {
        super.setDuracion(duracion);
    }
    @Override
    public void setHorario(Time horario) {
        super.setHorario(horario);
    }
    @Override
    public void setNombre(String nombre) {
        super.setNombre(nombre);
    }
    @Override
    public void setPrecio(double precio) {
        super.setPrecio(precio);
    }
    @Override
    public void setUbicacion(String ubicacion) {
        super.setUbicacion(ubicacion);
    }
    @Override
    public void setPeli(String peli) {
        super.setPeli(peli);
    }
    public void setNivelFelicidad(double nivelFelicidad) {
        this.nivelFelicidad = nivelFelicidad;
    }
    public void setNumChistes(int numChistes) {
        this.numChistes = numChistes;
    }
    public void setNumPP(int numPP) {
        this.numPP = numPP;
    }
    //metodo para vender entrada con comedia
    public void venderEntrada(double precioEntrada){
        if(precioEntrada==precio){// si el precio de entrada es igual al precio
        System.out.println("Entrada de "+nombre+" comedia vendida en :"+precioEntrada);//vende la entrada de comedia 
        }else if(precioEntrada<precio){//si es menor
        System.out.println("Cantidad insuficiente de dinero");//no le alcanza
        }else{
            System.out.println("Su cambio es "+(precioEntrada-precio));// si es mayor , devuelve el cambio
        }
    }
    public void imprimirInformacion(){//impresion de informacion de comedia
        System.out.println("\t\tCARTELERA DE CINE");
        System.out.println("\t\tPELICULA DE COMEDIA");
        System.out.println("El Cine es: "+nombre);
        System.out.println("La Ubicacion es: "+ubicacion);
        System.out.println("La pelicula es: "+peli);
        System.out.println("El director es: "+director);
        System.out.println("El horario es: "+horario);
        System.out.println("El precio es: "+precio);
        System.out.println("El numero de personajes es: "+numPP);
        System.out.println("El numero de chistes es: "+numChistes);
        System.out.println("El nivel de felicidad es:"+nivelFelicidad);
    }
}

