<?php
include "../../includes/conexion.php";

if ($conection->connect_error) {
    die("Conexión fallida: " . $conection->connect_error);
}

$sql = "SELECT productos.nombre, SUM(compras.total) AS ingresos_totales
FROM compras
JOIN productos ON compras.producto_id = productos.id
GROUP BY productos.nombre
ORDER BY ingresos_totales DESC limit 10";
$result = $conection->query($sql);

$datos = array();
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        $datos[] = $row;
    }
} else {
    echo "0 resultados";
}
$conection->close();

// Convertir datos a JSON
echo json_encode($datos);