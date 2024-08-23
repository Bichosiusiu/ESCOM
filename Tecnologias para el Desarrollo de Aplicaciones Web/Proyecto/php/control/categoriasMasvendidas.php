<?php
include "../../includes/conexion.php";

if ($conection->connect_error) {
    die("Conexión fallida: " . $conection->connect_error);
}

$sql = "SELECT c.nombre AS categoria, SUM(co.cantidad) AS total_vendido
        FROM compras co
        JOIN productos p ON co.producto_id = p.id
        JOIN categorias c ON p.categoria_id = c.id
        GROUP BY c.id
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

// Convertir datos a JSON
echo json_encode($datos);