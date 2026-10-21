package com.airline.model;

import com.airline.model.enums.SeatClass;
import java.io.Serializable;

/**
 * Uçaktaki bir koltuğu temsil eder.
 * Örnek koltuk numarası: "15A" (15. sıra, A kolonu)
 */
public class Seat implements Serializable {
    private static final long serialVersionUID = 2L;  // Versiyon güncellendi

    private String seatNum;      // Örn: "15A"
    private SeatClass Class; // ECONOMY veya BUSINESS
    private double price;        // Koltuk fiyatı
    private boolean reserveStatus;    // Rezerve edilmiş mi?
    private int row;             // Sıra numarası
    private char column;         // Kolon harfi (A, B, C, D, E, F)

    // Eski field isimleri için geçici değişkenler (backward compatibility)
    @SuppressWarnings("unused")
    private transient SeatClass seatClass;
    @SuppressWarnings("unused")
    private transient boolean reserved;

    /**
     * Yeni bir koltuk oluşturur.
     * @param seatNum Koltuk numarası (örn: "15A")
     * @param Class Koltuk sınıfı (ECONOMY/BUSINESS)
     * @param price Baz fiyat
     */
    public Seat(String seatNum, SeatClass Class, double price) {
        this.seatNum = seatNum;
        this.Class = Class;
        this.price = price;
        this.reserveStatus = false;
        parseSeatNum(seatNum);
    }

    /**
     * Koltuk numarasından sıra ve kolon bilgisini çıkarır.
     */
    private void parseSeatNum(String seatNum) {
        if (seatNum != null && seatNum.length() >= 2) {
            try {
                this.row = Integer.parseInt(seatNum.substring(0, seatNum.length() - 1));
                this.column = seatNum.charAt(seatNum.length() - 1);
            } catch (NumberFormatException e) {
                this.row = 0;
                this.column = 'A';
            }
        }
    }

    /**
     * Koltuğu rezerve eder.
     */
    public synchronized void reserve() {
        this.reserveStatus = true;
    }

    /**
     * Koltuk rezervasyonunu iptal eder.
     */
    public synchronized void release() {
        this.reserveStatus = false;
    }

    /**
     * Koltuğun rezerve edilip edilmediğini kontrol eder.
     */
    public boolean isReserveStatus() {
        return reserveStatus;
    }

    /**
     * Koltuk sınıfına göre hesaplanmış fiyatı döndürür.
     */
    public double getCalculatedPrice() {
        return price * Class.getPriceMultiplier();
    }

    // Getter ve Setter metodları
    public String getSeatNum() {
        return seatNum;
    }

    public void setSeatNum(String seatNum) {
        this.seatNum = seatNum;
        parseSeatNum(seatNum);
    }

    public SeatClass getClass_() {
        return Class;
    }

    public void setClass_(SeatClass Class) {
        this.Class = Class;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setReserveStatus(boolean reserveStatus) {
        this.reserveStatus = reserveStatus;
    }

    public int getRow() {
        return row;
    }

    public char getColumn() {
        return column;
    }

    @Override
    public String toString() {
        return String.format("Koltuk %s (%s)",
                seatNum, Class.getDisplayName());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Seat seat = (Seat) o;
        return seatNum != null && seatNum.equals(seat.seatNum);
    }

    @Override
    public int hashCode() {
        return seatNum != null ? seatNum.hashCode() : 0;
    }
}
