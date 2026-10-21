
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
public class MusteriMenu extends javax.swing.JFrame {

        
    private Musteri eczane;

    DefaultTableModel musteri_siparis_model;
    DefaultTableModel musteri_siparis_detay_model;




    private int initialX, initialY;
    /**
     * Creates new form yonetici_islem_form
     */
    DefaultTableModel model;
    DefaultTableModel sepetmodel;
       
    /**
     * Creates new form musteri_menu
     */
    public MusteriMenu(String kullanici_adi) {
        
        initComponents();
        
        ImageIcon icon = new ImageIcon("icon5.png");
        Image image = icon.getImage();
        setIconImage(image);
        setTitle("Müşteri Bilgi Ekranı");
        
        model = (DefaultTableModel)ilac_tablosu.getModel();
        sepetmodel = (DefaultTableModel)sepet.getModel();
        ilacGoruntule();
        
        
        siparis_olustur_sayfa.setVisible(false);
        hosgeldiniz.setVisible(true);
        siparis_goruntule_sayfa.setVisible(false);
        eczane_bilgilerisayfasi.setVisible(false);
        
        arama_cubugu_musteri.setForeground(Color.GRAY);
        arama_cubugu_musteri.setText("Aramak için tıklayınız.. örn Parol");
        
        musteri_siparis_model =(DefaultTableModel)musteri_siparisim.getModel();
        musteri_siparis_detay_model =(DefaultTableModel)musteri_siparisim_detay.getModel();
        
        
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
        
        eczane_bilgileri_ust.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                // Fare basıldığında, JFrame'in başlangıç konumunu al
                initialX = e.getX();
                initialY = e.getY();
            }
        });


        eczane_bilgileri_ust.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                // Fare sürüklendiğinde, JFrame'in konumunu güncelle
                int newX = getLocation().x + e.getX() - initialX;
                int newY = getLocation().y + e.getY() - initialY;
                setLocation(newX, newY);
            }
        });
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        siparis_olustur_ust.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                // Fare basıldığında, JFrame'in başlangıç konumunu al
                initialX = e.getX();
                initialY = e.getY();
            }
        });


        siparis_olustur_ust.addMouseMotionListener(new MouseAdapter() {
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
        
        
        adet_mesaji.setForeground(Color.GRAY);
        adet_mesaji.setText("Ürün seçiniz");
        adet_mesaji.setEditable(false);
        
        
        
        
        sepet.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
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
        sepet.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = sepet.getSelectedRow();
                    // Repaint the table to apply color changes
                    sepet.repaint();
                }
            }
        });
        
        
        
        toplam_tutar.setText("0₺");
        
        
        eczane = Sistem.musteriBul(kullanici_adi);
        
        //
        
        musteri_siparisim.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
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
        musteri_siparisim.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = musteri_siparisim.getSelectedRow();
                    // Repaint the table to apply color changes
                    musteri_siparisim.repaint();
                }
            }
        });
        
        
        //
        
        musteri_siparisim_detay.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
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
        musteri_siparisim_detay.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = musteri_siparisim_detay.getSelectedRow();
                    // Repaint the table to apply color changes
                    musteri_siparisim_detay.repaint();
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

        solpanel = new javax.swing.JPanel();
        jSeparator2 = new javax.swing.JSeparator();
        siparis_olustur_musteri = new javax.swing.JPanel();
        jLabel4 = new javax.swing.JLabel();
        siparis_goruntule_musteri = new javax.swing.JPanel();
        jLabel5 = new javax.swing.JLabel();
        eczane_bilgilerim = new javax.swing.JPanel();
        jLabel6 = new javax.swing.JLabel();
        cikis_musteri = new javax.swing.JPanel();
        jLabel16 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        musteri_anasayfa = new javax.swing.JPanel();
        siparis_olustur_sayfa = new javax.swing.JPanel();
        arama_cubugu_musteri = new javax.swing.JTextField();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jSeparator3 = new javax.swing.JSeparator();
        siparis_olustur_ust = new javax.swing.JPanel();
        jPanel4 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        ilac_tablosu = new javax.swing.JTable();
        jScrollPane3 = new javax.swing.JScrollPane();
        sepet = new javax.swing.JTable();
        jLabel7 = new javax.swing.JLabel();
        jSeparator4 = new javax.swing.JSeparator();
        jLabel10 = new javax.swing.JLabel();
        toplam_tutar = new javax.swing.JLabel();
        adet_mesaji = new javax.swing.JTextField();
        sepet_ekle_buton = new javax.swing.JButton();
        sepetten_sil_buton = new javax.swing.JButton();
        siparis_onay_buton = new javax.swing.JButton();
        uyari_mesaj = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        eczane_bilgilerisayfasi = new javax.swing.JPanel();
        eczane_bilgileri_ust = new javax.swing.JPanel();
        siparis_olustur_ust4 = new javax.swing.JPanel();
        jLabel12 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        eczane_bilgi_guncelle_buton = new javax.swing.JButton();
        parola_text = new javax.swing.JTextField();
        eczane_no_text = new javax.swing.JTextField();
        telefonno_text = new javax.swing.JTextField();
        adres_text = new javax.swing.JTextField();
        kullanici_adi_text = new javax.swing.JTextField();
        jLabel20 = new javax.swing.JLabel();
        uyari_text = new javax.swing.JLabel();
        siparis_goruntule_sayfa = new javax.swing.JPanel();
        siparis_goruntule_ust = new javax.swing.JPanel();
        siparis_olustur_ust2 = new javax.swing.JPanel();
        jScrollPane4 = new javax.swing.JScrollPane();
        musteri_siparisim = new javax.swing.JTable();
        jScrollPane5 = new javax.swing.JScrollPane();
        musteri_siparisim_detay = new javax.swing.JTable();
        jLabel2 = new javax.swing.JLabel();
        jSeparator1 = new javax.swing.JSeparator();
        jLabel3 = new javax.swing.JLabel();
        jSeparator5 = new javax.swing.JSeparator();
        hosgeldiniz = new javax.swing.JPanel();
        hosgeldin_ust = new javax.swing.JPanel();
        jPanel6 = new javax.swing.JPanel();
        jLabel17 = new javax.swing.JLabel();
        jLabel18 = new javax.swing.JLabel();
        jLabel19 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);

        solpanel.setBackground(new java.awt.Color(217, 217, 217));

        siparis_olustur_musteri.setBackground(new java.awt.Color(234, 233, 233));
        siparis_olustur_musteri.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        siparis_olustur_musteri.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                siparis_olustur_musteriMouseClicked(evt);
            }
        });

        jLabel4.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel4.setText("Sipariş Oluştur");

        javax.swing.GroupLayout siparis_olustur_musteriLayout = new javax.swing.GroupLayout(siparis_olustur_musteri);
        siparis_olustur_musteri.setLayout(siparis_olustur_musteriLayout);
        siparis_olustur_musteriLayout.setHorizontalGroup(
            siparis_olustur_musteriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(siparis_olustur_musteriLayout.createSequentialGroup()
                .addGap(36, 36, 36)
                .addComponent(jLabel4)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        siparis_olustur_musteriLayout.setVerticalGroup(
            siparis_olustur_musteriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, siparis_olustur_musteriLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, 35, Short.MAX_VALUE)
                .addContainerGap())
        );

        siparis_goruntule_musteri.setBackground(new java.awt.Color(234, 233, 233));
        siparis_goruntule_musteri.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        siparis_goruntule_musteri.setPreferredSize(new java.awt.Dimension(169, 39));
        siparis_goruntule_musteri.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                siparis_goruntule_musteriMouseClicked(evt);
            }
        });

        jLabel5.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel5.setText("Sipariş Görüntüle");

        javax.swing.GroupLayout siparis_goruntule_musteriLayout = new javax.swing.GroupLayout(siparis_goruntule_musteri);
        siparis_goruntule_musteri.setLayout(siparis_goruntule_musteriLayout);
        siparis_goruntule_musteriLayout.setHorizontalGroup(
            siparis_goruntule_musteriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(siparis_goruntule_musteriLayout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addComponent(jLabel5)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        siparis_goruntule_musteriLayout.setVerticalGroup(
            siparis_goruntule_musteriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, siparis_goruntule_musteriLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel5, javax.swing.GroupLayout.DEFAULT_SIZE, 32, Short.MAX_VALUE)
                .addContainerGap())
        );

        eczane_bilgilerim.setBackground(new java.awt.Color(234, 233, 233));
        eczane_bilgilerim.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        eczane_bilgilerim.setPreferredSize(new java.awt.Dimension(169, 48));
        eczane_bilgilerim.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                eczane_bilgilerimMouseClicked(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel6.setText("Eczane Bilgilerim");

        javax.swing.GroupLayout eczane_bilgilerimLayout = new javax.swing.GroupLayout(eczane_bilgilerim);
        eczane_bilgilerim.setLayout(eczane_bilgilerimLayout);
        eczane_bilgilerimLayout.setHorizontalGroup(
            eczane_bilgilerimLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(eczane_bilgilerimLayout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addComponent(jLabel6)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        eczane_bilgilerimLayout.setVerticalGroup(
            eczane_bilgilerimLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(eczane_bilgilerimLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel6, javax.swing.GroupLayout.DEFAULT_SIZE, 36, Short.MAX_VALUE)
                .addContainerGap())
        );

        cikis_musteri.setBackground(new java.awt.Color(234, 233, 233));
        cikis_musteri.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        cikis_musteri.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                cikis_musteriMouseClicked(evt);
            }
        });

        jLabel16.setFont(new java.awt.Font("Segoe UI", 0, 20)); // NOI18N
        jLabel16.setText("Çıkış");

        javax.swing.GroupLayout cikis_musteriLayout = new javax.swing.GroupLayout(cikis_musteri);
        cikis_musteri.setLayout(cikis_musteriLayout);
        cikis_musteriLayout.setHorizontalGroup(
            cikis_musteriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(cikis_musteriLayout.createSequentialGroup()
                .addGap(77, 77, 77)
                .addComponent(jLabel16)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        cikis_musteriLayout.setVerticalGroup(
            cikis_musteriLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(cikis_musteriLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel16, javax.swing.GroupLayout.DEFAULT_SIZE, 35, Short.MAX_VALUE)
                .addContainerGap())
        );

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/menu.png"))); // NOI18N

        javax.swing.GroupLayout solpanelLayout = new javax.swing.GroupLayout(solpanel);
        solpanel.setLayout(solpanelLayout);
        solpanelLayout.setHorizontalGroup(
            solpanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator2)
            .addComponent(cikis_musteri, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(eczane_bilgilerim, javax.swing.GroupLayout.DEFAULT_SIZE, 202, Short.MAX_VALUE)
            .addComponent(siparis_goruntule_musteri, javax.swing.GroupLayout.DEFAULT_SIZE, 202, Short.MAX_VALUE)
            .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 202, Short.MAX_VALUE)
            .addComponent(siparis_olustur_musteri, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        solpanelLayout.setVerticalGroup(
            solpanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(solpanelLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 128, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(siparis_olustur_musteri, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(siparis_goruntule_musteri, javax.swing.GroupLayout.PREFERRED_SIZE, 44, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(eczane_bilgilerim, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 108, Short.MAX_VALUE)
                .addComponent(cikis_musteri, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(105, 105, 105))
        );

        musteri_anasayfa.setBackground(new java.awt.Color(255, 255, 255));
        musteri_anasayfa.setPreferredSize(new java.awt.Dimension(544, 597));

        siparis_olustur_sayfa.setBackground(new java.awt.Color(255, 255, 255));

        arama_cubugu_musteri.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                arama_cubugu_musteriFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                arama_cubugu_musteriFocusLost(evt);
            }
        });
        arama_cubugu_musteri.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                arama_cubugu_musteriKeyReleased(evt);
            }
        });

        jLabel8.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel8.setText("Ara:");

        jLabel9.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel9.setText("Stok Durumu ve Liste");

        siparis_olustur_ust.setBackground(new java.awt.Color(255, 22, 22));
        siparis_olustur_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout siparis_olustur_ustLayout = new javax.swing.GroupLayout(siparis_olustur_ust);
        siparis_olustur_ust.setLayout(siparis_olustur_ustLayout);
        siparis_olustur_ustLayout.setHorizontalGroup(
            siparis_olustur_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        siparis_olustur_ustLayout.setVerticalGroup(
            siparis_olustur_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
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

        ilac_tablosu.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "İsim", "Barkod No", "İlaç Türü", "Fiyat", "Adet"
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
            ilac_tablosu.getColumnModel().getColumn(3).setPreferredWidth(35);
            ilac_tablosu.getColumnModel().getColumn(4).setResizable(false);
            ilac_tablosu.getColumnModel().getColumn(4).setPreferredWidth(35);
        }

        sepet.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "İsim", "Adet", "Tutar"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        sepet.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                sepetMouseClicked(evt);
            }
        });
        jScrollPane3.setViewportView(sepet);
        if (sepet.getColumnModel().getColumnCount() > 0) {
            sepet.getColumnModel().getColumn(0).setResizable(false);
            sepet.getColumnModel().getColumn(1).setResizable(false);
            sepet.getColumnModel().getColumn(1).setPreferredWidth(35);
            sepet.getColumnModel().getColumn(2).setResizable(false);
            sepet.getColumnModel().getColumn(2).setPreferredWidth(35);
        }

        jLabel7.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel7.setText("Sepet");

        jLabel10.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel10.setText("Toplam Tutar:");

        toplam_tutar.setFont(new java.awt.Font("Segoe UI", 0, 16)); // NOI18N
        toplam_tutar.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        toplam_tutar.setHorizontalTextPosition(javax.swing.SwingConstants.RIGHT);

        adet_mesaji.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                adet_mesajiFocusGained(evt);
            }
        });
        adet_mesaji.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                adet_mesajiActionPerformed(evt);
            }
        });

        sepet_ekle_buton.setText("Sepete Ekle");
        sepet_ekle_buton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        sepet_ekle_buton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sepet_ekle_butonActionPerformed(evt);
            }
        });

        sepetten_sil_buton.setText("Sepetten Sil");
        sepetten_sil_buton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        sepetten_sil_buton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sepetten_sil_butonActionPerformed(evt);
            }
        });

        siparis_onay_buton.setText("Siparişi Onayla");
        siparis_onay_buton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        siparis_onay_buton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                siparis_onay_butonActionPerformed(evt);
            }
        });

        uyari_mesaj.setForeground(new java.awt.Color(255, 0, 0));

        jLabel11.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel11.setText("Adet:");

        javax.swing.GroupLayout siparis_olustur_sayfaLayout = new javax.swing.GroupLayout(siparis_olustur_sayfa);
        siparis_olustur_sayfa.setLayout(siparis_olustur_sayfaLayout);
        siparis_olustur_sayfaLayout.setHorizontalGroup(
            siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(siparis_olustur_ust, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 532, Short.MAX_VALUE)
                    .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                        .addGap(26, 26, 26)
                        .addComponent(jLabel8, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(arama_cubugu_musteri))
                    .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                        .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                        .addGap(18, 18, 18)
                        .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                                .addComponent(jLabel11, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                    .addComponent(sepet_ekle_buton, javax.swing.GroupLayout.DEFAULT_SIZE, 124, Short.MAX_VALUE)
                                    .addComponent(adet_mesaji))
                                .addGap(12, 12, 12))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(siparis_onay_buton, javax.swing.GroupLayout.PREFERRED_SIZE, 124, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, siparis_olustur_sayfaLayout.createSequentialGroup()
                                    .addComponent(sepetten_sil_buton, javax.swing.GroupLayout.PREFERRED_SIZE, 124, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGap(12, 12, 12)))))
                    .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                        .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                .addComponent(jSeparator3, javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel9, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jSeparator4, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                                .addComponent(jLabel10, javax.swing.GroupLayout.PREFERRED_SIZE, 105, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(toplam_tutar, javax.swing.GroupLayout.PREFERRED_SIZE, 111, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(uyari_mesaj, javax.swing.GroupLayout.PREFERRED_SIZE, 268, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );
        siparis_olustur_sayfaLayout.setVerticalGroup(
            siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                .addComponent(siparis_olustur_ust, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(11, 11, 11)
                .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(arama_cubugu_musteri, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel9)
                .addGap(2, 2, 2)
                .addComponent(jSeparator3, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 175, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel7)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator4, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 178, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                        .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(adet_mesaji, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel11, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(13, 13, 13)
                        .addComponent(sepet_ekle_buton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(sepetten_sil_buton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(siparis_onay_buton)
                        .addGap(68, 68, 68)))
                .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(siparis_olustur_sayfaLayout.createSequentialGroup()
                        .addGroup(siparis_olustur_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel10)
                            .addComponent(toplam_tutar, javax.swing.GroupLayout.PREFERRED_SIZE, 22, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(uyari_mesaj, javax.swing.GroupLayout.PREFERRED_SIZE, 22, javax.swing.GroupLayout.PREFERRED_SIZE)))
        );

        eczane_bilgilerisayfasi.setBackground(new java.awt.Color(255, 255, 255));

        eczane_bilgileri_ust.setBackground(new java.awt.Color(255, 22, 22));
        eczane_bilgileri_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout eczane_bilgileri_ustLayout = new javax.swing.GroupLayout(eczane_bilgileri_ust);
        eczane_bilgileri_ust.setLayout(eczane_bilgileri_ustLayout);
        eczane_bilgileri_ustLayout.setHorizontalGroup(
            eczane_bilgileri_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        eczane_bilgileri_ustLayout.setVerticalGroup(
            eczane_bilgileri_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 26, Short.MAX_VALUE)
        );

        siparis_olustur_ust4.setBackground(new java.awt.Color(255, 22, 22));
        siparis_olustur_ust4.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout siparis_olustur_ust4Layout = new javax.swing.GroupLayout(siparis_olustur_ust4);
        siparis_olustur_ust4.setLayout(siparis_olustur_ust4Layout);
        siparis_olustur_ust4Layout.setHorizontalGroup(
            siparis_olustur_ust4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        siparis_olustur_ust4Layout.setVerticalGroup(
            siparis_olustur_ust4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 26, Short.MAX_VALUE)
        );

        jLabel12.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel12.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        jLabel12.setText("Parola");

        jLabel13.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel13.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        jLabel13.setText("Telefon No");

        jLabel14.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel14.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        jLabel14.setText("Adres");

        jLabel15.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel15.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        jLabel15.setText("Eczane İsim");

        eczane_bilgi_guncelle_buton.setText("Bilgileri Güncelle");
        eczane_bilgi_guncelle_buton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        eczane_bilgi_guncelle_buton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                eczane_bilgi_guncelle_butonActionPerformed(evt);
            }
        });

        kullanici_adi_text.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                kullanici_adi_textActionPerformed(evt);
            }
        });

        jLabel20.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel20.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        jLabel20.setText(" Kullanıcı Adı");

        javax.swing.GroupLayout eczane_bilgilerisayfasiLayout = new javax.swing.GroupLayout(eczane_bilgilerisayfasi);
        eczane_bilgilerisayfasi.setLayout(eczane_bilgilerisayfasiLayout);
        eczane_bilgilerisayfasiLayout.setHorizontalGroup(
            eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(eczane_bilgileri_ust, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(siparis_olustur_ust4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, eczane_bilgilerisayfasiLayout.createSequentialGroup()
                .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(eczane_bilgilerisayfasiLayout.createSequentialGroup()
                        .addGap(73, 73, 73)
                        .addComponent(jLabel20)
                        .addGap(18, 18, 18)
                        .addComponent(kullanici_adi_text))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, eczane_bilgilerisayfasiLayout.createSequentialGroup()
                        .addGap(80, 80, 80)
                        .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(eczane_bilgilerisayfasiLayout.createSequentialGroup()
                                .addComponent(jLabel12, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(parola_text))
                            .addGroup(eczane_bilgilerisayfasiLayout.createSequentialGroup()
                                .addComponent(jLabel14, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(adres_text)
                                    .addGroup(eczane_bilgilerisayfasiLayout.createSequentialGroup()
                                        .addComponent(uyari_text, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(0, 0, Short.MAX_VALUE))))))
                    .addGroup(eczane_bilgilerisayfasiLayout.createSequentialGroup()
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(eczane_bilgi_guncelle_buton)
                        .addGap(36, 36, 36))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, eczane_bilgilerisayfasiLayout.createSequentialGroup()
                        .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(eczane_bilgilerisayfasiLayout.createSequentialGroup()
                                .addGap(80, 80, 80)
                                .addComponent(jLabel13, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, eczane_bilgilerisayfasiLayout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(jLabel15)))
                        .addGap(18, 18, 18)
                        .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(eczane_no_text)
                            .addComponent(telefonno_text))))
                .addGap(154, 154, 154))
        );
        eczane_bilgilerisayfasiLayout.setVerticalGroup(
            eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(eczane_bilgilerisayfasiLayout.createSequentialGroup()
                .addComponent(eczane_bilgileri_ust, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(87, 87, 87)
                .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel20, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(kullanici_adi_text, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel12, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(parola_text, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel15, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(eczane_no_text, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel13, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(telefonno_text, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(eczane_bilgilerisayfasiLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel14, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(adres_text, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(uyari_text, javax.swing.GroupLayout.DEFAULT_SIZE, 23, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(eczane_bilgi_guncelle_buton, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(155, 155, 155)
                .addComponent(siparis_olustur_ust4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        siparis_goruntule_sayfa.setBackground(new java.awt.Color(255, 255, 255));

        siparis_goruntule_ust.setBackground(new java.awt.Color(255, 22, 22));
        siparis_goruntule_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout siparis_goruntule_ustLayout = new javax.swing.GroupLayout(siparis_goruntule_ust);
        siparis_goruntule_ust.setLayout(siparis_goruntule_ustLayout);
        siparis_goruntule_ustLayout.setHorizontalGroup(
            siparis_goruntule_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        siparis_goruntule_ustLayout.setVerticalGroup(
            siparis_goruntule_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 26, Short.MAX_VALUE)
        );

        siparis_olustur_ust2.setBackground(new java.awt.Color(255, 22, 22));
        siparis_olustur_ust2.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout siparis_olustur_ust2Layout = new javax.swing.GroupLayout(siparis_olustur_ust2);
        siparis_olustur_ust2.setLayout(siparis_olustur_ust2Layout);
        siparis_olustur_ust2Layout.setHorizontalGroup(
            siparis_olustur_ust2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        siparis_olustur_ust2Layout.setVerticalGroup(
            siparis_olustur_ust2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 26, Short.MAX_VALUE)
        );

        musteri_siparisim.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Siparis No", "Tutar", "Tamamlanma Durumu"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        musteri_siparisim.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                musteri_siparisimMouseClicked(evt);
            }
        });
        jScrollPane4.setViewportView(musteri_siparisim);
        if (musteri_siparisim.getColumnModel().getColumnCount() > 0) {
            musteri_siparisim.getColumnModel().getColumn(0).setPreferredWidth(30);
        }

        musteri_siparisim_detay.setModel(new javax.swing.table.DefaultTableModel(
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
        jScrollPane5.setViewportView(musteri_siparisim_detay);
        if (musteri_siparisim_detay.getColumnModel().getColumnCount() > 0) {
            musteri_siparisim_detay.getColumnModel().getColumn(1).setPreferredWidth(30);
            musteri_siparisim_detay.getColumnModel().getColumn(2).setPreferredWidth(40);
        }

        jLabel2.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel2.setText("Siparişlerim");

        jLabel3.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel3.setText("Sipariş Detayı");

        javax.swing.GroupLayout siparis_goruntule_sayfaLayout = new javax.swing.GroupLayout(siparis_goruntule_sayfa);
        siparis_goruntule_sayfa.setLayout(siparis_goruntule_sayfaLayout);
        siparis_goruntule_sayfaLayout.setHorizontalGroup(
            siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(siparis_goruntule_ust, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(siparis_olustur_ust2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                .addGap(40, 40, 40)
                .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 141, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(jScrollPane4, javax.swing.GroupLayout.DEFAULT_SIZE, 441, Short.MAX_VALUE)
                        .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                    .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 95, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jSeparator5, javax.swing.GroupLayout.PREFERRED_SIZE, 116, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(63, Short.MAX_VALUE))
        );
        siparis_goruntule_sayfaLayout.setVerticalGroup(
            siparis_goruntule_sayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(siparis_goruntule_sayfaLayout.createSequentialGroup()
                .addComponent(siparis_goruntule_ust, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, 26, Short.MAX_VALUE)
                .addGap(2, 2, 2)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 151, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(2, 2, 2)
                .addComponent(jSeparator5, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 237, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(37, 37, 37)
                .addComponent(siparis_olustur_ust2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        hosgeldiniz.setBackground(new java.awt.Color(255, 255, 255));

        hosgeldin_ust.setBackground(new java.awt.Color(255, 22, 22));
        hosgeldin_ust.setForeground(new java.awt.Color(255, 0, 51));

        javax.swing.GroupLayout hosgeldin_ustLayout = new javax.swing.GroupLayout(hosgeldin_ust);
        hosgeldin_ust.setLayout(hosgeldin_ustLayout);
        hosgeldin_ustLayout.setHorizontalGroup(
            hosgeldin_ustLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
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
                .addContainerGap(72, Short.MAX_VALUE)
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
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 236, Short.MAX_VALUE)
                .addComponent(jPanel6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        javax.swing.GroupLayout musteri_anasayfaLayout = new javax.swing.GroupLayout(musteri_anasayfa);
        musteri_anasayfa.setLayout(musteri_anasayfaLayout);
        musteri_anasayfaLayout.setHorizontalGroup(
            musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(siparis_olustur_sayfa, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(siparis_goruntule_sayfa, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(eczane_bilgilerisayfasi, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(hosgeldiniz, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        musteri_anasayfaLayout.setVerticalGroup(
            musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(siparis_olustur_sayfa, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(siparis_goruntule_sayfa, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(eczane_bilgilerisayfasi, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(musteri_anasayfaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(hosgeldiniz, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(solpanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 544, Short.MAX_VALUE))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                    .addGap(0, 202, Short.MAX_VALUE)
                    .addComponent(musteri_anasayfa, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(solpanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addComponent(musteri_anasayfa, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents
    
    public void siparisGoruntule(){
        musteri_siparis_model.setRowCount(0);
        musteri_siparis_detay_model.setRowCount(0);
        
        
        ArrayList<Siparis> siparisler = new ArrayList<Siparis>();
        
        siparisler = Sistem.siparisleriGetir();
        
        if(siparisler != null){
            
            
            for(Siparis siparis: siparisler){
                
                if(siparis.getEczaneno() == eczane.getEczaneno()){
                    String tamamlanmaDurumu;
                    if(siparis.getTamamlandi().equals("1")){
                        tamamlanmaDurumu = "Tamamlandı";
                    }else{
                        tamamlanmaDurumu = "Tamamlanmadı";
                    }
                    
                    Object[] eklenecek ={siparis.getSiparisno(), siparis.getTutar(), tamamlanmaDurumu};
                    musteri_siparis_model.addRow(eklenecek);
                    
                    
                    
                    
                }
                
               
                
            }
                
        }
        
    }
    
    
    public void dinamikAra(String ara){
        
        TableRowSorter<DefaultTableModel> tr = new TableRowSorter<DefaultTableModel>(model);
        
        ilac_tablosu.setRowSorter(tr);
        
        tr.setRowFilter(RowFilter.regexFilter(ara));
        
        
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
    
    
    
    
    
    private void siparis_olustur_musteriMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_siparis_olustur_musteriMouseClicked
        // TODO add your handling code here:

        siparis_olustur_sayfa.setVisible(true);
        hosgeldiniz.setVisible(false);
        siparis_goruntule_sayfa.setVisible(false);
        eczane_bilgilerisayfasi.setVisible(false);

        // bastigimizda renk alir

        siparis_olustur_musteri.setBackground(new Color(229,89,89));
        siparis_goruntule_musteri.setBackground(new Color(234,233,233));
        eczane_bilgilerim.setBackground(new Color(234,233,233));
    }//GEN-LAST:event_siparis_olustur_musteriMouseClicked

    private void siparis_goruntule_musteriMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_siparis_goruntule_musteriMouseClicked
        // TODO add your handling code here:

        siparis_olustur_sayfa.setVisible(false);
        hosgeldiniz.setVisible(false);
        siparis_goruntule_sayfa.setVisible(true);
        eczane_bilgilerisayfasi.setVisible(false);

        // bastigimizda renk alir

        siparis_olustur_musteri.setBackground(new Color(234,233,233));
        siparis_goruntule_musteri.setBackground(new Color(229,89,89));
        eczane_bilgilerim.setBackground(new Color(234,233,233));
        
        siparisGoruntule();
    }//GEN-LAST:event_siparis_goruntule_musteriMouseClicked

    private void eczane_bilgilerimMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_eczane_bilgilerimMouseClicked
        // TODO add your handling code here:

        siparis_olustur_sayfa.setVisible(false);
        hosgeldiniz.setVisible(false);
        siparis_goruntule_sayfa.setVisible(false);
        eczane_bilgilerisayfasi.setVisible(true);

        // bastigimizda renk alir

        siparis_olustur_musteri.setBackground(new Color(234,233,233));
        siparis_goruntule_musteri.setBackground(new Color(234,233,233));
        eczane_bilgilerim.setBackground(new Color(229,89,89));
        
        kullanici_adi_text.setText(eczane.getKullaniciadi());
        
        parola_text.setText(eczane.getParola());
        eczane_no_text.setText(eczane.getIsim());
        telefonno_text.setText(eczane.getTelefonno());
        adres_text.setText(eczane.getAdres());
        
        kullanici_adi_text.setEditable(false);
        parola_text.setEditable(false);
        eczane_no_text.setEditable(false);
        telefonno_text.setEditable(false);
        adres_text.setEditable(false);

        kullanici_adi_text.setEnabled(false);
        parola_text.setEnabled(false);
        eczane_no_text.setEnabled(false);
        telefonno_text.setEnabled(false);
        adres_text.setEnabled(false);
        
    }//GEN-LAST:event_eczane_bilgilerimMouseClicked

    private void cikis_musteriMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_cikis_musteriMouseClicked
        // TODO add your handling code here:

        new GirisAyrimi().setVisible(true);

        this.dispose();

    }//GEN-LAST:event_cikis_musteriMouseClicked

    private void arama_cubugu_musteriFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_arama_cubugu_musteriFocusGained
        // TODO add your handling code here:

        if(arama_cubugu_musteri.getText().equals("Aramak için tıklayınız.. örn Parol")){
            arama_cubugu_musteri.setForeground(Color.BLACK);
            arama_cubugu_musteri.setText("");

        }

    }//GEN-LAST:event_arama_cubugu_musteriFocusGained

    private void arama_cubugu_musteriFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_arama_cubugu_musteriFocusLost
        // TODO add your handling code here:

        if(arama_cubugu_musteri.getText().isEmpty()){
            arama_cubugu_musteri.setForeground(Color.gray);
            arama_cubugu_musteri.setText("Aramak için tıklayınız.. örn Parol");

        }

    }//GEN-LAST:event_arama_cubugu_musteriFocusLost

    private void arama_cubugu_musteriKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_arama_cubugu_musteriKeyReleased
        // TODO add your handling code here:

        String ara =arama_cubugu_musteri.getText();

        dinamikAra(ara);
    }//GEN-LAST:event_arama_cubugu_musteriKeyReleased

    private void ilac_tablosuMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ilac_tablosuMouseClicked
        // TODO add your handling code here:

        int selectedrow=ilac_tablosu.getSelectedRow();
        
        adet_mesaji.setForeground(Color.GRAY);
        adet_mesaji.setText("Adet giriniz..");
        adet_mesaji.setEditable(true);
        
        
        
        
        
        
        

        
    }//GEN-LAST:event_ilac_tablosuMouseClicked

    private void sepetMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_sepetMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_sepetMouseClicked

    private void adet_mesajiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_adet_mesajiActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_adet_mesajiActionPerformed

    private void sepet_ekle_butonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sepet_ekle_butonActionPerformed
        // TODO add your handling code here:
        
        
    
        
        if(adet_mesaji.getText().equals("Ürün seçiniz")){
            
            uyari_mesaj.setText("Öncelikle ürün seçmelisiniz..");
            
            
            
        }
        
        else if(adet_mesaji.getText().equals("Adet giriniz..")){
            
            uyari_mesaj.setText("Öncelikle adet girmelisiniz..");
        }
        
        else if(!(adet_mesaji.getText()).matches("[0-9]+")){
            
            uyari_mesaj.setText("Lütfen sayı giriniz..");
            
            
            
        }
        else {
            
            
            // sayı kontrolu vs okey
            
            int selectedrow=ilac_tablosu.getSelectedRow();

            String isim=model.getValueAt(selectedrow, 0).toString();
            int fiyat=Integer.parseInt(model.getValueAt(selectedrow, 3).toString());
            int stok=Integer.parseInt(model.getValueAt(selectedrow, 4).toString());
            
            int adet = Integer.parseInt(adet_mesaji.getText());
            int tutar = fiyat * adet;
            
            
            
        
            
            if(adet <= stok  && adet >0 ){
                
                boolean bulundu = false;
                boolean stokbitti= false;
                for(int i = 0; i < sepetmodel.getRowCount(); i++){
                    if(sepetmodel.getValueAt(i, 0).equals(isim)){
                        
                        if( Integer.parseInt(sepetmodel.getValueAt(i,1).toString()) + adet > stok){
                            
                            stokbitti=true;
                            
                            
                        }
                        else{
                            
                            sepetmodel.setValueAt(Integer.parseInt(sepetmodel.getValueAt(i,1).toString()) + adet,i,1);
                            sepetmodel.setValueAt(Integer.parseInt(sepetmodel.getValueAt(i,2).toString()) + tutar,i,2);
                            bulundu=true;
                            
                            String eskitutar=toplam_tutar.getText();
                            eskitutar=eskitutar.substring(0,eskitutar.indexOf("₺"));

                            toplam_tutar.setText((Integer.parseInt(eskitutar)+tutar)+"₺");
                        }
                        


                    }
                }
                
                if(!bulundu && !stokbitti){
                    
                    Object[] sepeteklenecek ={isim,String.valueOf(adet),String.valueOf(tutar)};
                    sepetmodel.addRow(sepeteklenecek);
                    String eskitutar=toplam_tutar.getText();
                    eskitutar=eskitutar.substring(0,eskitutar.indexOf("₺"));
                    
                    
                    
                    
                    toplam_tutar.setText((Integer.parseInt(eskitutar)+tutar)+"₺");
                    
                    
                    
                    
                    
                }
                
                if(!stokbitti){
                    
                    uyari_mesaj.setText("Sepete eklendi..");
                }
                else{
                    
                    uyari_mesaj.setText("Yeterli stok bulunmamaktadır..");
                }
                
                
                
            }
            
            else{
                
                uyari_mesaj.setText("Yeterli stok bulunmamaktadır..");
            }
            
            
            
        }
        
        
        
        
        
        
        
        
        
        
        
    }//GEN-LAST:event_sepet_ekle_butonActionPerformed

    private void siparis_onay_butonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_siparis_onay_butonActionPerformed
        // TODO add your handling code here:
        String siparis = "";
        
        int row = sepetmodel.getRowCount();
        if(row<=0){
            
            uyari_mesaj.setText("Sepetiniz boş..");
            
            
            
        }
        else{
            for(int i = 0;i< row ; i++ ){


                String ilacismi= sepetmodel.getValueAt(i, 0).toString();
                String adet= sepetmodel.getValueAt(i, 1).toString();
                String tutar= sepetmodel.getValueAt(i, 2).toString();
                
                
                int ilacrow=model.getRowCount();
                for(int j = 0; j< ilacrow ; j++){
                       
                    if(model.getValueAt(j, 0).toString().equals(ilacismi)){
                        int stok = Integer.parseInt(model.getValueAt(j, 4).toString());
                        Sistem.stokGuncelle( ilacismi,stok-Integer.parseInt(adet));
                        
                        j=ilacrow;
                        

                    }
                    
                    
                }
                
                
                
                
                siparis=siparis.concat(ilacismi+","+adet+","+tutar+",");


            }
            String toplamtutar = toplam_tutar.getText();
            toplamtutar = toplamtutar.substring(0,toplamtutar.indexOf("₺"));
            Sistem.siparisEkle(eczane.getIsim(), String.valueOf(eczane.getEczaneno()), siparis,toplamtutar);
            
            toplam_tutar.setText("0₺");
            ilacGoruntule();
            
            sepetmodel.setRowCount(0);
            
            uyari_mesaj.setText("Sipariş oluşturuldu..");
            
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
    }//GEN-LAST:event_siparis_onay_butonActionPerformed

    private void adet_mesajiFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_adet_mesajiFocusGained
        // TODO add your handling code here:
        if(adet_mesaji.getText().equals("Adet giriniz..") && ilac_tablosu.getSelectedRow()>=0){
            adet_mesaji.setEditable(true);
            adet_mesaji.setForeground(Color.BLACK);
            adet_mesaji.setText("");
            
        }
        
        
        
    }//GEN-LAST:event_adet_mesajiFocusGained

    private void sepetten_sil_butonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sepetten_sil_butonActionPerformed
        // TODO add your handling code here:
        
        int selectedrow=sepet.getSelectedRow();
        int row=sepetmodel.getRowCount();
        
        if(row<0){
            
            uyari_mesaj.setText("Sepette ürün bulunmamaktadır..");
            
        }
        else if(selectedrow<0){
            
            
            
            uyari_mesaj.setText("Sepetten silinecek ürün seçiniz..");
            
    
            
        }
        else{
            
            
            int tutar = Integer.parseInt(sepetmodel.getValueAt(selectedrow,2).toString());
            String eskitutar=toplam_tutar.getText();
            eskitutar=eskitutar.substring(0,eskitutar.indexOf("₺"));
                    
            toplam_tutar.setText((Integer.parseInt(eskitutar)-tutar)+"₺");
            
            sepetmodel.removeRow(selectedrow);
            
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }//GEN-LAST:event_sepetten_sil_butonActionPerformed

    private void musteri_siparisimMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_musteri_siparisimMouseClicked
        // TODO add your handling code here:
        int row = musteri_siparisim.getSelectedRow();
        
        if(row >= 0){
            musteri_siparis_detay_model.setRowCount(0);
            
            
            
            
            
            int siparisno=Integer.parseInt(musteri_siparis_model.getValueAt(row, 0).toString());
            String siparis=Sistem.siparisGetir(siparisno);
            
            
            String[] siparisbilgileri = siparis.split(",");
            
            for(int i=0;i<siparisbilgileri.length;i=i+3){
                
                Object[] eklenecek= {siparisbilgileri[i],siparisbilgileri[i+1],siparisbilgileri[i+2]};
                musteri_siparis_detay_model.addRow(eklenecek);
                
                
                
                
            }
            
            
            
            
        }
    }//GEN-LAST:event_musteri_siparisimMouseClicked

    private void eczane_bilgi_guncelle_butonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_eczane_bilgi_guncelle_butonActionPerformed
        // TODO add your handling code here:
        if(eczane_bilgi_guncelle_buton.getText().equals("Bilgileri Güncelle")){
            kullanici_adi_text.setEditable(true);
            parola_text.setEditable(true);
            eczane_no_text.setEditable(true);
            telefonno_text.setEditable(true);
            adres_text.setEditable(true);
            
            kullanici_adi_text.setEnabled(true);
            parola_text.setEnabled(true);
            eczane_no_text.setEnabled(true);
            telefonno_text.setEnabled(true);
            adres_text.setEnabled(true);
            
            uyari_text.setText("Bilgileri güncelleyiniz..");
            
            eczane_bilgi_guncelle_buton.setText("Kaydet");
        }else{
            if(parola_text.getText().isEmpty() || eczane_no_text.getText().isEmpty()
                    || telefonno_text.getText().isEmpty() || adres_text.getText().isEmpty()){
                uyari_text.setText("Bilgileri eksiksiz doldurunuz..");
            }else{
                String isim = eczane_no_text.getText();
                String adres = adres_text.getText();
                String telefonno = telefonno_text.getText();
                String kullaniciadi = kullanici_adi_text.getText();
                String parola = parola_text.getText();
                
                eczane.setIsim(isim);
                eczane.setAdres(adres);
                eczane.setTelefonno(telefonno);
                eczane.setKullaniciadi(kullaniciadi);
                eczane.setParola(parola);
                
                Sistem.musteriBilgisiGuncelle(eczane.getEczaneno(), isim, adres, telefonno, kullaniciadi, parola);
                
                kullanici_adi_text.setEditable(false);
                parola_text.setEditable(false);
                eczane_no_text.setEditable(false);
                telefonno_text.setEditable(false);
                adres_text.setEditable(false);
                
                kullanici_adi_text.setEnabled(false);
                parola_text.setEnabled(false);
                eczane_no_text.setEnabled(false);
                telefonno_text.setEnabled(false);
                adres_text.setEnabled(false);

                uyari_text.setText("Bilgiler güncellendi..");
                eczane_bilgi_guncelle_buton.setText("Bilgileri Güncelle");
            }
            
        }
    }//GEN-LAST:event_eczane_bilgi_guncelle_butonActionPerformed

    private void kullanici_adi_textActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_kullanici_adi_textActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_kullanici_adi_textActionPerformed

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
            java.util.logging.Logger.getLogger(MusteriMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MusteriMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MusteriMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MusteriMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MusteriMenu(null).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField adet_mesaji;
    private javax.swing.JTextField adres_text;
    private javax.swing.JTextField arama_cubugu_musteri;
    private javax.swing.JPanel cikis_musteri;
    private javax.swing.JButton eczane_bilgi_guncelle_buton;
    private javax.swing.JPanel eczane_bilgileri_ust;
    private javax.swing.JPanel eczane_bilgilerim;
    private javax.swing.JPanel eczane_bilgilerisayfasi;
    private javax.swing.JTextField eczane_no_text;
    private javax.swing.JPanel hosgeldin_ust;
    private javax.swing.JPanel hosgeldiniz;
    private javax.swing.JTable ilac_tablosu;
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
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPane5;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSeparator jSeparator2;
    private javax.swing.JSeparator jSeparator3;
    private javax.swing.JSeparator jSeparator4;
    private javax.swing.JSeparator jSeparator5;
    private javax.swing.JTextField kullanici_adi_text;
    private javax.swing.JPanel musteri_anasayfa;
    private javax.swing.JTable musteri_siparisim;
    private javax.swing.JTable musteri_siparisim_detay;
    private javax.swing.JTextField parola_text;
    private javax.swing.JTable sepet;
    private javax.swing.JButton sepet_ekle_buton;
    private javax.swing.JButton sepetten_sil_buton;
    private javax.swing.JPanel siparis_goruntule_musteri;
    private javax.swing.JPanel siparis_goruntule_sayfa;
    private javax.swing.JPanel siparis_goruntule_ust;
    private javax.swing.JPanel siparis_olustur_musteri;
    private javax.swing.JPanel siparis_olustur_sayfa;
    private javax.swing.JPanel siparis_olustur_ust;
    private javax.swing.JPanel siparis_olustur_ust2;
    private javax.swing.JPanel siparis_olustur_ust4;
    private javax.swing.JButton siparis_onay_buton;
    private javax.swing.JPanel solpanel;
    private javax.swing.JTextField telefonno_text;
    private javax.swing.JLabel toplam_tutar;
    private javax.swing.JLabel uyari_mesaj;
    private javax.swing.JLabel uyari_text;
    // End of variables declaration//GEN-END:variables
}
