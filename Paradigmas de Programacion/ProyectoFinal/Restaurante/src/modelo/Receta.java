package modelo;

public interface Receta {//interface receta
    String getNombre();//metodo general para devolver el nombre de comida,postre o bebida
    int getPrecio();//metodo general para devolver el precio de comida,postre o bebida
    String imprimir();//metodo general para imprimir dependiendo de que objeto sea, cada clase colocara lo que devolvera
}
