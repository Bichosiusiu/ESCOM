<?php
include '../../includes/conexion.php';

// Función para validar la contraseña
function validarContraseña($password) {
    // Longitud mínima de 8 caracteres
    if (strlen($password) < 8) {
        return false;
    }
    // Contiene al menos una mayúscula, un número y un caracter especial
    if (!preg_match('/[A-Z]/', $password) || !preg_match('/[0-9]/', $password) || !preg_match('/[^a-zA-Z0-9]/', $password)) {
        return false;
    }
    return true;
}

// Recibir y sanitizar entradas del formulario
$nombre = sanitizeInput($_POST["nom"], $conection);
$apellido = sanitizeInput($_POST["ap"], $conection);
$edad = sanitizeInput($_POST["edad"], $conection);
$dir = sanitizeInput($_POST["dir"], $conection);
$correo = sanitizeInput($_POST["correo"], $conection);
$usuario = sanitizeInput($_POST["usuario"], $conection);
$password = sanitizeInput($_POST["password"], $conection);
$monedero = 10000;

if (!filter_var($correo, FILTER_VALIDATE_EMAIL)) {
    echo "Correo no válido.";
    exit();
}

if (!is_numeric($edad) || $edad <= 0) {
    echo "Edad no válida.";
    exit();
}

if (!validarContraseña($password)) {
    echo "La contraseña debe contener al menos 8 caracteres, una mayúscula, un número y un caracter especial.";
    exit();
}

// Hashear la contraseña antes de guardarla
$password = hash("sha512", $password);

// Verificar si el correo ya existe
$verificar = mysqli_query($conection, "SELECT * FROM usuario WHERE correo='$correo'");
if (mysqli_num_rows($verificar) > 0) {
    echo "Correo ya existente";
    exit();
}

// Verificar si el usuario ya existe
$verificar_usuario = mysqli_query($conection, "SELECT * FROM usuario WHERE usuario='$usuario'");
if (mysqli_num_rows($verificar_usuario) > 0) {
    echo "Usuario ya existente";
    exit();
}

// Preparar y ejecutar la consulta SQL
$query = "INSERT INTO usuario(nombre, apellido, edad, direccion, correo, usuario, pass, monedero) VALUES ('$nombre', '$apellido', '$edad', '$dir', '$correo', '$usuario', '$password', '$monedero')";
$ejecutar = mysqli_query($conection, $query);

if ($ejecutar) {
    echo "exito";
} else {
    echo "fracaso";
}

mysqli_close($conection);
?>
