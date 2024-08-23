<?php
session_name('control_sesion');
session_start(); // se inicia sesion
include "../includes/conexion.php";
if (!isset($_SESSION["control"])) { //si no hay nada en en sesion usuario quiere decir que se quiere iniciar sesion desde fuera del login
    echo "<script>
    alert('Por favor, debes iniciar sesión');
    window.location='index.html';
    </script>";
    session_destroy(); // se prohibe el acceso y se destruye la sesión
    die(); //no se ejecuta la página y te devuelve a index.html
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="../css/estilos.css" rel="stylesheet" />
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet" />
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Open+Sans">
    <title>MainControl</title>
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
        <a href="MainControl.php">
            <div class="opcion">
                <i class="material-icons">query_stats</i>
                <span>Estadisticas</span>
            </div>
        </a>
        <a href="cliente.php">
            <div class="opcion">
                <i class="material-icons">person</i>
                <span>Clientes</span>
            </div>
        </a>
        <a href="../php/control/cerrarSesionControl.php">
            <div class="opcion">
                <i class="material-icons">logout</i>
                <span>Cerrar Sesión</span>
            </div>
        </a>
    </div>
    <form id="busqprod" name="busqprod" method="POST">
    <div class="busq">
          <input type="number" id="bus" name="bus" required="true" min="1"/>
          <input type="submit" value="Buscar Producto" />
    </div>
    </form>
    <button class="anadirProducto">Añadir Producto</button>
    <h1>Gestión de Inventario</h1>
</header>
    
<br><br>
<div class="contenedorProd">
    <div class="tabla-scroll">
        <table class='tabla'>
            <tr>
                <th>ID</th>
                <th>Nombre</th>
                <th>Descripcion</th>
                <th>Miniatura</th>
                <th>Marca</th>
                <th>Rating</th>
                <th>Precio</th>
                <th>Stock</th>
                <th>Descuento</th>
                <th>Categoria</th>
                <th>Id Administrador</th>
                <th>Acciones</th>
            </tr>
            <?php
            $sql = "SELECT * FROM productos";
            $rta = mysqli_query($conection, $sql);
            while ($mostrar = mysqli_fetch_row($rta)) { ?>
                <tr>
                    <td><?php echo $mostrar["0"] ?></td>
                    <td><?php echo $mostrar["1"] ?></td>
                    <td><?php echo $mostrar["2"] ?></td>
                    <td><?php echo $mostrar["3"] ?></td>
                    <td><?php echo $mostrar["4"] ?></td>
                    <td><?php echo $mostrar["5"] ?></td>
                    <td><?php echo $mostrar["6"] ?></td>
                    <td><?php echo $mostrar["7"] ?></td>
                    <td><?php echo $mostrar["8"] ?></td>
                    <td><?php echo $mostrar["9"] ?></td>
                    <td><?php echo $mostrar["11"] ?></td>
                    <td>
                        <button class='btndanger eliminarProd' data-id="<?php echo $mostrar["0"] ?>">Eliminar</button>
                        <button class='btnact actualizarProducto' data-id="<?php echo $mostrar["0"] ?>">Actualizar</button>
                    </td>
                </tr>
            <?php
            }
            ?>
        </table>
    </div>
</div>
   

<div id="updateInventarioModal" class="modal">
  <div class="modal-content">
    <form id="updateInventarioForm"class="updateForm">
    <div class="exit exit2">&times;</div>
    <div class="parte">
    <input type="hidden" name="id" id="id" required>
            <label for="nom">Nombre:</label>
            <input type="text" name="nombre" id="nom" required>
            <label for="descripcion">Descripción:</label>
            <textarea name="descripcion" id="descripcion" rows="3" required></textarea>
            <label for="min">Miniatura URL:</label>
            <input type="url" name="miniatura" id="min" required>
            <label for="mar">Marca:</label>
            <input type="text" name="marca" id="mar" required>
            <label for="rat">Rating:</label>
            <input type="number" name="rating" id="rat" step="0.01" min="0.1" max="5" required>
    </div>
    <div class="parte">
    <label for="pre">Precio:</label>
            <input type="number" name="precio" id="pre" step="0.01" min="1" required>
            <label for="stock">Stock:</label>
            <input type="number" name="stock" id="stock" min="1" required>
            <label for="des">Descuento (%):</label>
            <input type="number" name="descuento" id="des" step="0.01" min="0" max="100" required>
            <button type="submit">Actualizar</button>
    </div>
    </form>
  </div>
  </div>
  <div id="addInventarioModal" class="modal">
  <div class="modal-content">
    <form id="addInventarioForm" class="updateForm">
    <div class="exit exit3">&times;</div>
    <div class="parte">
            <label for="nom">Nombre:</label>
            <input type="text" name="nombre" id="nom" required>
            <label for="descripcion">Descripción:</label>
            <textarea name="descripcion" id="descripcion" rows="3" required></textarea>
            <label for="min">Miniatura URL:</label>
            <input type="url" name="miniatura" id="min" required>
            <label for="mar">Marca:</label>
            <input type="text" name="marca" id="mar" required>
            <label for="rat">Rating:</label>
            <input type="number" name="rating" id="rat" step="0.01" min="0.1" max="5" required>
    </div>
    <div class="parte">
    <label for="pre">Precio:</label>
            <input type="number" name="precio" id="pre" step="0.01" min="1" required>
            <label for="stock">Stock:</label>
            <input type="number" name="stock" id="stock" min="1" required>
            <label for="des">Descuento (%):</label>
            <input type="number" name="descuento" id="des" step="0.01" min="0" max="100" required>
            <label for="cat">Categoria:</label>
            <select id="cat" name="categoria"> 
                    <?php
                    $sql = "SELECT `id`, `nombre` FROM `categorias`";
                    $rta = mysqli_query($conection, $sql);
                    while ($mostrar = mysqli_fetch_row($rta)) { ?>
                        <option value="<?php echo $mostrar['0'] ?>"><?php echo $mostrar['1'] ?></option>
                    <?php } ?>
                </select>
            <button type="submit">Agregar Producto</button>
    </div>
    </form>
  </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../js/script.js"></script>
</body>
</html>