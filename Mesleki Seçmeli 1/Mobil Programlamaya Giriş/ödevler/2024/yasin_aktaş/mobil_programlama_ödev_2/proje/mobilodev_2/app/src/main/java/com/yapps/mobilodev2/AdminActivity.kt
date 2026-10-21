package com.yapps.mobilodev2

import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.android.material.button.MaterialButton

class AdminActivity : AppCompatActivity() {

    private lateinit var button:MaterialButton

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_admin)

        button = findViewById(R.id.button)

        button.setOnClickListener {
            finish()
        }

    }
}