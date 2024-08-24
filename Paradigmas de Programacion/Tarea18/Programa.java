package Tarea18_Interfaces;
import java.util.ArrayList;
import java.util.List;
public class Programa {
    private String clave;
    private String nombre;
    private int duracion;
    private double costo;
    private String aula;
    private List<Materia> materias;
    private List<Profesor> profesores;
    private List<Alumno> alumnos;


    public Programa(String clave,String nombre,int duracion,double costo,String aula){
        this.aula=aula;
        this.nombre=nombre;
        this.clave=clave;
        this.costo=costo;
        this.duracion=duracion;
        this.materias=new ArrayList<>();
        this.profesores=new ArrayList<>();
        this.alumnos=new ArrayList<>();
    }
    public String getAula() {
        return aula;
    }
    public String getClave() {
        return clave;
    }
    public double getCosto() {
        return costo;
    }
    public int getDuracion() {
        return duracion;
    }
    public List<Materia> getMaterias() {
        return materias;
    }
    public String getNombre() {
        return nombre;
    }
    public List<Profesor> getProfesores() {
        return profesores;
    }
    public List<Alumno> getAlumnos() {
        return alumnos;
    }
    public void setAula(String aula) {
        this.aula = aula;
    }
    public void setClave(String clave) {
        this.clave = clave;
    }
    public void setCosto(double costo) {
        this.costo = costo;
    }
    public void setDuracion(int duracion) {
        this.duracion = duracion;
    }
    public void setMaterias(List<Materia> materias) {
        this.materias = materias;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setProfesores(List<Profesor> profesores) {
        this.profesores = profesores;
    }
    public void setAlumnos(List<Alumno> alumnos) {
        this.alumnos = alumnos;
    }
    public void sancionarAlumno(Alumno alumno){
        System.out.println("El alumno "+alumno.getNombre()+"ha sido sancionado con exito");
    }
    public void cancelarCurso(Programa programa){
        programa=null;
    }
    public void agregarMateria(Materia m){
        materias.add(m);
    }
    public void eliminarMateria(Materia m){
        materias.remove(m);
    }
    public void agregarAlumno(Alumno a){
        alumnos.add(a);
    }
    public void eliminarAlumno(Alumno a){
        alumnos.remove(a);
    }
}