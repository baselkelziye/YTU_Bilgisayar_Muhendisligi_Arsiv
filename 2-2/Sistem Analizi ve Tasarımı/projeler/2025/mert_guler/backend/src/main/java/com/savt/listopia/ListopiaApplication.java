package com.savt.listopia;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.scheduling.annotation.EnableScheduling;

@EnableScheduling
@SpringBootApplication
public class ListopiaApplication {
    public static void main(String[] args) {
        SpringApplication.run(ListopiaApplication.class, args);
    }
}
