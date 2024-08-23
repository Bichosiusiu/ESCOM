let chartInstance = null;
$(document).ready(() => {
    const loadChart = () => {
        fetch('../php/control/productosMasVendidos.php')
        .then(response => response.json())
        .then(data => {
            const labels = data.map(item => item.nombre);
            const values = data.map(item => item.total_vendido);
            const ctx = document.getElementById('reportes').getContext('2d');
            if (chartInstance) {
                chartInstance.destroy();
            }
            chartInstance = new Chart(ctx, {
                type: 'bar',
                data: {
                    labels: labels,
                    datasets: [{
                        label: 'Cantidad Vendida',
                        data: values,
                        backgroundColor: 'rgba(75, 192, 192, 0.6)', // Color de fondo suave
                        borderColor: 'rgba(75, 192, 192, 1)', // Borde más oscuro
                        borderWidth: 2,
                        borderRadius: 8, // Borde redondeado de las barras
                        hoverBackgroundColor: 'rgba(75, 192, 192, 0.8)', // Color de fondo al pasar el mouse
                        hoverBorderColor: 'rgba(75, 192, 192, 1)' // Borde al pasar el mouse
                    }]
                },
                options: {
                    responsive: true,
                    plugins: {
                        legend: {
                            display: false // Oculta la leyenda
                        }
                    },
                    scales: {
                        x: {
                            grid: {
                                display: false // Oculta las líneas de la cuadrícula en el eje X
                            },
                            ticks: {
                                font: {
                                    size: 14, // Tamaño de fuente para las etiquetas en el eje X
                                    weight: 'bold' // Fuente en negrita
                                }
                            }
                        },
                        y: {
                            beginAtZero: true,
                            grid: {
                                color: 'rgba(0, 0, 0, 0.05)' // Color de la cuadrícula en el eje Y
                            },
                            ticks: {
                                font: {
                                    size: 14, // Tamaño de fuente para las etiquetas en el eje Y
                                    weight: 'bold' // Fuente en negrita
                                }
                            }
                        }
                    },
                    animation: {
                        duration: 1500, // Duración de la animación en milisegundos
                        easing: 'easeInOutQuart' // Tipo de animación
                    },
                    layout: {
                        padding: {
                            top: 20, // Espacio superior
                            right: 20, // Espacio derecho
                            bottom: 20, // Espacio inferior
                            left: 20 // Espacio izquierdo
                        }
                    }
                }
            });
        })
        .catch(error => console.error('Error:', error));
    };
    loadChart();
    $('.masVendidos').on('click', loadChart);
    $('.categoriasVendidas').on('click', function() {
        fetch('../php/control/categoriasMasVendidas.php')
    .then(response => response.json())
    .then(data => {
        const labels = data.map(item => item.categoria);
        const values = data.map(item => item.total_vendido);
        const ctx = document.getElementById('reportes').getContext('2d');
        if (chartInstance) {
            chartInstance.destroy();
        }
        chartInstance=new Chart(ctx, {
            type: 'bar',
            data: {
                labels: labels,
                datasets: [{
                    label: 'Cantidad Vendida',
                    data: values,
                    backgroundColor: [
                        'rgba(255, 99, 132, 0.6)',   // Rojo suave
                        'rgba(54, 162, 235, 0.6)',   // Azul suave
                        'rgba(255, 206, 86, 0.6)',   // Amarillo suave
                        'rgba(75, 192, 192, 0.6)',   // Verde azulado suave
                        'rgba(153, 102, 255, 0.6)'   // Violeta suave
                    ],
                    borderColor: [
                        'rgba(255, 99, 132, 1)',    // Rojo
                        'rgba(54, 162, 235, 1)',    // Azul
                        'rgba(255, 206, 86, 1)',    // Amarillo
                        'rgba(75, 192, 192, 1)',    // Verde azulado
                        'rgba(153, 102, 255, 1)'    // Violeta
                    ],
                    borderWidth: 2,
                    borderRadius:8,
                }]
            },
            options: {
                responsive: true,
                plugins: {
                    legend: {
                        display: false // Oculta la leyenda
                    }
                },
                scales: {
                    x: {
                        grid: {
                            display: false // Oculta las líneas de la cuadrícula en el eje X
                        },
                        ticks: {
                            font: {
                                size: 14, // Tamaño de fuente para las etiquetas en el eje X
                                weight: 'bold' // Fuente en negrita
                            }
                        }
                    },
                    y: {
                        beginAtZero: true,
                        grid: {
                            color: 'rgba(0, 0, 0, 0.05)' // Color de la cuadrícula en el eje Y
                        },
                        ticks: {
                            font: {
                                size: 14, // Tamaño de fuente para las etiquetas en el eje Y
                                weight: 'bold' // Fuente en negrita
                            }
                        }
                    }
                },
                animation: {
                    duration: 1500, // Duración de la animación en milisegundos
                    easing: 'easeInOutQuart' // Tipo de animación
                },
                layout: {
                    padding: {
                        top: 20, // Espacio superior
                        right: 20, // Espacio derecho
                        bottom: 20, // Espacio inferior
                        left: 20 // Espacio izquierdo
                    }
                }
            }
        });
    })
    .catch(error => console.error('Error:', error));
    });

    $('.stock').on('click', function() {
    fetch('../php/control/stockDisponible.php')
    .then(response => response.json())
    .then(data => {
        const labels = data.map(item => item.nombre);
        const values = data.map(item => item.stock);
        const ctx = document.getElementById('reportes').getContext('2d');

        // Función para generar colores de fondo y bordes basados en posición
        const backgroundColors = data.map((item, index) => {
            const alpha = 1 - (index / data.length) * 0.7; // Opacidad ajustada
            return `rgba(255, 99, 132, ${alpha})`; // Rojo con opacidad variable
        });

        const borderColors = data.map(() => 'rgba(255, 99, 132, 1)'); // Rojo sólido para bordes
        if (chartInstance) {
            chartInstance.destroy();
        }
        chartInstance=new Chart(ctx, {
            type: 'bar',
            data: {
                labels: labels,
                datasets: [{
                    label: 'Stock Disponible',
                    data: values,
                    backgroundColor: backgroundColors,
                    borderColor: borderColors,
                    borderWidth: 1,
                    borderRadius: 8,
                }]
            },
            options: {
                scales: {
                    y: {
                        beginAtZero: true
                    }
                }
            }
        });
    })
    .catch(error => console.error('Error:', error));
})
$('.ingresos').on('click', function() {
    fetch('../php/control/ingresosGlobales.php')
    .then(response => response.json())
    .then(data => {
        const labels = data.map(item => item.mes);
        const values = data.map(item => item.ingresos_totales);
        const ctx = document.getElementById('reportes').getContext('2d');

        // Colores graduales para las barras
        const backgroundColors = data.map((item, index) => {
            const hue = 200 - (index * 10); // Gradiente de color en tonos azules
            return `hsla(${hue}, 70%, 50%, 0.6)`; // Color HSLA con opacidad
        });

        const borderColor = 'rgba(54, 162, 235, 1)'; // Color sólido para el borde
        if (chartInstance) {
            chartInstance.destroy();
        }
        chartInstance=new Chart(ctx, {
            type: 'bar',
            data: {
                labels: labels,
                datasets: [{
                    label: 'Ingresos Globales',
                    data: values,
                    backgroundColor: backgroundColors,
                    borderColor: borderColor,
                    borderWidth: 1
                }]
            },
            options: {
                scales: {
                    y: {
                        beginAtZero: true,
                        ticks: {
                            callback: function(value) {
                                return '$' + value; // Añade el símbolo de dólar a las etiquetas del eje Y
                            }
                        }
                    }
                }
            }
        });
    })
    .catch(error => console.error('Error:', error));
})
$('.ingProd').on('click', function() {
fetch('../php/control/ingresosPorProductos.php')
    .then(response => response.json())
    .then(data => {
        const labels = data.map(item => item.nombre);
        const values = data.map(item => item.ingresos_totales);
        const ctx = document.getElementById('reportes').getContext('2d');

        // Colores progresivos para las barras (de verde a azul)
        const backgroundColors = data.map((item, index) => {
            const hue = 120 - (index * 10); // Gradiente de color en tonos verdes a azules
            return `hsla(${hue}, 70%, 50%, 0.6)`; // Color HSLA con opacidad
        });

        const borderColor = 'rgba(75, 192, 192, 1)'; // Color sólido para el borde
        if (chartInstance) {
            chartInstance.destroy();
        }
        chartInstance=new Chart(ctx, {
            type: 'bar',
            data: {
                labels: labels,
                datasets: [{
                    label: 'Ingresos por Producto',
                    data: values,
                    backgroundColor: backgroundColors,
                    borderColor: borderColor,
                    borderWidth: 1
                }]
            },
            options: {
                scales: {
                    y: {
                        beginAtZero: true,
                        ticks: {
                            callback: function(value) {
                                return '$' + value; // Añade el símbolo de dólar a las etiquetas del eje Y
                            }
                        }
                    }
                }
            }
        });
    })
    .catch(error => console.error('Error:', error));
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
});
