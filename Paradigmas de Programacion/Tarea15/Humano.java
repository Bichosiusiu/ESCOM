package Tarea15_Vida;

public class Humano {
    private Cabeza cabeza;
    private Corazon corazon;
    private Brazo[] brazos;
    private String[] piernas;

    public Humano( Brazo[] brazos, String[] piernas,String[] orejas,String nariz,String cerebro, String ventriculos[],String auriculas[],String aorta, String[] ojos){
        this.brazos=brazos;
        this.piernas=piernas;
        cabeza=new Cabeza(cerebro, ojos, nariz, orejas);
        corazon=new Corazon(ventriculos, auriculas, aorta);
    }

    public Brazo[] getBrazos() {
        return brazos;
    }
    public Cabeza getCabeza() {
        return cabeza;
    }
    public Corazon getCorazon() {
        return corazon;
    }
    public String[] getPiernas() {
        return piernas;
    }

    public void nacer(){
        System.out.println("Naciste");
    }

    public void crecer(){
        System.out.println("Haz crecido");
    }

    public String estudiarPOO(){
        return"Certificado de POO";
    }

    public void vacacionar(){
        System.out.println("Estas de vacaciones");
    }

    public void imprimir(){
        for(int i=0;i<brazos.length;i++){
            System.out.println("El antebrazo es:"+brazos[i].getAntebrazo());
            System.out.println("El triceps es:"+brazos[i].getTriceps());
            System.out.println("El biceps es: "+brazos[i].getBiceps());
            System.out.println("La mano es la: "+brazos[i].getMano());
        }
        for (String pierna : piernas) {
            System.out.println("La pierna es la: "+pierna);
        }
        cabeza.imprimircabeza();
        corazon.imprimircorazon();
    }
}
