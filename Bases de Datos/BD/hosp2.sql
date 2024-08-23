
create view vistauno as select p.nombre,p.edad,h.fechaIngreso,ch.tratamiento from paciente p inner join historial h on p.curp=h.curp inner join causahosp ch on ch.idCausaHosp=h.idCausaHosp;
show tables;
select * from vistauno;
alter table paciente modify tel varchar(10);
insert into paciente values("AAFS040521MVC1N","SUNEM AYALA FUENTES",19,"DIRECCION SUNEM",5525346728);
insert into historial values (115,4570,"AAFS040521MVC1N","2023/10/20","2023/10/21",12,5,308);
select * from vistauno;
create view vistados as select p.nombre as "Paciente",m.nombre as "Medico",ch.tratamiento from paciente p inner join historial h on p.curp=h.curp inner join causahosp ch on ch.idCausaHosp=h.idCausaHosp inner join medico m on m.cedula=h.cedula order by 1;
select * from vistados;
create view vistatres as select p.nombre,h.Nocama,h.fechaAlta,ch.observaciones from paciente p inner join historial h on p.curp=h.curp inner join causahosp ch on ch.idcausaHosp=h.idcausahosp;
select * from vistatres;
create view vistacuatro as select p.nombre, p.edad from paciente p inner join historial h on p.curp=h.curp inner join medico m on m.cedula=h.cedula inner join especialidad e on e.idEsp=m.idEsp where e.idEsp="NR";
select * from vistacuatro;
create view vistacinco as select p.curp,m.cedula,e.descEsp from paciente p inner join historial h on p.curp=h.curp inner join medico m on m.cedula=h.cedula inner join especialidad e on e.idEsp=m.idesp where YEAR(h.fechaAlta)=2005;
select * from vistacinco;
select * from vistacinco;
