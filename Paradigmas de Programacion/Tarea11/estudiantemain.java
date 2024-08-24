package Tarea11_Estudiante;

public class estudiantemain {
    public static void main(String[] args){
        String[] inscritas3 = {"Matemáticas"};
        String[] reprobadas3 = {"Inglés", "Educación Física","Historia","Quimica"};
        String[] inscritas4 = {"Matemáticas", "Historia", "Ciencias","Quimica","Fisica"};
        String[] inscritas5 = {"Matemáticas", "Historia", "Ciencias"};
        estudiante estudiante1 = new estudiante("123456", 67, false,9.86);
        estudiante estudiante2 = new estudiante("167855", 101, false,1,"Santiago");
        estudiante estudiante3 = new estudiante("677657", 150, true, "De mauro", inscritas3,reprobadas3);
        estudiante estudiante4 = new estudiante("787558", 110, true, "em7887@gmail.com", "Emiliano", inscritas4, null);
        estudiante estudiante5 = new estudiante("676438", 150, true, "jnoj@gmail.com", "Jonathan", inscritas5, null);
        estudiante[] estudiantes = {estudiante1, estudiante2, estudiante3, estudiante4, estudiante5};
        estudiante1.imprimir();
        estudiante2.imprimir();
        estudiante3.imprimir();
        estudiante4.imprimir();
        estudiante5.imprimir();
        estudiantes[0].regulares(estudiantes);
        estudiantes[0].maxcred(estudiantes);

}
}
