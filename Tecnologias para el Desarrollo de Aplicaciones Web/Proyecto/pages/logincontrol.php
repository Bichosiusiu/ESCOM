<?php
session_name('control_sesion');
session_start(); //para que no se pueda acceder desde la pura url, se inicia la sesion
if(isset($_SESSION["control"])){//si hay algo en usuario quiere decir que se dejo la sesion abierta
    header("location: MainControl.php");//por lo tanto se inicia directamente
}
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link href="../css/estilos.css" rel="stylesheet" />
    <link
      href="https://fonts.googleapis.com/icon?family=Material+Icons"
      rel="stylesheet"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css?family=Open+Sans"
    />
    <title>LoginControl</title>
  </head>
  <body class="login">
    <div class="contenedor">
      <h1 class="titulo">Login</h1>
      <form action="../php/control/loginControl_be.php" id="control-form" name="form" method="POST">
        <div class="elemento">
          <label for="usuario">Usuario</label>
          <input type="text" id="usuario" name="usuario" required="true" />
        </div>
        <div class="elemento">
          <label for="password">Password</label>
          <input
            type="password"
            id="password"
            name="password"
            required="true"
          />
        </div>
        <div class="elemento">
          <input type="submit" value="Enviar" />
        </div>
        <a href="index.html">
          <div class="icon">
            <i class="material-icons">home</i>
          </div>
        </a>
      </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../js/script.js"></script>
  </body>
</html>
