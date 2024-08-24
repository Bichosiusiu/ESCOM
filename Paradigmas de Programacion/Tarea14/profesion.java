package Tarea14_Persona;

public class profesion {
    private String nivel;
    private String escuela;

    public profesion(String nivel,String escuela){
        this.nivel=nivel;
        this.escuela=escuela;
    }
    public String getnivel(){
        return nivel;
    }
    public String getesc(){
        return escuela;
    }
}
