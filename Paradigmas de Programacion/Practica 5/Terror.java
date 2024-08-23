//Titulo:Terror
//descripcion:Hacer un programa donde se pueda crear objetos de generos de peliculas y que cada 
//objeto herede atributos de clases pasadas, hacer metodos de compra de boletos y de impresion de
//datos asi como recaudacion
//fecha:28/11/2023
//version:2.5
//autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel, Mendoza Segura Fernando
package Practica5;
import java.sql.Time;

public class Terror extends Pelicula {//la clase terror con la extension de la clase pelicula
    private String PersonajeTerror;
    private double nivelTerror;

    //constructor que inicializa los atributos de la clase pelicula y los de terror mismos
    public Terror(String nombre,String peli,String ubicacion,Time duracion,Time horario,String director,double precio,String PersonajeTerror,double nivelTerror){
        super(duracion, horario, director, precio, nombre, ubicacion,peli);
        this.PersonajeTerror=PersonajeTerror;
        this.nivelTerror=nivelTerror;

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
    public double getNivelTerror() {
        return nivelTerror;
    }
    public String getPersonajeTerror() {
        return PersonajeTerror;
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
    public void setNivelTerror(double nivelTerror) {
        this.nivelTerror = nivelTerror;
    }
    public void setPersonajeTerror(String personajeTerror) {
        PersonajeTerror = personajeTerror;
    }
    //metodo para vender entrada en pelicula de terror
    public void venderEntrada(double precioEntrada){
        if(precioEntrada==precio){//si el precio de entrada es precio
        System.out.println("Entrada de "+nombre+" vendida en :"+precioEntrada);//imprime el nombre de la pelicula y el precio
        }else if(precioEntrada<precio){//si es menor
        System.out.println("Cantidad insuficiente de dinero");//no le alcanza
        }else{
            System.out.println("Su cambio es "+(precioEntrada-precio));//si es mayor, te da cambio
        }
    }
    public void imprimirInformacion(){//imprime la pelicula de terror
        System.out.println("\t\tCARTELERA DE CINE");
        System.out.println("\t\tPELICULA DE TERROR");
        System.out.println("El Cine es: "+nombre);
        System.out.println("La Ubicacion es: "+ubicacion);
        System.out.println("La pelicula es: "+peli);
        System.out.println("El director es: "+director);
        System.out.println("El horario es: "+horario);
        System.out.println("El precio es: "+precio);
        System.out.println("El numero del personaje de terror es: "+PersonajeTerror);
        System.out.println("El nivel de miedo es: "+nivelTerror);
    }
}
