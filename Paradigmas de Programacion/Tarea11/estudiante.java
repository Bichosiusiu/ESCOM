package Tarea11_Estudiante;

public class estudiante {
    private String boleta;
    private double promedio;
    private int semestre;
    private String nombre;
    private String apellidos;
    private int creditos;
    private String [] inscritas;
    private String [] reprobadas;
    private boolean regular;
    private String correo;

    public estudiante(String boleta,int creditos,boolean regular,double promedio){
       this.boleta=boleta;
       this.creditos=creditos;
       this.regular=regular;
       this.promedio=promedio;
    }
    public estudiante(String boleta,int creditos,boolean regular,int semestre, String nombre){
       this.boleta=boleta;
       this.creditos=creditos;
       this.regular=regular;
       this.semestre=semestre;
       this.nombre=nombre;
    }
    public estudiante(String boleta,int creditos,boolean regular, String apellidos,String[] inscritas,String[] reprobadas){
       this.boleta=boleta;
       this.creditos=creditos;
       this.regular=regular;
       this.apellidos=apellidos;
       if (inscritas != null) {
        this.inscritas = inscritas;
    } else {
        this.inscritas = new String[0]; 
    }
       if (reprobadas != null) {
        this.reprobadas = reprobadas;
    } else {
        this.reprobadas = new String[0]; 
    }
    }
    public estudiante(String boleta,int creditos,boolean regular,String correo,String nombre,String[] inscritas,String[] reprobadas){
       this.boleta=boleta;
       this.creditos=creditos;
       this.regular=regular;
       this.correo=correo;
       this.nombre=nombre;
       if (inscritas != null) {
        this.inscritas = inscritas;
    } else {
        this.inscritas = new String[0]; 
    }
    if (reprobadas != null) {
        this.reprobadas = reprobadas;
    } else {
        this.reprobadas = new String[0]; 
    }
}
    public String getboleta(){
        return boleta;
    }
    public void setboleta(String nuevaBoleta) {
        this.boleta = nuevaBoleta;
    }
    public String getnombre(){
        return nombre;
    }
    public void setnombre(String nuevonombre) {
        this.nombre = nuevonombre;
    }
    public String getapellidos(){
        return apellidos;
    }
    public void setapellidos(String nuevoapellido) {
        this.apellidos = nuevoapellido;
    }
    public double getpromedio(){
        return promedio;
    }
    public void setpromedio(double nuevopromedio) {
        this.promedio = nuevopromedio;
    }
    public int getsemestre(){
        return semestre;
    }
    public void setsemestre(int nuevosemestre) {
        this.semestre = nuevosemestre;
    }
    public int getcreditos(){
        return creditos;
    }
    public void setcreditos(int nuevocreditos) {
        this.creditos = nuevocreditos;
    }
    public boolean getregular(){
        return regular;
    }
    public void setregular(boolean nuevoregular) {
        this.regular = nuevoregular;
    }
    public String getcorreo(){
        return correo;
    }
    public void setcorreo(String nuevocorreo) {
        this.correo = nuevocorreo;
    }
    public String[] getinscritas(){
        return inscritas;
    }
    public void setinscritas(String[] nuevoinscritas) {
        this.inscritas = nuevoinscritas;
    }
    public String[] getreprobadas(){
        return reprobadas;
    }
    public void setreprobadas(String[] nuevoreprobadas) {
        this.reprobadas = nuevoreprobadas;
    }
    public void imprimir(){
        System.out.println("Boleta: " + boleta);
        System.out.println("Nombre: " + nombre);
        System.out.println("Apellidos: " + apellidos);
        System.out.println("Promedio: " + promedio);
        System.out.println("Semestre: " + semestre);
        System.out.println("Creditos: " + creditos);
        System.out.println("Regular: " + regular);
        System.out.println("Correo: " + correo);

        System.out.println("Materias inscritas:");
    if (inscritas != null) {
        for (String materia : inscritas) {
            System.out.println("- " + materia);
        }
    } else {
        System.out.println("No hay materias inscritas");
    }
        System.out.println("Materias reprobadas:");
    if (reprobadas != null) {
        for (String materia : reprobadas) {
            System.out.println("- " + materia);
        }
    } else {
        System.out.println("No hay materias reprobadas");
    }
}
    public void regulares(estudiante[] e){
        int j=0;
        for(int i=0;i<e.length;i++){
        if(e[i].getregular()){
            j++;
        }
        }
        System.out.println("Los alumnos regulares son: "+j);
    }
    public void maxcred(estudiante[] e){
        int j=0;
        for(int i=0;i<e.length;i++){
        if(e[i].getcreditos()>100){
            j++;
        }
        }
        System.out.println("Los alumnos con mas de 100 creditos son: "+j);
    }
    }

