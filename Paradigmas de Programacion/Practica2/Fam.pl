%Titulo:Fam
%descripciom:En este programa contiene los integrantes de tu familia, considerando hasta los bisabuelos y haciendo reglas paar determinar preguntas que se haran en el compilador
%fecha:27/08/23
%version:3
%autor: Vazquez Blancas Cesar Said, Segundo Cruz Daniel
%Hechos
%hombre(nombre)
%mujer(nombre)
hombre(agustin).
hombre(dimas).
hombre(cesar).
hombre(crecencio).
hombre(dionicio).
hombre(jacobo).
hombre(fortino).
hombre(marcos).
hombre(bulmaro).
hombre(pedro).
hombre(julio).
hombre(santiago).
hombre(alejandro).
hombre(antonio).
hombre(dante).
mujer(margarita).
mujer(laura).
mujer(columba).
mujer(erika).
mujer(aurora).
mujer(genesis).
mujer(maria).
mujer(leonor).
mujer(asuncion).
mujer(alejandra).
mujer(cecilia).
mujer(guadalupe).
mujer(arely).
mujer(ana).
mujer(luisa).
%padre(padre,hijo).
%madre(madre,hijo).
padre(agustin,fortino).
padre(dimas,columba).
padre(crecencio,bulmaro).
padre(jacobo,genesis).
padre(jacobo,cesar).
padre(dionicio,margarita).
padre(fortino,jacobo).
padre(fortino,pedro).
padre(bulmaro,erika).
padre(fortino,marcos).
padre(fortino,laura).
padre(julio,santiago).
padre(antonio,arely).
padre(marcos,alejandro).
padre(dante,ana).
padre(bulmaro,cecilia).
padre(bulmaro,guadalupe).
padre(bulmaro,dante).
madre(columba,marcos).
madre(columba,laura).
madre(columba,pedro).
madre(margarita,erika).
madre(erika,cesar).
madre(columba,jacobo).
madre(leonor,margarita).
madre(aurora,bulmaro).
madre(erika,genesis).
madre(asuncion,fortino).
madre(maria,columba).
madre(laura,santiago).
madre(alejandra,alejandro).
madre(guadalupe,arely).
madre(luisa,ana).
madre(margarita,cecilia).
madre(margarita,guadalupe).
madre(margarita,dante).
%esposos(hombre,mujer).
esposo(agustin,asuncion).
esposo(dimas,maria).
esposo(crecencio,aurora).
esposo(dionicio,leonor).
esposo(fortino,columba).
esposo(bulmaro,margarita).
esposo(julio,laura).
esposo(marcos,alejandra).
esposo(antonio,guadalupe).
esposo(dante,luisa).
esposo(jacobo,erika).
%hermano(nombre,hermano)
hermano(jacobo,pedro).
hermano(jacobo,laura).
hermano(jacobo,marcos).
hermano(cesar,genesis).
hermano(erika,cecilia).
hermano(erika,guadalupe).
hermano(erika,dante).
hermano(laura,pedro).
hermano(laura,marcos).
hermano(marcos,pedro).
hermano(cecilia,guadalupe).
hermano(cecilia,dante).
hermano(dante,guadalupe).
%edad(nombre,años).
edad(marcos,40).
edad(pedro,42).
edad(laura,35).
edad(jacobo,45).
edad(erika,45).
edad(cesar,18).
edad(genesis,15).
edad(santiago,2).
edad(julio,36).
edad(alejandra,38).
edad(alejandro,14).
edad(cecilia,36).
edad(antonio,43).
edad(guadalupe,43).
edad(arely,13).
edad(dante,34).
edad(luisa,36).
edad(ana,17).
edad(bulmaro,81).
edad(margarita,81).
edad(fortino, 62).
edad(columba,59).
%reglas
matrimonio(X,Y):-
esposo(X,Y);esposo(Y,X).%definimos una conmutatividad entre esposos

hermanos(X,Y):- 
hermano(X,Y);hermano(Y,X).%definimos una conmutatividad entre hermanos

abuelo(Nieto,Abuelo):-
(padre(Padre,Nieto),padre(Abuelo,Padre);%buscamos al padre del nieto y a su vez el padre del padre que es el abuelo
madre(Madre,Nieto),padre(Abuelo,Madre)).%buscamos a la madre del nieto y a su vez el padre de la madre

