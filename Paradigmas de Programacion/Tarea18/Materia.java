package Tarea18_Interfaces;

public class Materia implements MateriaAlumno{
    private String nombre;
    private String clave;
    private int modulo;
    private String programa;

    public Materia(String nombre,String clave,int modulo,String programa){
        this.clave=clave;
        this.modulo=modulo;
        this.nombre=nombre;
        this.programa=programa;
    }
    public String getClave() {
        return clave;
    }
    public int getModulo() {
        return modulo;
    }
    public String getNombre() {
        return nombre;
    }
    public String getPrograma() {
        return programa;
    }
    public void setClave(String clave) {
        this.clave = clave;
    }
    public void setModulo(int modulo) {
        this.modulo = modulo;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setPrograma(String programa) {
        this.programa = programa;
    }
    @Override
    public void guardar(Object o) {
        if (o instanceof Programa) {
            ((Programa) o).agregarMateria(this);
        }
    }
    @Override
    public void eliminar(Object o) {
        if (o instanceof Programa) {
            ((Programa) o).eliminarMateria(this);
        }
    }
}

