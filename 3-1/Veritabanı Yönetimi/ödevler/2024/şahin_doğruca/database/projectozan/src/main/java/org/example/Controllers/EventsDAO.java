package org.example;

import java.sql.*;
import java.util.ArrayList;

public class EventsDAO {

    public boolean addEvent(Events event) {
        if (isNullOrEmpty(event.getEventName(), "Hata: Etkinlik adı boş bırakılamaz.") ||
            isNullOrEmpty(event.getEventDate(), "Hata: Etkinlik tarihi boş bırakılamaz.")) {
            return false;
        }

        String sql = "INSERT INTO events (user_id, event_name, event_date) VALUES (?, ?, ?)";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setInt(1, UserSession.getUserID());
            statement.setString(2, event.getEventName());
            statement.setDate(3, java.sql.Date.valueOf(event.getEventDate()));  // eventDate

            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("Etkinlik başarıyla eklendi!");
                return true;
            }
        } catch (SQLException e) {
            handleSQLException(e, "Etkinlik ekleme hatası.");
        }
        return false;
    }

    public Events getEventByEventId(int eventId) {
        if (isNullOrEmpty(eventId, "Hata: Etkinlik id'si boş bırakılamaz.")) {
            return null;
        }

        String sql = "SELECT * FROM events WHERE event_id = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setInt(1, eventId);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {

                return new Events(resultSet.getInt("event_id"),
                        resultSet.getInt("user_id"),
                        resultSet.getString("event_name"),
                        resultSet.getDate("event_date").toLocalDate());
            } else {
                System.out.println("Hata: Etkinlik bulunamadı.");
                return null;
            }
        } catch (SQLException e) {
            handleSQLException(e, "Etkinlik ID alma hatası.");
            return null;
        }
    }

    public ArrayList<Events> getEventsByUserId(int userId) {
        String sql = "SELECT * FROM events WHERE user_id = ?";
        ArrayList<Events> eventsList = new ArrayList<>();

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            statement.setInt(1, userId);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                Events event = new Events(
                        resultSet.getInt("event_id"),
                        userId,
                        resultSet.getString("event_name"),
                        resultSet.getDate("event_date").toLocalDate()
                );

                eventsList.add(event);
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return eventsList;
    }

    public void deleteEvent(int eventId) {
        String sql = "DELETE FROM events WHERE event_id = ?";

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            statement.setInt(1, eventId);

            statement.executeUpdate();

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    // Yardımcı metodlar
    private boolean isNullOrEmpty(Object value, String errorMessage) {
        if (value == null || (value instanceof String && ((String) value).trim().isEmpty())) {
            System.out.println(errorMessage);
            return true;
        }
        return false;
    }

    private void handleSQLException(SQLException e, String defaultMessage) {
        System.out.println(defaultMessage + " " + e.getMessage());
    }
}
