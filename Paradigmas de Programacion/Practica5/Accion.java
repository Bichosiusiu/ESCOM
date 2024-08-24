//Titulo:Accion
//descripcion:Hacer un programa donde se pueda crear objetos de generos de peliculas y que cada 
//objeto herede atributos de clases pasadas, hacer metodos de compra de boletos y de impresion de
//datos asi como recaudacion
//fecha:28/11/2023
//version:2.5
//autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel, Mendoza Segura Fernando
package Practica5;
import java.sql.Time;
public class Accion extends Pelicula{//crear clase para una pelicula de accion,contiene la extension a pelicula
    private int numPersecuciones;
    private int numEnfrentamientos;
    private double nivelViolencia;

    public Accion(String nombre,String ubicacion,String peli,Time duracion,Time horario,String director,double precio,int numPersecuciones,int numEnfrentamientos, double nivelViolencia){//constructor con todos los parametros heredados y no heredados
        super(duracion, horario, director, precio, nombre, ubicacion,peli);
        this.nivelViolencia=nivelViolencia;
        this.numEnfrentamientos=numEnfrentamientos;
        this.numPersecuciones=numPersecuciones;

    }
    //metodos getters 
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
    public double getNivelViolencia() {
        return nivelViolencia;
    }
    public int getNumEnfrentamientos() {
        return numEnfrentamientos;
    }
    public int getNumPersecuciones() {
        return numPersecuciones;
    }
    // metodos setter
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
    public void setNivelViolencia(double nivelViolencia) {
        this.nivelViolencia = nivelViolencia;
    }
    public void setNumEnfrentamientos(int numEnfrentamientos) {
        this.numEnfrentamientos = numEnfrentamientos;
    }
    public void setNumPersecuciones(int numPersecuciones) {
        this.numPersecuciones = numPersecuciones;
    }
    public void venderEntrada(double precioEntrada){//metodo que si se llama en esta clase, aparece todo esto
        if(precioEntrada==precio){// si el precio de entrada es igual al precio
        System.out.println("Entrada de "+ nombre +" vendida en :"+precioEntrada);// compras entrada
        }else if(precioEntrada<precio){// si es menor
        System.out.println("Cantidad insuficiente de dinero");// no te alcanza
        }else{
            System.out.println("Su cambio es "+(precioEntrada-precio));//si es mayor, te da cambio
        }
    }
    public void imprimirInformacion(){// impresion de datos para la pelicula de accion 
        System.out.println("\t\tCARTELERA CINE");
        System.out.println("\t\tPELICULA DE ACCION");
        System.out.println("El Cine es: "+nombre);
        System.out.println("La Ubicacion es: "+ubicacion);
        System.out.println("La pelicula es: "+peli);
        System.out.println("El director es: "+director);
        System.out.println("El horario es: "+horario);
        System.out.println("El precio es: "+precio);
        System.out.println("El numero de persecuciones es: "+numPersecuciones);
        System.out.println("El numero de enfrentamientos es:"+numEnfrentamientos);
        System.out.println("El nivel de felicidad es:"+nivelViolencia);
    }
}
