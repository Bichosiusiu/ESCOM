//Titulo:Cartelera
//descripcion:Hacer un programa donde se pueda crear objetos de generos de peliculas y que cada 
//objeto herede atributos de clases pasadas, hacer metodos de compra de boletos y de impresion de
//datos asi como recaudacion
//fecha:28/11/2023
//version:2.5
//autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel, Mendoza Segura Fernando
package Practica5;
import java.sql.Time;
public class Cartelera {
    public static void main(String[] args) {
        Time duracionTerror = Time.valueOf("1:35:48");//declaracion de tipo time
        Time horario = Time.valueOf("12:00:00");//declaracion de tipo time
        Time duracionComedia = Time.valueOf("1:40:27");//declaracion de tipo time
        Time horarioComedia = Time.valueOf("1:50:00");//declaracion de tipo time
        Time duracionAccion = Time.valueOf("1:47:55");//declaracion de tipo time
        Time horarioAccion = Time.valueOf("3:45:00");  //declaracion de tipo time     
        Terror peliTerror = new Terror("Americas", "Viernes 13", "Plaza las Americas",duracionTerror , horario, "Sean S. Cunningham", 65.7, "Jason", 4.2);
        //inicializacion del la pelicula de terror
        Comedia peliComedia=new Comedia("Americas", "Plaza las Americas", "Hangover", duracionComedia, horarioComedia, "Todd Phillips", 53.3, 4, 230, 4.7);
        //inicializacion de la pelicula de comedia
        Accion peliAccion=new Accion("Americas", "Plaza las Americas", "Terminator", duracionAccion, horarioAccion, "James Cameron", 42.7, 10, 3, 3.8);
        //inicializacion de la pelicula de accion
        peliTerror.imprimirInformacion();// imprimir informacion de pelicula de terror
        peliComedia.imprimirInformacion();// imprimir informacion de pelicula de comedia
        peliAccion.imprimirInformacion();// imprimir informacion de pelicula de accion
        peliTerror.comprarEntradas(2);//compra de boletos para peli de terror
        peliComedia.comprarEntradas(5);//compra de boletos para peli de comedia
        peliAccion.comprarEntradas(10);//compra de boletos para peli de accion 
        System.out.println("La recaudacion de "+peliTerror.getPeli()+" es de: "+peliTerror.recaudacion());// impresion de la recaudacion de pelicula de terror
        System.out.println("La recaudacion de "+peliComedia.getPeli()+" es de: "+peliComedia.recaudacion());// impresion de la recaudacion de pelicula de comedia
        System.out.println("La recaudacion de "+peliAccion.getPeli()+" es de: "+peliAccion.recaudacion());// impresion de la recaudacion de pelicula de accion
    }
}
