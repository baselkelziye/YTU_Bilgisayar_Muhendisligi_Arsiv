package com.airline.model;

import com.airline.model.enums.SeatClass;
import com.airline.exception.SeatNotFoundException;
import java.io.Serializable;
import java.util.*;

/**
 * Bir uçağı temsil eder.
 * Koltuk düzenini ve kapasite bilgilerini içerir.
 */
public class Plane implements Serializable {
    private static final long serialVersionUID = 1L;

    private String planeId;
    private String planeModel;
    private int capacity;
    private Map<String, Seat> seatMatrix; // Koltuk numarası -> Seat
    private int rows;
    private int seatsPerRow;
    private int businessRows; // İlk kaç sıra business class

    /**
     * Yeni bir uçak oluşturur ve koltukları initialize eder.
     * @param planeId Uçak ID
     * @param planeModel Uçak modeli (örn: "Boeing 737")
     * @param rows Toplam sıra sayısı
     * @param seatsPerRow Her sıradaki koltuk sayısı (genellikle 6: A-F)
     * @param businessRows İlk kaç sıra business class
     * @param basePrice Ekonomi sınıfı baz fiyat
     */
    public Plane(String planeId, String planeModel, int rows, int seatsPerRow,
                 int businessRows, double basePrice) {
        this.planeId = planeId;
        this.planeModel = planeModel;
        this.rows = rows;
        this.seatsPerRow = seatsPerRow;
        this.businessRows = businessRows;
        this.capacity = rows * seatsPerRow;
        this.seatMatrix = new LinkedHashMap<>();
        initializeSeats(basePrice);
    }

    /**
     * Varsayılan değerlerle uçak oluşturur (30 sıra, 6 koltuk, 5 business sıra).
     */
    public Plane(String planeId, String planeModel, double basePrice) {
        this(planeId, planeModel, 30, 6, 5, basePrice);
    }

    /**
     * Tüm koltukları oluşturur.
     * A, B, C koridor D, E, F şeklinde düzenlenir.
     */
    private void initializeSeats(double basePrice) {
        char[] columns = {'A', 'B', 'C', 'D', 'E', 'F'};

        int row = 1;
        while (row <= rows) {
            int col = 0;
            while (col < seatsPerRow && col < columns.length) {
                String seatNum = row + String.valueOf(columns[col]);
                SeatClass seatClass = (row <= businessRows) ? SeatClass.BUSINESS : SeatClass.ECONOMY;
                Seat seat = new Seat(seatNum, seatClass, basePrice);
                seatMatrix.put(seatNum, seat);
                col++;
            }
            row++;
        }
    }

    /**
     * Belirtilen numaralı koltuğu döndürür.
     */
    public Seat getSeat(String seatNum) {
        if (seatNum == null) {
            throw new SeatNotFoundException("Koltuk numarası null olamaz");
        }
        return seatMatrix.get(seatNum.toUpperCase());
    }

    /**
     * Tüm boş koltukları döndürür.
     */
    public List<Seat> getAvailableSeats() {
        List<Seat> availableSeats = new ArrayList<>();
        java.util.Iterator<Seat> iterator = seatMatrix.values().iterator();
        while (iterator.hasNext()) {
            Seat seat = iterator.next();
            if (!seat.isReserveStatus()) {
                availableSeats.add(seat);
            }
        }
        return availableSeats;
    }

    /**
     * Belirli bir sınıftaki boş koltukları döndürür.
     */
    public List<Seat> getAvailableSeatsByClass(SeatClass seatClass) {
        List<Seat> availableSeats = new ArrayList<>();
        java.util.Iterator<Seat> iterator = seatMatrix.values().iterator();
        while (iterator.hasNext()) {
            Seat seat = iterator.next();
            if (!seat.isReserveStatus() && seat.getClass_() == seatClass) {
                availableSeats.add(seat);
            }
        }
        return availableSeats;
    }

    /**
     * Tüm koltukları döndürür.
     */
    public List<Seat> getAllSeats() {
        return new ArrayList<>(seatMatrix.values());
    }

    /**
     * Boş koltuk sayısını döndürür.
     */
    public int getAvailableSeatCount() {
        int count = 0;
        java.util.Iterator<Seat> iterator = seatMatrix.values().iterator();
        while (iterator.hasNext()) {
            Seat seat = iterator.next();
            if (!seat.isReserveStatus()) {
                count++;
            }
        }
        return count;
    }

    /**
     * Dolu koltuk sayısını döndürür.
     */
    public int getReservedSeatCount() {
        return capacity - getAvailableSeatCount();
    }

    /**
     * Tüm koltukları serbest bırakır.
     */
    public void resetAllSeats() {
        java.util.Iterator<Seat> iterator = seatMatrix.values().iterator();
        while (iterator.hasNext()) {
            Seat seat = iterator.next();
            seat.release();
        }
    }

    // Getter ve Setter metodları
    public String getPlaneId() {
        return planeId;
    }

    public void setPlaneId(String planeId) {
        this.planeId = planeId;
    }

    public String getPlaneModel() {
        return planeModel;
    }

    public void setPlaneModel(String planeModel) {
        this.planeModel = planeModel;
    }

    public int getCapacity() {
        return capacity;
    }

    public Map<String, Seat> getSeatMatrix() {
        return seatMatrix;
    }

    public int getRows() {
        return rows;
    }

    public int getSeatsPerRow() {
        return seatsPerRow;
    }

    public int getBusinessRows() {
        return businessRows;
    }

    @Override
    public String toString() {
        return String.format("Plane{id='%s', model='%s', capacity=%d, available=%d}",
                planeId, planeModel, capacity, getAvailableSeatCount());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Plane plane = (Plane) o;
        return planeId != null && planeId.equals(plane.planeId);
    }

    @Override
    public int hashCode() {
        return planeId != null ? planeId.hashCode() : 0;
    }
}
