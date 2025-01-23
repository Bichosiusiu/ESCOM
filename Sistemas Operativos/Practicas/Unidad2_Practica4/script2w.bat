@echo off
cls
echo "-------------- Captura fecha ---------------"
for /F "tokens=1,2,3 delims=/ " %%V in ('date /t') do set dia=%%V%%W%%X
set tiempo=%time%
for /F "tokens=1,2,3 delims=:." %%V in ("%tiempo%") do set tiempo=%%V%%W%%X
set fecha=%dia%%tiempo%
echo "-------------- Empacando ----------------"
tar -cvf ".\respaldo%fecha%.tar" "C:\Users\vbcs1\directorio1" "C:\Users\vbcs1\directorio2" "C:\Users\vbcs1\directorio3"
echo "-------------- Comprimiendo ----------------"
"C:\Program Files\WinRAR\rar.exe" a -c- ".\respaldo%fecha%.rar" ".\respaldo%fecha%.tar"
echo "-------------- Enviando a otro directorio --------------"
copy ".\respaldo%fecha%.rar" "C:\Users\vbcs1\Respaldos"
echo "-------------- Descomprimiendo ------------------"
"C:\Program Files\WinRAR\rar.exe" e -y "C:\Users\vbcs1\Respaldos\respaldo%fecha%.rar" "C:\Users\vbcs1\Respaldos"
echo "-------------- Desempacando ----------------"
tar -xvf "C:\Users\vbcs1\Respaldos\respaldo%fecha%.tar" -C "C:\Users\vbcs1\Respaldos"
echo "-------------- Limpiando ------------------"
del ".\respaldo%fecha%.rar"
del ".\respaldo%fecha%.tar"
echo "-------------- Terminado ------------------"