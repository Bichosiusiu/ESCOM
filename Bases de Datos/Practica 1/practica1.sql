/*create database practica1;
use practica1;
create table almacen(
noalmacen int not null primary key, 
nombrealmacen varchar(60)not null,
direccionalmacen varchar(60) not null,
telalmacen varchar(30) not null,
estadoalamcen varchar(40) not null);
create table departamento(
nodepartamento char(3) not null primary key,
nombredepto varchar(30) not null);
create table ad(
noalmacen int ,
nodepartamento char(3),
primary key(noalmacen,nodepartamento),
foreign key (noalmacen)references almacen(noalmacen),
foreign key (nodepartamento)references departamento(nodepartamento));
insert into almacen values(103,"liverpool cuernavaca","autopista mexico acapulco km 87","017770074","morelos");
insert into almacen values(104,"liverpool puebla","avenida del niño poblano no 2510","012222297500","puebla");
insert into almacen values(105,"liverpool guadalajara","avenida rafael sandio no 159 int 204","013337772200","jalisco");
insert into almacen values(108,"liverpool pachuca","camino real de la plata no 100","017717178899","hidalgo");
insert into almacen values(106,"liverpool satelite","circuito centro comercial no 2251","015557293100","edo de mexico");
insert into almacen values(120,"liverpool perisur","periferico sur no 4690 col ampl","015554471200","cdmx");
insert into almacen values(143,"liverpool insurgentes","insurgentes sur no1310 col del valle","015554801300","cdmx");
insert into almacen values(157,"liverpool lindavista","colector 13 no 280 col. maria magdalena de las salinas","015557471000","cdmx");
insert into almacen values(165,"liverpool centro","venustiano carranza no 92 col centro","015551332800","cdmx");
insert into almacen values(176,"liverpool merida","calle 60 no 299 carr merida progreso km 8.5","019999427200","yucatan");
insert into departamento values("COM","computacion");
insert into departamento values("PER","perfumeria");
insert into departamento values("LB","Linea Blanca");
insert into departamento values("ELC","Electronica");
insert into departamento values("MU","Muebles");
insert into ad values(103,"COM");
insert into ad values(104,"LB");
insert into ad values(105,"COM");
insert into ad values(108,"MU");
insert into ad values(106,"PER");
insert into ad values(120,"ELC");
insert into ad values(143,"PER");
insert into ad values(165,"ELC");
insert into ad values(176,"COM");
insert into ad values(103,"PER");
insert into ad values(120,"COM");
insert into ad values(105,"LB");
insert into ad values(108,"LB");
insert into ad values(103,"LB");
insert into ad values(106,"MU");
insert into ad values(120,"MU");
insert into ad values(157,"LB");
insert into ad values(176,"LB");
insert into ad values(176,"ELC");
select nombrealmacen,telalmacen from almacen;
select nodepartamento from ad where noalmacen=176;
select * from almacen where estadoalamcen="cdmx";
insert into departamento values("VJ","Videojuegos");
insert into departamento values("TM","Telefonia Movil");
insert into departamento values("FV","Fotografia y Video");
insert into departamento values("BB","Bebes");
insert into departamento values("AE","Aparatos de Ejercicios");
select * from departamento;
update almacen set telalmacen="015551342900" where nombrealmacen="liverpool centro";
select * from almacen where nombrealmacen="liverpool centro";
alter table almacen add column correo varchar(80);
select * from almacen;
update almacen set correo="gdl@liverpool.com.mx" where noalmacen=103;
update almacen set correo="insur@liverpool.com.mx" where noalmacen=120;
update almacen set correo="centro@liverpool.com.mx" where noalmacen=157;
update almacen set correo="gdl@liverpool.com.mx" where noalmacen=103;
update almacen set correo="insur@liverpool.com.mx" where noalmacen=120;
update almacen set correo="centro@liverpool.com.mx" where noalmacen=157;
select*from almacen;
delete from ad where noalmacen=176;
delete from almacen where nombrealmacen="liverpool merida";
select * from almacen;
update ad set nodepartamento="BB" where nodepartamento="PER" and noalmacen=(select noalmacen from almacen where nombrealmacen="liverpool cuernavaca");
select * from ad;
insert into ad values((select noalmacen from almacen where nombrealmacen="liverpool pachuca"),(select nodepartamento from departamento where nombredepto="telefonia movil"));
insert into ad values((select noalmacen from almacen where nombrealmacen="liverpool pachuca"),(select nodepartamento from departamento where nombredepto="videojuegos"));*/
select * from ad;