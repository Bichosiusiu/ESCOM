@echo off
cls
echo "-------------- Eliminacion de Archivos --------------"
set "carpeta=C:\Users\vbcs1\Eliminados"
if not exist "%carpeta%" (
    echo "Error: El directorio '%carpeta%' no existe."
    exit /b
)
set count=0
setlocal enabledelayedexpansion
echo "Eliminando archivos en el directorio '%carpeta%' con segundo caracter 'e':"
for %%F in ("%carpeta%\*") do (
    set "file=%%~nxF"
    if "!file:~1,1!"=="e" (
        echo "Eliminando: %%F"
        del "%%F"
        set /a count+=1
    )
)
echo "---------------------------------------------------"
echo "Total de archivos eliminados: !count!"
echo "-------------- Proceso finalizado --------------"
endlocal

