<?php
session_name('control_sesion');
session_start();
include '../../includes/conexion.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $id = filter_input(INPUT_POST, 'id', FILTER_VALIDATE_INT);
    $nombre = filter_input(INPUT_POST, 'nombre', FILTER_SANITIZE_STRING);
    $descripcion = filter_input(INPUT_POST, 'descripcion', FILTER_SANITIZE_STRING);
    $miniatura = filter_input(INPUT_POST, 'miniatura', FILTER_SANITIZE_URL);
    $marca = filter_input(INPUT_POST, 'marca', FILTER_SANITIZE_STRING);
    $rating = filter_input(INPUT_POST, 'rating', FILTER_VALIDATE_FLOAT);
    $precio = filter_input(INPUT_POST, 'precio', FILTER_VALIDATE_FLOAT);
    $stock = filter_input(INPUT_POST, 'stock', FILTER_VALIDATE_INT);
    $descuento = filter_input(INPUT_POST, 'descuento', FILTER_VALIDATE_FLOAT);
    $idAdmin = $_SESSION["idcontrol"];

    if ($id === false || !$nombre || !$descripcion || !$miniatura || !$marca || $rating === false || $precio === false || $stock === false || $descuento === false || !$idAdmin) {
        echo "Entrada Invalida";
        exit;
    }
    $image_extensions = array('jpg', 'jpeg', 'png', 'gif', 'bmp', 'webp');
    $miniatura_ext = strtolower(pathinfo($miniatura, PATHINFO_EXTENSION));
    if (!filter_var($miniatura, FILTER_VALIDATE_URL) || !in_array($miniatura_ext, $image_extensions)) {
        echo "URL de Imagen Invalida";
        exit;
    }

    $nombre = mysqli_real_escape_string($conection, $nombre);
    $descripcion = mysqli_real_escape_string($conection, $descripcion);
    $miniatura = mysqli_real_escape_string($conection, $miniatura);
    $marca = mysqli_real_escape_string($conection, $marca);

    $sql = "UPDATE productos SET nombre= ?, descripcion= ?, miniatura= ?, marca= ?, rating= ?, precio= ?, stock= ?, descuento= ?, admin_id= ? WHERE id = ?";
    if ($stmt = mysqli_prepare($conection, $sql)) {
        mysqli_stmt_bind_param($stmt, 'ssssddidii', $nombre, $descripcion, $miniatura, $marca, $rating, $precio, $stock, $descuento, $idAdmin, $id);
        if (mysqli_stmt_execute($stmt)) {
            echo "success";
        } else {
            echo "error: " . mysqli_stmt_error($stmt);
        }
        mysqli_stmt_close($stmt);
    } else {
        echo "error: " . mysqli_error($conection);
    }
}

mysqli_close($conection);
?>

