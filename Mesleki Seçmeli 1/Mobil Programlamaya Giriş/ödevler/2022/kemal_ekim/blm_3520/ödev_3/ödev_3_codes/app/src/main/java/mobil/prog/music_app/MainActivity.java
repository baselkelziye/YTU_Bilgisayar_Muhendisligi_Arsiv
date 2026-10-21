package mobil.prog.music_app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText txt_username, txt_password;
    Button btnLogin, btnRegister;
    DBHelper DB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //-----------------------------------------
        txt_username = findViewById(R.id.txt_username);
        txt_password = findViewById(R.id.txt_password);
        btnLogin = findViewById(R.id.btn_login);
        btnRegister = findViewById(R.id.btn_register);
        DB = new DBHelper(this);


        // register sayfasına geçiş
        btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, RegisterActivity.class));
            }
        });


        // hak sayısı = 3
        final int[] attempt = {0};
        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                String user = txt_username.getText().toString();
                String password = txt_password.getText().toString();

                if (attempt[0] < 2){
                    if (user.equals("") || password.equals("")) {
                        String attemptsLeft = String.format("Attempts left: %d", 2 - attempt[0]);
                        Toast.makeText(MainActivity.this, "Please fill the blank fields." + "\n" + attemptsLeft, Toast.LENGTH_SHORT).show();
                        attempt[0]++;
                    } else {
                        Boolean checkuserpass = DB.checkusernamepassword(user, password);
                        if (checkuserpass == true) {
                            Toast.makeText(MainActivity.this, "Successfull login.", Toast.LENGTH_SHORT).show();
                            Intent intent = new Intent(getApplicationContext(), SongslistActivity.class);
                            startActivity(intent);
                        } else {
                            String attemptsLeft = String.format("Attempts left: %d", 2 - attempt[0]);
                            attempt[0]++;
                            Toast.makeText(MainActivity.this, "Please check your values." +  "\n" + attemptsLeft, Toast.LENGTH_SHORT).show();
                        }
                    }
                }
                else{
                    Toast.makeText(MainActivity.this, "Too many invalid attempts.", Toast.LENGTH_SHORT).show();
                    Intent intent1 = new Intent(getApplicationContext(), RegisterActivity.class);
                    startActivity(intent1);
                }


            }
        });


    }


}