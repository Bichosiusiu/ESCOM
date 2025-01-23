@echo off
cls
echo "-------------- Listado de Archivos --------------"
if "%~1"=="" (
    echo "Error: Debe proporcionar un directorio como argumento."
    echo "Uso: %0 <directorio>"
    exit /b
)
set "directorio=%~1"
if not exist "%directorio%" (
    echo "Error: El directorio '%directorio%' no existe."
    exit /b
)
set count=0
echo "Archivos en el directorio '%directorio%':"
for %%F in ("%directorio%\*") do (
    echo %%F
    set /a count+=1
)
echo "---------------------------------------------------"
echo "Total de archivos: %count%"
echo "-------------- Proceso finalizado --------------"

