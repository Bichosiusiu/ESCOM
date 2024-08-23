create database aeropuerto;
use aeropuerto;
CREATE TABLE Compañia
(
  numero_aprox_aviones INT NOT NULL,
  RFC INT NOT NULL,
  nombre_ INT NOT NULL,
  nacionalidad INT NOT NULL,
  direccion_sede INT NOT NULL,
  PRIMARY KEY (RFC)
);

CREATE TABLE Continental
(
  Continente INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (RFC),
  FOREIGN KEY (RFC) REFERENCES Compañia(RFC)
);

CREATE TABLE Internacional
(
  Fecha_del_ultimo_control INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (RFC),
  FOREIGN KEY (RFC) REFERENCES Compañia(RFC)
);

CREATE TABLE Nacional
(
  pais INT NOT NULL,
  permiso_de_viajes INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (RFC),
  FOREIGN KEY (RFC) REFERENCES Compañia(RFC)
);

CREATE TABLE Aeropuerto
(
  Codigo_aeropuerto INT NOT NULL,
  nombre INT NOT NULL,
  ciudad INT NOT NULL,
  no_pistas INT NOT NULL,
  PRIMARY KEY (Codigo_aeropuerto)
);

CREATE TABLE Ruta
(
  duracion INT NOT NULL,
  codigo_ruta INT NOT NULL,
  Codigo_aeropuerto INT NOT NULL,
  destinoCodigo_aeropuerto INT NOT NULL,
  PRIMARY KEY (codigo_ruta),
  FOREIGN KEY (Codigo_aeropuerto) REFERENCES Aeropuerto(Codigo_aeropuerto),
  FOREIGN KEY (destinoCodigo_aeropuerto) REFERENCES Aeropuerto(Codigo_aeropuerto)
);

CREATE TABLE Avion
(
  nombre_tripulacion INT NOT NULL,
  codigo_avion INT NOT NULL,
  modelo INT NOT NULL,
  no_pasajeros INT NOT NULL,
  fechaInspeccionTecnica INT NOT NULL,
  max_km INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (codigo_avion),
  FOREIGN KEY (RFC) REFERENCES Compañia(RFC)
);

CREATE TABLE Trabajador
(
  direccion INT NOT NULL,
  idioma INT NOT NULL,
  id INT NOT NULL,
  paises_res INT NOT NULL,
  nacionalidad INT NOT NULL,
  nombre INT NOT NULL,
  primer_ap INT NOT NULL,
  segundo_ap INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (RFC) REFERENCES Compañia(RFC)
);

CREATE TABLE Piloto
(
  permiso INT NOT NULL,
  ultima_evaluacion INT NOT NULL,
  id INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (id) REFERENCES Trabajador(id)
);

CREATE TABLE Tripulacion
(
  tel INT NOT NULL,
  id INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (id) REFERENCES Trabajador(id)
);

CREATE TABLE operarios
(
  tipo_tareas INT NOT NULL,
  permiso_mercancias_peligrosas INT NOT NULL,
  id INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (id) REFERENCES Trabajador(id)
);

CREATE TABLE Trabajar
(
  RFC INT NOT NULL,
  Codigo_aeropuerto INT NOT NULL,
  PRIMARY KEY (RFC, Codigo_aeropuerto),
  FOREIGN KEY (RFC) REFERENCES Compañia(RFC),
  FOREIGN KEY (Codigo_aeropuerto) REFERENCES Aeropuerto(Codigo_aeropuerto)
);

CREATE TABLE tener
(
  codigo_avion INT NOT NULL,
  codigo_ruta INT NOT NULL,
  PRIMARY KEY (codigo_avion, codigo_ruta),
  FOREIGN KEY (codigo_avion) REFERENCES Avion(codigo_avion),
  FOREIGN KEY (codigo_ruta) REFERENCES Ruta(codigo_ruta)
);

CREATE TABLE pilotar
(
  codigo_ruta INT NOT NULL,
  id INT NOT NULL,
  PRIMARY KEY (codigo_ruta, id),
  FOREIGN KEY (codigo_ruta) REFERENCES Ruta(codigo_ruta),
  FOREIGN KEY (id) REFERENCES Piloto(id)
);

CREATE TABLE Compañia_telefono
(
  telefono INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (telefono, RFC),
  FOREIGN KEY (RFC) REFERENCES Compañia(RFC)
);

CREATE TABLE Continental_paises_sin_permiso
(
  paises_sin_permiso INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (paises_sin_permiso, RFC),
  FOREIGN KEY (RFC) REFERENCES Continental(RFC)
);

CREATE TABLE Internacional_Paises_sin_permiso
(
  Paises_sin_permiso INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (Paises_sin_permiso, RFC),
  FOREIGN KEY (RFC) REFERENCES Internacional(RFC)
);

CREATE TABLE Internacional_controles_superados
(
  controles_superados INT NOT NULL,
  RFC INT NOT NULL,
  PRIMARY KEY (controles_superados, RFC),
  FOREIGN KEY (RFC) REFERENCES Internacional(RFC)
);

CREATE TABLE Tripulacion_idiomas
(
  idiomas INT NOT NULL,
  id INT NOT NULL,
  PRIMARY KEY (idiomas, id),
  FOREIGN KEY (id) REFERENCES Tripulacion(id)
);
show tables;
select * from piloto;
select * from compañia;
select * from aeropuerto;
select * from ruta;
select * from nacional;
select * from avion;
select * from trabajador;
