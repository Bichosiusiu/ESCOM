#!/bin/bash
directorio="/home/said/SegundaE" 
if [ ! -d "$directorio" ]; then
  echo "Error: $directorio no es un directorio válido."
  exit 1
fi
contador=0
for archivo in "$directorio"/*; do
  if [ -f "$archivo" ] && [[ "$(basename "$archivo")" =~ ^.e ]]; then
    echo "Eliminando archivo: $(basename "$archivo")"
    rm "$archivo"
    contador=$((contador + 1))
  fi
done
echo "Total de archivos eliminados: $contador"
