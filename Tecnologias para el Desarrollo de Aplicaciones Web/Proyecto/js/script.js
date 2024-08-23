console.log('Script cargado correctamente');
$(document).ready(() => {
    const alertLogin=(response)=>Swal.fire({
        icon: 'error',
        title: '¡Oops!',
        text: response.message,
        background: '#fff',
        confirmButtonColor: '#dc3545',
        confirmButtonText: 'Entendido',
        customClass: {
            popup: 'animated shake',
            title: 'text-danger font-weight-bold',
            content: 'text-muted'
        }
    });
    $('#registro-form').submit((event) => {
        event.preventDefault(); 
        registrarUsuario();
    });

    const registrarUsuario = () => {
        const formData = $('#registro-form').serialize();

        $.ajax({
            type: 'POST',
            url: $('#registro-form').attr('action'),
            data: formData,
            success: (response) => {
                if(response=="exito"){
                    Swal.fire({
                        icon: 'success',
                        title: '¡Registro Exitoso!',
                        text: 'Tu cuenta ha sido creada exitosamente. Serás redirigido a la página de inicio de sesión en breve.',
                        showConfirmButton: false,
                        timer: 2000,
                        background: '#f0f9ff',
                        color: '#1a73e8',
                        customClass: {
                            popup: 'animated fadeInDown faster',
                            title: 'font-weight-bold',
                            content: 'text-muted'
                        }
                    }).then(() => {
                        window.location.href = 'logincliente.php';
                    });
                }
                else if(response=="fracaso"){
                    Swal.fire({
                        icon: 'error',
                        title: 'Intentelo de nuevo',
                        showConfirmButton: false,
                        timer: 1500
                    })
                } else {
                $('#mensaje').html(response);
            }
            },
            error: (xhr, status, error) => {
                console.error('Error en la solicitud AJAX:', error);
                $('#mensaje').html('Hubo un error en el registro. Inténtelo de nuevo.');
            }
        });
    };
    $('#login-form').submit((event) => {
            event.preventDefault(); 
            const formData = $('#login-form').serialize();
            $.ajax({
                type: 'POST',
                url: '../php/cliente/loginCliente_be.php',
                data: formData,
                dataType: 'json', 
                success: (response) => {
                    if (response.success) {
                        window.location.href = response.redirect;
                    } else {
                        alertLogin(response)
                    }
                },
                error: (xhr, status, error) => {
                    console.error('Error en la solicitud AJAX:', error);
                    alert('Hubo un error en el proceso. Inténtelo de nuevo.');
                }
            });
        });
        
        $('#eleccionForm').on('change', function() {
            var categoria = $(this).find(":selected").val();
            console.log(categoria)
            $.ajax({
                type: 'POST',
                url: '../php/cliente/productos.php',
                data: { categoria: categoria },
                success: function(data) {
                    $('#productosContainer').html(data);
                    actualizarEstrellas();
                }
            });
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
        $(document).ready(function() {
            cargarContenido();
        });
        $(document).on('submit', '#car', function(e) {
            e.preventDefault();
            var formData = $(this).serialize();
            $.ajax({
                type: 'POST',
                url: '../php/cliente/add.php',
                data: formData,
                success: function(data) {
                    $('#cartContainer').html(data);
                    cargarContenido();
                },
                error: function(xhr, status, error) {
                    console.error("Error en la solicitud AJAX: ", error); 
                }
            });
        });
        $(document).on('click', '.eliminarProducto', function() {
            var id = $(this).data('id');
            console.log(id)
            $.ajax({
                type: 'GET',
                url: '../php/cliente/remove.php?action=remove&id=' + id,
                success: function(data) {
                    $('#cartContainer').html(data);
                    cargarContenido();
                },
                error: function(xhr, status, error) {
                    console.error("Error en la solicitud AJAX: ", error); 
                }
            });
        });
        $(document).on('click', '.venta', function() {
            console.log("hola");
            $.ajax({
                type: 'GET',
                url: '../php/cliente/venta.php',
                success: function(data) {
                    if (data=="exceso") {
                        Swal.fire({
                            icon: 'error',
                            title: '¡Pago Insuficiente!',
                            text: 'El monto excede el saldo disponible en tu monedero electrónico.',
                            background: '#f8d7da',
                            customClass: {
                                popup: 'animated shake',
                                title: 'text-danger font-weight-bold',
                                content: 'text-muted'
                            }
                        });
                    }else if(data=="stock"){
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
                            timer: 2000
                        });
                    }else{
                        Swal.fire({
                            icon: 'success',
                            title: '¡Venta Realizada!',
                            text: '¡Gracias por su compra!',
                            background: '#d4edda',
                            customClass: {
                                popup: 'animated bounceIn',
                                title: 'text-success font-weight-bold',
                                content: 'text-muted'
                            }
                        }).then(() => {
                        location.reload(); 
                    });
                    $('#cartContainer').html(data);
                    cargarContenido();
                }
                },
                error: function(xhr, status, error) {
                    console.error("Error en la solicitud AJAX: ", error); 
                }
            });
        });
        function cargarContenido() {
            $.ajax({
                url: '../php/cliente/eleccion.php', 
                type: 'GET',
                success: function(data) {
                    $('#cartContainer').html(data); 
                },
                error: function(xhr, status, error) {
                    console.error('Error al cargar el contenido:', error);
                }
            });
        }
        $('#control-form').submit((event) => {
            event.preventDefault(); 
            const formData = $('#control-form').serialize();
            $.ajax({
                type: 'POST',
                url: '../php/control/loginControl_be.php',
                data: formData,
                dataType: 'json', 
                success: (response) => {
                    if (response.success) {
                        window.location.href = response.redirect;
                    } else {
                        alertLogin(response)
                    }
                },
                error: (xhr, status, error) => {
                    console.error('Error en la solicitud AJAX:', error);
                    alert('Hubo un error en el proceso. Inténtelo de nuevo.');
                }
            });
        });
        $(document).on('click', '.eliminarCliente', function() {
            var userId = $(this).data('id');
            Swal.fire({
                title: '¿Estás seguro de querer eliminar este usuario?',
                icon: 'warning',
                showCancelButton: true,
                confirmButtonText: 'Sí, eliminar',
                cancelButtonText: 'Cancelar',
                background: '#fff3cd',
                confirmButtonColor: '#d33',
                cancelButtonColor: '#3085d6',
                customClass: {
                    popup: 'animated fadeInDown',
                    title: 'font-weight-bold',
                    confirmButton: 'btn btn-danger',
                    cancelButton: 'btn btn-secondary'
                }
            }).then((result) => {
                if (result.isConfirmed) {
                    $.ajax({
                        type: "GET",
                        url: '../php/control/eliminarCliente.php',
                        data: { action: 'remove', id: userId },
                        success: function(response) {
                            if (response.trim() == "success") {
                                Swal.fire({
                                    title: 'Cliente Eliminado',
                                    text: 'El cliente ha sido eliminado exitosamente.',
                                    icon: 'success',
                                    timer: 1500,
                                    showConfirmButton: false,
                                    background: '#d4edda',
                                    customClass: {
                                        popup: 'animated bounceIn',
                                        title: 'text-success font-weight-bold',
                                        content: 'text-muted'
                                    }
                                }).then(() => {
                                    location.reload();
                                });
                            } else {
                                Swal.fire({
                                    title: 'Error',
                                    text: 'Error: ' + response,
                                    icon: 'error',
                                    timer: 1500,
                                    showConfirmButton: false,
                                    background: '#f8d7da',
                                    customClass: {
                                        popup: 'animated shake',
                                        title: 'text-danger font-weight-bold',
                                        content: 'text-muted'
                                    }
                                });
                            }
                        },
                        error: function(xhr, status, error) {
                            Swal.fire({
                                title: 'AJAX Error',
                                text: 'Status: ' + status + ', Error: ' + error,
                                icon: 'error',
                                timer: 1500,
                                showConfirmButton: false,
                                background: '#f8d7da',
                                customClass: {
                                    popup: 'animated shake',
                                    title: 'text-danger font-weight-bold',
                                    content: 'text-muted'
                                }
                            });
                        }
                    });
                }
            });
        });
        
        $(document).on('click', '.actualizarCliente', function() {
              var userId = $(this).data('id');
              $.ajax({
                type: "GET",
                url: '../php/control/obtenerCliente.php',
                data: { id: userId },
                success: function(response) {
                  var data = JSON.parse(response);
                  var formulario = document.getElementById('updateForm');
                  formulario.style.display = 'block';
                    formulario.style.position = 'fixed';
                    formulario.style.top = '50%';
                    formulario.style.left = '50%';
                    formulario.style.transform = 'translate(-50%, -50%)';
                  $('#id').val(data.id);
                  $('#nom').val(data.nombre);
                  $('#ap').val(data.apellido);
                  $('#ed').val(data.edad);
                  $('#us').val(data.usuario);
                  $('#dir').val(data.direccion);
                  $('#cor').val(data.correo);
                  $('#mon').val(data.monedero);
                  $('#updateModal').show();
                }
              });
            });
              $('#updateForm').submit(function(e) {
                e.preventDefault();
                $.ajax({
                  type: "POST",
                  url: '../php/control/actualizarCliente.php',
                  data: $(this).serialize(),
                  success: function(response) {
                    if (response.trim() == "success") {
                        Swal.fire({
                            icon: 'success',
                            title: '¡Cliente Actualizado!',
                            text: 'Los detalles del cliente han sido actualizados correctamente.',
                            showConfirmButton: false,
                            timer: 2000,
                            customClass: {
                                popup: 'animated bounceInDown',
                                title: 'text-success font-weight-bold',
                                content: 'text-muted'
                            }
                        }).then(() => {
                            location.reload()
                        });
                    } else {
                        Swal.fire({
                            icon: "error",
                            title: "Error: " + response,
                            showConfirmButton: false,
                            timer: 1500
                        });
                    }
                  }
                });
              });
            $('.exit').click(() => {
                $('#updateModal').hide();
            });

            $(document).on('click', '.eliminarProd', function() {
                var prodId = $(this).data('id');
                Swal.fire({
                    title: '¿Estás seguro de querer eliminar este producto?',
                    icon: 'warning',
                    showCancelButton: true,
                    confirmButtonText: 'Sí, eliminar',
                    cancelButtonText: 'Cancelar',
                    background: '#fff3cd',
                    confirmButtonColor: '#d33',
                    cancelButtonColor: '#3085d6',
                    customClass: {
                        popup: 'animated fadeInDown',
                        title: 'font-weight-bold',
                        confirmButton: 'btn btn-danger',
                        cancelButton: 'btn btn-secondary'
                    }
                }).then((result) => {
                    if (result.isConfirmed) {
                        $.ajax({
                            type: "GET",
                            url: '../php/control/eliminarProducto.php',
                            data: { action: 'remove', id: prodId },
                            success: function(response) {
                                if (response.trim() == "success") {
                                    Swal.fire({
                                        title: 'Producto Eliminado',
                                        text: 'El producto ha sido eliminado exitosamente.',
                                        icon: 'success',
                                        timer: 1500,
                                        showConfirmButton: false,
                                        background: '#d4edda',
                                        customClass: {
                                            popup: 'animated bounceIn',
                                            title: 'text-success font-weight-bold',
                                            content: 'text-muted'
                                        }
                                    }).then(() => {
                                        location.reload();
                                    });
                                } else {
                                    Swal.fire({
                                        title: 'Error',
                                        text: 'Error: ' + response,
                                        icon: 'error',
                                        timer: 1500,
                                        showConfirmButton: false,
                                        background: '#f8d7da',
                                        customClass: {
                                            popup: 'animated shake',
                                            title: 'text-danger font-weight-bold',
                                            content: 'text-muted'
                                        }
                                    });
                                }
                            },
                            error: function(xhr, status, error) {
                                Swal.fire({
                                    title: 'AJAX Error',
                                    text: 'Status: ' + status + ', Error: ' + error,
                                    icon: 'error',
                                    timer: 1500,
                                    showConfirmButton: false,
                                    background: '#f8d7da',
                                    customClass: {
                                        popup: 'animated shake',
                                        title: 'text-danger font-weight-bold',
                                        content: 'text-muted'
                                    }
                                });
                            }
                        });
                    }
                });
            });
            
            $(document).on('click', '.actualizarProducto', function() {
                var prodId = $(this).data('id');
                $.ajax({
                  type: "GET",
                  url: '../php/control/obtenerProducto.php',
                  data: { id: prodId },
                  success: function(response) {
                    var data = JSON.parse(response);
                    var formulario = document.getElementById('updateInventarioForm');
                    formulario.style.display = 'block';
    formulario.style.position = 'fixed';
    formulario.style.top = '90px';
    formulario.style.left = '50%';
    formulario.style.transform = 'translateX(-50%)';
                    $('#id').val(data.id);
                    $('#nom').val(data.nombre);
                    $('#descripcion').val(data.descripcion);
                    $('#min').val(data.miniatura);
                    $('#mar').val(data.marca);
                    $('#rat').val(data.rating);
                    $('#pre').val(data.precio);
                    $('#stock').val(data.stock);
                    $('#des').val(data.descuento);
                    $('#updateInventarioModal').show();

                  }
                });
              });

              $('#updateInventarioForm').submit(function(e) {
                e.preventDefault(); // Prevenir el envío tradicional del formulario
                
                $.ajax({
                    type: "POST",
                    url: '../php/control/actualizarProducto.php',
                    data: $(this).serialize(), // Serializar datos del formulario
                    success: function(response) {
                        if (response.trim() == "success") {
                            Swal.fire({
                                icon: 'success',
                                title: '¡Producto Actualizado!',
                                text: 'El producto ha sido actualizado correctamente en el inventario.',
                                showConfirmButton: false,
                                timer: 2000,
                                background: '#d4edda',
                                customClass: {
                                    popup: 'animated fadeInDown',
                                    title: 'text-success font-weight-bold',
                                    content: 'text-muted'
                                }
                            });
                            setTimeout(function() {
                                location.reload(); 
                            }, 2000); 
                        } else {
                            Swal.fire({
                                icon: "error",
                                title: "Error: " + response,
                                showConfirmButton: false,
                                timer: 1500
                            });
                        }
                    },
                    error: function(xhr, status, error) {
                        console.error("AJAX Error:", status, error);
                        Swal.fire({
                            icon: "error",
                            title: "Error en la solicitud AJAX",
                            text: "Status: " + status + ", Error: " + error,
                            showConfirmButton: false,
                            timer: 1500
                        });
                    }
                });
            });
            $('.exit2').click(() => {
                $('#updateInventarioModal').hide();
            });
            $(document).on('click', '.exit5', function() {
                $('#contenedorDetalles').hide();
            });
            $('.anadirProducto').click(function() {
                    var formulario = document.getElementById('addInventarioForm');
                    formulario.style.display = 'block';
                    formulario.style.position = 'fixed';
                    formulario.style.top = '90px';
                    formulario.style.left = '50%';
                    formulario.style.transform = 'translateX(-50%)';
                    $('#addInventarioModal').show();
              });
              $('.exit3').click(() => {
                $('#addInventarioModal').hide();
            });
            $('#addInventarioForm').submit(function(e) {
                e.preventDefault();
                $.ajax({
                  type: "POST",
                  url: '../php/control/añadirProducto.php',
                  data: $(this).serialize(),
                  success: function(response) {
                    if (response.trim() == "success") {
                        Swal.fire({
                            icon: 'success',
                            title: '¡Producto Agregado!',
                            text: 'El producto ha sido agregado al inventario exitosamente.',
                            showConfirmButton: false,
                            timer: 2000,
                            background: '#d4edda',
                            customClass: {
                                popup: 'animated fadeInDown',
                                title: 'text-success font-weight-bold',
                                content: 'text-muted'
                            }
                        });
                        setTimeout(function() {
                            location.reload(); 
                        }, 2000); 
                    } else {
                        Swal.fire({
                            icon: "error",
                            title: "Ocurrio un error: "+response,
                            showConfirmButton: false,
                            timer: 1500
                        });
                    }
                  }
                });
              });
            $("#menu-icon").click(function(){
                $("#menu").toggle();
            });
            $("#menu-icon").mouseenter(function(){
                $("#menu").show();
            });

            // Ocultar el menú cuando se deja de pasar el mouse por cualquier parte del menú o del icono
            $("#menu-icon, #menu").mouseleave(function(event) {
                if (!$(event.relatedTarget).closest("#menu, #menu-icon").length) {
                    $("#menu").hide();
                }
            });
            $('#carrito-btn').click(function() {
                $('.contenedorEleccion').css({
                'display': 'block',
                'position': 'fixed',
                'top': '50px',
                'left': '75%',
                'max-widht': '40%',
                'transform': 'translateX(-50%)',
                'overflow-y': 'auto',
                'z-index': '1000' 
            });
              });
              $('.exit4').click(() => {
                $('.contenedorEleccion').hide();
            });
            $('#busqcliente').submit(function(event) {
                event.preventDefault();
                const formData = $(this).serialize();
                $.ajax({
                    url: '../php/control/busquedaCliente.php',
                    type: 'POST',
                    data: formData, 
                    success: function(data) {
                        $('.contenedorClientes').empty();
                        $('.contenedorClientes').html(data); 
                    },
                    error: function(xhr, status, error) {
                        console.error('Error al cargar el contenido:', error);
                    }
                });
            });
            $('#busqprod').submit(function(event) {
                event.preventDefault();
                const formData = $(this).serialize();
                $.ajax({
                    url: '../php/control/busquedaProducto.php',
                    type: 'POST',
                    data: formData, 
                    success: function(data) {
                        $('.contenedorProd').empty();
                        $('.contenedorProd').html(data); 
                    },
                    error: function(xhr, status, error) {
                        console.error('Error al cargar el contenido:', error);
                    }
                });
            });
            $(document).on('click', '.detallesCliente', function() {
                var clienId = $(this).data('id');
                console.log(clienId)
                $.ajax({
                    url: '../php/control/detallesCliente.php',
                    type: 'GET',
                    data: { id: clienId }, 
                    success: function(data) {
                    var his = document.getElementById('contenedorDetalles');
                    his.style.overflowY = "auto";  // Allow vertical scrolling
                    his.style.overflowX = "hidden"; // Prevent horizontal scrolling
                    his.style.scrollbarWidth = "thin";
                    his.style.width = "60%";
                    his.style.borderRadius = "10px";
                    his.style.height = "60%";
                    his.style.backgroundColor = "white";
                    his.style.padding = "30px";
                    his.style.display = "block";
                    his.style.position = "fixed";
                    his.style.top = "90px";
                    his.style.left = "50%";
                    his.style.transform = "translateX(-50%)"; 
                    his.style.transform = 'translateX(-50%)';
                    $('#contenedorDetalles').show();
                    $('#contenedorDetalles').html(data); 
                    },
                    error: function(xhr, status, error) {
                        console.error('Error al cargar el contenido:', error);
                    }
                });
            });
    });