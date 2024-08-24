package Tarea15_Vida;

public class Cabeza {
    private String cerebro;
    private String[] ojos;
    private String nariz;
    private String[] orejas;

    public Cabeza(String cerebro,String[] ojos,String nariz,String[] orejas){
        this.cerebro=cerebro;
        this.nariz=nariz;
        this.ojos=ojos;
        this.orejas=orejas;
    }
    public String getCerebro() {
        return cerebro;
    }
    public String getNariz() {
        return nariz;
    }
    public String[] getOjos() {
        return ojos;
    }
    public String[] getOrejas() {
        return orejas;
    }

    public String leer(String novela){
        return "Estas leyendo la novela "+novela;
    }

    public void escucharmusica(String cancion){
        System.out.println("Estas escuchando al cancion "+cancion);
    }

    public String estudiar(String materia){
        return "Estas estudiando "+materia;
    }

    public void verTV(String programa){
        System.out.println("Estas viendo "+programa);
    }

    public void imprimircabeza(){
        System.out.println("El cerebro es "+cerebro);
        for (String ojo : ojos) {
            System.out.println("El ojo es el: "+ojo);
        }
        System.out.println("La nariz es: "+nariz);
        for (String oreja : orejas) {
            System.out.println("La oreja es la: "+oreja);
        }
    }
}
