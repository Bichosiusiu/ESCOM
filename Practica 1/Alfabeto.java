
public class Alfabeto {
    private String simbolos;

    public Alfabeto(String simbolos){
        this.simbolos=simbolos;
    }
    public String getSimbolos() {
        return simbolos;
    }

    public void setSimbolos(String simbolos) {
        this.simbolos = simbolos;
    }
    
    public boolean isValidChar(char caracter){
        return simbolos.contains(String.valueOf(caracter));
    }

    public boolean isValidString(String w1){
        for (char c : w1.toCharArray()) {
            if(!isValidChar(c)){
                return false;
            }
        }
        return true;
    }
    public char obtenerSimbolo(){
        int tam= simbolos.length();
        int numero = (int) (Math.random() * tam);
        return simbolos.charAt(numero);
    }
    public void potencia(String combinacionActual, String alfabeto, int potencia){
        if (potencia == 0) {
            // Imprime la combinación actual cuando la potencia llega a cero
            System.out.println(combinacionActual);
        } else if (potencia > 0) {
            // Genera recursivamente todas las combinaciones posibles
            for (int i = 0; i < alfabeto.length(); i++) {
                char letra = alfabeto.charAt(i);
                potencia(combinacionActual + letra, alfabeto, potencia - 1);
            }
        } else {
            // Genera recursivamente todas las combinaciones invertidas
            for (int i = alfabeto.length() - 1; i >= 0; i--) {
                char letra = alfabeto.charAt(i);
                potencia(combinacionActual + letra, alfabeto, potencia + 1);
            }
        }
    }
    }

