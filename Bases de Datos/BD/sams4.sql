/*use sams;
DELIMITER #
create procedure uno(in socio VARCHAR(50))
begin
    select g.nombre as Gerente, c.nombre as Club from club c inner join gerente g on g.idClub=c.idClub inner join socioclub sc on sc.idClub=c.idClub inner join socio s on s.idSocio=sc.idSocio where s.nombre like concat("%",socio,"%");
end #
DELIMITER ;
call uno ("meza gonzalez manuel");
DELIMITER #
create procedure dos(in club VARCHAR(50))
begin
    select s.nombre as Servicio from club c inner join servicioclub sc on sc.idClub=c.idClub inner join servicio s on s.idServicio=sc.idServicio where c.nombre like club;
end #
DELIMITER ;
call dos ("hospital general");
call dos ("puerto vallarta");
DELIMITER #
create procedure tres(in gerente VARCHAR(50))
begin
    select c.nombre as Club, e.nombre as Estado from club c inner join estado e on e.idEdo=c.idEdo inner join gerente g on g.idClub=c.idClub where g.nombre like gerente;
end #
DELIMITER ;
call tres("Rivera guillen diego");
DELIMITER #
create procedure cuatro(in servicio VARCHAR(50))
begin
    select c.nombre as Club, g.nombre as Gerente from club c inner join gerente g on g.idClub=c.idClub inner join servicioclub sc on sc.idClub=c.idClub inner join servicio s on s.idServicio=sc.idServicio where s.nombre like servicio;
end #
DELIMITER ;
call cuatro("Service deli");
DELIMITER #
create procedure cinco(in idsocio int)
begin
    select c.nombre as Club, c.direccion as Direccion from club c inner join socioclub sc on sc.idClub=c.idClub inner join socio s on s.idSocio=sc.idSocio where s.idSocio=idsocio;
end #
DELIMITER ;
call cinco(10);
call cinco(33);
call cinco(78);
DELIMITER #
create procedure seis(in direccion varchar(50))
begin
    select s.nombre as Socio, c.nombre as Club from club c inner join socioclub sc on sc.idClub=c.idClub inner join socio s on s.idSocio=sc.idSocio where s.direccion like direccion;
end #
DELIMITER ;
call seis("av. juarez. s/n");
DELIMITER #
create procedure siete(in telefono varchar(50))
begin
    select g.nombre as Gerente, c.nombre as Club from club c inner join gerente g on g.idClub=c.idClub where c.tel like telefono;
end #
DELIMITER ;
call siete("Tel.: (624) 144 71 24");
call siete("Tel.: (81) 83-18-04-06");
call siete("Tel.: (747) 116-00-07");
DELIMITER #
create procedure ocho(in cp varchar(50))
begin
    select c.nombre as Club, e.nombre as Estado from club c inner join estado e on e.idEdo=c.idEdo where c.direccion like concat("%",cp,"%");
end #
DELIMITER ;
call ocho ("11220");
call ocho ("21090");
call ocho("58260");
create view vistauno as select c.nombre as Club, g.nombre as Gerente from club c inner join gerente g on g.idClub=c.idClub inner join estado e on e.idEdo=c.idEdo where e.nombre like "guerrero";
select * from vistauno;
create view vistados as select p.nombre as Producto, p.precioUnitario as Precio from club c inner join proveedorsams ps on ps.idClub=c.idClub inner join proveedor pr on pr.idProveedor=ps.idProveedor inner join producto p on pr.idProveedor=p.idProveedor where c.nombre like "guaymas";
select * from vistados;
create view vistatres as select c.nombre as Club, count(ps.idProveedor) as Proveedores from club c inner join proveedorsams ps on ps.idClub=c.idClub group by c.nombre;
select * from vistatres;
create view vistacuatro as select  p.* from club c inner join proveedorsams ps on ps.idClub=c.idClub inner join proveedor pr on pr.idProveedor=ps.idProveedor inner join producto p on p.idProveedor=pr.idProveedor where c.nombre like "acapulco diamante";
*/
select s.nombre as Socio, c.nombre as Club from club c inner join socioclub sc on sc.idClub=c.idClub inner join socio s on s.idSocio=sc.idSocio where s.direccion like "%conocida%";
select c.nombre as Club, count(sc.idSocio) as Socios from club c inner join socioclub sc on sc.idClub=c.idClub group by c.nombre;
select s.tel as TelSocio , c.nombre as Club, c.direccion as DirClub from club c inner join socioclub sc on sc.idClub=c.idClub inner join socio s on s.idSocio=sc.idSocio where s.nombre like "%linares%";
select pr.nombre as Proveedor from proveedor pr inner join producto p on pr.idProveedor=p.idProveedor where p.precioUnitario>5 and p.precioUnitario<10;
select nombre, tel from socio where idSocio in(50,52,100);
select e.nombre as Estado, count(c.idClub) as Clubes from club c inner join estado e on e.idEdo=c.idEdo group by e.nombre;
select s.nombre as Socio, c.nombre as Club , e.nombre as Estado from club c inner join socioclub sc on sc.idClub=c.idClub inner join socio s on s.idSocio=sc.idSocio inner join estado e on e.idEdo=c.idEdo where s.nombre like "%david%";
select g.nombre as Gerente, c.nombre as Club from club c inner join gerente g on g.idClub=c.idClub inner join estado e on e.idEdo=c.idEdo where e.nombre like "%micho%";


