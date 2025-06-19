package com.savt.listopia.model;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Getter;

import java.util.List;

@Getter
public class RecaptchaResponse {

    @JsonProperty("success")
    private Boolean success;

    @JsonProperty("score")
    private Float score;

    @JsonProperty("action")
    private String action;

    @JsonProperty("challenge_ts")
    private String challengeTs;

    @JsonProperty("hostname")
    private String hostname;

    @JsonProperty("error-codes")
    private List<String> errorCodes;

}