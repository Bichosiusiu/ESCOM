package Tarea18_Interfaces;
public class Profesor {
    private String clave;
    private String nombre;
    private String apellido;
    private String especialidad;
    private String cargo;

    public Profesor(String clave,String nombre,String apellido,String especialidad,String cargo){
        this.apellido=apellido;
        this.cargo=cargo;
        this.clave=clave;
        this.especialidad=especialidad;
        this.nombre=nombre;
    }
    public String getApellido() {
        return apellido;
    }
    public String getCargo() {
        return cargo;
    }
    public String getClave() {
        return clave;
    }
    public String getEspecialidad() {
        return especialidad;
    }
    public String getNombre() {
        return nombre;
    }
    public void setApellido(String apellido) {
        this.apellido = apellido;
    }
    public void setCargo(String cargo) {
        this.cargo = cargo;
    }
    public void setClave(String clave) {
        this.clave = clave;
    }
    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void dictarClase(){
        System.out.println("El profesor "+nombre+" esta dictando");
    }
    public void calificarExamenes(Alumno a,int calificacion){
        System.out.println("El alumno "+a.getNombre()+" consiguio una calificacion de "+calificacion);
    }
}
