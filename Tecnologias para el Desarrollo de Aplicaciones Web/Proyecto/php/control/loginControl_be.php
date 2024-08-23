<?php
session_name('control_sesion');
session_start();
include "../../includes/conexion.php";

$response = array();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Sanitización de los datos de entrada
    $usuario = mysqli_real_escape_string($conection, $_POST["usuario"]);
    $password = mysqli_real_escape_string($conection, $_POST["password"]);

    // Validación de los datos (opcional)
    if (empty($usuario) || empty($password)) {
        $response['success'] = false;
        $response['message'] = "Todos los campos son requeridos.";
    } else {
        // Consulta SQL con los datos sanitizados
        $query = "SELECT * FROM admin WHERE usuario='$usuario' AND pass='$password'";
        $validar = mysqli_query($conection, $query);

        if (mysqli_num_rows($validar) > 0) {
            $usuario = mysqli_fetch_assoc($validar);
            $_SESSION["control"] = $usuario['usuario'];
            $_SESSION["idcontrol"] = $usuario['id'];
            $response['success'] = true;
            $response['redirect'] = "MainControl.php";
        } else {
            $response['success'] = false;
            $response['message'] = "Datos Erroneos. Favor de Ingresar Datos Correctos";
        }
    }
} else {
    $response['success'] = false;
    $response['message'] = "Solicitud no válida";
}

echo json_encode($response);
?>
