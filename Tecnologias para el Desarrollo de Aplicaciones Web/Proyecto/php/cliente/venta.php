<?php
session_name('cliente_sesion');
session_start();
include '../../includes/conexion.php';

// Incluir la clase Dompdf
require_once '../../vendor/autoload.php';

use Dompdf\Dompdf;

$id_usuario = $_SESSION["idCliente"];
if ($_SESSION['total'] > $_SESSION["monedero"]) {
    echo "exceso";
} elseif (!empty($_SESSION["cart"])) {
    mysqli_begin_transaction($conection);
    try {
        foreach ($_SESSION["cart"] as $key => $value) {
            $id_producto = $value['id'];
            $cantidad = $value['quantity'];
            $total = $value['price'] * $value['quantity'];
            $fecha_actual = date("Y-m-d H:i:s");

            // Consulta para obtener el stock actual del producto
            $query = "SELECT stock FROM productos WHERE id = ?";
            $stmt = mysqli_prepare($conection, $query);
            mysqli_stmt_bind_param($stmt, "i", $id_producto);
            mysqli_stmt_execute($stmt);
            mysqli_stmt_bind_result($stmt, $stock);
            mysqli_stmt_fetch($stmt);
            mysqli_stmt_close($stmt);

            // Verificar si hay suficiente stock para el pedido
            if ($stock >= $cantidad) {
                // Actualizar el stock del producto
                $query = "UPDATE productos SET stock = stock - ? WHERE id = ?";
                $stmt = mysqli_prepare($conection, $query);
                mysqli_stmt_bind_param($stmt, "ii", $cantidad, $id_producto);
                mysqli_stmt_execute($stmt);
                mysqli_stmt_close($stmt);

                // Registrar la compra en la tabla 'compras'
                $query = "INSERT INTO compras (usuario_id, producto_id, cantidad, total, fecha) VALUES (?, ?, ?, ?, ?)";
                $stmt = mysqli_prepare($conection, $query);
                mysqli_stmt_bind_param($stmt, "iiids", $id_usuario, $id_producto, $cantidad, $total, $fecha_actual);
                mysqli_stmt_execute($stmt);
                mysqli_stmt_close($stmt);
            } else {
                // Mostrar mensaje de error si no hay suficiente stock
                echo "stock";
                // Cancelar la transacción si no hay suficiente stock
                mysqli_rollback($conection);
                exit(); // Salir del script después de mostrar el mensaje
            }
        }

        // Actualizar el monedero del cliente después de la compra
        $_SESSION["monedero"] -= $_SESSION['total'];
        $monact = $_SESSION["monedero"];
        $query = "UPDATE usuario SET monedero = ? WHERE id = ?";
        $stmt = mysqli_prepare($conection, $query);
        mysqli_stmt_bind_param($stmt, "di", $monact, $id_usuario);
        mysqli_stmt_execute($stmt);
        mysqli_stmt_close($stmt);

        // Confirmar la transacción si todo ha ido bien
        mysqli_commit($conection);

        // Generar el contenido HTML para el PDF
        $html_content = '
            <style>
                body { font-family: Arial, sans-serif; margin: 20px; }
                h1 { text-align: center; color: #333; margin-bottom: 20px; }
                table { width: 100%; border-collapse: collapse; margin-top: 20px; }
                th, td { border: 1px solid #ddd; padding: 12px; text-align: left; }
                th { background-color: #f2f2f2; }
                tr:nth-child(even) { background-color: #f9f9f9; }
                .total { text-align: right; font-weight: bold; margin-top: 20px; }
                .container { margin: 20px auto; padding: 20px; border: 1px solid #ddd; border-radius: 5px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }
            </style>';

        $html_content .= ' <div class="container">
                            <h1>Detalle de Venta</h1>
                            <p class="total">Cliente: ' . $_SESSION['nomcompleto'] . '</p>
                            <p class="total">Fecha: ' . $fecha_actual . '</p>';
        $html_content .= '<table>
                            <thead>
                                <tr>
                                    <th>ID Producto</th>
                                    <th>Nombre</th>
                                    <th>Cantidad</th>
                                    <th>Precio Unitario</th>
                                    <th>Total</th>
                                </tr>
                            </thead>
                            <tbody>';

        foreach ($_SESSION["cart"] as $producto) {
            $html_content .= '<tr>
                                <td>' . $producto['id'] . '</td>
                                <td>' . $producto['name'] . '</td>
                                <td>' . $producto['quantity'] . '</td>
                                <td>$' . number_format($producto['price'], 2) . '</td>
                                <td>$' . number_format($producto['price'] * $producto['quantity'], 2) . '</td>
                              </tr>';
        }

        $html_content .= '</tbody>
                        </table>';
        $html_content .= '<p class="total">Total: $' . number_format($_SESSION['total'], 2) . '</p></div>';

        // Crear instancia de Dompdf
        $dompdf = new Dompdf();
        $dompdf->loadHtml($html_content);

        // Renderizar el PDF
        $dompdf->render();

        // Obtener el contenido del PDF generado
        $contenido_pdf = $dompdf->output();

        // Ruta para guardar el archivo PDF en el servidor
        $carpeta_destino = '../../pdf';
        if (!is_dir($carpeta_destino)) {
            mkdir($carpeta_destino, 0777, true);
        }
        $nombre_archivo_pdf = 'venta_' . date('Y-m-d_H-i-s') . '.pdf';
        $ruta_pdf_guardado = $carpeta_destino . '/' . $nombre_archivo_pdf;

        // Guardar el archivo PDF en el servidor
        file_put_contents($ruta_pdf_guardado, $contenido_pdf);

        // Limpiar el carrito de compras después de completar la transacción
        unset($_SESSION['cart']);

        // Mostrar un enlace para descargar el archivo PDF generado automáticamente
        echo "<script>
                var link = document.createElement('a');
                link.href = '../pdf/$nombre_archivo_pdf'; // Ruta accesible desde el navegador
                link.download = 'venta.pdf';
                document.body.appendChild(link);
                link.click();
                document.body.removeChild(link);
              </script>";
    } catch (Exception $e) {
        // Manejar errores y hacer rollback en caso de excepción
        mysqli_rollback($conection);
        echo "<script>alert('Error en la venta: " . $e->getMessage() . "');</script>";
    }
} else {
    // Mostrar mensaje si el carrito está vacío
    echo "<script>alert('Elija productos');</script>";
}
?>
