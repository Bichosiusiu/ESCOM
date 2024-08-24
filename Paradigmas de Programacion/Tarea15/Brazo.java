package Tarea15_Vida;

public class Brazo {
    private String antebrazo;
    private String triceps;
    private String biceps;
    private String mano;

    public Brazo(String antebrazo, String triceps, String biceps, String mano){
        this.antebrazo=antebrazo;
        this.triceps=triceps;
        this.biceps=biceps;
        this.mano=mano;
    }
    public String getAntebrazo() {
        return antebrazo;
    }
    public String getBiceps() {
        return biceps;
    }
    public String getMano() {
        return mano;
    }
    public String getTriceps() {
        return triceps;
    }

    public void subir(){
        System.out.println("Levantaste la mano");
    }

    public void bajar(){
        System.out.println("Bajaste la mano");
    }

    public void cargar(){
        System.out.println("Estas cargando algo");    
    }
}
