
import java.awt.Color;
import java.awt.Component;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import javax.swing.ImageIcon;
import javax.swing.JTable;
import javax.swing.RowFilter;

import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableRowSorter;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */

/**
 *
 * @author volka
 */
public class AdminMenu extends javax.swing.JFrame {
    private int initialX, initialY;
    /**
     * Creates new form yonetici_islem_form
     */
    DefaultTableModel tamamlanmamis_siparislermodel ;
    DefaultTableModel tamamlanmis_siparislermodel;
    DefaultTableModel siparis_detay_tamamlanmamismodel; 
    DefaultTableModel siparis_detay_tamamlanmismodel ;
       
       
    
    
    
    DefaultTableModel model;
    DefaultTableModel musteritablosumodel;
    
    
    
    
    public void dinamikAra(String ara){
        
        TableRowSorter<DefaultTableModel> tr = new TableRowSorter<DefaultTableModel>(model);
        
        ilac_tablosu.setRowSorter(tr);
        String aramakucukharf= ara.toLowerCase();
        tr.setRowFilter(RowFilter.regexFilter("(?i)"+aramakucukharf));
        
        
    }
    public void ilacGoruntule(){
        model.setRowCount(0);
        
        ArrayList<Ilac> ilaclar = new ArrayList<Ilac>();
        
        ilaclar = Sistem.ilaclariGetir();
        
        if(ilaclar != null){
            
            
            for(Ilac ilac: ilaclar){
                
                Object[] eklenecek ={ilac.getIsim(),ilac.getBarkodno(),ilac.getTur(),ilac.getFiyat(),ilac.getAdet()};
                model.addRow(eklenecek);
                
                
            }
                
        }
        
    }
    
    public void siparisGoruntule(){
        tamamlanmamis_siparislermodel.setRowCount(0);
        tamamlanmis_siparislermodel.setRowCount(0);
        siparis_detay_tamamlanmismodel.setRowCount(0);
        siparis_detay_tamamlanmamismodel.setRowCount(0);
        
        
        ArrayList<Siparis> siparisler = new ArrayList<Siparis>();
        
        siparisler = Sistem.siparisleriGetir();
        int toplamKazanc = 0;
        if(siparisler != null){
            
            
            for(Siparis siparis: siparisler){
                
                if(siparis.getTamamlandi().equals("0")){
                    
                    Object[] eklenecek ={siparis.getEczaneismi(),siparis.getSiparisno(),siparis.getTutar()};
                    tamamlanmamis_siparislermodel.addRow(eklenecek);
                    
                    
                    
                }
                else{
                    Object[] eklenecek ={siparis.getEczaneismi(),siparis.getSiparisno(),siparis.getTutar()};
                    tamamlanmis_siparislermodel.addRow(eklenecek);
                    toplamKazanc += Integer.parseInt(siparis.getTutar());
                    
                }
               
                
            }
            toplam_kazanc.setText(String.valueOf(toplamKazanc + "₺"));
        }
        
    }
    
    
    
