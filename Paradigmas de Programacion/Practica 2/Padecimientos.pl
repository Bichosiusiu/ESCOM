%Titulo: Padecimientos

% Descripcion: Representa el conocimiento de personas,enfermedades, síntomas y fármacos con el objetivo es poder hacer consultas sobre
% el estado de salud de las personas, los síntomas que presentan, los fármacos que pueden tomar y las relaciones entre las enfermedades
% y los farmacos.

%fecha:30/09/2023
%version:2
%autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel

% padecer(Persona, Enfermedad)
% Describimos que persona padece que padecimiento
padecer(jose, gripe).
padecer(jose, hepatitis).
padecer(julio, migraña).
padecer(luis, hepatitis).
padecer(enrique, intoxicacion).
padecer(susana, gripe).

%sintoma(Enfermedad, Sintoma)
%Describimos que sintoma produce que padecimiento
sintoma(gripe, fiebre).
sintoma(gripe, cansancio).
sintoma(hepatitis, cansancio).
sintoma(intoxicacion, diarrea).
sintoma(migraña, dolor_de_cabeza).

%suprimir(Farmaco, Sintoma)
%Describimos que farmaco se suprime para que padecimiento
suprimir(metamizol, fiebre).
suprimir(ibuprofeno, dolor_de_cabeza).
suprimir(lomotil, diarrea).

% Reglas:

% Esta regla define que un fármaco alivia una enfermedad si la enfermedad tiene un síntoma que sea suprimido por el fármaco.
aliviar(Farmaco, Enfermedad) :-
    sintoma(Enfermedad, Sintoma), suprimir(Farmaco, Sintoma).

% Esta regla define que una persona debería tomar un fármaco si padece una enfermedad que sea aliviada por el fármaco.
tomar(Persona, Farmaco) :-
    padecer(Persona, Enfermedad), aliviar(Farmaco, Enfermedad).
