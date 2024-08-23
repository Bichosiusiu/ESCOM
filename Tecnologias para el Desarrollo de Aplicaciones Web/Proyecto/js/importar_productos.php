<?php
include '../includes/conexion.php';
// Paso 2: Leer el archivo JSON
$jsonData = file_get_contents('productos.json');
$productos = json_decode($jsonData, true);

// Verificar la conexión
if ($conection->connect_error) {
    die("Conexión fallida: " . $conection->connect_error);
}

// Paso 4: Iterar sobre los productos e insertar en la base de datos
foreach ($productos['products'] as $producto) {
    $id = $producto['id'];
    $nombre = $conection->real_escape_string($producto['title']);
    $descripcion = $conection->real_escape_string($producto['description']);
    $precio = $producto['price'];
    $descuento = $producto['discountPercentage'];
    $rating = $producto['rating'];
    $stock = $producto['stock'];
    $marca = $conection->real_escape_string($producto['brand']);
    $categoria_id = $conection->real_escape_string($producto['category']);
    $miniatura = $conection->real_escape_string($producto['thumbnail']);

    $sql = "INSERT INTO productos (id, nombre, descripcion, precio, descuento, rating, stock, marca, categoria_id, miniatura)
            VALUES ('$id', '$nombre', '$descripcion', '$precio', '$descuento', '$rating', '$stock', '$marca', '$categoria_id', '$miniatura')";

    if ($conection->query($sql) === TRUE) {
        echo "Producto insertado con éxito: " . $producto['title'] . "<br>";
    } else {
        echo "Error al insertar producto: " . $conection->error . "<br>";
    }
}

// Paso 5: Cerrar la conexión
$conection->close();
