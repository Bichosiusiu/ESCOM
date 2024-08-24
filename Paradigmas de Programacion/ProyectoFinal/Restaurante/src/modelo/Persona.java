package modelo;

abstract class Persona {
    protected String nombre;
    protected String direccion;
    protected int edad;

    public Persona() {//constructor vacio
    }

    public Persona(String nombre, String direccion, int edad) {//constructor con todos los atributos
        this.nombre = nombre;
        this.direccion = direccion;
        this.edad = edad;
    }

    public String getNombre() {
        return nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public int getEdad() {
        return edad;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }
    
    public abstract String imprimir();
}
