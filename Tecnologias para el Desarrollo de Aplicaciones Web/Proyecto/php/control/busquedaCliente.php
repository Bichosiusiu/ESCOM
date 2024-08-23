<?php
session_name('control_sesion');
session_start();
include '../../includes/conexion.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Verificar si se recibió correctamente el parámetro 'bus'
    if (isset($_POST['bus'])) {
        $id = $_POST['bus'];
        $sql = "SELECT id, usuario, nombre, edad, apellido, direccion, correo, monedero FROM usuario WHERE id = ?";
        
        if ($stmt = mysqli_prepare($conection, $sql)) {
            mysqli_stmt_bind_param($stmt, 'i', $id);
            
            if (mysqli_stmt_execute($stmt)) {
                mysqli_stmt_store_result($stmt);
                
                if (mysqli_stmt_num_rows($stmt) > 0) {
                    mysqli_stmt_bind_result($stmt, $id, $usuario, $nombre, $edad, $apellido, $direccion, $correo, $monedero);
                    $output=" ";
                    $output .= "<table class='tabla'>";
                    $output .= "<tr>
                                    <th>ID</th>
                                    <th>Usuario</th>
                                    <th>Nombre</th>
                                    <th>Edad</th>
                                    <th>Apellido</th>
                                    <th>Dirección</th>
                                    <th>Correo</th>
                                    <th>Monedero</th>
                                    <th>Acción</th>
                                </tr>";
                    
                    while (mysqli_stmt_fetch($stmt)) {
                        $output .= "<tr>
                                        <td>".$id."</td>
                                        <td>".$usuario."</td>
                                        <td>".$nombre."</td>
                                        <td>".$edad."</td>
                                        <td>".$apellido."</td>
                                        <td>".$direccion."</td>
                                        <td>".$correo."</td>
                                        <td>".$monedero."</td>
                                        <td>
                                            <button class='btndanger eliminarCliente' data-id=" . $id . ">Eliminar</button>
                                            <button class='btnact actualizarCliente' data-id=" . $id . ">Actualizar</button>
                                            <button class='btnact detallesCliente' data-id=" . $id . ">Detalles</button>
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
