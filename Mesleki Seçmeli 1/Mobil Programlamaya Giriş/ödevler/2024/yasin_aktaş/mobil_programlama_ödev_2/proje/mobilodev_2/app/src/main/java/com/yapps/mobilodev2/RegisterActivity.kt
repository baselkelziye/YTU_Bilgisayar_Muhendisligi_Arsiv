package com.yapps.mobilodev2

import android.os.Bundle
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProvider
import com.google.android.material.button.MaterialButton
import com.google.android.material.textfield.TextInputEditText

class RegisterActivity : AppCompatActivity() {

    private lateinit var viewModel: RegisterViewModel
    private lateinit var factory:RegisterViewModelFactory

    private lateinit var etName:TextInputEditText
    private lateinit var etSurname:TextInputEditText
    private lateinit var etStudentNumber:TextInputEditText
    private lateinit var etEmail:TextInputEditText
    private lateinit var etPassword:TextInputEditText
    private lateinit var etPasswordAgain:TextInputEditText
    private lateinit var button:MaterialButton

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_register)

        factory = RegisterViewModelFactory()
        viewModel = ViewModelProvider(this,factory)[RegisterViewModel::class.java]

        etName = findViewById(R.id.etName)
        etSurname = findViewById(R.id.etSurname)
        etStudentNumber = findViewById(R.id.etNumber)
        etEmail = findViewById(R.id.etEmail)
        etPassword = findViewById(R.id.etPassword)
        etPasswordAgain = findViewById(R.id.etPasswordAgain)
        button = findViewById(R.id.button)

        viewModel.registerMessage.observe(this, Observer { message ->
            if(message != null){
                Toast.makeText(this,message,Toast.LENGTH_SHORT).show()
            }
        })

        viewModel.registerResult.observe(this, Observer { result ->
            if(result != null && result){
                finish()
            }
        })

        button.setOnClickListener {
            viewModel.registerUser(
                etName.text.toString(),
                etSurname.text.toString(),
                etStudentNumber.text.toString(),
                etEmail.text.toString(),
                etPassword.text.toString(),
                etPasswordAgain.text.toString()
            )
        }

    }
}