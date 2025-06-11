package yazilim;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {

	public static void main(String[] args) throws SQLException {
		// TODO Auto-generated method stub
		String databaseName = "YazilimMuhProje";
		String userName = "postgres";
		String password = "12345";
		Connection conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/" + databaseName, userName, password);

		StartPage startPage = new StartPage(conn);
		startPage.showFrame();
	}
}