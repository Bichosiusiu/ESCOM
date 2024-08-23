<?php
include "../../includes/conexion.php";

if ($conection->connect_error) {
    die("Conexión fallida: " . $conection->connect_error);
}

$sql = "SELECT nombre, stock from productos ORDER BY stock ASC LIMIT 10";
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