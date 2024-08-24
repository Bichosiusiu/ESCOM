package C;

import java.util.ArrayList;
import java.util.List;

public class Alumno {
    private int boleta;
    private String nombre;
    private String turno;
    private String modalidad;
    private List<Calificacion> calificaciones;

    public Alumno(int boleta,String nombre, String turno,String modalidad){
        this.boleta=boleta;
        this.nombre=nombre;
        this.turno=turno;
        this.modalidad=modalidad;
        this.calificaciones=new ArrayList<>();
    }
    public int getBoleta() {
        return boleta;
    }
    public List<Calificacion> getCalificaciones() {
        return calificaciones;
    }
    public String getModalidad() {
        return modalidad;
    }
    public String getNombre() {
        return nombre;
    }
    public String getTurno() {
        return turno;
    }
    public void setBoleta(int boleta) {
        this.boleta = boleta;
    }
    public void setCalificaciones(List<Calificacion> calificaciones) {
        this.calificaciones = calificaciones;
    }
    public void setModalidad(String modalidad) {
        this.modalidad = modalidad;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setTurno(String turno) {
        this.turno = turno;
    }
    public void imprimiralumno(){
        System.out.println("La boleta del alumno es: "+boleta);
        System.out.println("El nombre del alumno es: "+nombre);
        System.out.println("La modalidad del alumno es: "+modalidad);
        System.out.println("El turno del alumno es: "+turno);
    }
    public void agregarCalificacion(Calificacion calif){
        calificaciones.add(calif);
    }
    public Calificacion buscarCalificacion(String materia){
        for (Calificacion cal : calificaciones) {
            if (cal.getMateria().equals(materia)) {
                return cal; 
            }
        }
        return null;
    }
}
