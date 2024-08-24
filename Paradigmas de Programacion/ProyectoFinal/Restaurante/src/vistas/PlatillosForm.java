package vistas;
import modelo.Bebida;
import modelo.Comida;
import modelo.Postre;
import javax.swing.JOptionPane;

public class PlatillosForm extends javax.swing.JFrame {
     private final Main main;//mandamos el main como atributo para poder regresar

    public PlatillosForm(Main main) {
        this.main=main;//inicializamos el form
        initComponents();
        this.setLocationRelativeTo(null);//colocamos al centro
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        txtnombeb = new javax.swing.JTextField();
        txtprebeb = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        txtsabbeb = new javax.swing.JTextField();
        jLabel11 = new javax.swing.JLabel();
        txttipbeb = new javax.swing.JTextField();
        btnbebida = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        txtnomcom = new javax.swing.JTextField();
        txtprecom = new javax.swing.JTextField();
        txtorgcom = new javax.swing.JTextField();
        btncomida = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        txtnompos = new javax.swing.JTextField();
        jLabel9 = new javax.swing.JLabel();
        txtprepos = new javax.swing.JTextField();
        jLabel13 = new javax.swing.JLabel();
        txtsabpos = new javax.swing.JTextField();
        txtorgpos = new javax.swing.JTextField();
        jLabel14 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        btnpostre = new javax.swing.JButton();
        jLabel15 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        jLabel17 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(255, 255, 255));
        setResizable(false);

        jPanel1.setBackground(new java.awt.Color(0, 0, 0));

        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("BEBIDA");

        jLabel4.setForeground(new java.awt.Color(255, 255, 255));
        jLabel4.setText("NOMBRE:");

