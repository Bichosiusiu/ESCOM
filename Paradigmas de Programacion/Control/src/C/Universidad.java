package C;

import java.util.ArrayList;
import java.util.List;

public class Universidad {
    private String nombre;
    private String direccion;
    private List<Grupo> grupos;
    
    public Universidad(String nombre,String direccion){
        this.nombre=nombre;
        this.direccion=direccion;
        this.grupos=new ArrayList<>();
    }

    public String getDireccion() {
        return direccion;
    }
    public List<Grupo> getGrupos() {
        return grupos;
    }
    public String getNombre() {
        return nombre;
    }
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }
    public void setGrupos(List<Grupo> grupos) {
        this.grupos = grupos;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public boolean buscarGrupo1(String grupo){
        for (Grupo grup : grupos) {
            if (grup.getGrupo().equals(grupo)) {
                return true; 
            }
        }
        return false;
    }
    public Grupo buscarGrupo2(String grupo){
        for (Grupo grup : grupos) {
            if (grup.getGrupo().equals(grupo)) {
                return grup; 
            }
        }
        return null;
    }
    public void agregarGrupo(Grupo grupo){
        grupos.add(grupo);
    }
}
