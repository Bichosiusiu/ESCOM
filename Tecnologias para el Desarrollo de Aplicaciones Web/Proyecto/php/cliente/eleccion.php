<?php 
session_name('cliente_sesion');
session_start();
$_SESSION['total'] = 0;
$output = "";
$output .= "
<table class='tabla2'>
<tr>
<th>ID</th>
<th>Nombre</th>
<th>Precio</th>
<th>Cantidad</th>
<th>Total</th>
<th>Accion</th>
<tr>
";
if (!empty($_SESSION["cart"])) {
    foreach ($_SESSION["cart"] as $key => $value) {
        $output .= "
        <tr>
        <td>" . $value['id'] . "</td>
        <td>" . $value['name'] . "</td>
        <td>$" . number_format($value['price'] , 2, '.', ''). "</td>
        <td>" . $value['quantity'] . "</td>
        <td>$" . number_format(($value['price'] * $value['quantity']), 2, '.', ''). "</td>
        <td>
        <button class='btndanger eliminarProducto' data-id=" . $value['id'] . ">Eliminar</button>
        </td>
        ";
        $_SESSION['total']  = number_format(($_SESSION['total'] + $value['price'] * $value['quantity']), 2, '.', '');
    }
    $output .= "
<tr>
<td colspan='3'></td>
<td><b>Total</b></td>
<td>$".$_SESSION['total']."</td>
<td>
<button class='venta'>Venta</button></td>
</tr>
";
}
echo $output;
