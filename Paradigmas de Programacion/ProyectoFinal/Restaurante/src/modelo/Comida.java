package modelo;

public class Comida implements Receta{//hernecia multiple o interfaz de receta
    private String nombre;
    private int precio;
    private String origen;

    public Comida() {//constructor vacio
    }

    
    public Comida(String nombre, int precio, String origen) {//constructor con todos los atributos
        this.nombre = nombre;
        this.precio = precio;
        this.origen = origen;
    }
    @Override
    public String getNombre() {
        return nombre;
    }
    @Override
    public int getPrecio() {
        return precio;
    }
    @Override
    public String imprimir(){//metodo para imprimir todos los atributos
        StringBuilder resultado = new StringBuilder();
        resultado.append("Nombre: ").append(nombre).append("\t");//se construye una gran cadena para devolver y asi se vea reflejada en el textarea
        resultado.append("Precio: ").append(precio).append("\t");//se construye la megacadena con append
        resultado.append("Origen: ").append(origen).append("\t");
        return resultado.toString();//retornamo la cadena
    }
    public String getOrigen() {
        return origen;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setPrecio(int precio) {
        this.precio = precio;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }
    
    
    
    
}
