<!DOCTYPE html>
<html lang="en" style= "height: 100%">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="../css/estilos.css"/>
    <link
      href="https://fonts.googleapis.com/icon?family=Material+Icons"
      rel="stylesheet"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css?family=Open+Sans"
    />
    <title>RegistroCliente</title>
  </head>
  <body class="login">
    <div class="contenedorReg">
      <h1 class="titulo">Registro</h1>
      <div class="partes">
      <div class="parte">
      <form id="registro-form" action="../php/cliente/registrar.php" name="forma" method="POST">
        <div class="elemento">
          <label for="nom">Nombre</label>
          <input type="text" id="nom" name="nom" required="true"/>
        </div>
        <div class="elemento">
          <label for="ap">Apellido</label>
          <input type="text" id="ap" name="ap" required="true"/>
        </div>
        <div class="elemento">
          <label for="edad">Edad</label>
          <input type="number" id="edad" name="edad" required="true" min="18" max="100"/>
        </div>
        <div class="elemento">
          <label for="dir">Direccion</label>
          <input type="text" id="dir" name="dir" required="true"/>
        </div>
        <div class="elemento">
          <label for="correo">Correo</label>
          <input type="email" id="correo" name="correo" required="true"/>
        </div>
        </div>
<div class="parte">
        <div class="elemento">
          <label for="usuario">Usuario</label>
          <input type="text" id="usuario" name="usuario" required="true"/>
        </div>
        <div class="elemento">
          <label for="password">Password</label>
          <input
            type="password"
            id="password"
            name="password"
            required="true"
          />
        </div>
        <div class="elemento">
          <input type="submit" value="Registrar" />
        </div>
        <div class="mensaje" id="mensaje"></div>
            <a href="loginCliente.php">
              <div class="registro">Iniciar sesión</div>
            </a>
            <a href="index.html">
                <div class="icon">
                    <i class="material-icons">home</i>
                </div>
            </a>
        </form>
</div>
    </div>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../js/script.js"></script>
  </body>
</html>
