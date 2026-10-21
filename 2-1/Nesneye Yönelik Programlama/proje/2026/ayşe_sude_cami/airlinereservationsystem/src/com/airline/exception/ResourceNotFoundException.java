package com.airline.exception;

/**
 * Genel kaynak bulunamadığında fırlatılan exception.
 * Uçak, kullanıcı, yolcu vb. kaynaklar bulunamadığında kullanılır.
 */
public class ResourceNotFoundException extends AirlineException {
    private static final long serialVersionUID = 1L;

    private final String resourceType;
    private final String resourceId;

    public ResourceNotFoundException(String resourceType) {
        super(resourceType + " bulunamadı", "RN-001");
        this.resourceType = resourceType;
        this.resourceId = null;
    }

    public ResourceNotFoundException(String resourceType, String resourceId) {
        super(resourceType + " bulunamadı: " + resourceId, "RN-001");
        this.resourceType = resourceType;
        this.resourceId = resourceId;
    }

    public String getResourceType() {
        return resourceType;
    }

    public String getResourceId() {
        return resourceId;
    }
}
