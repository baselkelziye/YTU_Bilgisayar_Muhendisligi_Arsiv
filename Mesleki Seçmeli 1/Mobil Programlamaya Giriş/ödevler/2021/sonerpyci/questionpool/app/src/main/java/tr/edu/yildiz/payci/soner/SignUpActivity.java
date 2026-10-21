package tr.edu.yildiz.payci.soner;

import android.app.Activity;
import android.app.DatePickerDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.shapes.Shape;
import android.support.constraint.ConstraintLayout;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.PhoneNumberFormattingTextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;
import java.util.regex.Pattern;

import tr.edu.yildiz.payci.soner.DAL.DbHelper;
import tr.edu.yildiz.payci.soner.model.Person;
import tr.edu.yildiz.payci.soner.model.UserBase;

import static tr.edu.yildiz.payci.soner.helpers.IOStream.readAllBytes;

public class SignUpActivity extends AppCompatActivity {
    final Integer PICK_PHOTO_FOR_AVATAR = 1;
    final Calendar myCalendar = Calendar.getInstance();
    final Pattern EMAIL_REGEX = Pattern.compile("(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|\\\"(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21\\x23-\\x5b\\x5d-\\x7f]|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])*\\\")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21-\\x5a\\x53-\\x7f]|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])+)\\])", Pattern.CASE_INSENSITIVE);
    byte[] selectedAvatar = new byte[]{};
    DbHelper dbHelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);

        ActionBar actionBar = getSupportActionBar();
        actionBar.hide();

        dbHelper = new DbHelper(this);

        defineListeners();
    }

    private void updateDatePickerOnSelect() {
        EditText birthDateField = (EditText) findViewById(R.id.birthDate);
        String myFormat = "dd/MM/yyyy"; //In which you need put here
        SimpleDateFormat sdf = new SimpleDateFormat(myFormat, Locale.US);
        birthDateField.setText(sdf.format(myCalendar.getTime()));
    }

    public void defineListeners() {
        EditText phoneField = (EditText) findViewById(R.id.phoneTxt);
        phoneField.addTextChangedListener(new PhoneNumberFormattingTextWatcher());

        EditText birthDateField = (EditText) findViewById(R.id.birthDate);
        ConstraintLayout avatarBox = (ConstraintLayout) findViewById(R.id.avatarBox);

        DatePickerDialog.OnDateSetListener date = (view, year, monthOfYear, dayOfMonth) -> {
            myCalendar.set(Calendar.YEAR, year);
            myCalendar.set(Calendar.MONTH, monthOfYear);
            myCalendar.set(Calendar.DAY_OF_MONTH, dayOfMonth);
            updateDatePickerOnSelect();
        };

        birthDateField.setOnClickListener((v) -> {
            new DatePickerDialog(SignUpActivity.this, date, myCalendar
                    .get(Calendar.YEAR), myCalendar.get(Calendar.MONTH),
                    myCalendar.get(Calendar.DAY_OF_MONTH)).show();
        });

        avatarBox.setOnClickListener((v) -> {
            Intent intent = new Intent();
            intent.setType("image/*");
            intent.setAction(Intent.ACTION_GET_CONTENT);
            startActivityForResult(
                    Intent.createChooser(intent, "Complete action using"),
                    PICK_PHOTO_FOR_AVATAR);
        });

        Button btnSignUp = (Button) findViewById(R.id.signUpBtn);
        btnSignUp.setOnClickListener((v) -> {

            EditText firstName = (EditText) findViewById(R.id.firstNameTxt);
            EditText lastName = (EditText) findViewById(R.id.lastNameTxt);
            EditText email = (EditText) findViewById(R.id.emailTxt);
            EditText phone = (EditText) findViewById(R.id.phoneTxt);
            EditText birthDate = (EditText) findViewById(R.id.birthDate);
            EditText password = (EditText) findViewById(R.id.passTxt);
            EditText passwordRe = (EditText) findViewById(R.id.passReTxt);

            boolean canSignup = validateInputForm(firstName, lastName, email, phone, birthDate, password, passwordRe);

            if (canSignup) {
                try {
                    signUp(firstName, lastName, email, phone, birthDate, password);
                } catch (ParseException e) {
                    e.printStackTrace();
                    Toast.makeText(SignUpActivity.this, "Signup UN-successfull!", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == PICK_PHOTO_FOR_AVATAR && resultCode == Activity.RESULT_OK) {
            if (data == null) {
                Toast.makeText(SignUpActivity.this, "Dosya Okunamadı.", Toast.LENGTH_SHORT).show();
                return;
            }
            try {
                InputStream inputStream = this.getContentResolver().openInputStream(data.getData());
                selectedAvatar = readAllBytes(inputStream);

                Bitmap bmp = BitmapFactory.decodeByteArray(selectedAvatar, 0, selectedAvatar.length);
                ImageView image = (ImageView) findViewById(R.id.avatarImage);
                image.setImageBitmap(Bitmap.createScaledBitmap(bmp, image.getWidth(), image.getHeight(), false));

            } catch (IOException e) {
                Toast.makeText(SignUpActivity.this, "Sistem Belirtilen Dosyayı Bulamıyor.", Toast.LENGTH_SHORT).show();
            }
            //Now you can do whatever you want with your inpustream, save it as file, upload to a server, decode a bitmap...


        }
    }

    public void signUp(EditText firstName, EditText lastName, EditText email, EditText phone, EditText birthDate, EditText password) throws ParseException {
        // hash password
        String hashedPassword = UserBase.convertStringToSHA256(password.getText().toString()) ;

        // convert birthDate to Date
        Date birthDateAsDate = new SimpleDateFormat("dd/MM/yyyy", Locale.US).parse(birthDate.getText().toString());

        Person person = new Person(
                0,
                firstName.getText().toString().trim(),
                lastName.getText().toString().trim(),
                email.getText().toString().trim(),
                hashedPassword,
                selectedAvatar,
                phone.getText().toString().trim(),
                birthDateAsDate
        );

        // insert new user and grab new user object with Id value.
        person = dbHelper.insertUser(person);

        if (person.getId() != 0){
            Toast.makeText(SignUpActivity.this, "Signup successful!", Toast.LENGTH_SHORT).show();
            Intent intent = new Intent(SignUpActivity.this, ScreenSlideFragmentPage.class);
            intent.putExtra("userId", person.getId());
            this.startActivity(intent);
        }

    }


    public boolean validateInputForm (EditText firstName, EditText lastName, EditText email, EditText phone, EditText birthDate, EditText password, EditText passwordRe) {

        try {
            //<editor-fold desc="Input Validations">
            if (firstName.getText().toString().length() < 2 || lastName.getText().toString().length() < 2)
                throw new Exception("Firstname and Lastname length cannot be less than 2");

            if ( !( firstName.getText().toString().trim().matches("[a-zA-Z]+( +[a-zA-Z]+)*") &&
                    lastName.getText().toString().trim().matches("[a-zA-Z]+( +[a-zA-Z]+)*") ))
                throw new Exception("Firstname and Lastname cannot contain Numbers or Special Chars");

            if (!password.getText().toString().equals(passwordRe.getText().toString()))
                throw new Exception("Passwords should be matched.");

            if (!email.getText().toString().matches(String.valueOf(EMAIL_REGEX)))
                throw new Exception("Incorrect E-mail Pattern.");
            //</editor-fold>

            //<editor-fold desc="Database Validations">
            if(dbHelper.checkIfUserExists(email.getText().toString()))
                throw new Exception("An user already exists with given email.");
            //</editor-fold>

            return true;
        } catch (Exception E) {
            Toast.makeText(SignUpActivity.this, E.getMessage(), Toast.LENGTH_SHORT).show();
            return false;
        }
    }
}