#!/bin/bash
clear
directorio_respaldos="/home/said/respaldos"
if [ ! -d "$directorio_respaldos" ]; then
    echo "El directorio $directorio_respaldos no existe."
    exit 1
fi
for archivo in "$directorio_respaldos"/*.tar; do
    if [ ! -e "$archivo" ]; then
        echo "No se encontraron archivos .tar en $directorio_respaldos."
        exit 1
    fi
    echo "Descomprimiendo $archivo..."
    ruta_destino="/home/said/Descomprimidos"
    mkdir -p "$ruta_destino"
    tar -xvf "$archivo" -C  "$ruta_destino"
    echo "Descompresión completada para $archivo"
done
echo "Todas las descompresiones han finalizado."
