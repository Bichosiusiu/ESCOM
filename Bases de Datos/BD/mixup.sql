use mixup;/*
delimiter //
create procedure sp1(in estado varchar(50))
begin 
select a.nombre as Nombre,a.tel as Telefono from asociado a inner join mixup m on a.idmixup=m.idmixup where m.ubicacion like estado;
end // delimiter ;
call sp1("DF");
delimiter //
create procedure sp2(in nombre varchar(50))
begin 
select * from mixup m inner join asociado a on a.idmixup=m.idmixup where m.nombre=nombre;
end // delimiter ;
select * from mixup;
call sp2("centro historico");
delimiter //
create procedure sp3(in nombre varchar(50))
begin 
select a.nombre as Nombre from mixup m inner join asociado a on a.idmixup=m.idmixup where m.nombre like nombre;
end //
delimiter ;
call sp3("plaza satelite");
delimiter //
create procedure sp4(in nombre varchar(50))
begin 
select count(a.idAsociado) as Asociados from mixup m inner join asociado a on a.idmixup=m.idmixup where m.nombre like nombre group by m.nombre;
end // delimiter ;
call sp4("perisur");
delimiter //
create procedure sp5 (in nombre varchar(50))
begin 
select ar.nombre as Produccion from mixup m inner join mixupdepto md on md.idmixup=m.idmixup inner join departamento d on d.idDepto=md.idDepto inner join articulo ar on ar.idDepto=d.idDepto where m.nombre like nombre;
end // delimiter ;*/
call sp1("DF");
call sp2("centro historico");
call sp3("plaza satelite");
call sp4("perisur");
call sp5("coatzacoalcos mx");
