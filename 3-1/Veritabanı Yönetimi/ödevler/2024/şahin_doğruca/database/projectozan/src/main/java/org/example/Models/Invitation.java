package org.example;

public class Invitation {
    private int invitationID;
    private int eventID;
    private int userID;
    private Status status;

    public Invitation(int invitationID, int eventID, int userID, Status status) {
        if (invitationID < 0 || eventID < 0 || userID < 0) {
            throw new IllegalArgumentException("ID alanları negatif olamaz.");
        }
        if (status == null) {
            throw new IllegalArgumentException("Status boş bırakılamaz.");
        }
        this.invitationID = invitationID;
        this.eventID = eventID;
        this.userID = userID;
        this.status = status;
    }

    public int getInvitationID() {
        return invitationID;
    }

    public void setInvitationID(int invitationID) {
        if (invitationID < 0) {
            throw new IllegalArgumentException("Invitation ID negatif olamaz.");
        }
        this.invitationID = invitationID;
    }

    public int getEventID() {
        return eventID;
    }

    public void setEventID(int eventID) {
        if (eventID < 0) {
            throw new IllegalArgumentException("Event ID negatif olamaz.");
        }
        this.eventID = eventID;
    }

    public int getUserID() {
        return userID;
    }

    public void setUserID(int userID) {
        if (userID < 0) {
            throw new IllegalArgumentException("User ID negatif olamaz.");
        }
        this.userID = userID;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        if (status == null) {
            throw new IllegalArgumentException("Status boş bırakılamaz.");
        }
        this.status = status;
    }

    @Override
    public String toString() {
        return "Invitation{" +
                "invitationID=" + invitationID +
                ", eventID=" + eventID +
                ", userID=" + userID +
                ", status=" + status +
                '}';
    }

    public enum Status {
        PENDING,
        ACCEPTED,
        DECLINED
    }
}
