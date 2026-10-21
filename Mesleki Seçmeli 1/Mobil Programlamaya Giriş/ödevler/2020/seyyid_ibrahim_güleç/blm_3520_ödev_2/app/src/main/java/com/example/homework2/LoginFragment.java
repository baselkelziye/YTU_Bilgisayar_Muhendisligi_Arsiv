package com.example.homework2;


import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.preference.PreferenceManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;


/**
 * A simple {@link Fragment} subclass.
 */
public class LoginFragment extends Fragment {
    private Button login_btn;
    private EditText username_et, password_et;

    private TextView tx1;
    private int counter = 3;
    private String username_str, password_str;
    private SharedPreferences preferences;

    public LoginFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        final View view = inflater.inflate(R.layout.fragment_login, container, false);

        login_btn = (Button) view.findViewById(R.id.btn_login);

        tx1 = (TextView) view.findViewById(R.id.counter_text);

        preferences = PreferenceManager.getDefaultSharedPreferences(getActivity().getApplicationContext());

        login_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                username_et = (EditText) view.findViewById(R.id.et_username_login);
                password_et = (EditText) view.findViewById(R.id.et_password_login);

                username_str = username_et.getText().toString();
                password_str = password_et.getText().toString();

                if(password_str.equals(preferences.getString(username_str, null))) {
                    Toast.makeText(getActivity().getApplicationContext(),
                            "User successfully logged in",Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(getActivity().getApplicationContext(), MenuActivity.class);
                    startActivity(intent);
                }else{
                    Toast.makeText(getActivity().getApplicationContext(), "Wrong Credentials",Toast.LENGTH_SHORT).show();

                    tx1.setVisibility(View.VISIBLE);
                    counter--;
                    tx1.setText(Integer.toString(counter));

                    if (counter == 0) {
                        login_btn.setEnabled(false);
                        getActivity().finish();
                    }
                }
            }
        });

        return view;
    }

}
