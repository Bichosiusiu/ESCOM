<?php
session_name('cliente_sesion');
session_start();
if(isset($_GET["action"]) && $_GET['action'] == "remove" && isset($_GET["id"])){
    $id_to_remove = $_GET["id"];
    foreach ($_SESSION["cart"] as $key => $value) {
        if($value["id"] == $id_to_remove){
            unset($_SESSION["cart"][$key]);
            break;
        }
    }
    echo "
    <script>
    Swal.fire({
    icon: 'success',
    title: '¡Producto Removido del Carrito!',
    text: 'El producto ha sido eliminado correctamente.',
    showConfirmButton: false,
    toast: true,
    timer: 2000,
    customClass: {
        popup: 'animated zoomIn',
        title: 'text-success font-weight-bold',
        content: 'text-muted'
    }
});</script>";
}
