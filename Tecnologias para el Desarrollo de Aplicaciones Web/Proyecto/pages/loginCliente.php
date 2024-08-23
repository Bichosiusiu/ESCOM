<?php
session_name('cliente_sesion');//se asigna una sesionn
session_start(); //para que no se pueda acceder desde la pura url, se inicia la sesion
if(isset($_SESSION["usuario"])){//si hay algo en usuario quiere decir que se dejo la sesion abierta
    header("location: MainCliente.php");//por lo tanto se inicia directamente
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
    <title>loginCliente</title>
  </head>
  <body class="login">
    <div class="contenedor">
      <h1 class="titulo">Login</h1>
      <form id="login-form">
        <div class="elemento">
          <label for="correo">Correo</label>
          <input type="email" id="correo" name="correo" required="true" />
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
        <a href="registro.php">
          <div class="registro2">Registro</div>
        </a>
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
