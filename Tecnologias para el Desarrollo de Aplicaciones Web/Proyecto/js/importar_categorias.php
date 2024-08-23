<?php
include '../includes/conexion.php';
// Verificar la conexión
if ($conection->connect_error) {
    die("Conexión fallida: " . $conection->connect_error);
}

// Paso 2: Leer el archivo JSON
$jsonData = file_get_contents('productos.json');
$productos = json_decode($jsonData, true);

// Paso 3: Obtener categorías únicas del JSON
$categorias = array_unique(array_column($productos['products'], 'category'));

// Paso 4: Insertar categorías en la tabla
foreach ($categorias as $categoria) {
    $categoriaId = strtolower(str_replace(' ', '_', $categoria)); // Crear un ID de categoría basado en el nombre
    $nombre = $conection->real_escape_string($categoria);

    // Insertar la categoría si no existe
    $sql = "INSERT INTO categorias (id, nombre) VALUES ('$categoriaId', '$nombre') ON DUPLICATE KEY UPDATE nombre='$nombre'";
    
    if ($conection->query($sql) === TRUE) {
        echo "Categoría insertada con éxito: " . $categoria . "<br>";
    } else {
        echo "Error al insertar categoría: " . $conection->error . "<br>";
    }
}

// Paso 5: Cerrar la conexión
$conection->close();

