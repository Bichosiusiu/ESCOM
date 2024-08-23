<?php 
session_name('control_sesion');//recuperamos la sesion con el nombre correspondiente
session_start();//iniciamos la sesion
session_destroy();//destruimos la sesion
header("Location: ../../pages/logincontrol.php");//redirigimos al login