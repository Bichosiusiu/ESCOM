<?php
include "../../includes/conexion.php";

if ($conection->connect_error) {
    die("Conexión fallida: " . $conection->connect_error);
}

$sql = "SELECT DATE_FORMAT(fecha, '%Y-%m') AS mes, SUM(total) AS ingresos_totales
FROM compras
GROUP BY mes
ORDER BY mes;";
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