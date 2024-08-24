package Tarea15_Vida;

public class Corazon {
    private String ventriculos[];
    private String auriculas[];
    private String aorta;

    public Corazon(String ventriculos[],String auriculas[],String aorta ){
        this.aorta=aorta;
        this.auriculas=auriculas;
        this.ventriculos=ventriculos;
    }
    public String getAorta() {
        return aorta;
    }
    public String[] getAuriculas() {
        return auriculas;
    }
    public String[] getVentriculos() {
        return ventriculos;
    }

    public void bombear(){
        System.out.println("Esta bombeando tu corazon");
    }

    public void parocardiaco(){
        System.out.println("Moriste");
    }

    public void reanimar(){
        System.out.println("Reviviste");
    }

    public void imprimircorazon(){
       for (String auri : auriculas) {
        System.out.println("La auricula es la:"+auri);
       }
       for(String ven : ventriculos){
        System.out.println("El ventriculo es: "+ven);
       }
       System.out.println("la aorta es: "+aorta);
    }
}
