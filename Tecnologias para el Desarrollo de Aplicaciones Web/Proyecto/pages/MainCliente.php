<?php
session_name('cliente_sesion');
session_start();
include "../includes/conexion.php";
if (!isset($_SESSION["usuario"])) {
    echo "
    <script>
    alert('Por favor, debes iniciar sesión');
    window.location='index.html';
    </script>";
    session_destroy();
    die();
}?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="../css/estilos.css" rel="stylesheet" />
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/animate.css/4.1.1/animate.min.css"/>
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet" />
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Open+Sans">
    <title>MainCliente</title>
</head>
<body class="login">
    <header>

        <div class="menu-toggle">
            <i class="material-icons" id="menu-icon" style="display: block">menu</i>
        </div>
        <div class="navegador" id="menu">
            <a href="index.html">
                <div class="opcion">
                    <i class="material-icons">home</i>
                    <span>Inicio</span>
                </div>
            </a>
            <a href="historial.php">
                <div class="opcion">
                    <i class="material-icons">history</i>
                    <span>Historial</span>
                </div>
            </a>
            <a href="../php/cliente/cerrarSesion.php">
                <div class="opcion">
                    <i class="material-icons">logout</i>
                    <span>Cerrar Sesión</span>
                </div>
            </a>
        </div>
        <div class="eleccion">
            <form id="eleccionForm" method="post">
                <label>Selecciona una categoría:</label>
                <select id="opciones" name="categoria">
                    <?php
                    $sql = "SELECT `id`, `nombre` FROM `categorias`";
                    $rta = mysqli_query($conection, $sql);
                    while ($mostrar = mysqli_fetch_row($rta)) { ?>
                        <option value="<?php echo $mostrar['0'] ?>"><?php echo $mostrar['1'] ?></option>
                    <?php } ?>
                </select>
            </form>
        </div>
        <button id="carrito-btn"><i class="material-icons" id="menu-icon" style="display: block">shopping_cart</i></button>
        <div class="monedero">
            <p>Saldo disponible: $<?php echo $_SESSION["monedero"]; ?></p>
        </div>
        
    </header>
    <main>
        <br><br><br><br>
        <h2 class="TituloMain">Bienvenido, <?php echo $_SESSION["usuario"]; ?>!</h2>
        <div class="contenedorMain">
            <div id="productosContainer" class="contenedorProductos"></div>
        </div>
        
        <div class="contenedorEleccion ">
            <div class="exit exit4">&times;</div>
            <div id="cartContainer"></div>
        </div>
        
    </main>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../js/script.js"></script>
    <script>
        $(document).ready(function(){
            var categoria = $(this).find(":selected").val();
            $.ajax({
                type: 'POST',
                url: '../php/cliente/productos.php',
                data: { categoria: categoria },
                success: function(data) {
                    $('#productosContainer').html(data);
                    actualizarEstrellas();
                }
            });
            const actualizarEstrellas = () => {
            const starsContainers = $('.stars-container');
            starsContainers.each(function(index, container) {
                const calificacion = parseFloat($(container).data('rating'));
                const estrellasHTML = crearEstrellas(calificacion);
                $(container).html(estrellasHTML);
            });
        };
    
        const crearEstrellas = (calificacion) => {
            const estrellasLlenas = Math.round(calificacion);
            let htmlEstrellas = '';
        
            for (let i = 0; i < estrellasLlenas; i++) {
                htmlEstrellas += '<span class="star">&#9733;</span>';
            }
        
            for (let i = estrellasLlenas; i < 5; i++) {
                htmlEstrellas += '<span class="star">&#9734;</span>';
            }
        
            return htmlEstrellas;
        };
        });
    </script>
</body>
</html>
