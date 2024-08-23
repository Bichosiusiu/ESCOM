<?php
include "../../includes/conexion.php";
                if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["categoria"])) {
                    $opcionSeleccionada = $_POST["categoria"];
                    $sql = "SELECT * FROM productos WHERE categoria_id='$opcionSeleccionada'";
                    $rta = mysqli_query($conection, $sql);
                    while ($mostrar = mysqli_fetch_row($rta)) {
                        $calificacion = $mostrar["5"];
                ?>
                        <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet" />
                        <div class="wrapper">
                            <form id="car" method="POST">
                                <div class="img"><img src="<?php echo $mostrar['3']; ?>"></div>
                                <div class="info">
                                    <div class="text">
                                        <h2><?php echo $mostrar['1'] ?></h2>
                                        <div class="stars-container" data-rating="<?php echo $calificacion; ?>"></div>
                                        <h3><?php echo $mostrar['4'] ?></h3>
                                        <p><?php echo $mostrar['2'] ?></p>
                                        <p class="disponible">Cantidad Disponible: <?php echo $mostrar['7']?></p>
                                    </div>
                                    <div class="posnac">
                                        <div class="caja1"><?php echo $mostrar['0'] ?></div>
                                        <div class="caja2">$<?php echo $mostrar['6'] ?></div>
                                        <div class="caja3">-%<?php echo $mostrar['8'] ?></div>
                                    </div>
                                    <div class="but-select">
                                        <input type="hidden" name="stock" value="<?= $mostrar["7"] ?>">
                                        <input type="hidden" name="id" value="<?= $mostrar["0"] ?>">
                                        <input type="hidden" name="name" value="<?= $mostrar["1"] ?>">
                                        <input type="hidden" name="price" value="<?= $mostrar["6"] - (($mostrar["6"] * $mostrar["8"]) / 100) ?>">
                                        <input type="submit" name="add_to_cart" value="Agregar al Carrito">
                                        <input type="number" name="quantity" class="select" value="1"min="1">
                                    </div>
                                </div>
                            </form>
                        </div>
                <?php
                    }
                }
                ?>