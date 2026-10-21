package berkay.ders.mobilprogramlama.semesterproject.model;

/**
 * Created by mberk on 14.12.2015.
 */
public class Contact {
    private long contactID;
    private String name;
    private String surname;
    private String phoneNumber;
    private String eMail;
    private double longitude;
    private double latitude;
    private long totalIncomingDuration = 0;
    private long totalOutgoingDuration = 0;
    private int missingCalls = 0;
    private int sentMessageCount = 0;
    private int receivedMessageCount = 0;
    private boolean isInSpeedDial = false;

    public long getContactID() {
        return contactID;
    }

    public void setContactID(long contactID) {
        this.contactID = contactID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String geteMail() {
        return eMail;
    }

    public void seteMail(String eMail) {
        this.eMail = eMail;
    }

    public double getLongitude() {
        return longitude;
    }

    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }

    public double getLatitude() {
        return latitude;
    }

    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }

    public long getTotalIncomingDuration() {
        return totalIncomingDuration;
    }

    public void setTotalIncomingDuration(long totalIncomingDuration) {
        this.totalIncomingDuration = totalIncomingDuration;
    }

    public long getTotalOutgoingDuration() {
        return totalOutgoingDuration;
    }

    public void setTotalOutgoingDuration(long totalOutgoingDuration) {
        this.totalOutgoingDuration = totalOutgoingDuration;
    }

    public int getMissingCalls() {
        return missingCalls;
    }

    public void setMissingCalls(int missingCalls) {
        this.missingCalls = missingCalls;
    }

    public int getSentMessageCount() {
        return sentMessageCount;
    }

    public void setSentMessageCount(int sentMessageCount) {
        this.sentMessageCount = sentMessageCount;
    }

    public int getReceivedMessageCount() {
        return receivedMessageCount;
    }

    public void setReceivedMessageCount(int receivedMessageCount) {
        this.receivedMessageCount = receivedMessageCount;
    }

    public boolean isInSpeedDial() {
        return isInSpeedDial;
    }

    public void setIsInSpeedDial(boolean isInSpeedDial) {
        this.isInSpeedDial = isInSpeedDial;
    }
}
