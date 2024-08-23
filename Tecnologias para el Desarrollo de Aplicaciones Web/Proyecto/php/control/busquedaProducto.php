<?php
session_name('control_sesion');
session_start();
include '../../includes/conexion.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Verificar si se recibió correctamente el parámetro 'bus'
    if (isset($_POST['bus'])) {
        $id = $_POST['bus'];
        $sql = "SELECT id, nombre, descripcion, miniatura, marca, rating, precio, stock, descuento, categoria_id, admin_id FROM productos WHERE id = ?";
        
        if ($stmt = mysqli_prepare($conection, $sql)) {
            mysqli_stmt_bind_param($stmt, 'i', $id);
            
            if (mysqli_stmt_execute($stmt)) {
                mysqli_stmt_store_result($stmt);
                
                if (mysqli_stmt_num_rows($stmt) > 0) {
                    mysqli_stmt_bind_result($stmt, $id, $nombre, $descripcion, $miniatura, $marca, $rating, $precio, $stock, $descuento, $categoria,$admin);
                    $output = " ";
                    $output .= "<table class='tabla'>";
                    $output .= "<tr>
                                    <th>ID</th>
                                    <th>Nombre</th>
                                    <th>Descripcion</th>
                                    <th>Miniatura</th>
                                    <th>Marca</th>
                                    <th>rating</th>
                                    <th>precio</th>
                                    <th>stock</th>
                                    <th>descuento</th>
                                    <th>categoria</th>
                                    <th>admin</th>
                                    <th>accion</th>
                                </tr>";
                    
                    while (mysqli_stmt_fetch($stmt)) {
                        $output .= "<tr>
                                        <td>".$id."</td>
                                        <td>".$nombre."</td>
                                        <td>".$descripcion."</td>
                                        <td>".$miniatura."</td>
                                        <td>".$marca."</td>
                                        <td>".$rating."</td>
                                        <td>".$precio."</td>
                                        <td>".$stock."</td>
                                        <td>".$descuento."</td>
                                        <td>".$categoria."</td>
                                        <td>".$admin."</td>
                                        <td>
                                            <button class='btndanger eliminarProd' data-id=" . $id . ">Eliminar</button>
                                            <button class='btnact actualizarProducto' data-id=" . $id . ">Actualizar</button>
                                        </td>
                                    </tr>";
                    }
                    
                    $output .= "</table>";
                    $output .= "</div>";
                    
                    echo $output;
                } else {
                    echo "No se encontraron resultados";
                }
            } else {
                echo "Error al ejecutar la consulta: " . mysqli_stmt_error($stmt);
            }
            
            mysqli_stmt_close($stmt);
        } else {
            echo "Error en la preparación de la consulta: " . mysqli_error($conection);
        }
    } else {
        echo "No se recibió el parámetro 'bus' correctamente";
    }
    
    mysqli_close($conection);
}
?>
