/*use hospital;
show tables;
select * from paciente;
select nombre,edad from paciente order by edad asc;
select nombre,CURP from paciente order by nombre desc;
select * from paciente where CURP="MALD770810";
select * from paciente where edad=26;
select * from paciente where edad>25;
select * from paciente where edad>=27;
select * from paciente where edad<=27;
select * from paciente where edad!=27;
select * from paciente where edad IN(26,27,28);
SELECT * FROM paciente WHERE edad = 26 OR edad = 28;
select * from paciente where edad>=25 and edad!=28;
select * from historial where fechaIngreso="2003/03/25";
select * from historial where fechaIngreso>"2003/03/25";
select * from historial where fechaIngreso between "2003/03/25"and "2003/03/27";
select COUNT(idhistorial) as "REGISTROS CAUSA.2" from historial where idcausaHosp=2;
select AVG(edad) as "Promedio de Paciente" from paciente;
select MIN(fechaIngreso) as "Fecha Inicial" from historial;*/
select MAX(fechaIngreso) as "Fecha Final" from historial;