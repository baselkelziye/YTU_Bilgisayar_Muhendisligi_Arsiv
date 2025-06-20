package com.savt.listopia.service;

import org.springframework.stereotype.Service;

@Service
public interface CaptchaService {
    void validateCaptcha(String captcha, String action, String remoteIp);
}