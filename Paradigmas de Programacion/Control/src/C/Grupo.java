package C;

import java.util.ArrayList;
import java.util.List;

public class Grupo {
    private String grupo;
    private List<Materia> materias;

    public Grupo(String grupo){
        this.grupo=grupo;
        this.materias=new ArrayList<>();
    }

    public String getGrupo() {
        return grupo;
    }
    public List<Materia> getMaterias() {
        return materias;
    }
    public void setGrupo(String grupo) {
        this.grupo = grupo;
    }
    public void setMaterias(List<Materia> materias) {
        this.materias = materias;
    }
    public void agregarMateria(Materia materia){
        materias.add(materia);
    }
    public boolean buscarMateria1(String materia){
        for (Materia mat : materias) {
            if (mat.getNombre().equals(materia)) {
                return true; 
            }
        }
        return false;
    }
    public Materia buscarMateria2(String materia){
        for (Materia mat : materias) {
            if (mat.getNombre().equals(materia)) {
                return mat; 
            }
        }
        return null;
    }
    public void imprimirinformacion(){
        System.out.println("El grupo es: "+grupo);
        for (Materia mat : materias) {
            System.out.println("La materia es: "+mat.getNombre());
            mat.imprimirMateria();
        }
    }
}

