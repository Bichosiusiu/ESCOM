<?php 
session_name('control_sesion');
session_start();// se inicia sesion
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
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
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
        <a href="cliente.php">
            <div class="opcion">
                <i class="material-icons">person</i>
                <span>Clientes</span>
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
    <h1>Reportes Generales
    </h1>
</header>
    <h2 class="TituloMain">Bienvenido <?php echo $_SESSION["control"]; ?>!</h2>
    <div class="contenedorMain">
    <div class="resumen">
    <button class="masVendidos">Productos mas Vendidos</button>
    <button class="categoriasVendidas">Categorias mas Vendidos</button>
    <button class="stock">Stock Disponible</button>
    <button class="ingresos">Ingresos Totales</button>
    <button class="ingProd">Ingresos por Producto</button>
    </div>
    <canvas id="reportes" width="30" height="10"></canvas>
    </div>
    <script src="../js/charts.js"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
</body>
</html>
