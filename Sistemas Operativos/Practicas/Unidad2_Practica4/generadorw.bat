@echo off
cls
echo "-------------- Generador de Script --------------"
set script=script.bat
(
    echo @echo off
    echo cls
    echo echo "Este es un script generado."
    echo pause
) > "%script%"
echo "Script '%script%' creado."
start notepad "%script%"
echo "Esperando a que se cierre Notepad para continuar..."
:wait
tasklist | find /i "notepad.exe" >nul
if errorlevel 1 (
    goto continue
) else (
    timeout /t 1 >nul
    goto wait
)
:continue
echo "El archivo '%script%' ha sido creado y editado."
echo "-------------- Contenido del script generado --------------"
type "%script%"
echo "-----------------------------------------------------------"
echo "Ejecutando '%script%'..."
call "%script%"
echo "-------------- Proceso finalizado --------------"
