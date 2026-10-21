package com.bariscanyilmaz.musicplayer.view;

import androidx.appcompat.app.AppCompatActivity;
import androidx.room.Room;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Toast;

import com.bariscanyilmaz.musicplayer.databinding.ActivityRegisterBinding;
import com.bariscanyilmaz.musicplayer.model.User;
import com.bariscanyilmaz.musicplayer.roomdb.AppDatabase;

public class RegisterActivity extends AppCompatActivity {

    private ActivityRegisterBinding binding;

    private AppDatabase db;

    final String emailPattern = "[a-zA-Z0-9._-]+@[a-z]+\\.+[a-z]+";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding= ActivityRegisterBinding.inflate(getLayoutInflater());
        View view=binding.getRoot();
        setContentView(view);
        db= Room.databaseBuilder(getApplicationContext(), AppDatabase.class,"app-db").allowMainThreadQueries().build();


        binding.registerFullname.addTextChangedListener(textWatcher);
        binding.registerEmail.addTextChangedListener(textWatcher);
        binding.registerPassword.addTextChangedListener(textWatcher);
        binding.registerPasswordAgain.addTextChangedListener(textWatcher);

    }

    private final TextWatcher textWatcher=new TextWatcher() {
        @Override
        public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

        }

        @Override
        public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            String fullNameInput=binding.registerFullname.getText().toString();
            String emailInput =binding.registerEmail.getText().toString();
            String passwordInput =binding.registerPassword.getText().toString();
            String passwordInputAgain =binding.registerPasswordAgain.getText().toString();

            binding.registerButton.setEnabled(
                    !fullNameInput.isEmpty() && !emailInput.isEmpty() && !passwordInput.isEmpty() && !passwordInputAgain.isEmpty()
            );

        }

        @Override
        public void afterTextChanged(Editable editable) {

        }
    };


    public void register(View view){

        //TODO user image
        //TODO send email
        String email = binding.registerEmail.getText().toString();
        String fullName = binding.registerFullname.getText().toString();
        String password = binding.registerPassword.getText().toString();
        String passwordAgain = binding.registerPasswordAgain.getText().toString();

        User user=db.userDao().getUserByEmail(email);

        if(email.matches(emailPattern) && user==null && password.equals(passwordAgain)){
            
            user=new User(email, password, fullName);
            db.userDao().insert(user);
            //send mail to user.mail
            Toast.makeText(this, "User created successfully", Toast.LENGTH_SHORT).show();
            redirectToLogin();

        }else{

            if(!email.matches(emailPattern)){
                binding.registerEmail.setError("Email is not valid");
            }
            
            if(user!=null){
                binding.registerEmail.setError("Email has already taken");
            }
            
            if(!password.equals(passwordAgain)){
                binding.registerPasswordAgain.setError("Passwords are not matching");
            }

        }
    }

    private void redirectToLogin(){
        Intent intent=new Intent(this,LoginActivity.class);
        startActivity(intent);
        finish();
    }
}