package C;

public class Profesor {
    private int matricula;
    private String nombre;
    private String categoria;

    public Profesor(int matricula,String nombre,String categoria){
        this.categoria=categoria;
        this.nombre=nombre;
        this.matricula=matricula;
    }
    public String getCategoria() {
        return categoria;
    }
    public int getMatricula() {
        return matricula;
    }
    public String getNombre() {
        return nombre;
    }
    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }
    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

}
