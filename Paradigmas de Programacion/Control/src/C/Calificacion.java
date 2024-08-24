package C;

public class Calificacion {
    private String materia;
    private int calif;

    public Calificacion(String materia,int calif){
        this.materia=materia;
        this.calif=calif;
    }

    public int getCalif() {
        return calif;
    }
    public String getMateria() {
        return materia;
    }
    public void setCalif(int calif) {
        this.calif = calif;
    }
    public void setMateria(String materia) {
        this.materia = materia;
    }
    public void imprimirCalificacion(){
        System.out.println("La materia es: "+materia);
        System.out.println("La calificacion es:"+calif);
    }
    
}
