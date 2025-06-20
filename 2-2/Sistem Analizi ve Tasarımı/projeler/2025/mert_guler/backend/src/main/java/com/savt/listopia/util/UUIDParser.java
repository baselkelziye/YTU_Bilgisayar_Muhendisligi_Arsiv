package com.savt.listopia.util;

import com.savt.listopia.exception.APIException;

import java.util.UUID;

public class UUIDParser {
    public static UUID parseUUIDorThrow(String uuid, RuntimeException throwable) {
        try {
            return UUID.fromString(uuid);
        } catch (Exception e) {
            throw throwable;
        }
    }

    public static UUID parseUUIDorThrow(String uuid) {
        return parseUUIDorThrow(uuid, new APIException("invalid_uuid"));
    }

    public static UUID parse(String uuid) {
        return parseUUIDorThrow(uuid);
    }

    public static UUID parseOrNull(String uuid) {
        try {
            return parse(uuid);
        } catch (Exception e) {
            return null;
        }
    }
}
