<?php
include '../../includes/conexion.php';

if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $sql = "SELECT * FROM usuario WHERE id = ?";
    if ($stmt = mysqli_prepare($conection, $sql)) {
        mysqli_stmt_bind_param($stmt, 'i', $id);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);
        $user = mysqli_fetch_assoc($result);
        echo json_encode($user);
        mysqli_stmt_close($stmt);
    } else {
        echo "error: " . mysqli_error($conection);
    }
}

mysqli_close($conection);