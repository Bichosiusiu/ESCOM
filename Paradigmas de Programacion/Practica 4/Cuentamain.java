public class Cuentamain {
    public static void main(String[] args) {
        CuentaInversion cuenta1=new CuentaInversion(0.05, 2500);//primer objeto instanciado por el primer constructor
        CuentaInversion cuenta2=new CuentaInversion("1", 0.07);//segundo objeto instanciado por el segundo constructor
        CuentaInversion cuenta3=new CuentaInversion("2", 2500.5, 0.07);//tercer objeto instanciado por el tercer constructor
        CuentaInversion cuenta4=new CuentaInversion("3", 4350.8, 0.11, "Samuel");//cuarto objeto instanciado por el cuarto constructor 
        cuenta1.deposito(7500.6);//deposito en la cuenta 1
        cuenta2.deposito(6600.4);//deposito en la cuenta 2
        cuenta3.deposito(3340.7);//deposito en la cuenta 3
        cuenta4.deposito(7789.6);//deposito en la cuenta 4
        boolean r1=cuenta1.retiro(2279);//guarda los retiros en booleanos para despues ser usados
        boolean r2=cuenta3.retiro(4579.8);
        boolean r3=cuenta4.retiro(12500);
        if(r1){
            System.out.println("El retiro fue exitoso");//si devuelve un true se hace el proceso
        }else{
            System.out.println("Cantidad insuficiente de dinero");//si devuelve un false no hace nada 
        }
        if(r2){
            System.out.println("El retiro fue exitoso");//si devuelve un true se hace el proceso
        }else{
            System.out.println("Cantidad insuficiente de dinero");//si devuelve un false no hace nada 
        }
        if(r3){
            System.out.println("El retiro fue exitoso");//si devuelve un true se hace el proceso
        }else{
            System.out.println("Cantidad insuficiente de dinero");//si devuelve un false no hace nada 
        }
        System.out.println("El interes de la cuenta 1 es: "+cuenta1.calcularinteres());//calcula el interes de la cuenta 1
        System.out.println("El interes de la cuenta 2 es: "+cuenta2.calcularinteres());//calcula el interes de la cuenta 2
        System.out.println("El interes de la cuenta 3 es: "+cuenta3.calcularinteres());//calcula el interes de la cuenta 3
        System.out.println("El interes de la cuenta 4 es: "+cuenta4.calcularinteres());//calcula el interes de la cuenta 4
        System.out.println("El balance de la cuenta 1 es: "+cuenta1.obtenerbalance());//calcula el balance de la cuenta 1
        System.out.println("El balance de la cuenta 2 es: "+cuenta2.obtenerbalance());//calcula el balance de la cuenta 2
        System.out.println("El balance de la cuenta 3 es: "+cuenta3.obtenerbalance());//calcula el balance de la cuenta 3
        System.out.println("El balance de la cuenta 4 es: "+cuenta4.obtenerbalance());//calcula el balance de la cuenta 4
    }
}
