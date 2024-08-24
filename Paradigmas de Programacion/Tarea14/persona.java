package Tarea14_Persona;

public class persona {
    private int id;
    private String nombre;
    private String ap;
    private profesion p;
    private domicilio dom;

    public persona(int id, String nombre, String ap, profesion p,String calle, int numero){
        this.id=id;
        this.nombre=nombre;
        this.ap=ap;
        this.p=p;
        dom=new domicilio(numero, calle);
    }
    
    public void imprimeper(){
        System.out.println("El id es: "+id);
        System.out.println("El nombre es: "+nombre);
        System.out.println("El apellido es :"+ap);
        System.out.println("El nivel es:"+p.getnivel());
        System.out.println("La escuela es: "+p.getesc());
        dom.imprimedom();
    }
}
