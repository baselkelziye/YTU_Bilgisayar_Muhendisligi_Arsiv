package mobil.prog.music_app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class RegisterActivity extends AppCompatActivity {

    EditText txt_username, txt_phone, txt_email, txt_password, txt_repassword;
    Button btn_register, btn_login;
    DBHelper DB;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        //-----------------------------------------
        txt_username = findViewById(R.id.txt_username);
        txt_phone = findViewById(R.id.txt_phone);
        txt_email = findViewById(R.id.txt_email);
        txt_password = findViewById(R.id.txt_password);
        txt_repassword = findViewById(R.id.txt_repassword);

        btn_register = findViewById(R.id.btn_register);
        btn_login = findViewById(R.id.btn_login);

        DB = new DBHelper(this);

        btn_register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String user = txt_username.getText().toString();
                String password = txt_password.getText().toString();
                String repassword = txt_repassword.getText().toString();

                if(user.equals("") || password.equals("") || repassword.equals("")){
                    Toast.makeText(RegisterActivity.this, "Please fill in the blank fields.", Toast.LENGTH_SHORT).show();
                }
                else{
                    if(password.equals(repassword)){
                        Boolean checkuser = DB.checkusername(user);
                        if(checkuser == false){
                            Boolean insert = DB.insertData(user,password);
                            if (insert == true){

                                /*
                                Intent intent_email = new Intent(Intent.ACTION_SENDTO);
                                intent_email.putExtra(Intent.EXTRA_EMAIL, txt_email.getText().toString());
                                intent_email.putExtra(Intent.EXTRA_TEXT, txt_phone.getText().toString());
                                intent_email.setType("message/rfc822");
                                startActivity(Intent.createChooser(intent_email, "Choose an email client:"));
                                */

                                Toast.makeText(RegisterActivity.this, "Successful registration.", Toast.LENGTH_SHORT).show();
                                Intent intent = new Intent(getApplicationContext(), MainActivity.class);

                                startActivity(intent);
                            }
                            else{
                                Toast.makeText(RegisterActivity.this, "Failed registration.", Toast.LENGTH_SHORT).show();
                            }
                        }
                        else{
                            Toast.makeText(RegisterActivity.this, "Username is already taken.", Toast.LENGTH_SHORT).show();
                        }
                    }
                    else{
                        Toast.makeText(RegisterActivity.this, "Passwords not matching.", Toast.LENGTH_SHORT).show();
                    }
                }


                //------------------------------------------------
                Intent intentBack = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(intentBack);
            }
        });

        btn_login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intentLogin = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(intentLogin);
            }
        });


    }
}