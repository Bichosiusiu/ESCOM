package modelo;

public class Bebida implements Receta{//implementacion de la herencia multiple o interfaz receta
    private String nombre;
    private int precio;
    private String tipo;
    private String sabor;

    public Bebida() {//constructor vacio
    }

    
    public Bebida(String nombre, int precio, String tipo, String sabor) {//constructor con todos los atributos
        this.nombre = nombre;
        this.precio = precio;
        this.tipo = tipo;
        this.sabor = sabor;
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
        resultado.append("Tipo: ").append(tipo).append("\t");
        return resultado.toString();//retornamo la cadena
    }
    public String getTipo() {
        return tipo;
    }

    public String getSabor() {
        return sabor;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setPrecio(int precio) {
        this.precio = precio;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setSabor(String sabor) {
        this.sabor = sabor;
    }
    
    
}
