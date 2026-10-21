package com.airline.exception;

/**
 * Tekrarlanan kayıt eklenmeye çalışıldığında fırlatılan exception.
 * Aynı uçuş numarası, kullanıcı adı vb. tekrar eklenmeye çalışıldığında kullanılır.
 */
public class DuplicateEntryException extends AirlineException {
    private static final long serialVersionUID = 1L;

    private final String entryType;
    private final String entryValue;

    public DuplicateEntryException(String entryType, String entryValue) {
        super(entryType + " zaten mevcut: " + entryValue, "DE-001");
        this.entryType = entryType;
        this.entryValue = entryValue;
    }

    public String getEntryType() {
        return entryType;
    }

    public String getEntryValue() {
        return entryValue;
    }
}
