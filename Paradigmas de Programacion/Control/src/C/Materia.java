package C;

import java.util.ArrayList;
import java.util.List;
public class Materia {
    private String nombre;
    private Profesor prof;
    private List<Alumno> alumnos;
    
    public Materia(String nombre,Profesor prof){
        this.nombre=nombre;
        this.prof=prof;
        this.alumnos=new ArrayList<>();
    }
    public List<Alumno> getAlumnos() {
        return alumnos;
    }
    public String getNombre() {
        return nombre;
    }
    public Profesor getProf() {
        return prof;
    }
    public void setAlumnos(List<Alumno> alumnos) {
        this.alumnos = alumnos;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setProf(Profesor prof) {
        this.prof = prof;
    }
    public void agregarAlumno(Alumno alumno){
        alumnos.add(alumno);
    }
    public void imprimirMateria(){
        System.out.println("El profesor es: "+prof.getNombre());
        System.out.println("La matricula es: "+prof.getMatricula());
        System.out.println("La categoria del profesor es: "+prof.getCategoria());
        for (Alumno al : alumnos) {
            al.imprimiralumno();
        }
    }
    public Alumno buscarAlumno(int boleta){
        for (Alumno al : alumnos) {
            if (al.getBoleta()==boleta){
                return al; 
            }
        }
        return null;
    }
}

