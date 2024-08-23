<?php
session_name('control_sesion');
session_start();
include '../../includes/conexion.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Sanitize and validate input data using filter_input
    $id = filter_input(INPUT_POST, 'id', FILTER_VALIDATE_INT);
    $nombre = filter_input(INPUT_POST, 'nombre', FILTER_SANITIZE_STRING);
    $apellido = filter_input(INPUT_POST, 'apellido', FILTER_SANITIZE_STRING);
    $edad = filter_input(INPUT_POST, 'edad', FILTER_VALIDATE_INT);
    $usuario = filter_input(INPUT_POST, 'usuario', FILTER_SANITIZE_STRING);
    $direccion = filter_input(INPUT_POST, 'direccion', FILTER_SANITIZE_STRING);
    $correo = filter_input(INPUT_POST, 'correo', FILTER_VALIDATE_EMAIL);
    $monedero = filter_input(INPUT_POST, 'monedero', FILTER_VALIDATE_FLOAT);

    // Check if any required field is missing or invalid
    if ($id === false || $edad === false || $correo === false || $monedero === false || !$nombre || !$apellido || !$usuario || !$direccion) {
        echo "Entrada invalida";
        exit;
    }

    // Further sanitize inputs with mysqli_real_escape_string for additional security
    $nombre = mysqli_real_escape_string($conection, $nombre);
    $apellido = mysqli_real_escape_string($conection, $apellido);
    $usuario = mysqli_real_escape_string($conection, $usuario);
    $direccion = mysqli_real_escape_string($conection, $direccion);
    $correo = mysqli_real_escape_string($conection, $correo);

    // Prepare the SQL statement with placeholders
    $sql = "UPDATE usuario SET usuario= ?, nombre= ?, edad= ?, apellido= ?, direccion= ?, correo= ?, monedero= ? WHERE id = ?";
    if ($stmt = mysqli_prepare($conection, $sql)) {
        // Bind the parameters to the SQL statement
        mysqli_stmt_bind_param($stmt, 'ssisssdi', $usuario, $nombre, $edad, $apellido, $direccion, $correo, $monedero, $id);
        // Execute the statement
        if (mysqli_stmt_execute($stmt)) {
            echo "success";
        } else {
            echo "error: " . mysqli_stmt_error($stmt);
        }
        // Close the statement
        mysqli_stmt_close($stmt);
    } else {
        echo "error: " . mysqli_error($conection);
    }
}

// Close the database connection
mysqli_close($conection);
?>
