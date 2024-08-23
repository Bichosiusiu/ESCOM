/*use sams;
alter table proveedor add column credito double;
select * from proveedor;
update proveedor set credito=20000;
select * from proveedor;
update socioclub set idClub=(select idClub from club where nombre="El Molinito") where idClub=(select idClub from club where nombre="Tepeyac");
select * from socioclub where idClub=(select idClub from club where nombre="El molinito");
update proveedor set credito=(credito-(credito*0.09)) where nombre="Sabritas";
select * from proveedor where nombre="Sabritas";
update producto set idProveedor=32 where idProveedor IN(27,24,25);
select * from producto where idProveedor=32;
update proveedor set credito=10000 where nombre like "S%";
select * from proveedor where nombre like "S%";
update producto set precioUnitario=200 where idProducto=15;
select * from producto where idProducto=15;
update producto set precioUnitario=(precioUnitario+(precioUnitario*0.1));
select * from producto;
update club set nombre=UPPER(nombre);
select * from club;
update socio set direccion="DIRECCION DE JUAN" where nombre like "% JUAN %";
select * from socio where nombre like "% JUAN %";
ALTER TABLE producto MODIFY COLUMN precioUnitario DECIMAL(7,2) NOT NULL;
describe producto;
select * from producto;
select * from gerente where idGerente not in (50,60,70,80,90,100,110,120,150,130,200,230,300);
select * from club where SUBSTRING(nombre, 2, 1) = 'e';
select * from socio where nombre like "A%";
select * from servicioclub where idClub=78;
select * from servicio where idServicio IN (1,2,3,4,7,9,10);
select * from proveedor where SUBSTRING(nombre, 2, 1) IN('a', 'e','i','o','u');
select avg(precioUnitario) as promedio from producto;
select nombre from proveedor inner join proveedorsams on  proveedor.idProveedor = proveedorsams.idClub where idClub=27;
select nombre, tel from socio order by nombre ASC;
select *from socio where nombre like "GOMEZ %";*/




