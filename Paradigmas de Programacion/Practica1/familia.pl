%Titulo:familia
%descripcion:Escribe un fichero denominado “familia.pl”,Define hechos en los que se afirmen,Define reglas para nietos,abuelos,hermanos,tíos,tias,primos,primas y suegros
%fecha:16/09/23
%version:2.5
%autor:Vazquez Blancas Cesar Said,Segundo Cruz Daniel
%Hechos
%definimos a los hombres
%hombre(hombre)
hombre(antonio).
hombre(juan).
hombre(luis).
hombre(rodrigo).
hombre(ricardo).
%definimos las mujeres
%mujer(mujer)
mujer(isabel).
mujer(ana).
mujer(marta).
mujer(carmen).
mujer(laura).
mujer(alicia).
%definimos los matrimonios
%matrimonio(hombre,mujer)
matrimonio(antonio,ana).
matrimonio(juan,carmen).
matrimonio(luis,isabel).
matrimonio(rodrigo,laura).
%definimos los hijos
%hijos(hijo,padre,madre)
hijo(juan,antonio,ana).
hijo(rodrigo,antonio,ana).
hijo(marta,antonio,ana).
hijo(carmen,luis,isabel).
hijo(ricardo,juan,carmen).
hijo(alicia,rodrigo,laura).
%reglas
matrimonio_reflexivo(X,Y):-matrimonio(X,Y);matrimonio(Y,X).%con esta regla hacemos que si el hombre
%esta casado con la mujer la mujer tambien, asi que la consulta puede ser regular o inversa

nieto(Nieto, Abuelo) :- 
(hombre(Abuelo), %si el abuelo es hombre entonces
hijo(Padre, Abuelo, _),%buscamos al hijo del abuelo
(mujer(Padre), hijo(Nieto, _, Padre); %verificamos si el hijo del abuelo es mujer y si es buscamos al hijo de la mujer
hombre(Padre), hijo(Nieto,Padre, _)) %si no es mujer entonces buscamos al hijo del hombre, osea el nieto
);%si es abuela entonces
(mujer(Abuelo), 
hijo(Padre, _, Abuelo),%buscamos al hijo de la abuela
(mujer(Padre), hijo(Nieto, _, Padre); %verificamos si el hijo es mujer y si es mujer buscamos a su hijo osea el nieto
hombre(Padre), hijo(Nieto, Padre, _))%verificamos si el hijo es hombre y si si entonces buscamos a su hijo osea el nieto
).

abuelo(Abuelo,Nieto):-
nieto(Nieto,Abuelo).%utilizamos nietos para hacer la relacion al reves y ya esta

hermano(Persona,Hermano):-
hijo(Persona,Padre,Madre),%utilizamos a la persona y a los padres de esa persona
hijo(Hermano,Padre,Madre),%al ser los mismos padres solo relacionamos a los padres de ambos y sacamos al hermano
Persona\=Hermano.%al ser hijo tambien de los padres la perosna puede aparecer en resultados pero con esta linea lo eliminamos 

tio(Sobrino,Tio):-
hijo(Sobrino,Padre,Madre),%utilizamos al hijo para llegar a los padres
(hermano(Padre,Tio),hombre(Tio);%los hermanos del padre son los tios y verificamos con hombre
hermano(Madre,Tio),hombre(Tio)).%los hermanos de la madre son tios tambien y se verifican con hombre

tia(Sobrino,Tia):-
hijo(Sobrino,Padre,Madre),%utilizamos al hijo para llegar a los padres
(hermano(Padre,Tia),mujer(Tia);%las hermanas del padre son las tias y verificamos con mujer
hermano(Madre,Tia),mujer(Tia);
hermano(Padre,Tio),matrimonio_reflexivo(Tio,Tia)).%las hermanos de la madre son tias tambien y se verifican con mujer


primo(Persona,Primo):-
(tio(Persona,Tio),%buscamos al tio de la persona
hijo(Primo,Tio,_),hombre(Primo);%enocntramos al hijo del tio que es el primo y verificamos que sea hombre
tia(Persona,Tia),%buscamos a la tia de la persona
hijo(Primo,_,Tia),hombre(Primo)).%enocntramos al hijo de la tia que es el primo y verificamos que sea hombre

prima(Persona,Prima):-
(tio(Persona,Tio),%buscamos al tio de la persona
hijo(Prima,Tio,_),mujer(Prima);%encontramos a la hija del tio que es la prima y verificamos que sea mujer
tia(Persona,Tia),%buscamos a la tia de la persona
hijo(Prima,_,Tia),mujer(Prima)).%encontramos a la hijoa de la tia que es la prima y verificamos que sea mujer

suegro(Persona,Suegros):-
matrimonio_reflexivo(Persona,Pareja),%utilizamos matrimonio reflexivo para que cualquiera sea el sexo de la persona se busque como sea
(hijo(Pareja,Suegros,_);%el padre de la pareja es el primer suegro
hijo(Pareja,_,Suegros)).%la madre de la pareja es el segundo suegro





