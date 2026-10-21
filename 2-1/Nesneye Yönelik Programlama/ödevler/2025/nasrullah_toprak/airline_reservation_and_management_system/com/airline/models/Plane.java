package com.airline.models;

public class Plane {
    private String planeID;
    private String planeModel;
    private int capacity;
    private Seat[][] seatMatrix;

    public Plane(String planeID, String planeModel, int capacity) {
        this.planeID = planeID;
        this.planeModel = planeModel;
        this.capacity = capacity;
        initializeSeats(capacity);
    }

    private void initializeSeats(int capacity) {
        int seatsPerRow = 6;
        int rows = (int) Math.ceil((double) capacity / seatsPerRow);
        seatMatrix = new Seat[rows][seatsPerRow];

        int seatCount = 0;
        for (int i = 0; i < rows && seatCount<capacity; i++) {
            for (int j = 0; j < seatsPerRow && seatCount<capacity; j++) {
                String seatNum = (i + 1) + "" + (char) ('A' + j);
                // Simple logic: First 1/3 rows are Business
                Seat.SeatClass type = (i < rows / 3) ? Seat.SeatClass.BUSINESS : Seat.SeatClass.ECONOMY;
                double price = (type == Seat.SeatClass.BUSINESS) ? 200.0 : 100.0;

                seatMatrix[i][j] = new Seat(seatNum, type, price);
                seatCount++;
            }
        }
    }

    public String getPlaneID() {
        return planeID;
    }

    public String getPlaneModel() {
        return planeModel;
    }

    public int getCapacity() {
        return capacity;
    }

    public Seat[][] getSeatMatrix() {
        return seatMatrix;
    }

    public Seat getSeat(String seatNum) {
        for (Seat[] row : seatMatrix) {
            for (Seat seat : row) {
                if (seat != null && seat.getSeatNum().equals(seatNum)) {
                    return seat;
                }
            }
        }
        return null;
    }
}
