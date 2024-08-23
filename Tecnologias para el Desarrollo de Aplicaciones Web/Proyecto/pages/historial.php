<?php 
session_name('cliente_sesion');
session_start();
include "../includes/conexion.php";
if(!isset($_SESSION["usuario"])){
    echo "
    <script>
    alert('Por favor, debes iniciar sesión');
    window.location='index.html';
    </script>";
    session_destroy();
    die();
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
    <title>Historial de Compras</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
</head>
<body>
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
            <a href="MainCliente.php">
                <div class="opcion">
                    <i class="material-icons">store</i>
                    <span>Tienda</span>
                </div>
            </a>
            <a href="../php/cliente/cerrarSesion.php">
                <div class="opcion">
                    <i class="material-icons">logout</i>
                    <span>Cerrar Sesión</span>
                </div>
            </a>
        </div>
    <h1>Historial de Compras</h1>
</header>
<div class="contenedorH">
<?php
    $totalCompras = 0;
    $totalGastado = 0;
    $ultimaCompra = "";

    $sql="select c.id,u.nombre,u.apellido,p.nombre as nombre_producto,c.cantidad,p.precio,u.direccion,c.total,c.fecha from compras c INNER join productos p on p.id=c.producto_id INNER join usuario u on u.id=c.usuario_id where u.id=?";
    if ($stmt = mysqli_prepare($conection, $sql)) {
        mysqli_stmt_bind_param($stmt, "i", $_SESSION["idCliente"]);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);
        
        while ($mostrar = mysqli_fetch_assoc($result)) {
            $totalCompras++;
            $totalGastado += $mostrar["total"];
            $ultimaCompra = $mostrar["fecha"];
        }
    }
    ?>
    <div class="resumen">
        <div>
            <h2>Total de Compras</h2>
            <p><?php echo $totalCompras?></p> 
        </div>
        <div>
            <h2>Total Gastado</h2>
            <p><?php echo "$".$totalGastado?></p> 
        </div>
        <div>
            <h2>Última Compra</h2>
            <p><?php echo $ultimaCompra?></p>
        </div>
    </div>
    <div class="tabla-container">
    <table class='tabla'>
        <thead >
            <tr>
                <th>ID</th>
                <th>Nombre</th>
                <th>Apellido</th>
                <th>Producto</th>
                <th>Cantidad</th>
                <th>Precio Unitario</th>
                <th>Direccion</th>
                <th>Total</th>
                <th>Fecha</th>
            </tr>
        </thead>
        <tbody>
            <?php
            if ($stmt = mysqli_prepare($conection, $sql)) {
                mysqli_stmt_bind_param($stmt, "i", $_SESSION["idCliente"]);
                mysqli_stmt_execute($stmt);
                $result = mysqli_stmt_get_result($stmt);
                while ($mostrar = mysqli_fetch_assoc($result)) {
                    echo "<tr>
                            <td>" . htmlspecialchars($mostrar["id"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["nombre"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["apellido"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["nombre_producto"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["cantidad"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["precio"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["direccion"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["total"]) . "</td>
                            <td>" . htmlspecialchars($mostrar["fecha"]) . "</td>
                        </tr>";
                }
                mysqli_free_result($result);
            }
            ?>
        </tbody>
    </table>
</div>

</div>
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script src="../js/script.js"></script>
</body>
</html>