        txtnombeb.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtnombebActionPerformed(evt);
            }
        });

        jLabel7.setForeground(new java.awt.Color(255, 255, 255));
        jLabel7.setText("PRECIO:");

        jLabel10.setForeground(new java.awt.Color(255, 255, 255));
        jLabel10.setText("SABOR:");

        jLabel11.setForeground(new java.awt.Color(255, 255, 255));
        jLabel11.setText("TIPO:");

        btnbebida.setText("AGREGAR BEBIDA");
        btnbebida.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnbebidaActionPerformed(evt);
            }
        });

        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("COMIDA");

        jLabel5.setForeground(new java.awt.Color(255, 255, 255));
        jLabel5.setText("NOMBRE:");

        jLabel8.setForeground(new java.awt.Color(255, 255, 255));
        jLabel8.setText("PRECIO:");

        jLabel12.setForeground(new java.awt.Color(255, 255, 255));
        jLabel12.setText("ORIGEN:");

        btncomida.setText("AGREGAR COMIDA");
        btncomida.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btncomidaActionPerformed(evt);
            }
        });

        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setText("POSTRE");

        jLabel6.setForeground(new java.awt.Color(255, 255, 255));
        jLabel6.setText("NOMBRE:");

        txtnompos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtnomposActionPerformed(evt);
            }
        });

        jLabel9.setForeground(new java.awt.Color(255, 255, 255));
        jLabel9.setText("PRECIO:");

        jLabel13.setForeground(new java.awt.Color(255, 255, 255));
        jLabel13.setText("SABOR:");

        txtorgpos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtorgposActionPerformed(evt);
            }
        });

        jLabel14.setForeground(new java.awt.Color(255, 255, 255));
        jLabel14.setText("ORIGEN:");

        jButton1.setText("REGRESAR");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        btnpostre.setText("AGREGAR POSTRE");
        btnpostre.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnpostreActionPerformed(evt);
            }
        });

        jLabel15.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/bebidas.jpg"))); // NOI18N
        jLabel15.setText("jLabel15");

        jLabel16.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/comida.jpg"))); // NOI18N
        jLabel16.setText("jLabel16");

        jLabel17.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/postres.jpg"))); // NOI18N
        jLabel17.setText("jLabel17");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel7))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(101, 101, 101)
                        .addComponent(jLabel1)))
                .addGap(178, 178, 178)
                .addComponent(jLabel2)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel10)
                            .addComponent(jLabel11)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(jLabel15, javax.swing.GroupLayout.PREFERRED_SIZE, 188, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(39, 39, 39)
                                .addComponent(jLabel16, javax.swing.GroupLayout.PREFERRED_SIZE, 227, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(46, 46, 46)
                                .addComponent(jLabel17, javax.swing.GroupLayout.PREFERRED_SIZE, 218, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addContainerGap(41, Short.MAX_VALUE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel4)
                        .addGap(12, 12, 12)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(btnbebida)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(btncomida)
                                .addGap(117, 117, 117)
                                .addComponent(btnpostre)
                                .addGap(105, 105, 105))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                    .addComponent(txtsabbeb, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 143, Short.MAX_VALUE)
                                    .addComponent(txtprebeb, javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(txtnombeb, javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(txttipbeb, javax.swing.GroupLayout.Alignment.LEADING))
                                .addGap(33, 33, 33)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(jLabel12)
                                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(jLabel5)
                                        .addComponent(jLabel8)))
                                .addGap(18, 18, 18)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(txtorgcom, javax.swing.GroupLayout.PREFERRED_SIZE, 113, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(70, 70, 70)
                                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jLabel13)
                                            .addComponent(jLabel14))
                                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(txtprecom, javax.swing.GroupLayout.PREFERRED_SIZE, 113, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(txtnomcom, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGap(68, 68, 68)
                                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jLabel6)
                                            .addComponent(jLabel9))
                                        .addGap(18, 18, 18)
                                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jLabel3)
                                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                .addComponent(txtsabpos, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 126, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addComponent(txtprepos, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 127, Short.MAX_VALUE)
                                                .addComponent(txtorgpos, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 126, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addComponent(txtnompos)))
                                        .addGap(0, 0, Short.MAX_VALUE))))))))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jButton1)
                .addGap(16, 16, 16))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(13, 13, 13)
                .addComponent(jButton1)
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2)
                    .addComponent(jLabel3))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(txtnombeb, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5)
                    .addComponent(txtnomcom, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6)
                    .addComponent(txtnompos, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtprebeb, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel7)
                    .addComponent(jLabel8)
                    .addComponent(txtprecom, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel9)
                    .addComponent(txtprepos, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtsabbeb, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel10)
                    .addComponent(jLabel12)
                    .addComponent(txtorgcom, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel13)
                    .addComponent(txtsabpos, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txttipbeb, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel11)
                    .addComponent(jLabel14)
                    .addComponent(txtorgpos, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnpostre)
                    .addComponent(btncomida)
                    .addComponent(btnbebida))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 69, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel16, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel15, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel17, javax.swing.GroupLayout.PREFERRED_SIZE, 170, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(30, 30, 30))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
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

    private void txtnombebActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtnombebActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtnombebActionPerformed

    private void txtnomposActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtnomposActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtnomposActionPerformed

    private void txtorgposActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtorgposActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtorgposActionPerformed

    private void btnbebidaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnbebidaActionPerformed
        if(txtnombeb.getText().equals("")||txtprebeb.getText().equals("")||txtsabbeb.getText().equals("")||txttipbeb.getText().equals("")){//si las cajas de bebida estan vacias, mandara un mensaje de error
            JOptionPane.showMessageDialog(null, "Favor de rellenat todas las cajas", "Información", JOptionPane.INFORMATION_MESSAGE);
        }else{
            String nom=txtnombeb.getText();//lo que hay en nombre lo guardara en la cadena nombre
            int precio=Integer.parseInt(txtprebeb.getText());//lo que hay en precio lo guardara en el int de precio haciendo una conversion de string a int
            String sab=txtsabbeb.getText();//lo que hay en sabor lo guardara en la cadena sab
            String tip=txttipbeb.getText();//lo que hay en tipo lo guardara en la cadena tip
            Bebida b=new Bebida(nom,precio,tip,sab);
            main.getRestaurante().agregarAlMenu(b);// accedemos al main y a su objeto de tipo restaurante y de ahi accedemos al metodo agregar al menu para agregar el objeto bebida a la lista de receta
            txtnombeb.setText("");// limpiamos las cajas
            txtprebeb.setText("");
            txtsabbeb.setText("");
            txttipbeb.setText("");
            JOptionPane.showMessageDialog(null, "Registro Exitoso", "Información", JOptionPane.INFORMATION_MESSAGE);//mandamos mensaje de confirmacion
        }
    }//GEN-LAST:event_btnbebidaActionPerformed

    private void btncomidaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btncomidaActionPerformed
        if(txtnomcom.getText().equals("")||txtprecom.getText().equals("")||txtorgcom.getText().equals("")){//si las cajas de comida estan vacias, mandara un mensaje de error
            JOptionPane.showMessageDialog(null, "Favor de rellenat todas las cajas", "Información", JOptionPane.INFORMATION_MESSAGE);
        }else{
            String nom=txtnomcom.getText();//lo que hay en nombre lo guardara en la cadena nombre
            int precio=Integer.parseInt(txtprecom.getText());//lo que hay en precio lo guardara en el int de precio haciendo una conversion de string a int
            String org=txtorgcom.getText();// lo que hay en org lo gusradar en la cadena org
            Comida c=new Comida(nom,precio,org);
            main.getRestaurante().agregarAlMenu(c);// accedemos al main y a su objeto de tipo restaurante y de ahi accedemos al metodo agregar al menu para agregar el objeto comida a la lista de receta
            txtnomcom.setText("");// limpiamos las cajas
            txtprecom.setText("");
            txtorgcom.setText("");
            JOptionPane.showMessageDialog(null, "Registro Exitoso", "Información", JOptionPane.INFORMATION_MESSAGE);//mandamos mensaje de confirmacion
        }
    }//GEN-LAST:event_btncomidaActionPerformed

    private void btnpostreActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnpostreActionPerformed
        if(txtnompos.getText().equals("")||txtprepos.getText().equals("")||txtsabpos.getText().equals("")||txtorgpos.getText().equals("")){//si las cajas de postre estan vacias, mandara un mensaje de error
            JOptionPane.showMessageDialog(null, "Favor de rellenat todas las cajas", "Información", JOptionPane.INFORMATION_MESSAGE);
        }else{
            String nom=txtnompos.getText();//lo que hay en nombre lo guardara en la cadena nombre
            int precio=Integer.parseInt(txtprepos.getText());//lo que hay en precio lo guardara en el int de precio haciendo una conversion de string a int
            String sab=txtsabpos.getText();//lo que hay en saboe lo guardara en la cadena sab
            String org = txtorgpos.getText();//lo que hay en origen lo guardara en la cadena org
            Postre p=new Postre(nom,precio,sab,org);
            main.getRestaurante().agregarAlMenu(p);// accedemos al main y a su objeto de tipo restaurante y de ahi accedemos al metodo agregar al menu para agregar el objeto postre a la lista de receta
            txtnompos.setText("");// limpiamos las cajas
            txtprepos.setText("");
            txtsabpos.setText("");
            txtorgpos.setText("");
            JOptionPane.showMessageDialog(null, "Registro Exitoso", "Información", JOptionPane.INFORMATION_MESSAGE);//mandamos mensaje de confirmacion
        }
    }//GEN-LAST:event_btnpostreActionPerformed



    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnbebida;
    private javax.swing.JButton btncomida;
    private javax.swing.JButton btnpostre;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JTextField txtnombeb;
    private javax.swing.JTextField txtnomcom;
    private javax.swing.JTextField txtnompos;
    private javax.swing.JTextField txtorgcom;
    private javax.swing.JTextField txtorgpos;
    private javax.swing.JTextField txtprebeb;
    private javax.swing.JTextField txtprecom;
    private javax.swing.JTextField txtprepos;
    private javax.swing.JTextField txtsabbeb;
    private javax.swing.JTextField txtsabpos;
    private javax.swing.JTextField txttipbeb;
    // End of variables declaration//GEN-END:variables
}
