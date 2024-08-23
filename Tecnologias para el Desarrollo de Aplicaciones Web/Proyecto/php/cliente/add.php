<?php
session_name('cliente_sesion');
session_start();
$agregar="<script>
Swal.fire({
icon: 'success',
title: '¡Producto Agregado al Carrito!',
showConfirmButton: false,
timer: 2000,
toast: true,
position: 'top-end',
showCloseButton: true,
background: '#d4edda',
customClass: {
popup: 'animated bounceInRight',
title: 'text-success font-weight-bold',
closeButton: 'btn btn-outline-success'
}
});
</script>";
$stock="<script>
    Swal.fire({
    icon: 'error',
    title: '¡Oops!',
    text: '¡Has superado el stock de este producto!',
    background: '#f8d7da',
    iconColor: '#dc3545',
    toast: true,
    showClass: {
        popup: 'animated bounceIn'
    },
    hideClass: {
        popup: 'animated bounceOut'
    },
    customClass: {
        title: 'text-danger font-weight-bold',
        content: 'text-muted',
        closeButton: 'btn btn-outline-danger'
    },
    position: 'top-end',
    showConfirmButton: false,
    timer: 2000,
});
</script>";
    if (isset($_SESSION["cart"])) {
        $session_array_id = array_column($_SESSION["cart"], "id");
        if (!in_array($_POST["id"], $session_array_id)) {
            if($_POST["stock"]>=$_POST["quantity"]){
            $session_array = array(
                "id" => $_POST["id"],
                "name" => $_POST["name"],
                "price" => $_POST["price"],
                "quantity" => $_POST["quantity"]
            );
            $_SESSION["cart"][] = $session_array;
            echo $agregar;
        }
        else{
            echo $stock;
        }
        }else{
            echo "<script>
        Swal.fire({
    icon: 'error',
    title: '¡Oops!',
    text: 'Este producto ya ha sido agregado al carrito.',
    background: '#fff3cd',
    iconColor: '#ffc107',
    showClass: {
        popup: 'animated bounceInDown'
    },
    hideClass: {
        popup: 'animated bounceOutUp'
    },
    customClass: {
        title: 'text-warning font-weight-bold',
        content: 'text-muted',
        closeButton: 'btn btn-outline-warning'
    },
    showConfirmButton: false,
    toast: true,
    position: 'top-end',
    timer: 2000,
});</script>";
        }
    } else {
        if($_POST["stock"]>=$_POST["quantity"]){
        $session_array = array(
            "id" => $_POST["id"],
            "name" => $_POST["name"],
            "price" => $_POST["price"],
            "quantity" => $_POST["quantity"]
        );
        $_SESSION["cart"][] = $session_array; 
        echo $agregar;
    }else{
        echo $stock;
    }
}
