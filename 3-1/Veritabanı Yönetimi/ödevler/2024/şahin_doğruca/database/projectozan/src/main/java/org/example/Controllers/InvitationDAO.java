package org.example;

import javax.xml.crypto.Data;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class InvitationDAO {

    public boolean addInvitation(int eventID, String username) {
        if (isNullOrEmpty(username, "Hata: Kullanıcı adı boş bırakılamaz.")) {
            return false;
        }

        // Kullanıcı ID'sini kullanıcı adı üzerinden alıyoruz
        UsersDAO usersDAO = new UsersDAO();
        int userID = usersDAO.getUserIDByUsername(username);
        if (userID == -1) {
            System.out.println("Hata: Davet gönderilecek kullanıcı bulunamadı.");
            return false;
        }


        if (eventID == -1) {
            System.out.println("Hata: Etkinlik bulunamadı.");
            return false;
        }

        // Davetiyeyi ekle
        String sql = "INSERT INTO invitation (event_id, user_id, status) VALUES (?, ?, ?)";

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setInt(1, eventID); // Event ID
            statement.setInt(2, userID); // Kullanıcı ID
            statement.setString(3, Invitation.Status.PENDING.toString());

            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("Davet başarıyla gönderildi!");
                return true;
            }

        } catch (SQLException e) {
            handleSQLException(e, "Davet ekleme hatası.");
        }

        return false;
    }

    public ArrayList<Events> getAllAcceptedInvitations(int user_id) {
        ArrayList<Events> acceptedInvitations = new ArrayList<>();
        EventsDAO eventsDAO = new EventsDAO();

        String sql = "SELECT event_id FROM invitation WHERE user_id = ? and status = 'ACCEPTED'";

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            statement.setInt(1, user_id);
            ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
                Events event = eventsDAO.getEventByEventId(resultSet.getInt("event_id"));

                acceptedInvitations.add(event);

            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return acceptedInvitations;
    }

    public ArrayList<Invitation> getAllPendingInvitations(int user_id) {
        String sql = "SELECT * FROM invitation WHERE user_id = ? and status = 'PENDING'";
        ArrayList<Invitation> invitations = new ArrayList<>();

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            statement.setInt(1, user_id);
            try (ResultSet resultSet = statement.executeQuery()) {
                while (resultSet.next()) {
                    int invitationID = resultSet.getInt("invitation_id");
                    int userID = resultSet.getInt("user_id");

                    Invitation invitation = new Invitation(0, resultSet.getInt("event_id"), user_id, Invitation.Status.PENDING);
                    invitation.setInvitationID(resultSet.getInt("invitation_id"));

                    invitations.add(invitation);

                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return invitations;
    }

    public ArrayList<Invitation> getInvitationsByEvent(int event_id) {
        String sql = "SELECT * FROM invitation WHERE event_id = ? and status = 'ACCEPTED'";
        ArrayList<Invitation> invitations = new ArrayList<>();

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            statement.setInt(1, event_id);
            try (ResultSet resultSet = statement.executeQuery()) {
                while (resultSet.next()) {


                    Invitation invitation = new Invitation(resultSet.getInt("invitation_id"), event_id, resultSet.getInt("user_id"), Invitation.Status.ACCEPTED);

                    invitations.add(invitation);

                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return invitations;
    }

    public boolean updateInvitationStatus(int invitationID, Invitation.Status status) {
        String sql = "UPDATE invitation SET status = ? WHERE invitation_id = ?";

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, status.toString());
            statement.setInt(2, invitationID);

            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("Davet başarıyla gönderildi!");
                return true;
            }


        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return false;
    }

    // Yardımcı metodlar
    private boolean isNullOrEmpty(String value, String errorMessage) {
        if (value == null || value.trim().isEmpty()) {
            System.out.println(errorMessage);
            return true;
        }
        return false;
    }

    private void handleSQLException(SQLException e, String defaultMessage) {
        System.out.println(defaultMessage + " " + e.getMessage());
    }


}
