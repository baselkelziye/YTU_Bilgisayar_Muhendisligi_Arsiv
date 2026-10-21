package com.example.must.mobilehomework.file;

import android.content.Context;
import android.widget.Toast;

import com.example.must.mobilehomework.LoginActivity;
import com.example.must.mobilehomework.MainActivity;
import com.example.must.mobilehomework.model.User;

/**
 * Created by must on 30.04.2016.
 */
public class LoginController {
    FileController fc;
    User user;

    public LoginController(){
        fc = new FileController();

    }

    public User controlLoginInput(String userName, String password, Context context){
        String line = fc.getUser(userName, context);

        if(line == null){
            Toast.makeText(context, "Böyle bir kullanıcı adı yok", Toast.LENGTH_SHORT).show();
            return null;
        }
        else{
            String[] userLine  = line.split(" ");
            return new User(userLine[2],userLine[3],userLine[0], userLine[1]);
        }

    }
}
