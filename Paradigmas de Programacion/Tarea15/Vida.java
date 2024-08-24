package Tarea15_Vida;

public class Vida {
    public static void main(String[] args) {
        Brazo brazo1=new Brazo("Derecho", "Derecho", "Derecho", "Derecho");
        Brazo brazo2=new Brazo("Izquierdo", "Izquierdo", "Izquierdo", "Izquierdo");
        String[] ojos={"derecho","izquierdo"};
        String[] orejas={"derecho","izquierdo"};
        String[] ventriculos={"derecho","izquierdo"};
        String[] auriculas={"derecha","izquierda"};
        String[]piernas={"derecha","izquierda"};
        Brazo[] brazos = {brazo1,brazo2};
        Humano persona1 = new Humano(brazos, piernas, orejas, "chata", "Hemisferio derecho", ventriculos, auriculas, "aorta", ojos);
        persona1.imprimir();
    }   
}
