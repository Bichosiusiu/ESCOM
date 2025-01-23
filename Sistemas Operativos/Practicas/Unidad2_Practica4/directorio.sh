#!/bin/bash
if [ -z "$1" ]; then
  echo "Error"
  echo "Uso: $0 <directorio>"
  exit 1
fi
if [ ! -d "$1" ]; then
  echo "Error: $1 no es un directorio válido."
  exit 1
fi
contador=0
echo "Archivos en el directorio $1:"
for archivo in "$1"/*; do
  if [ -f "$archivo" ]; then
    echo "$(basename "$archivo")"
    contador=$((contador + 1))
  fi
done
echo "Número total de archivos: $contador"

