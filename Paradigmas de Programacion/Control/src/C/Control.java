package C;
import java.util.Scanner;
import javax.swing.JOptionPane;
public class Control {
    public static void main(String[] args) {
        int decision1,decision2;
        boolean control=true,control2;
        Scanner scanner = new Scanner(System.in);
        Universidad universidad=new Universidad("Escom", "Zacatenco");
        while(control!=false){
            System.out.println("Ingresa quien trata de entrar al sistema: ");
            System.out.println("1.-Control Escolar");
            System.out.println("2.-Profesor");
            System.out.println("3.-Alumno");
            System.out.println("4.-Salir");
            decision1= scanner.nextInt();
            scanner.nextLine();
            control2=true;
            switch (decision1) {
                case 1:
                while(control2!=false){
                    System.out.println("Ingrese lo que quiere ralizar ");
                    System.out.println("1.-Agregar Grupo");
                    System.out.println("2.-Inscribir materias a grupo");
                    System.out.println("3.-Inscribir alumnos a materia");
                    System.out.println("4.-Imprimir los valores de los grupos: ");
                    System.out.println("5.-Salir");
                    decision2= scanner.nextInt();
                    scanner.nextLine();
                    switch (decision2) {
                        case 1:
                            String nomgrupo;
                            System.out.println("AGREGAR GRUPO");
                            System.out.println("Ingresa el nombre del grupo: ");
                            nomgrupo=scanner.nextLine();
                            if(universidad.buscarGrupo1(nomgrupo)){
                                JOptionPane.showMessageDialog(null, "El Grupo ya existe", "Mensaje", JOptionPane.INFORMATION_MESSAGE);
                            }else{
                                Grupo grupo=new Grupo(nomgrupo);
                                universidad.agregarGrupo(grupo);
                            }
                            break;

                        case 2:
                            String nommateria,profcategoria,profnombre;
                            int profmatricula;
                            System.out.println("INSCRIBIR MATERIAS A GRUPO");
                            System.out.println("Ingresa el nombre del grupo: ");
                            nomgrupo=scanner.nextLine();
                            System.out.println("Ingresa el nombre de la materia");
                            nommateria=scanner.nextLine();
                            Grupo grupo1=universidad.buscarGrupo2(nomgrupo);
                            Materia materia1=grupo1.buscarMateria2(nommateria);
                            if(grupo1!=null && materia1==null){
                                System.out.println("Agrega el nombre del profesor que imparte esta materia");
                                profnombre=scanner.nextLine();
                                System.out.println("Escribe la matricula del profesor: ");
                                profmatricula=scanner.nextInt();
                                scanner.nextLine();
                                System.out.println("Escribe la categoria del profesor: ");
                                profcategoria=scanner.nextLine();
                                Profesor profesor=new Profesor(profmatricula, profnombre, profcategoria);
                                materia1=new Materia(nommateria, profesor);
                                grupo1.agregarMateria(materia1);
                            }else{
                                JOptionPane.showMessageDialog(null, "El Grupo no existe o la materia ya esta registrada", "Mensaje", JOptionPane.INFORMATION_MESSAGE);
                            }
                            break;
                        case 3:
                            String nomgrupo1,nommateria1,nombrealumno,modalidad,turno;
                            int numeroboleta;
                            System.out.println("INSCRIBIR ALUMNOS A MATERIAS");
                            System.out.println("Ingresa el nombre del grupo: ");
                            nomgrupo1=scanner.nextLine();
                            System.out.println("Ingresa el nombre de la materia");
                            nommateria1=scanner.nextLine();
                            Grupo grupo2=universidad.buscarGrupo2(nomgrupo1);
                            Materia materia2=grupo2.buscarMateria2(nommateria1);
                            if(grupo2!=null && materia2!=null){
                                System.out.println("Agrega la boleta del alumno:");
                                numeroboleta=scanner.nextInt();
                                scanner.nextLine();
                                System.out.println("Agrega el nombre del alumno");
                                nombrealumno=scanner.nextLine();
                                System.out.println("Escribe la modalidad del alumno: ");
                                modalidad=scanner.nextLine();
                                System.out.println("Escribe el turno del alumno: ");
                                turno=scanner.nextLine();
                                Alumno alumno1=new Alumno(numeroboleta, nombrealumno, turno, modalidad);
                                materia2.agregarAlumno(alumno1);
                            }else{
                                JOptionPane.showMessageDialog(null, "El Grupo no existe o la materia no esta registrada", "Mensaje", JOptionPane.INFORMATION_MESSAGE);
                            }
                            break;
                        
                            case 4:
                            String nomgrupo2;
                            System.out.println("IMPRIMIR GRUPOS:");
                            System.out.println("Ingresa el nombre del grupo: ");
                            nomgrupo2=scanner.nextLine();
                            Grupo grupo3=universidad.buscarGrupo2(nomgrupo2);
                            grupo3.imprimirinformacion();
                            break;

                            case 5:
                            control2=false;
                        default:
                            break;
                    }

                }
                break;
                case 2:
                while(control2!=false){
                    System.out.println("Ingrese lo que quiere ralizar ");
                    System.out.println("1.-Ver grupo");
                    System.out.println("2.-Subir calificaciones");
                    System.out.println("3.-Salir");
                    decision2= scanner.nextInt();
                    scanner.nextLine();
                    switch (decision2) {
                        case 1:
                            String nomgrupo;
                            System.out.println("VER GRUPO");
                            System.out.println("Ingresa el nombre del grupo: ");
                            nomgrupo=scanner.nextLine();
                            Grupo grupo1=universidad.buscarGrupo2(nomgrupo);
                            if(grupo1==null){
                                JOptionPane.showMessageDialog(null, "El Grupo no existe", "Mensaje", JOptionPane.INFORMATION_MESSAGE);
                            }else{
                                grupo1.imprimirinformacion();
                            }
                            break;

                        case 2:
                            int boleta,calif;
                            String nommateria;
                            System.out.println("SUBIR CALIFICACIONES");
                            System.out.println("Ingresa el nombre del grupo: ");
                            nomgrupo=scanner.nextLine();
                            System.out.println("Ingresa el nombre de la materia: ");
                            nommateria=scanner.nextLine();
                            System.out.println("Ingresa la boleta alumno al que quieres subir su calificacion: ");
                            boleta=scanner.nextInt();
                            scanner.nextLine();
                            Grupo grupo2=universidad.buscarGrupo2(nomgrupo);
                            Materia materia1=grupo2.buscarMateria2(nommateria);
                            Alumno alumno1=materia1.buscarAlumno(boleta);
                            System.out.println("Ingresa la calificacion: ");
                            calif=scanner.nextInt();
                            scanner.nextLine();
                            Calificacion cal=new Calificacion(nommateria, calif);
                            alumno1.agregarCalificacion(cal);
                            break;
                            
                        case 3:
                        control2=false;
                        default:
                            break;
                    }

                }
                break;

                case 3:
                 while(control2!=false){
                    System.out.println("Ingrese lo que quiere ralizar ");
                    System.out.println("1.-Imprimir Calificaciones");
                    System.out.println("2.-Salir");
                    decision2= scanner.nextInt();
                    scanner.nextLine();
                    switch (decision2) {
                        case 1:
                            String nomgrupo,nommateria;
                            int boleta;
                            System.out.println("IMPRIMIR CALIFICACIONES");
                            System.out.println("Ingresa el nombre del grupo: ");
                            nomgrupo=scanner.nextLine();
                            System.out.println("Ingresa la materia: ");
                            nommateria=scanner.nextLine();
                            System.out.println("Ingresa tu boleta: ");
                            boleta=scanner.nextInt();
                            scanner.nextLine();
                            Grupo grupo1=universidad.buscarGrupo2(nomgrupo);
                            Materia mater=grupo1.buscarMateria2(nommateria);
                            Alumno alum=mater.buscarAlumno(boleta);
                            Calificacion calif=alum.buscarCalificacion(nommateria);
                            if(grupo1==null ||mater==null || alum==null){
                                JOptionPane.showMessageDialog(null, "Uno de los registros no existe", "Mensaje", JOptionPane.INFORMATION_MESSAGE);
                            }else{
                                calif.imprimirCalificacion();
                            }
                            break;

                        case 2:
                            control2=false;
                            break;
  
                        default:
                            break;
                    }

                }
                break;

                case 4:
                control=false;
                    break;
            
                default:
                    break;
            }
        }
        scanner.close();
    }

}

