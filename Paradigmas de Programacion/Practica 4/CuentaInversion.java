//Titulo:CuentaInversion 
//descripcion:Hacer un programa donde se pueda crear objetos y hacer acciones como deposito, retiro y consulta asi como interes
//fecha:14/11/2023
//version:4.5
//autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel, Mendoza Segura Fernando
public class CuentaInversion {//crear la clase cuenta inversion con sus atributos
    private String Id;
    private double balance;
    private double tarifa;
    private String nombre;

    public CuentaInversion(String Id,double balance, double tarifa, String nombre){//constructor con 4 parametros
        this.tarifa=tarifa;
        this.Id=Id;
        this.balance=balance;
        this.nombre=nombre;
    }
    public CuentaInversion(String Id,double balance, double tarifa){//constructor con 3 parametros
        this.tarifa=tarifa;
        this.Id=Id;
        this.balance=balance;
    }
    public CuentaInversion(String Id, double tarifa){//constructor con 2 parametros
        this.tarifa=tarifa;
        this.Id=Id;
    }
    public CuentaInversion(double tarifa,double balance){//constructor con 1 parametro
        this.tarifa=tarifa;
        this.balance=balance;
    }
    public double calcularinteres(){//metodo que calcula el interes tomando el balance y la tarifa y devolviendo el interes asi como actualizarlo al balance
        double interes=balance*tarifa;
        balance+=interes;
        return interes;
    }
    public double obtenerbalance(){//metodo para devolver el balance
        return balance;
    }
    public void deposito(double cantidad){//metodo para hacer un deposito en la cuenta
        balance+=cantidad;
    }
    public boolean retiro(double cantidad){//metodo para retirar el dinero
        if(cantidad<=balance){//si la cantidad es menor al balance 
            balance-=cantidad;//se hace el decremento del balance
            return true;//devuelve un true
        }
        return false;//si no devuelve un false
    }
}
