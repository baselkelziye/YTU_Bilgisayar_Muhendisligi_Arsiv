package Database;

import Entities.Finance;
import Helper.DBConnector;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Date;

public class FinanceOperations {

    public void updateStatus() {
        LocalDate tdy_temp = LocalDate.now();
        int currentDay = tdy_temp.getDayOfMonth();
        System.out.println(currentDay);
        if(currentDay != 14) return;

        int currentMonth = tdy_temp.getMonthValue() - 1 ;
        java.sql.Date tdy = java.sql.Date.valueOf(tdy_temp);
        String[] months = {
                "Ocak", "Şubat", "Mart", "Nisan", "Mayıs", "Haziran", "Temmuz", "Ağustos", "Eylül", "Ekim", "Kasım", "Aralık"
        };

        try{
            String query = "INSERT INTO finans (Tarih , Aciklama , Deger) VALUES (?,?,?)";
            PreparedStatement statement = DBConnector.getConnection().prepareStatement(query);
            statement.setDate(1,tdy);
            for(Entities.Car car : Entities.Car.setList()) {
                Object[] temp = car.getObjects();
                String carPlate = (String) temp[0];
                Double value = (Double) temp[4];
                String definition = carPlate + " plakali arabanin " + months[currentMonth] + " ayindaki vergi ödemesi" ;
                statement.setString(2,definition);
                statement.setDouble(3,value);
                statement.executeUpdate();
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }

    }

    public void rentingUpdate(String plate, String tc, Double price) {
        LocalDate tdy_temp = LocalDate.now();
        java.sql.Date tdy = java.sql.Date.valueOf(tdy_temp);

        try{
            String query = "INSERT INTO finans (Tarih , Aciklama , Deger) VALUES (?,?,?)";
            PreparedStatement statement = DBConnector.getConnection().prepareStatement(query);
            statement.setDate(1,tdy);
            String definition = tc + " TC'li musterinin " + plate + " plakali arabaya ödediği ücret ";
            statement.setDate(1,tdy);
            statement.setString(2,definition);
            statement.setDouble(3,price);
            statement.executeUpdate();
        }catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Entities.Finance> setList() {
        List<Entities.Finance> newList = new ArrayList<Finance>();
        Statement statement = null;
        try{
            statement = DBConnector.getConnection().createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM finans");
            while(rs.next()) {
                Date tempDate = rs.getDate("Tarih");
                String tempDefinition = rs.getString("Aciklama");
                Double tempValue = rs.getDouble("Deger");
                Entities.Finance tempFinance = new Finance(tempDefinition,tempDate,tempValue);
                newList.add(tempFinance);
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }

        return newList;
    }

    public static void main(String[] args) {
        FinanceOperations fo = new FinanceOperations();
        fo.updateStatus();

    }
}
