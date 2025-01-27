module mertguler.hospitalreservationsystemjava {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.base;
    requires javafx.graphics;

    opens mertguler to javafx.fxml;
    exports mertguler;
    exports mertguler.GUI;
    opens mertguler.GUI to javafx.fxml;
    exports mertguler.GUI.Admin;
    opens mertguler.GUI.Admin to javafx.fxml;
    exports mertguler.GUI.MainMenu;
    opens mertguler.GUI.MainMenu to javafx.fxml;
    exports mertguler.GUI.Universal.Lists;
    opens mertguler.GUI.Universal.Lists to javafx.fxml;
    exports mertguler.GUI.Admin.Hospital to javafx.fxml;
    opens mertguler.GUI.Admin.Hospital to javafx.fxml;
    exports mertguler.GUI.Admin.Section to javafx.fxml;
    opens mertguler.GUI.Admin.Section to javafx.fxml;
    exports mertguler.GUI.Admin.Doctor to javafx.fxml;
    opens mertguler.GUI.Admin.Doctor to javafx.fxml;
    exports mertguler.GUI.Universal.Patient to javafx.fxml;
    opens mertguler.GUI.Universal.Patient to javafx.fxml;
    exports mertguler.GUI.Universal.Rendezvous to javafx.fxml;
    opens mertguler.GUI.Universal.Rendezvous to javafx.fxml;
    exports mertguler.GUI.Receptionist to javafx.fxml;
    opens mertguler.GUI.Receptionist to javafx.fxml;
    exports mertguler.GUI.Doctor to javafx.fxml;
    opens mertguler.GUI.Doctor to javafx.fxml;
    exports mertguler.GUI.Doctor.PatientWork to javafx.fxml;
    opens mertguler.GUI.Doctor.PatientWork to javafx.fxml;
    exports mertguler.CRS to javafx.fxml;

}