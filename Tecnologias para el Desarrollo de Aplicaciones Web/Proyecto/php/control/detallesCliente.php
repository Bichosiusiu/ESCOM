<?php
include '../../includes/conexion.php';

if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $totalCompras = 0;
    $totalGastado = 0;
    $ultimaCompra = "";
    $sql = "SELECT c.id, u.nombre, u.apellido, p.nombre AS nombre_producto, c.cantidad, p.precio, u.direccion, c.total, c.fecha 
            FROM compras c 
            INNER JOIN productos p ON p.id = c.producto_id 
            INNER JOIN usuario u ON u.id = c.usuario_id 
            WHERE u.id = ? 
            ORDER BY c.id DESC";

    if ($stmt = mysqli_prepare($conection, $sql)) {
        mysqli_stmt_bind_param($stmt, "i", $id);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);

        if (mysqli_num_rows($result) > 0) {
            $output = "
            <table class='tabla'>
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
            </tr>";
            
            while ($mostrar = mysqli_fetch_assoc($result)) {
                $output .= "
                <tr>
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
                $totalCompras++;
            $totalGastado += $mostrar["total"];
            $ultimaCompra = $mostrar["fecha"];
            }
            
            $output .= "</table>";
            echo '<div class="exit exit5">&times;</div>
            <div class="resumen">
        <div>
            <h2>Total de Compras</h2>
            <p>'.$totalCompras.'</p> 
        </div>
        <div>
            <h2>Total Gastado</h2>
            <p>$'.$totalGastado.'</p> 
        </div>
        <div>
            <h2>Última Compra</h2>
            <p>'.$ultimaCompra.'</p>
        </div>
    </div>'.$output;
        } else {
            echo "<div class='exit exit5'>&times;</div><br>No hay historial";
        }

        mysqli_stmt_close($stmt);
    } else {
        echo "Error en la consulta SQL.";
    }
    
    mysqli_close($conection);
} else {
    echo "ID de usuario no especificado.";
}
?>
