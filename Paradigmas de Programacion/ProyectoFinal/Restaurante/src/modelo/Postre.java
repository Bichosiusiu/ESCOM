package modelo;

public class Postre implements Receta{//herencia multiple o interfaz de receta
    private String nombre;
    private int precio;
    private String sabor;
    private String origen;

    public Postre() {//contructor vacio
    }
    
    

    public Postre(String nombre, int precio, String sabor, String origen) {//constructor con todos los atributos 
        this.nombre = nombre;
        this.precio = precio;
        this.sabor = sabor;
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
        StringBuilder resultado = new StringBuilder();//se construye una gran cadena para devolver y asi se vea reflejada en el textarea
        resultado.append("Nombre: ").append(nombre).append("\t");//se construye la megacadena con append
        resultado.append("Precio: ").append(precio).append("\t");
        resultado.append("Sabor: ").append(sabor).append("\t");
        resultado.append("Origen: ").append(origen).append("\t");
        return resultado.toString();//retornamos la cadena
    }

    public String getSabor() {
        return sabor;
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

    public void setSabor(String sabor) {
        this.sabor = sabor;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }
    
    
}
