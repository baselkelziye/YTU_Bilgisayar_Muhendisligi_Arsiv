package tr.edu.yildiz.altugnumanyildiz;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.ImageDecoder;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

public class EditQuestionActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {


    Bitmap selectedImage;
    ImageView questionAddImageView;
    EditText questionText;
    EditText optionA;
    EditText optionB;
    EditText optionC;
    EditText optionD;
    EditText optionE;
    Button saveQuestion;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_question);

        questionAddImageView = (ImageView) findViewById(R.id.questionEditImageView);
        questionText = (EditText) findViewById(R.id.editQuestionText);
        optionA = (EditText) findViewById(R.id.editOptionAText);
        optionB = (EditText) findViewById(R.id.editOptionBText);
        optionC = (EditText) findViewById(R.id.editOptionCText);
        optionD = (EditText) findViewById(R.id.editOptionDText);
        optionE = (EditText) findViewById(R.id.editOptionEText);
        saveQuestion = (Button) findViewById(R.id.editQuestionButton);

        Intent intent = getIntent();
        final Question questionPass = intent.getParcelableExtra("questionPass");


        selectedImage = BitmapFactory.decodeByteArray(questionPass.getByteArrays(),0,questionPass.getByteArrays().length);
        questionAddImageView.setImageBitmap(selectedImage);
        questionText.setText(questionPass.getQuestionText());
        optionA.setText(questionPass.getOptionA());
        optionB.setText(questionPass.getOptionB());
        optionC.setText(questionPass.getOptionC());
        optionD.setText(questionPass.getOptionD());
        optionE.setText(questionPass.getOptionE());

        final Spinner spinner = findViewById(R.id.editSpinner);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this,R.array.options,android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);
        spinner.setOnItemSelectedListener(this);

        char ch1 = questionPass.getCorrectAnswer().charAt(0);
        int selection = Integer.valueOf(ch1 - 'A');

        spinner.setSelection(selection);


        saveQuestion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                byte[] byteArray = save();
                dbOperation db = new dbOperation(getApplicationContext());
                Question question = new Question();

                question.setQuestionText(questionText.getText().toString());
                question.setOptionA(optionA.getText().toString());
                question.setOptionB(optionB.getText().toString());
                question.setOptionC(optionC.getText().toString());
                question.setOptionD(optionD.getText().toString());
                question.setOptionE(optionE.getText().toString());
                question.setDataType("Image");
                question.setCorrectAnswer(spinner.getSelectedItem().toString());
                question.setTeacherID(1);
                question.setQuestionID(questionPass.getQuestionID());
                question.setByteArrays(byteArray);

                boolean result = db.questionUpdate(question);
                db.close();
                if  (result)  {
                    Toast.makeText(getApplicationContext(),"You have successfully updated a new question",Toast.LENGTH_LONG).show();
                    Intent intent = new Intent(getApplicationContext(),QuestionsActivity.class);
                    startActivity(intent);
                }  else {
                    Toast.makeText(getApplicationContext(),"Something went wrong, try again!",Toast.LENGTH_LONG).show();
                }
            }
        });


    }

    @Override
    public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
        String text = adapterView.getItemAtPosition(i).toString();
        Toast.makeText(adapterView.getContext(),text, Toast.LENGTH_LONG);
    }

    @Override
    public void onNothingSelected(AdapterView<?> adapterView) {

    }

    public void selectQuestionImage(View view) {

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED){
            ActivityCompat.requestPermissions(this,new String[] {Manifest.permission.READ_EXTERNAL_STORAGE},1);
        } else {
            Intent intentToGallery = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
            startActivityForResult(intentToGallery,2);
        }

    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {

        if (requestCode == 1) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                Intent intentToGallery = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                startActivityForResult(intentToGallery,2);
            }
        }
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {

        if (requestCode == 2 && resultCode == RESULT_OK && data != null) {

            Uri imageData = data.getData();


            try {

                if (Build.VERSION.SDK_INT >= 28) {

                    ImageDecoder.Source source = ImageDecoder.createSource(this.getContentResolver(),imageData);
                    selectedImage = ImageDecoder.decodeBitmap(source);
                    questionAddImageView.setImageBitmap(selectedImage);

                } else {
                    selectedImage = MediaStore.Images.Media.getBitmap(this.getContentResolver(),imageData);
                    questionAddImageView.setImageBitmap(selectedImage);
                }

            } catch (IOException e) {
                e.printStackTrace();
            }


        }


        super.onActivityResult(requestCode, resultCode, data);
    }

    public byte[] save() {


        Bitmap smallImage = makeSmallerImage(selectedImage,300);

        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        smallImage.compress(Bitmap.CompressFormat.PNG,50,outputStream);
        byte[] byteArray = outputStream.toByteArray();


        return byteArray;
    }

    public Bitmap makeSmallerImage(Bitmap image, int maximumSize) {

        int width = image.getWidth();
        int height = image.getHeight();

        float bitmapRatio = (float) width / (float) height;

        if (bitmapRatio > 1) {
            width = maximumSize;
            height = (int) (width / bitmapRatio);
        } else {
            height = maximumSize;
            width = (int) (height * bitmapRatio);
        }

        return Bitmap.createScaledBitmap(image,width,height,true);
    }
}