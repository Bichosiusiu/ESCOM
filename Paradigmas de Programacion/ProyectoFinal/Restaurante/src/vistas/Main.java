package vistas;
import javax.swing.JOptionPane;
import modelo.Restaurante;
import java.util.List;
import java.util.ArrayList;
import modelo.Repartidor;
import java.util.Random;
public class Main extends javax.swing.JFrame {
    private Restaurante r;//inicializamos una clase restaurante para guardar ahi los datos
    private List<Repartidor> rep;//inicializamos una lista de repartidores para registrarlo y despues tomarla como refernecia em la busqueda y asignacion en un pedido

    public Main() {
        initComponents();
        r=new Restaurante();//inicializamos cada vez que se corre el proyecto
        rep=new ArrayList<>();//inicializamos cada vez que se corre el proyecto
        this.setLocationRelativeTo(null);//colocamos al centro el form main
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        btnpedido = new javax.swing.JButton();
        btnrepartidor = new javax.swing.JButton();
        btnplatillo = new javax.swing.JButton();
        btnrestaurante = new javax.swing.JButton();
        btnsalir = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        btnmenu = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);

        jPanel1.setBackground(new java.awt.Color(0, 0, 0));

        btnpedido.setText("REALIZAR PEDIDO");
        btnpedido.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnpedidoActionPerformed(evt);
            }
        });

        btnrepartidor.setText("REGISTRAR REPARTIDOR");
        btnrepartidor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnrepartidorActionPerformed(evt);
            }
        });

        btnplatillo.setText("REGISTRAR PLATILLO");
        btnplatillo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnplatilloActionPerformed(evt);
            }
        });

        btnrestaurante.setText("REGISTRAR RESTAURANTE");
        btnrestaurante.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnrestauranteActionPerformed(evt);
            }
        });

        btnsalir.setText("SALIR");
        btnsalir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnsalirActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Perpetua", 0, 24)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("MENU PRINCIPAL");

        btnmenu.setText("MOSTRAR MENU");
        btnmenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnmenuActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(181, 181, 181)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(btnrestaurante, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addComponent(btnrepartidor, javax.swing.GroupLayout.DEFAULT_SIZE, 200, Short.MAX_VALUE)
                                .addComponent(btnmenu, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(btnpedido, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addComponent(btnplatillo, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(237, 237, 237)
                        .addComponent(btnsalir, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(195, 195, 195)
                        .addComponent(jLabel1)))
                .addContainerGap(198, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addComponent(jLabel1)
                .addGap(34, 34, 34)
                .addComponent(btnmenu)
                .addGap(27, 27, 27)
                .addComponent(btnpedido)
                .addGap(30, 30, 30)
                .addComponent(btnrepartidor)
                .addGap(27, 27, 27)
                .addComponent(btnplatillo)
                .addGap(26, 26, 26)
                .addComponent(btnrestaurante)
                .addGap(18, 18, 18)
                .addComponent(btnsalir)
                .addContainerGap(26, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnmenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnmenuActionPerformed
        if(r.getNombre()==null){//si no hya restaurante , mandara un mensaje para que se registre
            JOptionPane.showMessageDialog(null, "No hay restaurante registrado", "Información", JOptionPane.INFORMATION_MESSAGE);
        }
        else{//si hay restaurante
        setVisible(false);//ocultamos el main
        MenuForm mf = new MenuForm(Main.this);//inicializamos el form del menu
        mf.setVisible(true);//mostramos el frame del menu
        }
    }//GEN-LAST:event_btnmenuActionPerformed

    private void btnplatilloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnplatilloActionPerformed
        if(r.getNombre()==null){//si no hya restaurante , mandara un mensaje para que se registre
            JOptionPane.showMessageDialog(null, "No hay restaurante registrado", "Información", JOptionPane.INFORMATION_MESSAGE);
        }
        else{//si hay restaurante
        setVisible(false);//ocultamos el main 
        PlatillosForm pf=new PlatillosForm(Main.this);//inicilizamos el form de platillos
        pf.setVisible(true);//mostramos el form de los platillos
        }
    }//GEN-LAST:event_btnplatilloActionPerformed

    private void btnsalirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnsalirActionPerformed
        System.exit(0);//el boton salir hara que se cierre el proyecto
    }//GEN-LAST:event_btnsalirActionPerformed

    private void btnrestauranteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnrestauranteActionPerformed
        setVisible(false);//ocultamos el main
        RestauranteForm rf=new RestauranteForm(Main.this);//mostrara el form para registrar restaurante
        rf.setVisible(true);//se muestra el form
    }//GEN-LAST:event_btnrestauranteActionPerformed

    private void btnpedidoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnpedidoActionPerformed
        if(r.getNombre()==null){//si no hya restaurante , mandara un mensaje para que se registre
            JOptionPane.showMessageDialog(null, "No hay restaurante registrado", "Información", JOptionPane.INFORMATION_MESSAGE);
        }
        else if(obtenerRepartidorAleatorio()==null){//si hay restaurante, entonces verificamos que haya repartidores para los pedidos
            JOptionPane.showMessageDialog(null, "No hay repartidores registrados", "Información", JOptionPane.INFORMATION_MESSAGE);
        }else{//si hay repartidores
        setVisible(false);//ocultamos el main
        PedidosForm pf = new PedidosForm(Main.this);//inicializamos el form de pedidos
        pf.setVisible(true);//mostramos el frame del pedidos
        }
    }//GEN-LAST:event_btnpedidoActionPerformed

    private void btnrepartidorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnrepartidorActionPerformed
        if(r.getNombre()==null){//si no hya restaurante , mandara un mensaje para que se registre
            JOptionPane.showMessageDialog(null, "No hay restaurante registrado", "Información", JOptionPane.INFORMATION_MESSAGE);
        }
        else{//si hay restaurante
        setVisible(false);//ocultamos el main
        RepartidorForm rf=new RepartidorForm(Main.this);//mostramos el form de reaprtidores para registrarlos
        rf.setVisible(true);//se abre el form
        }
    }//GEN-LAST:event_btnrepartidorActionPerformed

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Main().setVisible(true);
            }
        });
    }
    public Restaurante getRestaurante() {//funcion para acceder al objeto restaurante y hacer los registros de sus atributos
        return r;//regresamos el objeto de tipo restaurante
    }
    public List getRepartidores() {//funcion para acceder a la lista de repartidores y hacer los registros de sus atributos
        return rep;//regresamos la lista de repartidores
    }
    public void agregarRepartidor(Repartidor r){//funcion para agregar un objeto de tipo repartidor a la lista de repartidores de este form, que es el general
        rep.add(r);//utilizamos funcion add para agregar
    }
    public String imprimir(){//funcion para imprimir repartidores 
    if (rep.isEmpty()) {//si la lista de repartidores esta vacia
        return "No hay repartidores registrados";//retorna esta string
    }
    StringBuilder resultado = new StringBuilder();//si no, se crea un stringbuilder, que esta practicamente va a concatenar varias string y convertirla en una sola, esto para que se vea en el jtextarea de menera completa
    for (Repartidor re : rep) {//ciclo foreach para que todos los repartidores se impriman
            resultado.append(re.imprimir()).append("\n");//con esta funcion haremos la gran cadena, apppend lo que hara es juntar las cadenas y el salto de linea, esto cada vez que el repartidor sea reflejado, se utiliza la funcion imprimir repartidor para acceder a la impresion de todos los atributos por repartidor
        }
    return resultado.toString();//retornamos la gran cadena
}
    public Repartidor obtenerRepartidorAleatorio() {
        if (rep.isEmpty()) {
            return null;  // si la lista está vacía, devuelve null
        }
        // crear un objeto Random para generar índices aleatorios
        Random random = new Random();
        // generar un índice aleatorio dentro del rango de la lista
        int indiceAleatorio = random.nextInt(rep.size());
        // obtener el repartidor correspondiente al índice aleatorio
        return rep.get(indiceAleatorio);
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnmenu;
    private javax.swing.JButton btnpedido;
    private javax.swing.JButton btnplatillo;
    private javax.swing.JButton btnrepartidor;
    private javax.swing.JButton btnrestaurante;
    private javax.swing.JButton btnsalir;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
