#!/bin/bash
g="generado.sh"
echo "Creando el archivo $g..."
cat <<EOL > $g
#!/bin/bash
echo "Este es un script generado por otro script"
EOL
echo "Editando el archivo $g..."
nano $g
echo "Cambiando permisos del archivo $g..."
chmod +x $g
echo "Ejecutando el archivo $g..."
./$g
