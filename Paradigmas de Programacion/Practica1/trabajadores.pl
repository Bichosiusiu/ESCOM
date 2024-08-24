%Titulo:trabajadores
%descripcion:Declaralossiguienteshechosrelativosatrabajadoresdeuna empresa.Utilizaelpredicadoencargado_de_tarea(trabajador,tarea)oMiguel está encargado delastareas deadmisión, controlyvigilancia.oRicardoestáencargadodelastareasdeplanificacióny asesoramiento.oAliciaestáencargadadeladirecciónycontrol.Definereglasquepermitancomprobarlossiguienteshechos:oSiunatareahasidoencargadaaalgunapersona.Utiliza elpredicadoencargada(Tarea).oSi dos personas comparten alguna tarea, esdecir,comparten_tarea(Persona1,Persona2).
%fecha:16/09/23
%version:2
%autor:Vazquez Blancas Cesar Said, Segundo Cruz Daniel
%Hechos
%encargado_de_tarea(trabajador,tarea)
encargado_de_tarea(miguel,admision).
encargado_de_tarea(miguel,control).
encargado_de_tarea(miguel,vigilancia).
encargado_de_tarea(ricardo,planificacion).
encargado_de_tarea(ricardo,asesoramiento).
encargado_de_tarea(alicia,direccion).
encargado_de_tarea(alicia,control).
%reglas
encargada(Tarea):-
encargado_de_tarea(_,Tarea).%solo se dice la tarea y si existe mandara un true

comparten_tarea(Persona1,Persona2):-
encargado_de_tarea(Persona1,Tarea),%verificamos que una persona haga una tarea
encargado_de_tarea(Persona2,Tarea),%verificamos que otra perosna haga la misma tarea
Persona1 \= Persona2.%hace que no se devuelva el mismo nombre que pones en persona