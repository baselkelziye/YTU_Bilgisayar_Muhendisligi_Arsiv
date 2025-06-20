package com.savt.listopia.security.auth;

import com.savt.listopia.model.user.Session;
import org.springframework.security.authentication.AbstractAuthenticationToken;

public class AuthenticationToken extends AbstractAuthenticationToken {
    Session session;

    public AuthenticationToken(Session session) {
        super(null);
        this.session = session;
        setAuthenticated(true);
    }

    @Override
    public Object getCredentials() {
        return null;
    }

    @Override
    public Session getPrincipal() {
        return session;
    }
}
