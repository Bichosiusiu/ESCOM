#!/bin/sh
clear
echo -n "Introduce dos valores numéricos separados por espacios: "
read var1 var2
echo "Los valores son:"
echo "var1=$var1"
echo "var2=$var2"
if [ $var1 -lt $var2 ]; then
    echo "$var1 es menor que $var2"
    while [ $var1 -lt $var2 ]; do
        echo "contador=$var1"
        var1=`expr $var1 + 1`
    done
else
    echo "$var1 es mayor o igual que $var2"
    case $var2 in
        10) echo "Fui un 10";;
        20) echo "Fui un 20";;
        *) echo "Otro valor";; 
    esac
fi

