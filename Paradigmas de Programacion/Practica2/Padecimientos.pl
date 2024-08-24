%Titulo: Padecimientos

% Descripcion: Representa el conocimiento de personas,enfermedades, s�ntomas y f�rmacos con el objetivo es poder hacer consultas sobre
% el estado de salud de las personas, los s�ntomas que presentan, los f�rmacos que pueden tomar y las relaciones entre las enfermedades
% y los farmacos.

%fecha:30/09/2023
%version:2
%autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel

% padecer(Persona, Enfermedad)
% Describimos que persona padece que padecimiento
padecer(jose, gripe).
padecer(jose, hepatitis).
padecer(julio, migra�a).
padecer(luis, hepatitis).
padecer(enrique, intoxicacion).
padecer(susana, gripe).

%sintoma(Enfermedad, Sintoma)
%Describimos que sintoma produce que padecimiento
sintoma(gripe, fiebre).
sintoma(gripe, cansancio).
sintoma(hepatitis, cansancio).
sintoma(intoxicacion, diarrea).
sintoma(migra�a, dolor_de_cabeza).

%suprimir(Farmaco, Sintoma)
%Describimos que farmaco se suprime para que padecimiento
suprimir(metamizol, fiebre).
suprimir(ibuprofeno, dolor_de_cabeza).
suprimir(lomotil, diarrea).

% Reglas:

% Esta regla define que un f�rmaco alivia una enfermedad si la enfermedad tiene un s�ntoma que sea suprimido por el f�rmaco.
aliviar(Farmaco, Enfermedad) :-
    sintoma(Enfermedad, Sintoma), suprimir(Farmaco, Sintoma).

% Esta regla define que una persona deber�a tomar un f�rmaco si padece una enfermedad que sea aliviada por el f�rmaco.
tomar(Persona, Farmaco) :-
    padecer(Persona, Enfermedad), aliviar(Farmaco, Enfermedad).
