package Tarea18_Interfaces;
public class Alumno implements MateriaAlumno{
    private String nombre;
    private String clave;
    private String apellido;
    private double creditos;

    public Alumno(String nombre,String clave,double creditos,String apellidos){
        this.clave=clave;
        this.apellido=apellidos;
        this.nombre=nombre;
        this.creditos=creditos;
    }
    public String getClave() {
        return clave;
    }
    public String getApellido() {
        return apellido;
    }
    public String getNombre() {
        return nombre;
    }
    public double getCreditos() {
        return creditos;
    }
    public void setClave(String clave) {
        this.clave = clave;
    }
    public void setApellido(String apellido) {
        this.apellido = apellido;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setCreditos(double creditos) {
        this.creditos = creditos;
    }
    @Override
    public void guardar(Object o) {
        if (o instanceof Programa ) {
            ((Programa) o).agregarAlumno(this);
        }
    }
    @Override
    public void eliminar(Object o) {
        if (o instanceof Programa) {
            ((Programa) o).eliminarAlumno(this);
        }
    }
    public void pagar(double cantidad){
        System.out.println("El alumno "+nombre+" ha pagado "+cantidad);
    }
    public void retirarse(int hora){
        System.out.println("El alumno "+nombre+"se fue a las "+hora);
    }
    public void aplazar(int dias){
        System.out.println("El alumno "+nombre+" ha aplazado su trabajo "+dias);
    }
    

}

