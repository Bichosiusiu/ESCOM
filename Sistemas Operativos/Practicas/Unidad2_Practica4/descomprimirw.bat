@echo off
cls
echo "-------------- Descomprimiendo Respaldo --------------"
setlocal enabledelayedexpansion
set respaldo=C:\Users\vbcs1\Respaldos
set destino=C:\Users\vbcs1\Descomprimidos
if not exist "%destino%" (
    mkdir "%destino%"
)
for %%R in ("%respaldo%\respaldo*.rar") do (
    echo "Descomprimiendo %%R..."
    "C:\Program Files\WinRAR\rar.exe" e -y "%%R" "%destino%"
    set tar=%%~dpnR.tar
    tar -xvf "!tar!" -C "%destino%"
)
echo "-------------- Descompresión completada --------------"
endlocal
