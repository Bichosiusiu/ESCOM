%Titulo:Deportistas
%descripcion: Predicadossobredeportistas:Utilizaelpredicadojuega(Persona,Deporte)paradeclararlo siguienteshechosrelativosadeportistas:oHéctorjuegaalbaloncesto.oMigueljuegaalbalonmanoyrugbyoAliciajuegaaltenis,baloncestoyajedrez.Defineunpredicadoquepermitacomprobarsidospersonas jueganalmismodeporte.
%fecha:16/09/23
%version:1.5
%autor:Vazquez Blancas Cesar Said, Segundo Cruz Daniel
%Hechos
%juega(Persona,Deporte).
juega(hector,baloncesto).
juega(miguel,balonmano).
juega(miguel,rugby).
juega(alicia,tenis).
juega(alicia,baloncesto).
juega(alicia,ajedrez).
%reglas
juegan_mismodeporte(Persona1,Persona2):-
juega(Persona1,Deporte),%verificamos que una persona juegue un deporte
juega(Persona2,Deporte),%persona diferente juega el mismo deporte
Persona1\=Persona2.%persona 1 y 2 deben de ser diferentes