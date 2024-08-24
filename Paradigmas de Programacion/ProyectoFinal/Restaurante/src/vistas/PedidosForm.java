package vistas;
import javax.swing.JOptionPane;
import modelo.Repartidor;
import modelo.Receta;
import modelo.Pedido;
import java.util.List;
import java.util.ArrayList;
public class PedidosForm extends javax.swing.JFrame {
    private final Main main;//mandamos el main como atributo para poder regresar
    int total=0;//hacemos un atributo total y se incializa en 0
    List<String> pla;//arreglo de platillos, de tipo string
    public PedidosForm(Main main) {
        this.main=main;//inicializamos el main
        initComponents();
        pla = new ArrayList<>();//inicializamos la lista
        this.setLocationRelativeTo(null);//colocamos al centro
        jTextArea1.setEditable(false);//hacemos que el textarea no sea editable
        jTextArea1.append(main.getRestaurante().imprimirPedido());//accedemos al objeto restaurante del main e imprimimos su lista de pedidos
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        txtnom = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        cmbpago = new javax.swing.JComboBox<>();
        jButton1 = new javax.swing.JButton();
        txtdir = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        txtedad = new javax.swing.JTextField();
        btnpedido = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jLabel6 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        txtplatillo = new javax.swing.JTextField();
        btnplatillo = new javax.swing.JButton();

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 100, Short.MAX_VALUE)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 100, Short.MAX_VALUE)
        );

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);

        jPanel2.setBackground(new java.awt.Color(0, 0, 0));

        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("NOMBRE:");

        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("DIRECCION:");

        jLabel4.setForeground(new java.awt.Color(255, 255, 255));
        jLabel4.setText("METODO DE PAGO:");

        cmbpago.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "SELECCIONAR", "EFECTIVO", "TARJETA" }));

        jButton1.setText("REGRESAR");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setText("EDAD:");

        btnpedido.setText("AGREGAR PEDIDO");
        btnpedido.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnpedidoActionPerformed(evt);
            }
        });

        jTextArea1.setColumns(20);
        jTextArea1.setFont(new java.awt.Font("Sylfaen", 0, 16)); // NOI18N
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        jLabel6.setForeground(new java.awt.Color(255, 255, 255));
        jLabel6.setText("AGREGAR ANTES DE QUE ACABE CON EL PEDIDO PARA QUE SE GUARDE SU");

        jLabel5.setForeground(new java.awt.Color(255, 255, 255));
        jLabel5.setText("PLATILLOS: ELIGE LOS PLATILLOS QUE QUIERAS, PRESIONE EL BOTON DE ");

        jLabel7.setForeground(new java.awt.Color(255, 255, 255));
        jLabel7.setText("TERMINE CON SU ORDEN, CUANDO TERMINE SU ELECCION DE PLATILLOS, PRESIONE AGREGAR PÉDIDO");

        jLabel8.setForeground(new java.awt.Color(255, 255, 255));
        jLabel8.setText("PLATILLOS:");

        txtplatillo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtplatilloActionPerformed(evt);
            }
        });

        btnplatillo.setText("AGREGAR PLATILLO");
        btnplatillo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnplatilloActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(18, 18, 18)
                .addComponent(jLabel1)
                .addGap(18, 18, 18)
                .addComponent(txtnom, javax.swing.GroupLayout.PREFERRED_SIZE, 241, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addComponent(jScrollPane1)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton1))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createSequentialGroup()
                                .addGap(356, 356, 356)
                                .addComponent(jLabel4)
                                .addGap(18, 18, 18)
                                .addComponent(cmbpago, javax.swing.GroupLayout.PREFERRED_SIZE, 124, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                .addComponent(jLabel7)
                                .addGroup(jPanel2Layout.createSequentialGroup()
                                    .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                                            .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                .addGroup(jPanel2Layout.createSequentialGroup()
                                                    .addGap(22, 22, 22)
                                                    .addComponent(jLabel3)
                                                    .addGap(33, 33, 33))
                                                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                                                    .addContainerGap()
                                                    .addComponent(jLabel2)
                                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                                            .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                .addComponent(txtdir, javax.swing.GroupLayout.DEFAULT_SIZE, 241, Short.MAX_VALUE)
                                                .addComponent(txtedad)))
                                        .addGroup(jPanel2Layout.createSequentialGroup()
                                            .addGap(108, 108, 108)
                                            .addComponent(btnpedido)))
                                    .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(jPanel2Layout.createSequentialGroup()
                                            .addGap(27, 27, 27)
                                            .addComponent(jLabel5)
                                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                            .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 147, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGroup(jPanel2Layout.createSequentialGroup()
                                            .addGap(72, 72, 72)
                                            .addComponent(jLabel8)
                                            .addGap(18, 18, 18)
                                            .addComponent(txtplatillo, javax.swing.GroupLayout.PREFERRED_SIZE, 163, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addGap(43, 43, 43)
                                            .addComponent(btnplatillo)))
                                    .addGap(0, 0, Short.MAX_VALUE))))
                        .addGap(0, 10, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jButton1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(txtnom, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4)
                    .addComponent(cmbpago, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(20, 20, 20)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtdir, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2)
                    .addComponent(jLabel5)
                    .addComponent(jLabel6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel7)
                .addGap(5, 5, 5)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(txtedad, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel3))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(33, 33, 33)
                        .addComponent(btnpedido))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(35, 35, 35)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel8, javax.swing.GroupLayout.PREFERRED_SIZE, 22, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(txtplatillo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnplatillo))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 24, Short.MAX_VALUE)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 436, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        this.setVisible(false); // Oculta la ventana del apartado
        main.setVisible(true);//muestra el main
    }//GEN-LAST:event_jButton1ActionPerformed

    private void txtplatilloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtplatilloActionPerformed

    }//GEN-LAST:event_txtplatilloActionPerformed

    private void btnplatilloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnplatilloActionPerformed
        agregarPlatillo();//funcion agregar platillo
        limpiarPlatillo();//limpiamos caja
    }//GEN-LAST:event_btnplatilloActionPerformed

    private void btnpedidoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnpedidoActionPerformed
        agregarPedido();//funcion para agregar pedido
        limpia();//limpamos cajas
        jTextArea1.setText("");//limpiamos text area
        jTextArea1.append(main.getRestaurante().imprimirPedido());//imprimimos de nuevo los pedidos, ahora con la adicion del pedido anterior
    }//GEN-LAST:event_btnpedidoActionPerformed
    public void agregarPedido(){
        if(txtnom.getText().equals("")||txtdir.getText().equals("")||txtedad.getText().equals("")||txtnom.getText().equals("")||cmbpago.getSelectedItem().equals("SELECCIONAR")||pla.isEmpty()){//si las cajas estan vacias, ,mandar un mensaje de error
           JOptionPane.showMessageDialog(null, "Favor de Rellenar todas las cajas o haber agregado platillos", "Información", JOptionPane.INFORMATION_MESSAGE);
        }else{//si no 
        String nom=txtnom.getText();//lo que hay en la caja de nombre, guardarlo en el string nom
        String dir=txtdir.getText();//lo que hay en la caja de direccion, guardarlo en el string dir
        int edad=Integer.parseInt(txtedad.getText());//lo que hay en la caja de edad, guardarlo en el int edad, pero para esto debemos de hacer la conversion de string a int
        String pago=cmbpago.getSelectedItem().toString();//lo que hay en la caja de pago, guardarlo en el string pago, pero al ser combo box, debemos de convertirlo a string
        Repartidor r=main.obtenerRepartidorAleatorio();// obtenemos un repartidor que se guardara como r y utilizaremos el main para acceder a la lista de repartidores del mein y ahi la funcion de obtener repartidor para asignarlo al r, asi obtenemos un repartidor de forma aleatoria
        Pedido p = new Pedido(new ArrayList<>(pla),nom,dir,edad,r,pago,total);//llamamos al constructor de pedido y le damos todos los valores, la lista de platillos, se agrega de la lista que hay en este form, esto pq se supone que ya deben de haber registrado por lo menos un platillo
        main.getRestaurante().agregarPedido(p);//llamamso al main, para obtener el restaurante que es el objeto principal, y de ahi acceder a sus atributos para agregar a su lista de pedidos el actual pedido anteriormente creado
        total=0;//el total vuelve a 0
        pla.clear();//limpiamos la lista de platillos
        JOptionPane.showMessageDialog(null, "Pedido agregado", "Información", JOptionPane.INFORMATION_MESSAGE);//mensaje de confirmacion
        }
    }
    public void agregarPlatillo(){
    if(txtplatillo.getText().equals("")){//si la caja esta vacia muestra este mensaje 
        JOptionPane.showMessageDialog(null, "Agrega algo a la caja", "Información", JOptionPane.INFORMATION_MESSAGE);
    }else{
    String platillo=txtplatillo.getText();//lo que hay en la caja de platillo se guarda en el string platillo
        Receta r=main.getRestaurante().buscarPlatillo(platillo);//guardamos en el obejto de tipo receta lo que encontremis de la busqueda en el restaurante del main y si su nombre es igual a algun objeto de la lista de platillos del restaurante, devolvera el objeto
        if(r==null){//si devuelve null, significa que el objeto no existe y manda este mensaje
            JOptionPane.showMessageDialog(null, "El platillo o bebida no existe", "Información", JOptionPane.INFORMATION_MESSAGE);
        }else{//si hay algo 
            pla.add(platillo);//en esta lista de cadenas de platillos, se agrega el nombre del platillo
            total+=r.getPrecio();//el total se incrementa con le precio del platillo
            JOptionPane.showMessageDialog(null, "El platillo o bebida agregada", "Información", JOptionPane.INFORMATION_MESSAGE);// se confirma el registro
        }
    }
}
    public void limpiarPlatillo(){
        txtplatillo.setText("");//limpia la caja de texto platillo
    }
    public void limpia(){
        txtnom.setText("");//limpia cajas de texto
        txtdir.setText("");
        txtedad.setText("");
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnpedido;
    private javax.swing.JButton btnplatillo;
    private javax.swing.JComboBox<String> cmbpago;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JTextField txtdir;
    private javax.swing.JTextField txtedad;
    private javax.swing.JTextField txtnom;
    private javax.swing.JTextField txtplatillo;
    // End of variables declaration//GEN-END:variables
}
