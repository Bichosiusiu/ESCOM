package modelo;
import java.util.ArrayList;
import java.util.List;
public class Restaurante {
    private String nombre;
    private String direccion;
    private String telefono;
    private List<Receta> menu;
    private List<Pedido> pedidos;

    public Restaurante() {//constructor vacio  con las inicializaciones
        this.menu = new ArrayList<>();//inicializamos la composicion receta
        this.pedidos=new ArrayList<>();//inicializamos la composicion pedidos
    }
    
    

    public Restaurante(String nombre, String direccion, String telefono) {//constructor general
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.menu = new ArrayList<>();
        this.pedidos=new ArrayList<>();
    }

    public String getNombre() {
        return nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public String getTelefono() {
        return telefono;
    }

    public List<Receta> getMenu() {
        return menu;
    }

    public List<Pedido> getPedidos() {
        return pedidos;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public void setMenu(List<Receta> menu) {
        this.menu = menu;
    }

    public void setPedidos(List<Pedido> pedidos) {
        this.pedidos = pedidos;
    }
    public void agregarAlMenu(Receta m) {//metodo para agregar al menu
        menu.add(m);//añadimos con el metodo add un objeto de tipo receta, ya sea bebida, comida o postre
    }
    public String imprimir(){//metodo para imprimir el menu
         if (menu.isEmpty()) {//si no hay menu devolver la cadena no hay menu disponible
        return "No hay menú disponible";
    }
    StringBuilder resultado = new StringBuilder();//construccion de la megacadena
    for (Receta receta : menu) {//foreach para que todo lo que haya en la lista de receta se imprima
        if (receta instanceof Bebida bebida) {//si la instancia es bebida
            resultado.append(bebida.imprimir()).append("\n");//mandar a llamar a bebida.imprimir para imprimir sus atributos correspondientes y juntar toda la cadena
        } else if (receta instanceof Comida comida) {//si la instancia es comida
            resultado.append(comida.imprimir()).append("\n");//mandar a llamar a comida.imprimir para imprimir sus atributos correspondientes y juntar toda la cadena
        } else if (receta instanceof Postre postre) {//si la instancia es postre
            resultado.append(postre.imprimir()).append("\n");//mandar a llamar a postre.imprimir para imprimir sus atributos correspondientes y juntar toda la cadena
        }
    }
    return resultado.toString();//retornamos la mega cadena
}
    public Receta buscarPlatillo(String eleccion){//recibimos una string para buscar en la lista de recetas
        for(Receta receta:menu){//recorremos con el foreach
            if(receta.getNombre().equals(eleccion)){//si lo que hay en la receta su nombre es igual a la eleccion
                return receta;//retornamos el objeto de tipo receta completo
            }
        }
        return null;//si no retornamos null
    }
    public void agregarPedido(Pedido p) {//metodo para agregar un pedido a la lista de pedidos
        pedidos.add(p);//agregamos al pedido con el metodo add
    }
    public String imprimirPedido(){
         if (pedidos.isEmpty()) {//si pedidos esta vacia mandar una string que diga que no hay pedidos
        return "No hay pedidos";
    }
    StringBuilder resultado = new StringBuilder();//construimos la megacadena
    for (Pedido pe : pedidos) {//recorremos los pedidos con el foreach
            resultado.append(pe.imprimir()).append("\n");//concatenamos con la impresion de todos los atributos de todos los pedidos
    }
    return resultado.toString();//retornamos la megacadena para ser usada en el textArea
}
}
