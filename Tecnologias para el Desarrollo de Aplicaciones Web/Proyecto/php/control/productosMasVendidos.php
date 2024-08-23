<?php
include "../../includes/conexion.php";

if ($conection->connect_error) {
    die("Conexión fallida: " . $conection->connect_error);
}

$sql = "SELECT p.nombre, SUM(c.cantidad) AS total_vendido
        FROM compras c
        JOIN productos p ON c.producto_id = p.id
        GROUP BY c.producto_id
        ORDER BY total_vendido DESC
        LIMIT 10";
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

echo json_encode($datos);
