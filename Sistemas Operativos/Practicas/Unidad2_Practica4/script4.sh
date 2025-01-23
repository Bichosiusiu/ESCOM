#!/bin/bash
clear
Op="Opcion: "
echo $Op
select i in Directorio DirectorioExtendido Salir
do
    case $i in
        Directorio) 
            ls  
            ;;
        DirectorioExtendido) 
            ls -l  
            ;;
        Salir) 
            break  
            ;;
        *) 
            echo "Opción inválida" 
            ;;
    esac
done
echo ""  
for i in hola como estan todos
do
    echo -n "$i "  
done
echo "" 
