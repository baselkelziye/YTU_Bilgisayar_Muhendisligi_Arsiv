package com.savt.listopia.exception;

public class ResourceAlreadyExistException extends RuntimeException {
    private String resourceName;
    private String field;
    private String fieldName;
    private Long fieldId;

    public ResourceAlreadyExistException() {}

    public ResourceAlreadyExistException(String resourceName, String field, String fieldName) {
        super(String.format("%s already exist with %s: %s", resourceName, field, fieldName));
        this.resourceName = resourceName;
        this.field = field;
        this.fieldName = fieldName;
    }

    public ResourceAlreadyExistException(String resourceName, String field, Long fieldId) {
        super(String.format("%s already exist with  %s: %d", resourceName, field, fieldId));
        this.resourceName = resourceName;
        this.field = field;
        this.fieldId = fieldId;
    }
}
