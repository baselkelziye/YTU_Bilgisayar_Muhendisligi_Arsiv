package com.yapps.mobilodev2

import android.content.Intent
import android.content.pm.PackageManager
import android.net.Uri
import android.os.Build
import android.os.Bundle
import android.widget.EditText
import android.widget.ImageButton
import android.widget.ImageView
import android.widget.Spinner
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.content.res.AppCompatResources
import androidx.cardview.widget.CardView
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProvider
import com.bumptech.glide.Glide
import com.google.android.material.button.MaterialButton
import java.io.File

class UserActivity : AppCompatActivity() {

    private val REQUEST_STORAGE_PERMISSION:Int = 1000

    private lateinit var buttonBack:ImageButton
    private lateinit var imgProfile:ImageView
    private lateinit var etName:EditText
    private lateinit var etSurname:EditText
    private lateinit var etEmail:EditText
    private lateinit var etNumber:EditText
    private lateinit var etType:TextView
    private lateinit var etPhone:EditText
    private lateinit var etPassword:EditText
    private lateinit var etSocial:EditText
    private lateinit var spEducation:Spinner
    private lateinit var buttonUpdate:MaterialButton
    private lateinit var buttonDelete:MaterialButton
    private lateinit var buttonLogout:MaterialButton
    private lateinit var buttonForward:MaterialButton
    private lateinit var card:CardView

    private var uriPath:String = ""

    private lateinit var viewModel: UserViewModel
    private lateinit var factory:UserViewModelFactory

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_user)

        buttonBack = findViewById(R.id.button_back)
        imgProfile = findViewById(R.id.img_profile)
        etName = findViewById(R.id.et_name)
        etSurname = findViewById(R.id.et_surname)
        etEmail = findViewById(R.id.et_email)
        etNumber = findViewById(R.id.et_number)
        etType = findViewById(R.id.et_type)
        etPhone = findViewById(R.id.et_phone)
        etPassword = findViewById(R.id.et_password)
        etSocial = findViewById(R.id.et_social)
        spEducation = findViewById(R.id.sp_education)
        buttonUpdate = findViewById(R.id.button_update)
        buttonDelete = findViewById(R.id.button_delete)
        buttonLogout = findViewById(R.id.button_logout)
        buttonForward = findViewById(R.id.button_forward)
        card = findViewById(R.id.card)

        val intent = intent
        val userId:Long = intent.getLongExtra("userId",0L)

        factory = UserViewModelFactory(userId)
        viewModel = ViewModelProvider(this,factory)[UserViewModel::class.java]

        viewModel.user.observe(this, Observer {  user ->
            if(user != null){
                updateScreen(user)
            }else{
                ThisApplication.sharedPrefs.setRemember(false)
                val intent = Intent(this,MainActivity::class.java)
                startActivity(intent)
                finish()
            }
        })

        viewModel.updateMessage.observe(this, Observer { message ->
            if(message != null){
                Toast.makeText(this,message,Toast.LENGTH_SHORT).show()
            }
        })

        buttonBack.setOnClickListener{
            ThisApplication.sharedPrefs.setRemember(false)
            val intent = Intent(this,MainActivity::class.java)
            startActivity(intent)
            finish()
        }

        buttonUpdate.setOnClickListener {
            viewModel.updateUser(etName.text.toString(),etSurname.text.toString(),etNumber.text.toString(),etEmail.text.toString(),etPassword.text.toString(),etSocial.text.toString(),uriPath,spEducation.selectedItemPosition,etPhone.text.toString())
        }

        buttonDelete.setOnClickListener {
            viewModel.deleteAccount()
        }

        buttonLogout.setOnClickListener {
            ThisApplication.sharedPrefs.setRemember(false)
            val intent = Intent(this,MainActivity::class.java)
            startActivity(intent)
            finish()
        }

        val galleryLauncher = registerForActivityResult(ActivityResultContracts.GetContent()) {
            val galleryUri = it
            try{
                uriPath = galleryUri.toString()
                Glide.with(applicationContext).load(Uri.parse(uriPath)).into(imgProfile)
            }catch(e:Exception){
                e.printStackTrace()
            }

        }

        card.setOnClickListener {
            if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU){
                if (ContextCompat.checkSelfPermission(this, android.Manifest.permission.READ_MEDIA_IMAGES) != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(this, arrayOf(android.Manifest.permission.READ_MEDIA_IMAGES), REQUEST_STORAGE_PERMISSION)
                }else{
                    galleryLauncher.launch("image/*")
                }
            }else{
                if (ContextCompat.checkSelfPermission(this, android.Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(this, arrayOf(android.Manifest.permission.READ_EXTERNAL_STORAGE), REQUEST_STORAGE_PERMISSION)
                }else{
                    galleryLauncher.launch("image/*")
                }
            }

        }

        buttonForward.setOnClickListener {
            // Alıcı e-posta adresi
            val recipient = "destek@example.com"

            // E-posta konusu
            val subject = "Konu: Yardım İstiyorum"

            // E-posta mesajı
            val message = "Merhaba, \n\nYardımınıza ihtiyacım var."

            // E-posta yönlendirme Intent'i oluştur
            val emailIntent = Intent(Intent.ACTION_SENDTO, Uri.parse("mailto:$recipient"))
            emailIntent.putExtra(Intent.EXTRA_SUBJECT, subject)
            emailIntent.putExtra(Intent.EXTRA_TEXT, message)

            // E-posta uygulamasına yönlendir
            startActivity(Intent.createChooser(emailIntent, "E-posta Gönder"))
        }

    }
    private fun updateScreen(user:User){
        etName.setText(user.name)
        etSurname.setText(user.surname)
        etEmail.setText(user.email)
        etNumber.setText(user.studentId)
        etType.text = user.type
        etPassword.setText(user.password)
        etSocial.setText(user.instagram)
        etPhone.setText(user.phone)
        spEducation.setSelection(user.education)
        try{
            //Glide.with(applicationContext).load(Uri.parse(user.imagePath)).into(imgProfile)
            //Glide.with(applicationContext).load(Uri.fromFile(File(user.imagePath))).into(imgProfile)
            imgProfile.setImageURI(Uri.parse(user.imagePath))
        }catch (e:Exception){
            Toast.makeText(this,e.toString(),Toast.LENGTH_SHORT).show()
            imgProfile.setImageDrawable(AppCompatResources.getDrawable(this,R.drawable.baseline_account_circle_24))
            e.printStackTrace()
        }
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        when (requestCode) {
            REQUEST_STORAGE_PERMISSION -> {
                // Kullanıcı kameraya erişim izni isteğine yanıt verdiğinde bu blok çalışır
                if (grantResults.isNotEmpty() && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    // Kullanıcı izni kabul etti, kameraya erişim sağlandı
                    // Burada kamera işlemlerini yapabilirsiniz
                } else {
                    // Kullanıcı izni reddetti veya iptal etti, uygun bir geri bildirim sağlayabilirsiniz
                }
            }
            // Diğer izinler için ek bloklar ekleyebilirsiniz
        }
    }
}