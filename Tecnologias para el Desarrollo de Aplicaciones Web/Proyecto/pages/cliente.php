<?php 
session_name('control_sesion');
session_start();// se inicia sesion
include "../includes/conexion.php";
if(!isset($_SESSION["control"])){//si no hay nada en en sesion usuario quiere decir que se quiere iniciar sesion desde fuera del login
    echo "
    <script>
    alert('Por favor, debes iniciar sesión');
    window.location='index.html';
    </script>";
    session_destroy(); // se prohibe el acceso y se destruye la sesión
    die();//no se ejecuta la página y te devuelve a index.html
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="../css/estilos.css" rel="stylesheet" />
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet" />
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Open+Sans">
    <title>MainControl</title>
</head>
<body class="login">
<header>
    <div class="menu-toggle">
        <i class="material-icons" id="menu-icon" style="display: block">menu</i>
    </div>
    <div class="navegador" id="menu">
        <a href="index.html">
            <div class="opcion">
                <i class="material-icons">home</i>
                <span>Inicio</span>
            </div>
        </a>
        <a href="MainControl.php">
            <div class="opcion">
                <i class="material-icons">query_stats</i>
                <span>Estadisticas</span>
            </div>
        </a>
        <a href="inventario.php">
            <div class="opcion">
                <i class="material-icons">inventory_2</i>
                <span>Inventario</span>
            </div>
        </a>
        <a href="../php/control/cerrarSesionControl.php">
            <div class="opcion">
                <i class="material-icons">logout</i>
                <span>Cerrar Sesión</span>
            </div>
        </a>
    </div>
    <form id="busqcliente" name="busqcliente" method="POST">
    <div class="busq">
          <input type="number" id="bus" name="bus" required="true" min="1"/>
          <input type="submit" value="Buscar Cliente" />
    </div>
    </form>
    <h1>Gestión de Clientes</h1>
</header>
    <br><br>
    <div class="contenedorClientes">
    <div class="tabla-scroll">
        <table class='tabla'>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Nombre</th>
                    <th>Apellido</th>
                    <th>Usuario</th>
                    <th>Edad</th>
                    <th>Direccion</th>
                    <th>Correo</th>
                    <th>Monedero</th>
                    <th>Accion</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $sql="SELECT * FROM usuario";
                $rta = mysqli_query($conection, $sql);
                while ($mostrar = mysqli_fetch_row($rta)) {?>
                <tr>
                    <td><?php echo $mostrar["0"] ?></td>
                    <td><?php echo $mostrar["2"] ?></td>
                    <td><?php echo $mostrar["4"] ?></td>
                    <td><?php echo $mostrar["1"] ?></td>
                    <td><?php echo $mostrar["3"] ?></td>
                    <td><?php echo $mostrar["5"] ?></td>
                    <td><?php echo $mostrar["6"] ?></td>
                    <td><?php echo $mostrar["8"] ?></td>
                    <td>
                        <button class='btndanger eliminarCliente' data-id="<?php echo $mostrar["0"] ?>">Eliminar</button>
                        <button class='btnact actualizarCliente' data-id="<?php echo $mostrar["0"] ?>">Actualizar</button>
                        <button class='btnact detallesCliente' data-id="<?php echo $mostrar["0"] ?>">Detalles</button>
                    </td>
                </tr>
                <?php
                }
                mysqli_close($conection); 
                ?>
            </tbody>
        </table>
    </div>
</div>
<div id="updateModal" class="modal">
  <div class="modal-content">
    <form id="updateForm" class="updateForm">
    <div class="exit">&times;</div>
      <div class="parte">
      <input type="hidden" name="id" id="id" required="true">
      <label for="nom">Nombre:</label>
      <input type="text" name="nombre" id="nom" required="true">
      <label for="ap">Apellido:</label>
      <input type="text" name="apellido" id="ap" required="true">
      <label for="ed">Edad:</label>
      <input type="number" name="edad" id="ed" required="true" min="18" max="100">
      <label for="us">Usuario:</label>
      <input type="text" name="usuario" id="us" required="true">
      </div>
      <div class="parte">
      <label for="dir">Direccion:</label>
      <input type="text" name="direccion" id="dir" required="true">
      <label for="cor">Correo:</label>
      <input type="email" name="correo" id="cor" required="true">
      <label for="mon">Monedero:</label>
      <input type="number" name="monedero" id="mon" required="true" step="0.01" min="0">
      <button type="submit">Actualizar</button>
      </div>
    </form>
  </div>
</div>
<div  id="contenedorDetalles">
</div>
<script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../js/script.js"></script>
</body>
</html>
