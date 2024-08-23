use sams;
/*create table auditoria_socios(
id_auditoria int auto_increment primary key,
numero_socio int not null,
nombre varchar(80) not null,
fecha_modificacion datetime default null,
accion varchar(50) default null);

create trigger antesactualizarsocios
before update on socio
for each row
insert into auditoria_socios
set accion = "update o modificacion",
numero_socio= old.idSocio,
nombre=old.nombre,
fecha_modificacion= now();

update socio set nombre="PEREZ BONILLA OMAR"where idSocio=190;
update socio set direccion="NUEVA DIRECCION" where idSocio=185;
select * from socio;
select * from auditoria_socios;
create trigger nombre_producto
before insert on producto 
for each row
set new.nombre=ucase(new.nombre);
insert into producto (idProducto,nombre,idProveedor, precioUnitario) values(189,"sopa la moderna",22,25.30);
select * from producto;

create table historial_prod(
id_historial int auto_increment primary key,
numero_producto int not null,
precio_anterior double not null,
precio_nuevo double not null,
fecha_modif datetime default null,
usuario varchar(60));

create trigger historialpreciosprod
before update on producto
for each row 
insert into historial_prod(numero_producto,precio_anterior,precio_nuevo,fecha_modif,usuario)
values(new.idProducto,old.precioUnitario,new.precioUnitario,current_timestamp,current_user);
select * from producto;
update producto set precioUnitario=105.30 where idProducto=12;
update producto set nombre="Papitas" where idProducto=13;
select * from producto;
select*from historial_prod;
delimiter @
create trigger histprecprod
after update on producto
for each row 
begin 
if new.precioUnitario <>old.precioUnitario then 
insert into historial_prod(numero_producto,precio_anterior,precio_nuevo,fecha_modif,usuario)
values(new.idProducto, old.precioUnitario,new.precioUnitario,current_timestamp,current_user);
end if;
end@
delimiter ;
update producto set precioUnitario=105.30 where idProducto=14;
update producto set nombre ="Papitas" where idProducto=15;
select * from historial_prod;

delimiter @
create trigger Precionegativo 
before insert on producto 
for each row
begin if new.precioUnitario <0 then
set new.precioUnitario=0;
end if;
end @
delimiter ;
insert into producto(idProducto,nombre,idProveedor,precioUnitario) values(83,"Nuevo Producto",22,-10.15);
insert into producto(idProducto,nombre,idProveedor,precioUnitario) values(84,"Nuevo Producto",22,10.15);
select * from producto;

delimiter @
create trigger mensaje
before insert on producto
for each row 
begin 
declare mensaje_error varchar(100);
if new.precioUnitario<=0 then
set mensaje_error = concat("Error: Precio no valido, ",current_user);
signal sqlstate '45000' set message_text = mensaje_error;
end if;
end;
@
delimiter ;
insert into producto(idProducto,nombre,idProveedor,precioUnitario) values(91,"Nuevo Producto",31,-1);
select* from producto;
insert into producto(idProducto,nombre,idProveedor,precioUnitario) values(91,"Nuevo Producto",22,10);
select * from producto;