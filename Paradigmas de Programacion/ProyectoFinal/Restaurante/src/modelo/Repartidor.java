package modelo;

public class Repartidor extends Persona{//herencia de persona
    String transporte;
    String tiempo;
    double score;

    public Repartidor() {//constructor vacio
    }

    public Repartidor(String transporte, String tiempo, double score) {//constructor con todos los atributos de repartidor
        this.transporte = transporte;
        this.tiempo = tiempo;
        this.score = score;
    }

    public Repartidor(String transporte, String tiempo, double score, String nombre, String direccion, int edad) {//constructor con todos los atributos, incluyendo la herencia
        super(nombre, direccion, edad);//se inicializa la herencia
        this.transporte = transporte;
        this.tiempo = tiempo;
        this.score = score;
    }

    public String getTransporte() {
        return transporte;
    }

    public String getTiempo() {
        return tiempo;
    }

    public double getScore() {
        return score;
    }

    public void setTransporte(String transporte) {
        this.transporte = transporte;
    }

    public void setTiempo(String tiempo) {
        this.tiempo = tiempo;
    }

    public void setScore(double score) {
        this.score = score;
    }
    @Override
    public String imprimir(){//metodo para imprimir todos los atributos
        StringBuilder resultado = new StringBuilder();//se construye una gran cadena para devolver y asi se vea reflejada en el textarea
        resultado.append("Nombre: ").append(nombre).append("\t");//se construye la megacadena con append
        resultado.append("Direccion: ").append(direccion).append("\t");
        resultado.append("Edad: ").append(edad).append("\t");
        resultado.append("Medio de transporte: ").append(transporte).append("\t");
        resultado.append("Tiempo de espera estimado: ").append(tiempo).append("\t");
        resultado.append("Score: ").append(score).append("\t");
        return resultado.toString();//retornamos la cadena
    }
}
