%Titulo:lovers
%descripcion:Escribe un fichero denominado “lovers.pl” que contenga los siguientes hechos dondeelpredicadoama(X,Y)indicaqueXamaaY.Escribeenprologlassiguientespreguntaso¿Aquiénama“Juan”?o¿Quiénamaa“Ana”?o¿Quiénamaaalguien?o¿Quiénesamadoporalguien?o¿Quiénesseamanmutuamente?o¿Quiénamasinsercorrespondido?Añadealficherolovers.plunareglaquepermitadescribiralos “lovers”,esdecir, aquellas personasqueseaman mutuamente. 
%fecha:16/09/23
%version:1.5
%autor:Vazquez Blancas Cesar Said, Segundo Cruz Daniel
%Hechos
ama(ana,miguel).
ama(luis,isabel).
ama(diana,laura).
ama(luis,carlos).
ama(miguel,ana).
ama(laura,juan).
ama(juan,luis).
ama(isabel,carlos).
ama(laura,diana).
ama(laura,juan).
%Reglas
%regla para describir los lovers
%esta regla describe a los lovers como X y Y pues se quieren encontrar,
%por lo tanto si ama uno al otro seria como X ama a Y y para que sea mutuo,
%tendria que haber un Y ama a X, por lo que con eso seria suficiente
lovers(X,Y):-ama(X,Y),ama(Y,X).