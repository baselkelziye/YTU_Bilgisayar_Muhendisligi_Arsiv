package Proje;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.io.IOException;
import java.util.ArrayList;

public class FileOpsTest {
    
    private fileOperations fileOps;
    
    @BeforeEach
    public void setUp() {
        fileOps = new fileOperations();
    }
    
    @Test
    public void testOku() throws IOException {
        // Test case 1: Sistemde Olan Kullanici
        User user = fileOps.Oku("Berkay", "Gumusay", "12");
        Assertions.assertNotNull(user);
        
        // Test Case 2: Sistemde Olmayan Kullanici
        User invalidUser = fileOps.Oku("Ismet", "Inonu", "1923");
        Assertions.assertNull(invalidUser);
    }
    
    @Test
    public void testGetChildList() throws IOException {
        // Test case : Çocukların Listesini Alma
        ArrayList<User> childList = fileOps.getChildList();
        Assertions.assertNotNull(childList);
        Assertions.assertFalse(childList.isEmpty());
    }
    
    @Test
    public void testFindChild() throws IOException {
        // Test case 1: Sisteme Kayıtlı Olan Bir Çocuğu Dosyada Arama
        boolean foundChild = fileOps.findChild("Berkay", "Gumusay");
        Assertions.assertTrue(foundChild);
        
        // Test case 2: Sisteme Kayıtlı Olmayan Bir Çocuğu Dosyada Arama
        boolean notFoundChild = fileOps.findChild("Ismet", "Inonu");
        Assertions.assertFalse(notFoundChild);
    }
    
}