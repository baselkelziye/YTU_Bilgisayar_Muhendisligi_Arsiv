package com.example.ytumezunandroidapp;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.TaskStackBuilder;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.HashMap;

public class ResetPassword extends AppCompatActivity {

    EditText email, newPassword, newPassword2;
    Button update;

    private FirebaseAuth mAuth;
    public FirebaseUser mUser;
    private DatabaseReference mReference;
    HashMap<String, Object> mData;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_resetpassword);

        email = (EditText) findViewById(R.id.resetpassword_et_email);
        newPassword = (EditText) findViewById(R.id.resetpassword_et_newPassword);
        newPassword2 = (EditText) findViewById(R.id.resetpassword_et_newPassword2);

        update = (Button) findViewById(R.id.resetpassword_bt_update);

        mAuth = FirebaseAuth.getInstance();
        mReference = FirebaseDatabase.getInstance().getReference();

        update.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                resetPassword(v);
            }
        });
    }

    public void resetPassword(View view){
        if (!TextUtils.isEmpty(email.getText().toString()) && !TextUtils.isEmpty(newPassword.getText().toString())
            && !TextUtils.isEmpty(newPassword2.getText().toString())){
                mUser = mAuth.getCurrentUser();

                assert  mUser != null;

                mAuth.sendPasswordResetEmail(email.getText().toString())
                        .addOnCompleteListener(new OnCompleteListener<Void>() {
                            @Override
                            public void onComplete(@NonNull Task<Void> task) {
                                if(task.isSuccessful()){
                                    Toast.makeText(ResetPassword.this, "E-postayı Kontrol Ediniz...", Toast.LENGTH_SHORT).show();
                                    mData = new HashMap<>();
                                    mData.put("sifre", newPassword.getText().toString());
                                    mReference = FirebaseDatabase.getInstance().getReference("Kullanicilar").child(mUser.getUid());
                                    mReference.updateChildren(mData)
                                            .addOnCompleteListener(ResetPassword.this, new OnCompleteListener<Void>() {
                                                @Override
                                                public void onComplete(@NonNull Task<Void> task) {
                                                    if(task.isSuccessful()){
                                                        Toast.makeText(ResetPassword.this, "E-postayı Kontrol Ediniz...", Toast.LENGTH_SHORT).show();
                                                        Intent intent = new Intent(getApplicationContext(), Login.class);
                                                        startActivity(intent);
                                                    }
                                                    else{
                                                        Toast.makeText(ResetPassword.this, "Şifre Güncellenemedi!", Toast.LENGTH_SHORT).show();
                                                    }
                                                }
                                            });
                                }
                                else {
                                    Toast.makeText(ResetPassword.this, "Şifre Güncellenemedi!", Toast.LENGTH_SHORT).show();
                                }
                            }
                        });
        }
        else{
            Toast.makeText(this, "Yukarıdaki Alanların Doldurulması Zorunludur!", Toast.LENGTH_SHORT).show();
        }
    }
}
