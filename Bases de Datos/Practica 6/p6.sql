delimiter #
show tables#
CREATE procedure empleadosmx()
begin
    select a.nombre,a.tel, m.nombre as "mixup"
    from asociado a inner join mixup m on a.idmixup = m.idmixup
    where m.ubicacion ="DF";
end#

create procedure empleadosmx1(in estado varchar(40))
BEGIN
    select a.nombre, m.nombre as "mixup"
    from asociado a inner join mixup m on a.idmixup = m.idmixup
    where m.ubicacion = estado;
end#
delimiter ;
call empleadosmx;

/*punto 1*/
delimiter #
create PROCEDURE proc1()
begin



/*Punto 2*/
create procedure punto2(in nom varchar(40))
begin
    select *
        from mixup m
        inner join asociado a
            on a.idmixup = m.idmixup
        where m.nombre = nom;
end #


/*Punto 3 Lo mismo que el dos pero ordenado por grupos, group by mixup*/
create procedure punto2()
begin
    select *
        from mixup m
        inner join asociado a
            on a.idmixup = m.idmixup

end #
/*Punto 4*/

select count(a.idAsociado) AS "Numero de asociados"
    from asociado a
        inner join mixup m
            on a.idmixup = m.idmixup
    where m.nombre



/*Punto 5*/
