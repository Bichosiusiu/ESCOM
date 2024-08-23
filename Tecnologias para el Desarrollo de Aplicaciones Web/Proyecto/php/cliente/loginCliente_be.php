<?php
session_name('cliente_sesion');
session_start();
include "../../includes/conexion.php";

$response = array(); 

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Sanitizar entradas
    $correo = sanitizeInput($_POST["correo"], $conection);
    $password = sanitizeInput($_POST["password"], $conection);

    // Validar que los campos no estén vacíos
    if (empty($correo) || empty($password)) {
        $response['success'] = false;
        $response['message'] = "Todos los campos son obligatorios.";
        echo json_encode($response);
        exit();
    }

    // Hash de la contraseña
    $password = hash("sha512", $password);

    // Consulta SQL
    $query = "SELECT * FROM usuario WHERE correo='$correo' AND pass='$password'";
    $validar = mysqli_query($conection, $query);

    if (mysqli_num_rows($validar) > 0) {
        $usuario = mysqli_fetch_assoc($validar);
        $_SESSION["monedero"] = $usuario['monedero'];
        $_SESSION["idCliente"] = $usuario['id'];
        $_SESSION["nomcompleto"] = $usuario['nombre'] . ' ' . $usuario['apellido'];
        $_SESSION["usuario"] = $usuario['nombre'];
        $_SESSION["gastado"] = 0;
        $response['success'] = true;
        $response['redirect'] = "MainCliente.php";
    } else {
        $response['success'] = false;
        $response['message'] = "Datos Erroneos. Favor de Ingresar Datos Correctos";
    }
} else {
    $response['success'] = false;
    $response['message'] = "Solicitud no válida";
}

echo json_encode($response);
?>