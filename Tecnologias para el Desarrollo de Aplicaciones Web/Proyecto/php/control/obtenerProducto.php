<?php
include '../../includes/conexion.php';

if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $sql = "SELECT * FROM productos WHERE id = ?";
    if ($stmt = mysqli_prepare($conection, $sql)) {
        mysqli_stmt_bind_param($stmt, 'i', $id);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);
        if ($result) {
            $prod = mysqli_fetch_assoc($result);
            echo json_encode($prod);
        } else {
            echo json_encode(["error" => "Producto no encontrado"]);
        }
        mysqli_stmt_close($stmt);
    } else {
        echo json_encode(["error" => mysqli_error($conection)]);
    }
} else {
    echo json_encode(["error" => "ID no proporcionado"]);
}

mysqli_close($conection);
