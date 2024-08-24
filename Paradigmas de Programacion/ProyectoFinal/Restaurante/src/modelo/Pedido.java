package modelo;
import java.util.List;

public class Pedido {
    private static int numeropedidoglobal=1;//inicializamos en 1 para llevar el conteo general de pedidos
    private int numeropedido;
    private List<String> platillos;
    private Cliente c;
    private Repartidor r;
    private String metpago;
    private int total;

    public Pedido() {//constructor vacio
    }

    public Pedido(List<String> platillos, String nombre,String direccion, int edad, Repartidor r, String metpago, int total) {//constructor con todos los atributos
        this.numeropedido = numeropedidoglobal++;//cada vez que se hace el constructor se aumenta en 1 el pedido
        this.platillos = platillos;
        c = new Cliente(nombre,direccion,edad);//composicion de cliente
        this.r = r;//agregacion de repartidor
        this.metpago = metpago;
        this.total = total;
    }

    public int getNumeropedido() {
        return numeropedido;
    }

    public List<String> getPlatillos() {
        return platillos;
    }

    public Cliente getC() {
        return c;
    }

    public Repartidor getR() {
        return r;
    }

    public String getMetpago() {
        return metpago;
    }

    public int getTotal() {
        return total;
    }

    public void setNumeropedido(int numeropedido) {
        this.numeropedido = numeropedido;
    }

    public void setPlatillos(List<String> platillos) {
        this.platillos = platillos;
    }

    public void setC(Cliente c) {
        this.c = c;
    }

    public void setR(Repartidor r) {
        this.r = r;
    }

    public void setMetpago(String metpago) {
        this.metpago = metpago;
    }

    public void setTotal(int total) {
        this.total = total;
    }
    public String imprimir(){//metodo para imprimir todos los atributos
        StringBuilder resultado = new StringBuilder();//se construye una gran cadena para devolver y asi se vea reflejada en el textarea
        resultado.append("Numero de pedido: ").append(numeropedido).append("\t");//se construye la megacadena con append
        resultado.append("Cliente: ").append(c.getNombre()).append("\t");
        resultado.append("Repartidor: ").append(r.getNombre()).append("\t");
        resultado.append("Metodo de pago: ").append(metpago).append("\t");
        for(String p:platillos){//for each para imprimir todo lo que hya en platillos
        resultado.append("Platillo: ").append(p).append("\t");
        }
        resultado.append("Total: ").append(total).append("\t");
        return resultado.toString();//retornamos la cadena
    }
    
}
