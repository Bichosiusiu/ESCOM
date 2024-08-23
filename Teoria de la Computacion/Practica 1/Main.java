import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {
    public static void main(String[] args)
    {
        
        Scanner scanner = new Scanner(System.in);
        System.out. println  ("ingresa el numero 1 para guardar alfabeto por elemetos o el numero 2 por rango, 3 para salir");
        int opc; // opc = scanner.nextInt();
        //scanner.nextLine();
        String alf ;
do
{       
        
        opc = scanner.nextInt();
        
        if (opc == 1)
        {
            System.out.println("Ingrese el alfabeto (A) de al menos tres símbolos (ejemplo : 102),");
            System.out.println("Nota: en realidad se leen asi 112 = 1,1,2 y se borra el elemento repetido");
            System.out.println("entonces 112 = 1,2 por lo que si ingresamos cadenas con elementos repetidos");
            System.out.println("por ejemplo 112 en realidad estamos ingresando solo 2 elementos");
            scanner.nextLine();
            int a;

            do 
            {
            
                alf = scanner.nextLine();       
                alf = alf.replaceAll("(.)\\1+", "$1");
                a = alf.length();
                
                if(a<3)
                {
                    System.out.println("No coloco tres elemenos intentelo denuevo porfavor");
                }
                

            } while(a<3);



            Alfabeto alfabeto = new Alfabeto(alf);
            System.out.println("Alfabeto (cadena): "+alfabeto.getSimbolos());
            String w1, w2;
            

            System.out.println("Ingrese la primera cadena (w1) del alfabeto ∑:");
            do 
            {
                
                //System.out.println("Ingrese la primera cadena (w1) del alfabeto ∑:");
                w1 = scanner.nextLine();

                if(!alfabeto.isValidString(w1))
                {
                 System.out.println("cadena no valida vuelvalo a intentar: ");   
                }

                //System.out.println("Ingrese la primera cadena (w1) del alfabeto ∑:");

            } while (!alfabeto.isValidString(w1));
            
            System.out.println("Ingrese la segunda cadena (w2) del alfabeto ∑:");
            do 
            {
                w2 = scanner.nextLine();

                if(!alfabeto.isValidString(w2))
                {
                 System.out.println("cadena no valida vuelvalo a intentar: ");   
                }
            
            } while (!alfabeto.isValidString(w2));
            
            System.out.println("w1= "+w1);
            System.out.println("w2= "+w2);
            relacion(w1, w2);
            int np, l;
            
            do 
            {
                System.out.println("Ingrese el número de elementos (np) a generar para los lenguajes L1 y L2:");
                np = scanner.nextInt();
                System.out.println("Ingrese la longitud (l) de las palabras a generar:");
                l = scanner.nextInt();
            } while (np <= 0 || l <= 0);
            
            Lenguaje LG = new Lenguaje(alfabeto);
            List<String> L1 = LG.generador(np, l);
            List<String> L2 = LG.generador(np, l);

            System.out.println("L1: "+L1);
            System.out.println("L2: "+L2);

            L1.removeAll(L2);

            System.out.println("LD: "+L1);
            System.out.println("Ingresa una potencia de -5 a 5");

            int p= scanner.nextInt();
            alfabeto.potencia("",alfabeto.getSimbolos(),p);
            String er = "(?=.*(\\d).*\\1)\\d{5,}";
            System.out.println("Ingrese una palabra para verificar con la expresión regular:");
            scanner.nextLine();
            String palabra = scanner.nextLine();
            // Verificar si la palabra cumple con la expresión regular
            if (isER(palabra, er)) 
            {
                System.out.println("La palabra cumple con la expresión regular.");
            } 
            else  
            {
                System.out.println("La palabra NO cumple con la expresión regular.");
            }
            scanner.close();
            return;
        }
        else if (opc==2)
        {
            System.out.println("Ingrese el rango de caracteres (por ejemplo, 'a' a 'z'):");

                char start = scanner.next().charAt(0);
                char end = scanner.next().charAt(0);
                scanner.nextLine();

                if (start > end) {
                    System.out.println("Rango inválido: el primer carácter debe ser menor o igual al segundo.");
                    continue; // Reiniciar el ciclo para que el usuario ingrese un rango válido
                }

                alf = generateAlphabet(start, end);
                Alfabeto alfabeto = new Alfabeto(alf);
                System.out.println("Alfabeto (cadena): "+alfabeto.getSimbolos());
            String w1, w2;
            

            System.out.println("Ingrese la primera cadena (w1) del alfabeto ∑:");
            do 
            {
                
                //System.out.println("Ingrese la primera cadena (w1) del alfabeto ∑:");
                w1 = scanner.nextLine();

                if(!alfabeto.isValidString(w1))
                {
                 System.out.println("cadena no valida vuelvalo a intentar: ");   
                }

                //System.out.println("Ingrese la primera cadena (w1) del alfabeto ∑:");

            } while (!alfabeto.isValidString(w1));
            
            System.out.println("Ingrese la segunda cadena (w2) del alfabeto ∑:");
            do 
            {
                w2 = scanner.nextLine();

                if(!alfabeto.isValidString(w2))
                {
                 System.out.println("cadena no valida vuelvalo a intentar: ");   
                }
            
            } while (!alfabeto.isValidString(w2));
            
            System.out.println("w1= "+w1);
            System.out.println("w2= "+w2);
            relacion(w1, w2);
            int np, l;
            
            do 
            {
                System.out.println("Ingrese el número de elementos (np) a generar para los lenguajes L1 y L2:");
                np = scanner.nextInt();
                System.out.println("Ingrese la longitud (l) de las palabras a generar:");
                l = scanner.nextInt();
            } while (np <= 0 || l <= 0);
            
            Lenguaje LG = new Lenguaje(alfabeto);
            List<String> L1 = LG.generador(np, l);
            List<String> L2 = LG.generador(np, l);

            System.out.println("L1: "+L1);
            System.out.println("L2: "+L2);

            L1.removeAll(L2);

            System.out.println("LD: "+L1);
            System.out.println("Ingresa una potencia de -5 a 5");

            int p= scanner.nextInt();
            alfabeto.potencia("",alfabeto.getSimbolos(),p);
            String er = "(?=.*(\\d).*\\1)\\d{5,}";
            System.out.println("Ingrese una palabra para verificar con la expresión regular:");
            scanner.nextLine();
            String palabra = scanner.nextLine();
            // Verificar si la palabra cumple con la expresión regular
            if (isER(palabra, er)) 
            {
                System.out.println("La palabra cumple con la expresión regular.");
            } 
            else  
            {
                System.out.println("La palabra NO cumple con la expresión regular.");
            }
            scanner.close();
            return;
        }
        else if(opc!=3)
        {
            System.out.println("Opcion no valida, reintelo porfavor");
            //scanner.close();
            //scanner.nextInt();
            //return;
        }
    }while(opc!=3);

    System.out.println("Hasta luego");
    scanner.close();
}    

    public static void relacion(String w1, String w2)
    {
        if(w1.length()>w2.length())
        {
             System.out.println("Tu cadena w1 es mayor, entonces no es sufijo, prefijo o subcadena de w2");
        }
        else
        {
            if(w2.startsWith(w1))
            {
                System.out.println("La cadena w1 es prefijo de w2");
            }

            if(w2.endsWith(w1))
            {
                System.out.println("La cadena w1 es sufijo de w2");
            }

            if(w2.contains(w1))
            {
                System.out.println("La cadena w1 es subcadena de w2");
            }

            if(subsecuencia(w1,w2))
            {
                System.out.println("La cadena w1 es subsecuencia de w2");
            }
        }
    }
    public static boolean subsecuencia(String w1, String w2)
    {
        int i=0,j=0;
        while(i<w1.length()&&j<w2.length())
        {
            if(w1.charAt(i)==w2.charAt(j))  
            {
                i++;
            }
                j++;
        }
        return i== w1.length();
    }



    public static boolean isER(String palabra, String er) 
    {
        Pattern pattern = Pattern.compile(er);
        Matcher matcher = pattern.matcher(palabra);
        return matcher.matches();
    }
    public static String generateAlphabet(char start, char end) {
        StringBuilder alphabet = new StringBuilder();
        for (char c = start; c <= end; c++) {
            alphabet.append(c);
        }
        return alphabet.toString();
    }
}
