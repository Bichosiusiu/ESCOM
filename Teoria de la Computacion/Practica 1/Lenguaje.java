import java.util.*;
public class Lenguaje {
    private Alfabeto alf ; 
    
    public Lenguaje(Alfabeto alf){
        this.alf=alf;
    }

    public List<String> generador(int np, int l){
        List<String> lenguaje = new ArrayList<>();
        for(int i=0;i<np;i++){
            StringBuilder palabra = new StringBuilder();
            for(int j=0;j<l;j++){
            char c= alf.obtenerSimbolo();
            palabra.append(c);
            }
            lenguaje.add(palabra.toString());
        }
        return lenguaje;
    }
}
