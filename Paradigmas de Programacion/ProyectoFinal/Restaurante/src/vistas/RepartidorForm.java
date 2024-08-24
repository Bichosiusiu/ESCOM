package vistas;
import javax.swing.JOptionPane;
import modelo.Repartidor;
public class RepartidorForm extends javax.swing.JFrame {
    private final Main main;//mandamos el main como atributo para poder regresar
    public RepartidorForm(Main main) {
        this.main=main;//inicializamos el form
        initComponents();
        this.setLocationRelativeTo(null);//colocamos al centro
        jTextArea1.setEditable(false);//la textarea no sera editable
        jTextArea1.append(main.imprimir());//la text area recibira la gran cadena del main, de la lista de imorimir , esto para imprimir todos los objetos de esa lista general
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPasswordField1 = new javax.swing.JPasswordField();
        jPanel1 = new javax.swing.JPanel();
        jButton1 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        txtnom = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        txtdir = new javax.swing.JTextField();
        cmbmed = new javax.swing.JComboBox<>();
        jLabel5 = new javax.swing.JLabel();
        txttiem = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        txted = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();
        txtscore = new javax.swing.JTextField();
        btnagregar = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();

        jPasswordField1.setText("jPasswordField1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);

        jPanel1.setBackground(new java.awt.Color(0, 0, 0));

        jButton1.setText("REGRESAR");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("NOMBRE:");

        jLabel4.setForeground(new java.awt.Color(255, 255, 255));
        jLabel4.setText("MEDIO DE TRANSPORTE:");

        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("DIRECCION:");

        cmbmed.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "SELECCIONAR", "MOTO", "CARRO", "BICICLETA", "PATINETA" }));

        jLabel5.setForeground(new java.awt.Color(255, 255, 255));
        jLabel5.setText("TIEMPO DE ESPERA:");

        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setText("EDAD:");

        jLabel6.setForeground(new java.awt.Color(255, 255, 255));
        jLabel6.setText("SCORE:");

        btnagregar.setText("AGREGAR");
        btnagregar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnagregarActionPerformed(evt);
            }
        });

        jTextArea1.setColumns(20);
        jTextArea1.setFont(new java.awt.Font("Sylfaen", 0, 16)); // NOI18N
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(jButton1))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(jLabel1)
                            .addComponent(jLabel3))
                        .addGap(18, 18, 18)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(txtnom, javax.swing.GroupLayout.DEFAULT_SIZE, 177, Short.MAX_VALUE)
                                        .addGap(211, 211, 211))
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(txtdir, javax.swing.GroupLayout.PREFERRED_SIZE, 235, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(jLabel4)
                                        .addGap(18, 18, 18)
                                        .addComponent(cmbmed, javax.swing.GroupLayout.PREFERRED_SIZE, 147, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(jLabel5)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(txttiem, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE))))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(txted, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(47, 47, 47)
                                .addComponent(jLabel6)
                                .addGap(18, 18, 18)
                                .addComponent(txtscore, javax.swing.GroupLayout.PREFERRED_SIZE, 43, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(btnagregar)
                                .addGap(108, 108, 108))))
                    .addComponent(jScrollPane1))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jButton1)
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(txtnom, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4)
                    .addComponent(cmbmed, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(txtdir, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5)
                    .addComponent(txttiem, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(txted, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6)
                    .addComponent(txtscore, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnagregar))
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 347, Short.MAX_VALUE)
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        this.setVisible(false); // Oculta la ventana del apartado
        main.setVisible(true);//muestra el main
    }//GEN-LAST:event_jButton1ActionPerformed

    private void btnagregarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnagregarActionPerformed
        agregar();//metodo para agregar los repartidores
        jTextArea1.setText("");//limpiamos el jarea
        jTextArea1.append(main.imprimir());//volvemos a imprimir para saber si se adirio el repartidor
    }//GEN-LAST:event_btnagregarActionPerformed

    public void agregar(){
        if(txtnom.getText().equals("")||txtdir.getText().equals("")||txted.getText().equals("")||txtscore.getText().equals("")||cmbmed.getSelectedItem().equals("SELECCIONAR")||txttiem.getText().equals("")){//si las cajas estan vacias manda mensaje de error
            JOptionPane.showMessageDialog(null, "Favor de rellenat todas las cajas", "Información", JOptionPane.INFORMATION_MESSAGE);
        }else{
            String nom=txtnom.getText();//en la string nom se guarda lo que hay en la caja nom
            String dir=txtdir.getText();//en la string dir se guarda lo que hay en la caja dir
            int ed=Integer.parseInt(txted.getText());//en el int ed se guarda lo que hay en la caja ed haciendo una conversion de string a int
            String med=cmbmed.getSelectedItem().toString();//en la string med se guarda lo que hay en la combo box de med, pero esto convertirlo a string
            String tiem=txttiem.getText();//en el string tiem se guarda lo que hay en la cja tiem
            double score=Double.parseDouble(txtscore.getText());//en el double score se guarda lo que hay en la caja de score pero con una conversion de string a double
            Repartidor nuevorep=new Repartidor(med,tiem,score,nom,dir,ed);//se crea un objeto de tipo repartidor,y se el asigna todo al constructor con los datos anteriores
            main.agregarRepartidor(nuevorep);//accedemos al main a la lista de repartiodes y agregamos un repartidor que es el anteriormente construido
            txtnom.setText("");//limpiamos cajas
            txtdir.setText("");
            txted.setText("");
            txttiem.setText("");
            txtscore.setText("");
            JOptionPane.showMessageDialog(null, "Registro Exitoso", "Información", JOptionPane.INFORMATION_MESSAGE);//mensaje de confirmacion
        }
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnagregar;
    private javax.swing.JComboBox<String> cmbmed;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPasswordField jPasswordField1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JTextField txtdir;
    private javax.swing.JTextField txted;
    private javax.swing.JTextField txtnom;
    private javax.swing.JTextField txtscore;
    private javax.swing.JTextField txttiem;
    // End of variables declaration//GEN-END:variables
}
