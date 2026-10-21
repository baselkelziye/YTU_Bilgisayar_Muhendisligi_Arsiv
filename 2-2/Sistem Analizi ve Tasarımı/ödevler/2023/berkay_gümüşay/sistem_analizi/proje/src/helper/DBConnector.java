package Helper;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnector {
    private static Connection connection;

    public static Connection getConnection() {
        try {
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/rentacar", "root", "admin123");
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }
}