abuela(Nieto,Abuela):-
(padre(Padre,Nieto),madre(Abuela,Padre);%buscamos el padre del nieto y a su vez la madre del padre
madre(Madre,Nieto),madre(Abuela,Madre)).%buscamos a la madre del nieto y a su vez a la madre de la madre

bisabuelo(Bisnieto,Bisabuelo):-
(padre(Padre,Bisnieto),abuelo(Padre,Bisabuelo);%buscamos al padre del bisnieto y a su vez al abuelo del padre
madre(Madre,Bisnieto),abuelo(Madre,Bisabuelo)).%buscamos a la madre del bisnieto y a su vez al abuelo de la madre

bisabuela(Bisnieto,Bisabuela):-
(padre(Padre,Bisnieto),abuela(Padre,Bisabuela);%buscamos al padre del bisnieto y a su vez a la abuela del padre
madre(Madre,Bisnieto),abuela(Madre,Bisabuela)).%buscamos a la madre del bisnieto y a su vez a la abuela de la madre

tio(Sobrino, Tio):-
(padre(Padre,Sobrino),hermanos(Padre,Tio),hombre(Tio);%encontramos al padre de sobrino, luego a sus hermanos y verificamos que sean hombres
madre(Madre,Sobrino),hermanos(Madre,Tio),hombre(Tio);%buscamos a la madre del sobrino, luego a sus hermanos y verificamos que sea hombre
padre(Padre,Sobrino),hermanos(Padre,Tia),mujer(Tia),matrimonio(Tio,Tia);%buscamos a los hermanos del padre, verificamos que sea mujer y buscamos al esposo de la tia
madre(Madre,Sobrino),hermanos(Madre,Tia),mujer(Tia),matrimonio(Tio,Tia)).%encontramos a la madre del sobrino, luego a sus hermanos y verificamos que sean hombres

tia(Sobrino, Tia):-
(padre(Padre,Sobrino),hermanos(Padre,Tia),mujer(Tia);%encontramos al padre, a sus hermanos y verificamos que sea mujer
madre(Madre,Sobrino),hermanos(Madre,Tia),mujer(Tia);%encontramos a la madre, a sus hermanos y verificamos que sea mujer
padre(Padre,Sobrino),hermanos(Padre,Tio),hombre(Tio),matrimonio(Tio,Tia);%buscamos a los hermanos del padre, verificamos que sea hombre y buscamos a su esposa
madre(Madre,Sobrino),hermanos(Madre,Tio),hombre(Tio),matrimonio(Tio,Tia)).%buscamos a los hermanos de la madre, verificamos que sea hombre y buscamos a su esposa

primo(Persona,Primo):-
tio(Persona,Tio),padre(Tio,Primo),hombre(Primo).%buscamos al tio y a sus hijos

prima(Persona,Prima):-
tio(Persona,Tio),padre(Tio,Prima),mujer(Prima).%buscamos al tio y a sus hijas

sobrino(Tio,Sobrino):-
hermanos(Tio,Padre),padre(Padre,Sobrino),hombre(Sobrino);%buscamos a los hermanos del tio, los padres y vemos si su hijo es hombre
hermanos(Tio,Madre),madre(Madre,Sobrino),hombre(Sobrino).%buscamos a las hermanas del tio, y vemos si tiene hijo.

sobrina(Tio,Sobrino):-
hermanos(Tio,Padre),padre(Padre,Sobrino),mujer(Sobrino);%buscamos a los hermanos del tio, y vemos si tiene hija.
hermanos(Tio,Madre),madre(Madre,Sobrino),mujer(Sobrino).%buscamos a las hermanas del tio, y vemos si tiene hija.

mayor_que(X, Y) :-
    edad(X, EdadX),%obtenemos la persona y su edad
    edad(Y, EdadY),%obtenemos la otra
    EdadX > EdadY.%hacemos la comparacion

menor_que(X, Y) :-
    edad(X, EdadX),%obtenemos la persona y su edad
    edad(Y, EdadY),%obtenemos la otra
    EdadX < EdadY.%hacemos la comparacion

igual_edad(X, Y) :-
    edad(X, EdadX),%obtenemos la persona y su edad
    edad(Y, EdadY),%obtenemos la otra
    EdadX =:= EdadY.%hacemos la comparacion
