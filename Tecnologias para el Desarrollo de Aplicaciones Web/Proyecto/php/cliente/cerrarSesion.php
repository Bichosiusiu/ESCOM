<?php  //se usa para el boton de cerrar sesion
session_name('cliente_sesion');//iniciamos la sesion con el nombre correspondiente
session_start();
session_destroy();//destruimos la sesion
header("Location: ../../pages/loginCliente.php");//redirigimos al login