<?php
$conection = mysqli_connect("localhost","root","","Tienda");
//conexion a my sql
function sanitizeInput($data, $conection) {
    return mysqli_real_escape_string($conection, trim($data));
}