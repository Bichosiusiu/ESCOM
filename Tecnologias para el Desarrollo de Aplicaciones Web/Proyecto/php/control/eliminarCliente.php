<?php
session_name('control_sesion');
session_start();
include '../../includes/conexion.php';

if (isset($_GET['action']) && $_GET['action'] == 'remove' && isset($_GET['id'])) {
    $id = $_GET['id'];
    $sql_update_orders = "UPDATE compras SET usuario_id = NULL WHERE usuario_id = ?";
    if ($stmt_orders = mysqli_prepare($conection, $sql_update_orders)) {
        mysqli_stmt_bind_param($stmt_orders, 'i', $id);
        mysqli_stmt_execute($stmt_orders);
        mysqli_stmt_close($stmt_orders);
    }

    $sql_delete_user = "DELETE FROM usuario WHERE id = ?";
    if ($stmt_user = mysqli_prepare($conection, $sql_delete_user)) {
        mysqli_stmt_bind_param($stmt_user, 'i', $id);
        if (mysqli_stmt_execute($stmt_user)) {
            echo "success";
        } else {
            echo "error: " . mysqli_stmt_error($stmt_user);
        }
        mysqli_stmt_close($stmt_user);
    } else {
        echo "error: " . mysqli_error($conection);
    }
} else {
    echo "error: Parametros invalidos";
}

mysqli_close($conection);