    public AdminMenu() {
        
        initComponents();
        
        ImageIcon icon = new ImageIcon("icon5.png");
        Image image = icon.getImage();
        setIconImage(image);
        setTitle("Yönetici Bilgi Ekranı");
        
        tamamlanmamis_siparislermodel =(DefaultTableModel)tamamlanmamis_siparisler.getModel();
        tamamlanmis_siparislermodel =(DefaultTableModel)tamamlanmis_siparisler.getModel();
        siparis_detay_tamamlanmamismodel =(DefaultTableModel)siparis_detay_tamamlanmamis.getModel();
        siparis_detay_tamamlanmismodel =(DefaultTableModel)siparis_detay_tamamlanmis.getModel();
        
        
        
        
        
        
        
        musteritablosumodel =(DefaultTableModel)musteriler_tablosu.getModel();
        musterigoruntule();
        
        model = (DefaultTableModel)ilac_tablosu.getModel();
        ilacGoruntule();
        siparisGoruntule();
        
        
        
        ilac_stok_sayfa.setVisible(false);
        hosgeldiniz.setVisible(true);
        siparis_goruntule_sayfa.setVisible(false);
        musteri_goruntule_sayfasi.setVisible(false);
        
        arama_cubugu_admin.setForeground(Color.GRAY);
        arama_cubugu_admin.setText("Aramak için tıklayınız.. örn Parol");
        
        arama_cubugu_musteri.setForeground(Color.GRAY);
        arama_cubugu_musteri.setText("Aramak için tıklayınız.. örn Çiçek Eczane");
        
        
        
        
        
        hosgeldin_ust.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                // Fare basıldığında, JFrame'in başlangıç konumunu al
                initialX = e.getX();
                initialY = e.getY();
            }
        });


        hosgeldin_ust.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                // Fare sürüklendiğinde, JFrame'in konumunu güncelle
                int newX = getLocation().x + e.getX() - initialX;
                int newY = getLocation().y + e.getY() - initialY;
                setLocation(newX, newY);
            }
        });
        
        
        ilac_stok_ust.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                // Fare basıldığında, JFrame'in başlangıç konumunu al
                initialX = e.getX();
                initialY = e.getY();
            }
        });


        ilac_stok_ust.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                // Fare sürüklendiğinde, JFrame'in konumunu güncelle
                int newX = getLocation().x + e.getX() - initialX;
                int newY = getLocation().y + e.getY() - initialY;
                setLocation(newX, newY);
            }
        });
        
        
        musteri_goruntule_ust.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                // Fare basıldığında, JFrame'in başlangıç konumunu al
                initialX = e.getX();
                initialY = e.getY();
            }
        });


        musteri_goruntule_ust.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                // Fare sürüklendiğinde, JFrame'in konumunu güncelle
                int newX = getLocation().x + e.getX() - initialX;
                int newY = getLocation().y + e.getY() - initialY;
                setLocation(newX, newY);
            }
        });
        
        
        siparis_goruntule_ust.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                // Fare basıldığında, JFrame'in başlangıç konumunu al
                initialX = e.getX();
                initialY = e.getY();
            }
        });


        siparis_goruntule_ust.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                // Fare sürüklendiğinde, JFrame'in konumunu güncelle
                int newX = getLocation().x + e.getX() - initialX;
                int newY = getLocation().y + e.getY() - initialY;
                setLocation(newX, newY);
            }
        });
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ilac_tablosu.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component component = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (isSelected) {
                    // Change the background color of the selected row
                    component.setBackground(new Color(229,89,89));
                } else {
                    // Reset the background color of other rows
                    component.setBackground(table.getBackground());
                }
                return component;
            }
        });

        // Add a ListSelectionListener to change row color when selected
        ilac_tablosu.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = ilac_tablosu.getSelectedRow();
                    // Repaint the table to apply color changes
                    ilac_tablosu.repaint();
                }
            }
        });
        
        
        
        
        
        
        
        musteriler_tablosu.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component component = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (isSelected) {
                    // Change the background color of the selected row
                    component.setBackground(new Color(229,89,89));
                } else {
                    // Reset the background color of other rows
                    component.setBackground(table.getBackground());
                }
                return component;
            }
        });

        // Add a ListSelectionListener to change row color when selected
        musteriler_tablosu.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = musteriler_tablosu.getSelectedRow();
                    // Repaint the table to apply color changes
                    musteriler_tablosu.repaint();
                }
            }
        });
        
        
        
        
        
        
        
        //
        
        
        
        tamamlanmis_siparisler.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component component = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (isSelected) {
                    // Change the background color of the selected row
                    component.setBackground(new Color(229,89,89));
                } else {
                    // Reset the background color of other rows
                    component.setBackground(table.getBackground());
                }
                return component;
            }
        });

        // Add a ListSelectionListener to change row color when selected
        tamamlanmis_siparisler.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = tamamlanmis_siparisler.getSelectedRow();
                    // Repaint the table to apply color changes
                    tamamlanmis_siparisler.repaint();
                }
            }
        });
        
        tamamlanmamis_siparisler.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component component = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (isSelected) {
                    // Change the background color of the selected row
                    component.setBackground(new Color(229,89,89));
                } else {
                    // Reset the background color of other rows
                    component.setBackground(table.getBackground());
                }
                return component;
            }
        });

        // Add a ListSelectionListener to change row color when selected
        tamamlanmamis_siparisler.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = tamamlanmamis_siparisler.getSelectedRow();
                    // Repaint the table to apply color changes
                    tamamlanmamis_siparisler.repaint();
                }
            }
        });
        
        //
        
        siparis_detay_tamamlanmis.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component component = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (isSelected) {
                    // Change the background color of the selected row
                    component.setBackground(new Color(229,89,89));
                } else {
                    // Reset the background color of other rows
                    component.setBackground(table.getBackground());
                }
                return component;
            }
        });

        // Add a ListSelectionListener to change row color when selected
        siparis_detay_tamamlanmis.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = siparis_detay_tamamlanmis.getSelectedRow();
                    // Repaint the table to apply color changes
                    siparis_detay_tamamlanmis.repaint();
                }
            }
        });
        
        
        
        siparis_detay_tamamlanmamis.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component component = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                if (isSelected) {
                    // Change the background color of the selected row
                    component.setBackground(new Color(229,89,89));
                } else {
                    // Reset the background color of other rows
                    component.setBackground(table.getBackground());
                }
                return component;
            }
        });

        // Add a ListSelectionListener to change row color when selected
        siparis_detay_tamamlanmamis.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = siparis_detay_tamamlanmamis.getSelectedRow();
                    // Repaint the table to apply color changes
                    siparis_detay_tamamlanmamis.repaint();
                }
            }
        });
        
        
        
        
        
        
        
        
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenu1 = new javax.swing.JMenu();
        jMenu2 = new javax.swing.JMenu();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu3 = new javax.swing.JMenu();
        jMenu4 = new javax.swing.JMenu();
        jLabel8 = new javax.swing.JLabel();
        jSeparator3 = new javax.swing.JSeparator();
        jLabel10 = new javax.swing.JLabel();
        jPanel7 = new javax.swing.JPanel();
        jPanel1 = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        jSeparator1 = new javax.swing.JSeparator();
        ilac_stok_islemleri = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        siparis_goruntule = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        musteri_goruntule = new javax.swing.JPanel();
        jLabel4 = new javax.swing.JLabel();
        cikis_admin = new javax.swing.JPanel();
        jLabel16 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        admin_anasayfa = new javax.swing.JPanel();
        ilac_stok_sayfa = new javax.swing.JPanel();
        arama_cubugu_admin = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jSeparator2 = new javax.swing.JSeparator();
        jLabel9 = new javax.swing.JLabel();
        jSeparator4 = new javax.swing.JSeparator();
        ilac_stok_ust = new javax.swing.JPanel();
        jPanel4 = new javax.swing.JPanel();
        isim_alani_stok = new javax.swing.JTextField();
        tur_alani_stok = new javax.swing.JTextField();
        fiyat_alani_stok = new javax.swing.JTextField();
        adet_alani_stok = new javax.swing.JTextField();
        jLabel11 = new javax.swing.JLabel();
        ekle_buton_stok = new javax.swing.JButton();
        guncelle_butonu_stok = new javax.swing.JButton();
        jLabel12 = new javax.swing.JLabel();
        silme_butonu_stok = new javax.swing.JButton();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        mesaj_alani = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        ilac_tablosu = new javax.swing.JTable();
        musteri_goruntule_sayfasi = new javax.swing.JPanel();
        musteri_goruntule_ust = new javax.swing.JPanel();
        hosgeldin_ust2 = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        musteriler_tablosu = new javax.swing.JTable();
        arama_cubugu_musteri = new javax.swing.JTextField();
        jSeparator5 = new javax.swing.JSeparator();
        jLabel20 = new javax.swing.JLabel();
        jLabel21 = new javax.swing.JLabel();
        jSeparator6 = new javax.swing.JSeparator();
        siparis_goruntule_sayfa = new javax.swing.JPanel();
        siparis_goruntule_ust = new javax.swing.JPanel();
        jPanel5 = new javax.swing.JPanel();
        jScrollPane3 = new javax.swing.JScrollPane();
        siparis_detay_tamamlanmamis = new javax.swing.JTable();
        jScrollPane4 = new javax.swing.JScrollPane();
        tamamlanmamis_siparisler = new javax.swing.JTable();
        jLabel5 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        siparisigonder_butonu = new javax.swing.JButton();
        jLabel22 = new javax.swing.JLabel();
        jLabel23 = new javax.swing.JLabel();
        jSeparator7 = new javax.swing.JSeparator();
        jScrollPane7 = new javax.swing.JScrollPane();
        tamamlanmis_siparisler = new javax.swing.JTable();
        jScrollPane5 = new javax.swing.JScrollPane();
        siparis_detay_tamamlanmis = new javax.swing.JTable();
        uyari_gonderi = new javax.swing.JLabel();
        jLabel24 = new javax.swing.JLabel();
        toplam_kazanc = new javax.swing.JLabel();
        hosgeldiniz = new javax.swing.JPanel();
        hosgeldin_ust = new javax.swing.JPanel();
        jPanel6 = new javax.swing.JPanel();
        jLabel17 = new javax.swing.JLabel();
        jLabel18 = new javax.swing.JLabel();
        jLabel19 = new javax.swing.JLabel();

        jMenu1.setText("jMenu1");

        jMenu2.setText("jMenu2");

        jMenu3.setText("File");
        jMenuBar1.add(jMenu3);

        jMenu4.setText("Edit");
        jMenuBar1.add(jMenu4);

        jLabel8.setText("jLabel8");

        jLabel10.setText("jLabel10");

        jPanel7.setBackground(new java.awt.Color(255, 22, 22));
        jPanel7.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout jPanel7Layout = new javax.swing.GroupLayout(jPanel7);
        jPanel7.setLayout(jPanel7Layout);
        jPanel7Layout.setHorizontalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jPanel7Layout.setVerticalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 28, Short.MAX_VALUE)
        );

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));

        jPanel2.setBackground(new java.awt.Color(217, 217, 217));

        ilac_stok_islemleri.setBackground(new java.awt.Color(234, 233, 233));
        ilac_stok_islemleri.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        ilac_stok_islemleri.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                ilac_stok_islemleriMouseClicked(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel2.setText("İlaç Stok İşlemleri");

        javax.swing.GroupLayout ilac_stok_islemleriLayout = new javax.swing.GroupLayout(ilac_stok_islemleri);
        ilac_stok_islemleri.setLayout(ilac_stok_islemleriLayout);
        ilac_stok_islemleriLayout.setHorizontalGroup(
            ilac_stok_islemleriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(ilac_stok_islemleriLayout.createSequentialGroup()
                .addGap(23, 23, 23)
                .addComponent(jLabel2)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        ilac_stok_islemleriLayout.setVerticalGroup(
            ilac_stok_islemleriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, ilac_stok_islemleriLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, 35, Short.MAX_VALUE)
                .addContainerGap())
        );

        siparis_goruntule.setBackground(new java.awt.Color(234, 233, 233));
        siparis_goruntule.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        siparis_goruntule.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                siparis_goruntuleMouseClicked(evt);
            }
        });

        jLabel3.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel3.setText("Sipariş Görüntüle");

        javax.swing.GroupLayout siparis_goruntuleLayout = new javax.swing.GroupLayout(siparis_goruntule);
        siparis_goruntule.setLayout(siparis_goruntuleLayout);
        siparis_goruntuleLayout.setHorizontalGroup(
            siparis_goruntuleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(siparis_goruntuleLayout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addComponent(jLabel3)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        siparis_goruntuleLayout.setVerticalGroup(
            siparis_goruntuleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, siparis_goruntuleLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, 32, Short.MAX_VALUE)
                .addContainerGap())
        );

        musteri_goruntule.setBackground(new java.awt.Color(234, 233, 233));
        musteri_goruntule.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        musteri_goruntule.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                musteri_goruntuleMouseClicked(evt);
            }
        });

        jLabel4.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel4.setText("Müşteri Görüntüle");

        javax.swing.GroupLayout musteri_goruntuleLayout = new javax.swing.GroupLayout(musteri_goruntule);
        musteri_goruntule.setLayout(musteri_goruntuleLayout);
        musteri_goruntuleLayout.setHorizontalGroup(
            musteri_goruntuleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(musteri_goruntuleLayout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addComponent(jLabel4)
                .addContainerGap(22, Short.MAX_VALUE))
        );
        musteri_goruntuleLayout.setVerticalGroup(
            musteri_goruntuleLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(musteri_goruntuleLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, 36, Short.MAX_VALUE)
                .addContainerGap())
        );

        cikis_admin.setBackground(new java.awt.Color(234, 233, 233));
        cikis_admin.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        cikis_admin.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                cikis_adminMouseClicked(evt);
            }
        });

        jLabel16.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel16.setText("Çıkış");

        javax.swing.GroupLayout cikis_adminLayout = new javax.swing.GroupLayout(cikis_admin);
        cikis_admin.setLayout(cikis_adminLayout);
        cikis_adminLayout.setHorizontalGroup(
            cikis_adminLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(cikis_adminLayout.createSequentialGroup()
                .addGap(79, 79, 79)
                .addComponent(jLabel16)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        cikis_adminLayout.setVerticalGroup(
            cikis_adminLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, cikis_adminLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel16, javax.swing.GroupLayout.DEFAULT_SIZE, 36, Short.MAX_VALUE)
                .addContainerGap())
        );

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/menu.png"))); // NOI18N

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(musteri_goruntule, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(siparis_goruntule, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(ilac_stok_islemleri, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(cikis_admin, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 140, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(ilac_stok_islemleri, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(siparis_goruntule, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(musteri_goruntule, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 95, Short.MAX_VALUE)
                .addComponent(cikis_admin, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(105, 105, 105))
        );

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, 203, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        admin_anasayfa.setBackground(new java.awt.Color(255, 255, 255));
        admin_anasayfa.setPreferredSize(new java.awt.Dimension(527, 585));

        ilac_stok_sayfa.setBackground(new java.awt.Color(255, 255, 255));

        arama_cubugu_admin.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                arama_cubugu_adminFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                arama_cubugu_adminFocusLost(evt);
            }
        });
        arama_cubugu_admin.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                arama_cubugu_adminKeyReleased(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel6.setText("Ara:");

        jLabel7.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel7.setText("Stok Durumu ve Liste");

        jLabel9.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel9.setText("İlaç Ekle ,Sil ,Güncelle İşlemleri");

        ilac_stok_ust.setBackground(new java.awt.Color(255, 22, 22));
        ilac_stok_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout ilac_stok_ustLayout = new javax.swing.GroupLayout(ilac_stok_ust);
        ilac_stok_ust.setLayout(ilac_stok_ustLayout);
        ilac_stok_ustLayout.setHorizontalGroup(
            ilac_stok_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        ilac_stok_ustLayout.setVerticalGroup(
            ilac_stok_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 26, Short.MAX_VALUE)
        );

        jPanel4.setBackground(new java.awt.Color(255, 22, 22));

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 28, Short.MAX_VALUE)
        );

        isim_alani_stok.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                isim_alani_stokActionPerformed(evt);
            }
        });

        jLabel11.setFont(new java.awt.Font("SansSerif", 0, 18)); // NOI18N
        jLabel11.setText("İsim");

        ekle_buton_stok.setText(" Yeni İlaç Ekle");
        ekle_buton_stok.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        ekle_buton_stok.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ekle_buton_stokActionPerformed(evt);
            }
        });

        guncelle_butonu_stok.setText("İlaç Güncelle");
        guncelle_butonu_stok.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        guncelle_butonu_stok.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                guncelle_butonu_stokActionPerformed(evt);
            }
        });

        jLabel12.setFont(new java.awt.Font("SansSerif", 0, 18)); // NOI18N
        jLabel12.setText("İlaç Türü");

        silme_butonu_stok.setText("Stoktan İlaç Sil");
        silme_butonu_stok.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        silme_butonu_stok.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                silme_butonu_stokActionPerformed(evt);
            }
        });

        jLabel13.setFont(new java.awt.Font("SansSerif", 0, 18)); // NOI18N
        jLabel13.setText("Fiyat");

        jLabel14.setFont(new java.awt.Font("SansSerif", 0, 18)); // NOI18N
        jLabel14.setText("Adet");

        ilac_tablosu.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "İsim", "Barkod No", "İlaç Türü", "Fiyat", "Adet Durumu"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        ilac_tablosu.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                ilac_tablosuMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(ilac_tablosu);
        if (ilac_tablosu.getColumnModel().getColumnCount() > 0) {
            ilac_tablosu.getColumnModel().getColumn(0).setResizable(false);
            ilac_tablosu.getColumnModel().getColumn(1).setResizable(false);
            ilac_tablosu.getColumnModel().getColumn(1).setPreferredWidth(30);
            ilac_tablosu.getColumnModel().getColumn(2).setResizable(false);
            ilac_tablosu.getColumnModel().getColumn(3).setResizable(false);
            ilac_tablosu.getColumnModel().getColumn(3).setPreferredWidth(30);
            ilac_tablosu.getColumnModel().getColumn(4).setResizable(false);
            ilac_tablosu.getColumnModel().getColumn(4).setPreferredWidth(30);
        }

        javax.swing.GroupLayout ilac_stok_sayfaLayout = new javax.swing.GroupLayout(ilac_stok_sayfa);
        ilac_stok_sayfa.setLayout(ilac_stok_sayfaLayout);
        ilac_stok_sayfaLayout.setHorizontalGroup(
            ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(ilac_stok_ust, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                        .addComponent(jScrollPane1)
                        .addContainerGap())
                    .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                        .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jSeparator4)
                            .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                                .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                        .addComponent(jSeparator2, javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(jLabel7, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                    .addComponent(jLabel9))
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                                .addGap(26, 26, 26)
                                .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(arama_cubugu_admin)))
                        .addContainerGap())
                    .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                        .addGap(40, 40, 40)
                        .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, ilac_stok_sayfaLayout.createSequentialGroup()
                                .addComponent(jLabel11)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(isim_alani_stok, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, ilac_stok_sayfaLayout.createSequentialGroup()
                                .addComponent(jLabel12, javax.swing.GroupLayout.PREFERRED_SIZE, 74, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tur_alani_stok, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, ilac_stok_sayfaLayout.createSequentialGroup()
                                .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(jLabel13)
                                    .addComponent(jLabel14))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(fiyat_alani_stok, javax.swing.GroupLayout.DEFAULT_SIZE, 162, Short.MAX_VALUE)
                                    .addComponent(adet_alani_stok))))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 10, Short.MAX_VALUE)
                        .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(mesaj_alani, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 216, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addComponent(silme_butonu_stok, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 130, Short.MAX_VALUE)
                                .addComponent(guncelle_butonu_stok, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(ekle_buton_stok, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                        .addGap(21, 21, 21))))
        );
        ilac_stok_sayfaLayout.setVerticalGroup(
            ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                .addComponent(ilac_stok_ust, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(11, 11, 11)
                .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(arama_cubugu_admin, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel7)
                .addGap(2, 2, 2)
                .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 219, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel9, javax.swing.GroupLayout.PREFERRED_SIZE, 22, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator4, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                        .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel11, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(isim_alani_stok, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(ekle_buton_stok))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel12, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(tur_alani_stok, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(fiyat_alani_stok, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel13, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(ilac_stok_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(adet_alani_stok, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel14, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(26, 26, 26))
                    .addGroup(ilac_stok_sayfaLayout.createSequentialGroup()
                        .addGap(46, 46, 46)
                        .addComponent(guncelle_butonu_stok)
                        .addGap(29, 29, 29)
                        .addComponent(silme_butonu_stok)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(mesaj_alani, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        musteri_goruntule_sayfasi.setBackground(new java.awt.Color(255, 255, 255));

        musteri_goruntule_ust.setBackground(new java.awt.Color(255, 22, 22));
        musteri_goruntule_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout musteri_goruntule_ustLayout = new javax.swing.GroupLayout(musteri_goruntule_ust);
        musteri_goruntule_ust.setLayout(musteri_goruntule_ustLayout);
        musteri_goruntule_ustLayout.setHorizontalGroup(
            musteri_goruntule_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 537, Short.MAX_VALUE)
        );
        musteri_goruntule_ustLayout.setVerticalGroup(
            musteri_goruntule_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 26, Short.MAX_VALUE)
        );

        hosgeldin_ust2.setBackground(new java.awt.Color(255, 22, 22));
        hosgeldin_ust2.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout hosgeldin_ust2Layout = new javax.swing.GroupLayout(hosgeldin_ust2);
        hosgeldin_ust2.setLayout(hosgeldin_ust2Layout);
        hosgeldin_ust2Layout.setHorizontalGroup(
            hosgeldin_ust2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 537, Short.MAX_VALUE)
        );
        hosgeldin_ust2Layout.setVerticalGroup(
            hosgeldin_ust2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 28, Short.MAX_VALUE)
        );

        musteriler_tablosu.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Eczane İsim", "Telefon No", "Adres", "Eczane No"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane2.setViewportView(musteriler_tablosu);
        if (musteriler_tablosu.getColumnModel().getColumnCount() > 0) {
            musteriler_tablosu.getColumnModel().getColumn(0).setResizable(false);
            musteriler_tablosu.getColumnModel().getColumn(1).setResizable(false);
            musteriler_tablosu.getColumnModel().getColumn(2).setResizable(false);
            musteriler_tablosu.getColumnModel().getColumn(3).setResizable(false);
            musteriler_tablosu.getColumnModel().getColumn(3).setPreferredWidth(20);
        }

        arama_cubugu_musteri.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                arama_cubugu_musteriFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                arama_cubugu_musteriFocusLost(evt);
            }
        });
        arama_cubugu_musteri.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                arama_cubugu_musteriMouseClicked(evt);
            }
        });
        arama_cubugu_musteri.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                arama_cubugu_musteriKeyReleased(evt);
            }
        });

        jLabel20.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel20.setText("Ara:");

        jLabel21.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel21.setText("Müşteriler");

        javax.swing.GroupLayout musteri_goruntule_sayfasiLayout = new javax.swing.GroupLayout(musteri_goruntule_sayfasi);
        musteri_goruntule_sayfasi.setLayout(musteri_goruntule_sayfasiLayout);
        musteri_goruntule_sayfasiLayout.setHorizontalGroup(
            musteri_goruntule_sayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(musteri_goruntule_ust, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(hosgeldin_ust2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, musteri_goruntule_sayfasiLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(musteri_goruntule_sayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(musteri_goruntule_sayfasiLayout.createSequentialGroup()
                        .addComponent(jLabel20, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(arama_cubugu_musteri, javax.swing.GroupLayout.PREFERRED_SIZE, 419, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(musteri_goruntule_sayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, musteri_goruntule_sayfasiLayout.createSequentialGroup()
                            .addGap(6, 6, 6)
                            .addComponent(jSeparator5, javax.swing.GroupLayout.PREFERRED_SIZE, 452, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addComponent(jLabel21, javax.swing.GroupLayout.PREFERRED_SIZE, 95, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jSeparator6, javax.swing.GroupLayout.PREFERRED_SIZE, 76, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(40, 40, 40))
        );
        musteri_goruntule_sayfasiLayout.setVerticalGroup(
            musteri_goruntule_sayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(musteri_goruntule_sayfasiLayout.createSequentialGroup()
                .addComponent(musteri_goruntule_ust, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(26, 26, 26)
                .addGroup(musteri_goruntule_sayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(arama_cubugu_musteri, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel20, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(5, 5, 5)
                .addComponent(jSeparator5, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel21, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator6, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(2, 2, 2)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 360, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 51, Short.MAX_VALUE)
                .addComponent(hosgeldin_ust2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        siparis_goruntule_sayfa.setBackground(new java.awt.Color(255, 255, 255));

        siparis_goruntule_ust.setBackground(new java.awt.Color(255, 22, 22));
        siparis_goruntule_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout siparis_goruntule_ustLayout = new javax.swing.GroupLayout(siparis_goruntule_ust);
        siparis_goruntule_ust.setLayout(siparis_goruntule_ustLayout);
        siparis_goruntule_ustLayout.setHorizontalGroup(
            siparis_goruntule_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 537, Short.MAX_VALUE)
        );
        siparis_goruntule_ustLayout.setVerticalGroup(
            siparis_goruntule_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 26, Short.MAX_VALUE)
        );

        jPanel5.setBackground(new java.awt.Color(255, 22, 22));

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 28, Short.MAX_VALUE)
        );

        siparis_detay_tamamlanmamis.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "İlaç İsim", "Adet", "Tutar"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane3.setViewportView(siparis_detay_tamamlanmamis);
        if (siparis_detay_tamamlanmamis.getColumnModel().getColumnCount() > 0) {
            siparis_detay_tamamlanmamis.getColumnModel().getColumn(1).setResizable(false);
            siparis_detay_tamamlanmamis.getColumnModel().getColumn(1).setPreferredWidth(25);
            siparis_detay_tamamlanmamis.getColumnModel().getColumn(2).setResizable(false);
            siparis_detay_tamamlanmamis.getColumnModel().getColumn(2).setPreferredWidth(25);
        }

        tamamlanmamis_siparisler.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Eczane İsim", "Sipariş No", "Tutar"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tamamlanmamis_siparisler.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tamamlanmamis_siparislerMouseClicked(evt);
            }
        });
        jScrollPane4.setViewportView(tamamlanmamis_siparisler);
        if (tamamlanmamis_siparisler.getColumnModel().getColumnCount() > 0) {
            tamamlanmamis_siparisler.getColumnModel().getColumn(0).setResizable(false);
            tamamlanmamis_siparisler.getColumnModel().getColumn(1).setResizable(false);
            tamamlanmamis_siparisler.getColumnModel().getColumn(1).setPreferredWidth(35);
            tamamlanmamis_siparisler.getColumnModel().getColumn(2).setResizable(false);
            tamamlanmamis_siparisler.getColumnModel().getColumn(2).setPreferredWidth(35);
        }

        jLabel5.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel5.setText("Tamamlanmamış Siparişler");

        jLabel15.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel15.setText("Tamamlanmamış Sipariş Detayı");

        siparisigonder_butonu.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        siparisigonder_butonu.setText("Siparişi Gönder");
        siparisigonder_butonu.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        siparisigonder_butonu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                siparisigonder_butonuActionPerformed(evt);
            }
        });

        jLabel22.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel22.setText("Tamamlanmış Siparişler");

        jLabel23.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel23.setText("Tamamlanmış Sipariş Detayı");

        tamamlanmis_siparisler.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Eczane İsim", "Sipariş No", "Tutar"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tamamlanmis_siparisler.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tamamlanmis_siparislerMouseClicked(evt);
            }
        });
        jScrollPane7.setViewportView(tamamlanmis_siparisler);
        if (tamamlanmis_siparisler.getColumnModel().getColumnCount() > 0) {
            tamamlanmis_siparisler.getColumnModel().getColumn(0).setResizable(false);
            tamamlanmis_siparisler.getColumnModel().getColumn(1).setResizable(false);
            tamamlanmis_siparisler.getColumnModel().getColumn(1).setPreferredWidth(35);
            tamamlanmis_siparisler.getColumnModel().getColumn(2).setResizable(false);
            tamamlanmis_siparisler.getColumnModel().getColumn(2).setPreferredWidth(35);
        }

        siparis_detay_tamamlanmis.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "İlaç İsim", "Adet", "Tutar"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane5.setViewportView(siparis_detay_tamamlanmis);
        if (siparis_detay_tamamlanmis.getColumnModel().getColumnCount() > 0) {
            siparis_detay_tamamlanmis.getColumnModel().getColumn(1).setResizable(false);
            siparis_detay_tamamlanmis.getColumnModel().getColumn(1).setPreferredWidth(25);
            siparis_detay_tamamlanmis.getColumnModel().getColumn(2).setResizable(false);
            siparis_detay_tamamlanmis.getColumnModel().getColumn(2).setPreferredWidth(25);
        }

        jLabel24.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel24.setText("Toplam Kazanç:");

        toplam_kazanc.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);

        javax.swing.GroupLayout siparis_goruntule_sayfaLayout = new javax.swing.GroupLayout(siparis_goruntule_sayfa);
        siparis_goruntule_sayfa.setLayout(siparis_goruntule_sayfaLayout);
        siparis_goruntule_sayfaLayout.setHorizontalGroup(
            siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(siparis_goruntule_ust, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                .addGap(15, 15, 15)
                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jSeparator7)
                    .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                        .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel5)
                            .addComponent(jLabel22))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, siparis_goruntule_sayfaLayout.createSequentialGroup()
                                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 237, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel23, javax.swing.GroupLayout.PREFERRED_SIZE, 227, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(15, 15, 15))
                            .addComponent(jLabel15, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 252, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, siparis_goruntule_sayfaLayout.createSequentialGroup()
                        .addGap(53, 53, 53)
                        .addComponent(siparisigonder_butonu, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(30, 30, 30)
                        .addComponent(uyari_gonderi, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, siparis_goruntule_sayfaLayout.createSequentialGroup()
                        .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                                .addComponent(jLabel24)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(toplam_kazanc, javax.swing.GroupLayout.PREFERRED_SIZE, 113, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(6, 6, 6))
                            .addComponent(jScrollPane7, javax.swing.GroupLayout.PREFERRED_SIZE, 237, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 237, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(14, 14, 14)))
                .addContainerGap())
            .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                    .addGap(16, 16, 16)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 237, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(284, Short.MAX_VALUE)))
        );
        siparis_goruntule_sayfaLayout.setVerticalGroup(
            siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                .addComponent(siparis_goruntule_ust, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jLabel15))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 180, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(siparisigonder_butonu, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(uyari_gonderi, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 11, Short.MAX_VALUE)
                .addComponent(jSeparator7, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel22)
                    .addComponent(jLabel23))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane7, javax.swing.GroupLayout.DEFAULT_SIZE, 175, Short.MAX_VALUE)
                    .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel24, javax.swing.GroupLayout.DEFAULT_SIZE, 24, Short.MAX_VALUE)
                    .addComponent(toplam_kazanc, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                    .addGap(71, 71, 71)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 180, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(334, Short.MAX_VALUE)))
        );

        hosgeldiniz.setBackground(new java.awt.Color(255, 255, 255));

        hosgeldin_ust.setBackground(new java.awt.Color(255, 22, 22));
        hosgeldin_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout hosgeldin_ustLayout = new javax.swing.GroupLayout(hosgeldin_ust);
        hosgeldin_ust.setLayout(hosgeldin_ustLayout);
        hosgeldin_ustLayout.setHorizontalGroup(
            hosgeldin_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 537, Short.MAX_VALUE)
        );
        hosgeldin_ustLayout.setVerticalGroup(
            hosgeldin_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 34, Short.MAX_VALUE)
        );

        jPanel6.setBackground(new java.awt.Color(255, 22, 22));
        jPanel6.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout jPanel6Layout = new javax.swing.GroupLayout(jPanel6);
        jPanel6.setLayout(jPanel6Layout);
        jPanel6Layout.setHorizontalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jPanel6Layout.setVerticalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 28, Short.MAX_VALUE)
        );

        jLabel17.setFont(new java.awt.Font("Segoe Print", 1, 14)); // NOI18N
        jLabel17.setForeground(new java.awt.Color(255, 22, 22));
        jLabel17.setText("“Sağlık, zenginlikten daha değerlidir.” - Aristoteles");

        jLabel18.setFont(new java.awt.Font("Segoe Print", 1, 14)); // NOI18N
        jLabel18.setForeground(new java.awt.Color(255, 22, 22));
        jLabel18.setText("“Sağlıklı bir beden, güçlü bir zihnin evidir.” - John Locke");

        jLabel19.setFont(new java.awt.Font("Segoe Print", 1, 14)); // NOI18N
        jLabel19.setForeground(new java.awt.Color(255, 22, 22));
        jLabel19.setText("“Sağlık, insanın yaşamındaki en büyük kazançtır.” - Virgil");

        javax.swing.GroupLayout hosgeldinizLayout = new javax.swing.GroupLayout(hosgeldiniz);
        hosgeldiniz.setLayout(hosgeldinizLayout);
        hosgeldinizLayout.setHorizontalGroup(
            hosgeldinizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(hosgeldin_ust, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, hosgeldinizLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(hosgeldinizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(hosgeldinizLayout.createSequentialGroup()
                        .addGap(21, 21, 21)
                        .addComponent(jLabel17, javax.swing.GroupLayout.PREFERRED_SIZE, 371, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jLabel18)
                    .addComponent(jLabel19, javax.swing.GroupLayout.PREFERRED_SIZE, 416, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(55, 55, 55))
        );
        hosgeldinizLayout.setVerticalGroup(
            hosgeldinizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(hosgeldinizLayout.createSequentialGroup()
                .addComponent(hosgeldin_ust, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(176, 176, 176)
                .addComponent(jLabel17, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel18, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel19, javax.swing.GroupLayout.PREFERRED_SIZE, 49, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 224, Short.MAX_VALUE)
                .addComponent(jPanel6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        javax.swing.GroupLayout admin_anasayfaLayout = new javax.swing.GroupLayout(admin_anasayfa);
        admin_anasayfa.setLayout(admin_anasayfaLayout);
        admin_anasayfaLayout.setHorizontalGroup(
            admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(ilac_stok_sayfa, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(siparis_goruntule_sayfa, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(musteri_goruntule_sayfasi, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(hosgeldiniz, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        admin_anasayfaLayout.setVerticalGroup(
            admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(ilac_stok_sayfa, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(siparis_goruntule_sayfa, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(musteri_goruntule_sayfasi, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(admin_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(hosgeldiniz, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(admin_anasayfa, javax.swing.GroupLayout.DEFAULT_SIZE, 537, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(admin_anasayfa, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents
    
    
    public void musterigoruntule(){
        
        musteritablosumodel.setRowCount(0);
        ArrayList<Musteri> musteriler= new ArrayList<Musteri>();
        
        
        musteriler = Sistem.musterileriGetir();
        
        if(musteriler!= null) {
            
            for(Musteri musteri :musteriler){
                
                Object [] eklenecek = {musteri.getIsim(),musteri.getTelefonno(),musteri.getAdres(),musteri.getEczaneno()};
                
                musteritablosumodel.addRow(eklenecek);
                
                
                
                
                
            }
            
        }
        
    }
    
    private void musteri_goruntuleMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_musteri_goruntuleMouseClicked
        // TODO add your handling code here:

        ilac_stok_sayfa.setVisible(false);
        hosgeldiniz.setVisible(false);
        siparis_goruntule_sayfa.setVisible(false);
        musteri_goruntule_sayfasi.setVisible(true);

        // bastigimizda renk alir

        ilac_stok_islemleri.setBackground(new Color(234,233,233));
        siparis_goruntule.setBackground(new Color(234,233,233));
        musteri_goruntule.setBackground(new Color(229,89,89));

    }//GEN-LAST:event_musteri_goruntuleMouseClicked

    private void siparis_goruntuleMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_siparis_goruntuleMouseClicked
        // TODO add your handling code here:

        ilac_stok_sayfa.setVisible(false);
        hosgeldiniz.setVisible(false);
        siparis_goruntule_sayfa.setVisible(true);
        musteri_goruntule_sayfasi.setVisible(false);
        
        // bastigimizda renk alir

        ilac_stok_islemleri.setBackground(new Color(234,233,233));
        siparis_goruntule.setBackground(new Color(229,89,89));
        musteri_goruntule.setBackground(new Color(234,233,233));

    }//GEN-LAST:event_siparis_goruntuleMouseClicked

    private void ilac_stok_islemleriMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ilac_stok_islemleriMouseClicked
        // TODO add your handling code here:

        ilac_stok_sayfa.setVisible(true);
        hosgeldiniz.setVisible(false);
        siparis_goruntule_sayfa.setVisible(false);
        musteri_goruntule_sayfasi.setVisible(false);

        // bastigimizda renk alir

        ilac_stok_islemleri.setBackground(new Color(229,89,89));
        siparis_goruntule.setBackground(new Color(234,233,233));
        musteri_goruntule.setBackground(new Color(234,233,233));

    }//GEN-LAST:event_ilac_stok_islemleriMouseClicked

    private void arama_cubugu_adminKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_arama_cubugu_adminKeyReleased
        // TODO add your handling code here:

        String ara =arama_cubugu_admin.getText();

        dinamikAra(ara);

    }//GEN-LAST:event_arama_cubugu_adminKeyReleased

    private void isim_alani_stokActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_isim_alani_stokActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_isim_alani_stokActionPerformed

    private void ekle_buton_stokActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ekle_buton_stokActionPerformed
        // TODO add your handling code here:
        mesaj_alani.setText("");
        String isim = isim_alani_stok.getText();
        String tur= tur_alani_stok.getText();
        String fiyat = fiyat_alani_stok.getText();
        String adet = adet_alani_stok.getText();
        
        
        ArrayList<Ilac> ilaclar = new ArrayList<Ilac>();
        boolean bulundu= false;
        ilaclar = Sistem.ilaclariGetir();
        
        if(ilaclar != null){
            if(isim.isEmpty() || tur.isEmpty() || fiyat.isEmpty() || adet.isEmpty()){
                mesaj_alani.setText("Boş alan bırakmayınız...");
                
            }
            else{
                for(Ilac ilac: ilaclar){
                
                    if(ilac.getIsim().compareTo(isim)==0){
                        
                        mesaj_alani.setText("Bu ilaç zaten bulunmakta...");
                        
                        bulundu = true;
                    }
                    
                
                
                }
                if(!bulundu){
                    
                    Sistem.ilacEkle(isim,tur,fiyat,adet);

                    ilacGoruntule();
                    mesaj_alani.setText("Yeni ilaç başarıyla eklendi...");
                    
                    
                }
                
                
            }
            
            
                
        }
        
        

    }//GEN-LAST:event_ekle_buton_stokActionPerformed

    private void guncelle_butonu_stokActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_guncelle_butonu_stokActionPerformed
        // TODO add your handling code here:

        String isim=isim_alani_stok.getText();
    String tur=tur_alani_stok.getText();
    String fiyat=fiyat_alani_stok.getText();
    String adet=adet_alani_stok.getText();

    if(isim.isEmpty() || tur.isEmpty() || fiyat.isEmpty() || adet.isEmpty()){
        mesaj_alani.setText("Lütfen tüm alanları doldurunuz...");
        return;
    }

    int selectedrow = ilac_tablosu.getSelectedRow();

    if(selectedrow==-1){

        if(model.getRowCount()== 0){
            mesaj_alani.setText("İlaç tablosu şuanda boş...");

        }else{

            mesaj_alani.setText("Lütfen güncellenecek bir ilaç seçiniz...");
        }

    }
    else{

        int barkodno = (int)model.getValueAt(selectedrow,1);

        Sistem.ilacGuncelle(barkodno,isim.toString(),tur.toString(),fiyat.toString(),adet.toString());

        ilacGoruntule();

        mesaj_alani.setText("İlaç başarıyla güncellendi");
        
        
        //sıfırlama
        
        isim_alani_stok.setText("");
        tur_alani_stok.setText("");
        fiyat_alani_stok.setText("");
        adet_alani_stok.setText("");
        

    }

    }//GEN-LAST:event_guncelle_butonu_stokActionPerformed

    private void silme_butonu_stokActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_silme_butonu_stokActionPerformed
        // TODO add your handling code here:

        mesaj_alani.setText("");
        String isim = isim_alani_stok.getText();
        String tur= tur_alani_stok.getText();
        String fiyat = fiyat_alani_stok.getText();
        String adet = adet_alani_stok.getText();
        
        
        if(isim_alani_stok.getText().isEmpty() ||tur_alani_stok.getText().isEmpty() ||fiyat_alani_stok.getText().isEmpty() ||adet_alani_stok.getText().isEmpty()){
            
            mesaj_alani.setText("Boş alan bırakmayınız...");
            
            
        }
        else{
            
            ArrayList<Ilac> ilaclar = new ArrayList<Ilac>();
            boolean bulundu= false;
            ilaclar = Sistem.ilaclariGetir();

            for(Ilac ilac: ilaclar){

                if(ilac.getIsim().compareTo(isim)==0 && ilac.getTur().compareTo(tur)==0){
                    Sistem.ilacSil(ilac.getBarkodno());

                    ilacGoruntule();

                    mesaj_alani.setText("İlaç başarıyla silindi");   


                    bulundu = true;
                    break;
                }



            }
            if(!bulundu){

                mesaj_alani.setText("Bu ilaç bulunmamaktadır..");

            }
        }
        
        
        
        
        
        
        
        
        

        

        

    }//GEN-LAST:event_silme_butonu_stokActionPerformed

    private void ilac_tablosuMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ilac_tablosuMouseClicked
        // TODO add your handling code here:

        int selectedrow=ilac_tablosu.getSelectedRow();

        isim_alani_stok.setText(model.getValueAt(selectedrow, 0).toString());
        tur_alani_stok.setText(model.getValueAt(selectedrow, 2).toString());
        fiyat_alani_stok.setText(model.getValueAt(selectedrow, 3).toString());
        adet_alani_stok.setText(model.getValueAt(selectedrow, 4).toString());

    }//GEN-LAST:event_ilac_tablosuMouseClicked

    private void arama_cubugu_adminFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_arama_cubugu_adminFocusLost
        // TODO add your handling code here:
        
        
        if(arama_cubugu_admin.getText().isEmpty()){
            arama_cubugu_admin.setForeground(Color.gray);
            arama_cubugu_admin.setText("Aramak için tıklayınız.. örn Parol");
            
        }
        
    }//GEN-LAST:event_arama_cubugu_adminFocusLost

    private void arama_cubugu_adminFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_arama_cubugu_adminFocusGained
        // TODO add your handling code here:
        
        if(arama_cubugu_admin.getText().equals("Aramak için tıklayınız.. örn Parol")){
            arama_cubugu_admin.setForeground(Color.BLACK);
            arama_cubugu_admin.setText("");
            
        }
        
    }//GEN-LAST:event_arama_cubugu_adminFocusGained

    private void cikis_adminMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cikis_adminMouseClicked
        // TODO add your handling code here:
        
        
        new GirisAyrimi().setVisible(true);
        
        this.dispose();
        
        
        
    }//GEN-LAST:event_cikis_adminMouseClicked

    public void dinamikAramusteri(String ara){
        
        TableRowSorter<DefaultTableModel> tr = new TableRowSorter<DefaultTableModel>(musteritablosumodel);
        
        musteriler_tablosu.setRowSorter(tr);
        
        String aramakucukharf= ara.toLowerCase();
        tr.setRowFilter(RowFilter.regexFilter("(?i)"+aramakucukharf));
        
        
    }
    
    
    
    private void arama_cubugu_musteriKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_arama_cubugu_musteriKeyReleased
        // TODO add your handling code here:
        String ara_musteri= arama_cubugu_musteri.getText();
        
        dinamikAramusteri(ara_musteri);
        
        
        
        
    }//GEN-LAST:event_arama_cubugu_musteriKeyReleased

    private void arama_cubugu_musteriFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_arama_cubugu_musteriFocusGained
        // TODO add your handling code here:
        
        if(arama_cubugu_musteri.getText().equals("Aramak için tıklayınız.. örn Çiçek Eczane")){
            arama_cubugu_musteri.setForeground(Color.BLACK);
            arama_cubugu_musteri.setText("");
            
        }
        
        
        
    }//GEN-LAST:event_arama_cubugu_musteriFocusGained

    private void arama_cubugu_musteriFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_arama_cubugu_musteriFocusLost
        // TODO add your handling code here:
        
        if(arama_cubugu_musteri.getText().isEmpty()){
            arama_cubugu_musteri.setForeground(Color.gray);
            arama_cubugu_musteri.setText("Aramak için tıklayınız.. örn Çiçek Eczane");
            
        }
        
        
    }//GEN-LAST:event_arama_cubugu_musteriFocusLost

    private void arama_cubugu_musteriMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_arama_cubugu_musteriMouseClicked
        // TODO add your handling code here:
        
        arama_cubugu_musteri.setText("");
        arama_cubugu_musteri.setForeground(Color.BLACK);
        
        
    }//GEN-LAST:event_arama_cubugu_musteriMouseClicked

    private void siparisigonder_butonuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_siparisigonder_butonuActionPerformed
        // TODO add your handling code here:
        
        
        
        int row=tamamlanmamis_siparisler.getSelectedRow();
        if(row >= 0){
            
            int siparisno=Integer.parseInt(tamamlanmamis_siparislermodel.getValueAt(row, 1).toString());
            Sistem.siparisGonder(siparisno);
            
            
            
            siparisGoruntule();
            uyari_gonderi.setText("Sipariş gönderildi..");
    
        }
        else{
            
            uyari_gonderi.setText("Sipariş seçiniz..");
            
            
            
            
            
        }
        
        
        
        
        
        
        
        
        
        
    }//GEN-LAST:event_siparisigonder_butonuActionPerformed

    private void tamamlanmamis_siparislerMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tamamlanmamis_siparislerMouseClicked
        // TODO add your handling code here:
        int row = tamamlanmamis_siparisler.getSelectedRow();
        
        if(row >= 0){
            siparis_detay_tamamlanmamismodel.setRowCount(0);
            
            
            
            
            
            int siparisno=Integer.parseInt(tamamlanmamis_siparislermodel.getValueAt(row, 1).toString());
            String siparis=Sistem.siparisGetir(siparisno);
            
            
            String[] siparisbilgileri = siparis.split(",");
            
            for(int i=0;i<siparisbilgileri.length;i=i+3){
                
                Object[] eklenecek= {siparisbilgileri[i],siparisbilgileri[i+1],siparisbilgileri[i+2]};
                siparis_detay_tamamlanmamismodel.addRow(eklenecek);
                
                
                
                
            }
            
            
            
            
        }
        
        
        
        
    }//GEN-LAST:event_tamamlanmamis_siparislerMouseClicked

    private void tamamlanmis_siparislerMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tamamlanmis_siparislerMouseClicked
        // TODO add your handling code here:
        
        int row = tamamlanmis_siparisler.getSelectedRow();
        
        if(row >= 0){
            siparis_detay_tamamlanmismodel.setRowCount(0);
            
            
            
            
            
            int siparisno=Integer.parseInt(tamamlanmis_siparislermodel.getValueAt(row, 1).toString());
            String siparis=Sistem.siparisGetir(siparisno);
            
            
            String[] siparisbilgileri = siparis.split(",");
            
            for(int i=0;i<siparisbilgileri.length;i=i+3){
                
                Object[] eklenecek= {siparisbilgileri[i],siparisbilgileri[i+1],siparisbilgileri[i+2]};
                siparis_detay_tamamlanmismodel.addRow(eklenecek);
                
                
                
                
            }
            
            
            
            
        }
        
        
        
        
        
        
        
    }//GEN-LAST:event_tamamlanmis_siparislerMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(AdminMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AdminMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AdminMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AdminMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        
        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AdminMenu().setVisible(true);
            }
        });
        
        
        
        
        
        
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField adet_alani_stok;
    private javax.swing.JPanel admin_anasayfa;
    private javax.swing.JTextField arama_cubugu_admin;
    private javax.swing.JTextField arama_cubugu_musteri;
    private javax.swing.JPanel cikis_admin;
    private javax.swing.JButton ekle_buton_stok;
    private javax.swing.JTextField fiyat_alani_stok;
    private javax.swing.JButton guncelle_butonu_stok;
    private javax.swing.JPanel hosgeldin_ust;
    private javax.swing.JPanel hosgeldin_ust2;
    private javax.swing.JPanel hosgeldiniz;
    private javax.swing.JPanel ilac_stok_islemleri;
    private javax.swing.JPanel ilac_stok_sayfa;
    private javax.swing.JPanel ilac_stok_ust;
    private javax.swing.JTable ilac_tablosu;
    private javax.swing.JTextField isim_alani_stok;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel19;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel20;
    private javax.swing.JLabel jLabel21;
    private javax.swing.JLabel jLabel22;
    private javax.swing.JLabel jLabel23;
    private javax.swing.JLabel jLabel24;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenu jMenu3;
    private javax.swing.JMenu jMenu4;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanel7;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPane5;
    private javax.swing.JScrollPane jScrollPane7;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSeparator jSeparator2;
    private javax.swing.JSeparator jSeparator3;
    private javax.swing.JSeparator jSeparator4;
    private javax.swing.JSeparator jSeparator5;
    private javax.swing.JSeparator jSeparator6;
    private javax.swing.JSeparator jSeparator7;
    private javax.swing.JLabel mesaj_alani;
    private javax.swing.JPanel musteri_goruntule;
    private javax.swing.JPanel musteri_goruntule_sayfasi;
    private javax.swing.JPanel musteri_goruntule_ust;
    private javax.swing.JTable musteriler_tablosu;
    private javax.swing.JButton silme_butonu_stok;
    private javax.swing.JTable siparis_detay_tamamlanmamis;
    private javax.swing.JTable siparis_detay_tamamlanmis;
    private javax.swing.JPanel siparis_goruntule;
    private javax.swing.JPanel siparis_goruntule_sayfa;
    private javax.swing.JPanel siparis_goruntule_ust;
    private javax.swing.JButton siparisigonder_butonu;
    private javax.swing.JTable tamamlanmamis_siparisler;
    private javax.swing.JTable tamamlanmis_siparisler;
    private javax.swing.JLabel toplam_kazanc;
    private javax.swing.JTextField tur_alani_stok;
    private javax.swing.JLabel uyari_gonderi;
    // End of variables declaration//GEN-END:variables
}
