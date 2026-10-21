package tr.edu.yildiz.payci.soner;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.ContentResolver;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.v4.app.Fragment;
import android.support.v4.content.FileProvider;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.RecyclerView;
import android.util.Base64;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.VideoView;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.lang.ref.WeakReference;
import java.util.ArrayList;

import tr.edu.yildiz.payci.soner.DAL.DbHelper;
import tr.edu.yildiz.payci.soner.helpers.OnItemClickListener;
import tr.edu.yildiz.payci.soner.helpers.QuestionSpinnerAdapter;
import tr.edu.yildiz.payci.soner.helpers.RecyclerExamsAdapter;
import tr.edu.yildiz.payci.soner.helpers.RecyclerQuestionsAdapter;
import tr.edu.yildiz.payci.soner.helpers.SerializableManager;
import tr.edu.yildiz.payci.soner.model.Exam;
import tr.edu.yildiz.payci.soner.model.Question;
import tr.edu.yildiz.payci.soner.model.QuestionMedia;

import static android.content.Context.MODE_PRIVATE;
import static tr.edu.yildiz.payci.soner.helpers.IOStream.readAllBytes;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link ScreenSlideFragmentHolder#newInstance} factory method to
 * create an instance of this fragment.
 */
public class ScreenSlideFragmentHolder extends Fragment {



    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String FRAGMENT_TYPE = "fragmentType";
    private static final String USER_ID = "userId";
    private static final String MY_PREFS_NAME = "Question_Pool_SP";
    private static final Integer PICK_CONTENT_FOR_QUESTION = 1;


    private int fragmentType;
    private long userId;
    DbHelper dbHelper;
    RecyclerView rv;
    RecyclerView examsRv;
    ImageButton btnAddQuestion;
    ImageButton btnAddExam;
    RecyclerQuestionsAdapter questionsAdapter;
    RecyclerExamsAdapter examsAdapter;
    ArrayList<Question> questions;
    ArrayList<Exam> exams;
    LayoutInflater inflater;
    View popupView;
    byte[] selectedContent = null;
    Uri selectedMediaUri = null;
    String selectedContentType = null;
    boolean playingAudio = false;
    boolean initialized = false;
    private WeakReference<OnItemClickListener> questionListenerRef;
    MediaPlayer mediaPlayer;

    public ScreenSlideFragmentHolder() {
        // Required empty public constructor
    }

    public void setFragmentType(int fragmentType) {
        this.fragmentType = fragmentType;
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param fragmentType Parameter 1.
     * @return A new instance of fragment ScreenSlideFragmentHolder.
     */

    public static ScreenSlideFragmentHolder newInstance(int fragmentType, long userId) {
        ScreenSlideFragmentHolder fragment = new ScreenSlideFragmentHolder();
        fragment.setFragmentType(fragmentType);
        Bundle args = new Bundle();
        args.putInt(FRAGMENT_TYPE, fragmentType);
        args.putLong(USER_ID, userId);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            fragmentType = getArguments().getInt(FRAGMENT_TYPE);
            userId = getArguments().getLong(USER_ID);
            dbHelper = new DbHelper(getContext());
            mediaPlayer = new MediaPlayer();
            mediaPlayer.setLooping(false);


            mediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                @Override
                public void onCompletion(MediaPlayer mp) {
                    playingAudio = false;
                }
            });
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        this.inflater = inflater;
        int resId = R.layout.activity_question;
        switch (fragmentType) {
            case 0:
                resId = R.layout.activity_question;
                break;
            case 1:
                resId = R.layout.activity_exam;
                break;
        }


        View view = (ViewGroup)inflater.inflate(resId, container, false);
        //((ViewPager) container).addView(view, 0);
        return view;
        /*return (ViewGroup) inflater.inflate(
                R.layout.fragment_screen_slide_page, container, false);*/
    }

    @Override
    public void onViewCreated(View view, Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        if (fragmentType == 0) {
            ImageButton btnRefreshQuestions =(ImageButton) view.findViewById(R.id.refresh_questions_btn);
            btnRefreshQuestions.setOnClickListener((v -> {
                refreshQuestions();
            }));

            btnAddQuestion = (ImageButton) view.findViewById(R.id.add_new_question_btn);
            btnAddQuestion.setOnClickListener((v -> {
                createQuestionPopup(view, null);
            }));

            rv = (RecyclerView) view.findViewById(R.id.question_recycler_view);

            questions = dbHelper.getQuestionsByUserId(userId);

            rv.setItemAnimator(new DefaultItemAnimator());
            rv.setNestedScrollingEnabled(false);
            rv.setHasFixedSize(true);

            questionsAdapter = new RecyclerQuestionsAdapter(questions, getContext(), new OnItemClickListener() {

                @Override
                public void onQuestionItemClick(View v, Question item) {
                }
                @Override
                public boolean onQuestionItemLongClick(View v, Question item) {
                    final AlertDialog.Builder builder = new AlertDialog.Builder(v.getContext());
                    builder.setTitle("Attention")
                            .setMessage("Please select an operation to perform for the question " + item.getId())
                            .setNeutralButton("Back", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {

                                }
                            })
                            .setPositiveButton("Edit", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    createQuestionPopup(view, item);
                                }
                            }).setNegativeButton("Delete", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    // TODO : DELETE QUESTION
                                    final AlertDialog.Builder builder2 = new AlertDialog.Builder(builder.getContext());
                                    builder2.setTitle("Question Will Be Deleted")
                                            .setMessage("Are you sure about that?")
                                            .setNeutralButton("No", new DialogInterface.OnClickListener() {
                                                @Override
                                                public void onClick(DialogInterface dialog, int which) {

                                                }
                                            }).setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                                                @Override
                                                public void onClick(DialogInterface dialog, int which) {
                                                    //TODO : DELETE QUESTION
                                                    deleteQuestion(item);
                                                }
                                            }).show();
                                }
                            });

                    builder.create().show();
                    return true;
                }

                @Override
                public void onExamItemClick(View v, Exam item) {

                }

                @Override
                public boolean onExamItemLongClick(View v, Exam item) {
                    return false;
                }

            });
            rv.setAdapter(questionsAdapter);
            refreshQuestions();
        } else if (fragmentType == 1) {
            ImageButton btnRefreshExams =(ImageButton) view.findViewById(R.id.refresh_exams_btn);
            btnRefreshExams.setOnClickListener((v -> {
                refreshExams();
            }));

            btnAddExam = (ImageButton) view.findViewById(R.id.add_new_exam_btn);
            btnAddExam.setOnClickListener((v -> {
                createExamPopup(view, null);
            }));

            examsRv = (RecyclerView) view.findViewById(R.id.exam_recycler_view);

            exams = dbHelper.getExamsByUserId(userId);
            /*exams = new ArrayList<>();
            exams.add(new Exam(1,1, "deneme sınav", 3, 15, 120 ));
            exams.add(new Exam(2,1, "deneme sınav2", 3, 20, 90 ));*/


            examsRv.setItemAnimator(new DefaultItemAnimator());
            examsRv.setNestedScrollingEnabled(false);
            examsRv.setHasFixedSize(true);

            examsAdapter = new RecyclerExamsAdapter(exams, getContext(), new OnItemClickListener() {

                @Override
                public void onQuestionItemClick(View v, Question item) {
                }
                @Override
                public boolean onQuestionItemLongClick(View v, Question item) {
                    return false;
                }

                @Override
                public void onExamItemClick(View v, Exam item) {
                    if(!initialized) {
                        refreshExams();
                        initialized = true;
                    }
                }

                @Override
                public boolean onExamItemLongClick(View v, Exam item) {
                    final AlertDialog.Builder builder = new AlertDialog.Builder(v.getContext());
                    builder.setTitle("Attention")
                            .setMessage("Please select an operation to perform for the question " + item.getId())
                            .setNeutralButton("Back", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {

                                }
                            })
                            .setPositiveButton("Send", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    sendExam2(view, item);
                                }
                            });

                    builder.create().show();
                    return true;
                }

            });
            examsRv.setAdapter(examsAdapter);
            //refreshExams();
        }
    }

    public void refreshQuestions() {
        questionsAdapter.refresh();
    }

    public void refreshExams() {
        examsAdapter.refresh();
    }

    public void deleteQuestion(Question question) {
        try {
            dbHelper.deleteQuestion(question);
            Toast.makeText(getActivity(), "Question Deleted.", Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(getActivity(), "Cannot remove specified question. Question May be used in an exam. Please check it and try again.", Toast.LENGTH_SHORT).show();
        }
        questionsAdapter.removeItem(question);
    }

    @SuppressLint("NonConstantResourceId")
    public void createQuestionPopup(View view, Question question) {
        popupView = inflater.inflate(R.layout.popup_add_edit_question, null);

        // create the popup window
        int width = LinearLayout.LayoutParams.WRAP_CONTENT;
        int height = LinearLayout.LayoutParams.WRAP_CONTENT;
        boolean focusable = true; // lets taps outside the popup also dismiss it
        final PopupWindow popupWindow = new PopupWindow(popupView, width, height, focusable);
        popupWindow.setOutsideTouchable(true);
        // show the popup window
        // which view you pass in doesn't matter, it is only used for the window tolken
        popupWindow.showAtLocation(view, Gravity.CENTER, 0, 0);
        view.setAlpha((float) 0.1);

        popupWindow.setOnDismissListener(new PopupWindow.OnDismissListener() {
            @Override
            public void onDismiss() {
                view.setAlpha((float) 1);
            }
        });

        ImageButton btnPopupAddQuestion = popupView.findViewById(R.id.add_question_btn);
        ImageButton btnPopupEditQuestion = popupView.findViewById(R.id.edit_question_btn);
        FrameLayout frameQuestionContent = popupView.findViewById(R.id.question_content_holder);

        frameQuestionContent.setOnClickListener((v) -> {
            Intent intent = new Intent();
            intent.setType("image/* video/* audio/*");
            intent.setAction(Intent.ACTION_GET_CONTENT);
            startActivityForResult(
                    Intent.createChooser(intent, "Complete action using"),
                    PICK_CONTENT_FOR_QUESTION);
        });

        if (question == null) {
            btnPopupEditQuestion.setVisibility(View.GONE);
            btnPopupAddQuestion.setVisibility(View.VISIBLE);
            btnPopupAddQuestion.setOnClickListener((v -> {
                insertNewQuestionOnClick(popupView);
                popupWindow.dismiss();
            }));

        } else {
            btnPopupAddQuestion.setVisibility(View.GONE);
            btnPopupEditQuestion.setVisibility(View.VISIBLE);

            TextView questionPopupHeader = (TextView) popupView.findViewById(R.id.question_header);
            questionPopupHeader.setText("Edit Question");


            EditText questionTextElement = (EditText) popupView.findViewById(R.id.question_text_input);
            EditText questionOptElement_A = (EditText) popupView.findViewById(R.id.question_A_content);
            EditText questionOptElement_B = (EditText) popupView.findViewById(R.id.question_B_content);
            EditText questionOptElement_C = (EditText) popupView.findViewById(R.id.question_C_content);
            EditText questionOptElement_D = (EditText) popupView.findViewById(R.id.question_D_content);
            EditText questionOptElement_E = (EditText) popupView.findViewById(R.id.question_E_content);

            questionTextElement.setText(question.getText());
            questionOptElement_A.setText(question.getA());
            questionOptElement_B.setText(question.getB());
            questionOptElement_C.setText(question.getC());
            questionOptElement_D.setText(question.getD());
            questionOptElement_E.setText(question.getE());


            RadioGroup radioGroup = (RadioGroup) popupView.findViewById(R.id.radioGroup);

            switch (question.getCorrectAnswer()) {
                case "A":
                    radioGroup.check(R.id.question_radio_A);
                    break;
                case "B":
                    radioGroup.check(R.id.question_radio_B);
                    break;
                case "C":
                    radioGroup.check(R.id.question_radio_C);
                    break;
                case "D":
                    radioGroup.check(R.id.question_radio_D);
                    break;
                case "E":
                    radioGroup.check(R.id.question_radio_E);
                    break;
            }

            if (question.getQuestionMedia() != null) {
                byte[] content = question.getQuestionMedia().getContent();
                String contentType = question.getQuestionMedia().getContentType();
                if (contentType.contains("image")) {
                    //handle image
                    Bitmap bmp = BitmapFactory.decodeByteArray(content, 0, content.length);
                    ImageView image = (ImageView) popupView.findViewById(R.id.question_content_imageBox);
                    image.setImageBitmap(Bitmap.createScaledBitmap(bmp, image.getWidth(), image.getHeight(), false));
                    VideoView video = (VideoView) popupView.findViewById(R.id.question_content_videoBox);
                    ImageView audio = (ImageView) popupView.findViewById(R.id.question_content_audioBox);
                    image.setVisibility(View.VISIBLE);
                    video.setVisibility(View.GONE);
                    audio.setVisibility(View.GONE);

                } else  if (contentType.contains("video")) {
                    //handle video for edit
                } else  if (contentType.contains("audio")) {
                    //handle audio

                    ImageView audioBox = (ImageView) popupView.findViewById(R.id.question_content_audioBox);
                    ImageView image = (ImageView) popupView.findViewById(R.id.question_content_imageBox);
                    VideoView video = (VideoView) popupView.findViewById(R.id.question_content_videoBox);
                    image.setVisibility(View.GONE);
                    video.setVisibility(View.GONE);
                    audioBox.setVisibility(View.VISIBLE);
                }
            }
            btnPopupEditQuestion.setOnClickListener((v -> {
                rv.stopScroll();
                editQuestionOnClick(popupView, question);
                popupWindow.dismiss();
            }));


        }




        // dismiss the popup window when touched
        /*popupView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                popupWindow.dismiss();
                return true;
            }
        });*/

    }

    @SuppressLint("NonConstantResourceId")
    public void createExamPopup(View view, Exam exam) {
        popupView = inflater.inflate(R.layout.popup_add_edit_exam, null);

        // create the popup window
        int width = LinearLayout.LayoutParams.WRAP_CONTENT;
        int height = LinearLayout.LayoutParams.WRAP_CONTENT;
        boolean focusable = true; // lets taps outside the popup also dismiss it
        final PopupWindow popupWindow = new PopupWindow(popupView, width, height, focusable);
        popupWindow.setOutsideTouchable(true);
        // show the popup window
        // which view you pass in doesn't matter, it is only used for the window tolken
        popupWindow.showAtLocation(view, Gravity.CENTER, 0, 0);
        view.setAlpha((float) 0.1);

        popupWindow.setOnDismissListener(new PopupWindow.OnDismissListener() {
            @Override
            public void onDismiss() {
                view.setAlpha((float) 1);
            }
        });


        ImageButton btnPopupAddQuestion = popupView.findViewById(R.id.add_exam_btn);
        ImageButton btnPopupEditQuestion = popupView.findViewById(R.id.edit_exam_btn);

        Spinner spinner = (Spinner) popupView.findViewById(R.id.question_spinner);
        questions = dbHelper.getQuestionsByUserId(userId);
        QuestionSpinnerAdapter myAdapter = new QuestionSpinnerAdapter(getContext(), 0, questions);
        spinner.setAdapter(myAdapter);

        if (exam == null) {
            btnPopupEditQuestion.setVisibility(View.GONE);
            btnPopupAddQuestion.setVisibility(View.VISIBLE);



            EditText examTextElement = (EditText) popupView.findViewById(R.id.exam_name_value);
            EditText examDifficultyTextElement = (EditText) popupView.findViewById(R.id.difficulty_value);
            EditText minDurationElement = (EditText) popupView.findViewById(R.id.min_duration_value);
            EditText maxDurationElement = (EditText) popupView.findViewById(R.id.max_duration_value);

            SharedPreferences prefs = getActivity().getSharedPreferences(MY_PREFS_NAME, MODE_PRIVATE);

            int examDifficulty_SP = prefs.getInt("examDifficulty", 3);
            int examMinDuration_SP = prefs.getInt("examMinDuration", 15);
            int examMaxDuration_SP = prefs.getInt("examMaxDuration", 90);

            examDifficultyTextElement.setText(String.valueOf(examDifficulty_SP));
            minDurationElement.setText(String.valueOf(examMinDuration_SP));
            maxDurationElement.setText(String.valueOf(examMaxDuration_SP));

            btnPopupAddQuestion.setOnClickListener((v -> {
                insertNewExamOnClick(popupView);
                popupWindow.dismiss();
            }));

        } else {
            btnPopupAddQuestion.setVisibility(View.GONE);
            btnPopupEditQuestion.setVisibility(View.VISIBLE);
            EditText examTextElement = (EditText) popupView.findViewById(R.id.exam_name_value);
            EditText examDifficultyTextElement = (EditText) popupView.findViewById(R.id.difficulty_value);
            EditText minDurationElement = (EditText) popupView.findViewById(R.id.min_duration_value);
            EditText maxDurationElement = (EditText) popupView.findViewById(R.id.max_duration_value);

            examTextElement.setText(exam.getExamName());
            examDifficultyTextElement.setText(String.valueOf(exam.getDifficulty()));
            minDurationElement.setText(String.valueOf(exam.getMinDuration()));
            maxDurationElement.setText(String.valueOf(exam.getMaxDuration()));

            btnPopupEditQuestion.setOnClickListener((v -> {
                rv.stopScroll();
                //editExamOnClick(popupView, exam);
                popupWindow.dismiss();
            }));


        }




        // dismiss the popup window when touched
        /*popupView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                popupWindow.dismiss();
                return true;
            }
        });*/

    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        selectedContent = null;
        selectedMediaUri = null;
        selectedContentType = null;
        if (requestCode == PICK_CONTENT_FOR_QUESTION && resultCode == Activity.RESULT_OK) {
            selectedMediaUri = data.getData();
            selectedContentType = getMimeType(selectedMediaUri);
            if (selectedContentType.contains("image")) {
                //handle image
                if (data == null) {
                    Toast.makeText(getActivity(), "Cannot read specified file.", Toast.LENGTH_SHORT).show();
                    return;
                }
                try {
                    InputStream inputStream = getActivity().getContentResolver().openInputStream(data.getData());
                    selectedContent = readAllBytes(inputStream);

                    Bitmap bmp = BitmapFactory.decodeByteArray(selectedContent, 0, selectedContent.length);
                    ImageView image = (ImageView) popupView.findViewById(R.id.question_content_imageBox);
                    image.setImageBitmap(Bitmap.createScaledBitmap(bmp, image.getWidth(), image.getHeight(), false));
                    VideoView video = (VideoView) popupView.findViewById(R.id.question_content_videoBox);
                    ImageView audio = (ImageView) popupView.findViewById(R.id.question_content_audioBox);
                    video.setVisibility(View.GONE);
                    audio.setVisibility(View.GONE);
                } catch (IOException e) {
                    Toast.makeText(getActivity(), "System cannot find specified file.", Toast.LENGTH_SHORT).show();
                }

            } else  if (selectedContentType.contains("video")) {
                //handle video
            } else  if (selectedContentType.contains("audio")) {
                //handle audio

                try {
                    InputStream inputStream = getActivity().getContentResolver().openInputStream(data.getData());
                    selectedContent = readAllBytes(inputStream);
                    ImageView audioBox = (ImageView) popupView.findViewById(R.id.question_content_audioBox);

                    ImageView image = (ImageView) popupView.findViewById(R.id.question_content_imageBox);
                    VideoView video = (VideoView) popupView.findViewById(R.id.question_content_videoBox);
                    image.setVisibility(View.GONE);
                    video.setVisibility(View.GONE);
                    audioBox.setVisibility(View.VISIBLE);
                    /*audioBox.setOnClickListener((v -> {
                        playMp3(selectedContent);
                    }));*/
                    FrameLayout frameQuestionContent = popupView.findViewById(R.id.question_content_holder);
                    frameQuestionContent.setOnClickListener((v) -> {
                        playMp3(selectedContent);
                    });
                } catch (IOException e) {
                    Toast.makeText(getActivity(), "System cannot find specified file.", Toast.LENGTH_SHORT).show();
                }



            }
        }
    }

    public String getMimeType(Uri uri)
    {
        ContentResolver cr = getActivity().getContentResolver();
        return cr.getType(uri);
    }

    private void playMp3(byte[] mp3SoundByteArray)
    {
        try
        {
            if(mediaPlayer!=null) {
                if(mediaPlayer.isPlaying())
                    mediaPlayer.stop();
                mediaPlayer.reset();
                mediaPlayer.release();
                mediaPlayer = null;
                mediaPlayer = new MediaPlayer();
                playingAudio = true;
                //InputStream targetStream = new ByteArrayInputStream(mp3SoundByteArray);
                String base64EncodedString = Base64.encodeToString(mp3SoundByteArray, 0);
                String url = "data:audio/mp3;base64,"+base64EncodedString;
                mediaPlayer.setDataSource(url);
                mediaPlayer.prepare();
                mediaPlayer.start();
                super.onResume();
            }
         }
        catch (IOException ex)
        {
            String s = ex.toString();
            ex.printStackTrace();
        }
    }

    public void insertNewQuestionOnClick(View popupView) {
        EditText questionTextElement = (EditText) popupView.findViewById(R.id.question_text_input);
        EditText questionOptElement_A = (EditText) popupView.findViewById(R.id.question_A_content);
        EditText questionOptElement_B = (EditText) popupView.findViewById(R.id.question_B_content);
        EditText questionOptElement_C = (EditText) popupView.findViewById(R.id.question_C_content);
        EditText questionOptElement_D = (EditText) popupView.findViewById(R.id.question_D_content);
        EditText questionOptElement_E = (EditText) popupView.findViewById(R.id.question_E_content);
        String questionText = questionTextElement.getText().toString().trim();
        String questionOpt_A = questionOptElement_A.getText().toString().trim();
        String questionOpt_B = questionOptElement_B.getText().toString().trim();
        String questionOpt_C = questionOptElement_C.getText().toString().trim();
        String questionOpt_D = questionOptElement_D.getText().toString().trim();
        String questionOpt_E = questionOptElement_E.getText().toString().trim();
        String correctAnswer = "";

        QuestionMedia questionMedia = null;
        if (selectedContent != null) {
            questionMedia = new QuestionMedia(0, 0, selectedContentType, selectedContent);
        }

        RadioGroup radioGroup = (RadioGroup) popupView.findViewById(R.id.radioGroup);
        int selectedId = radioGroup.getCheckedRadioButtonId();
        RadioButton radioButton = (RadioButton) popupView.findViewById(selectedId);

        switch (radioButton.getId()) {
            case R.id.question_radio_A:
                correctAnswer = "A";
                break;
            case R.id.question_radio_B:
                correctAnswer = "B";
                break;

            case R.id.question_radio_C:
                correctAnswer = "C";
                break;

            case R.id.question_radio_D:
                correctAnswer = "D";
                break;

            case R.id.question_radio_E:
                correctAnswer = "E";
                break;
        }

        Question question = new Question(0, userId, questionText, questionOpt_A, questionOpt_B, questionOpt_C, questionOpt_D, questionOpt_E, correctAnswer, questionMedia);
        question = dbHelper.insertQuestion(question);

        questionsAdapter.addItem(question);

        if (question.getId() != 0){
            Toast.makeText(getContext(), String.format("Question successfully saved."), Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(getContext(), String.format("Error on Saving Question."), Toast.LENGTH_SHORT).show();
        }
    }

    public void insertNewExamOnClick(View popupView) {
        EditText examNameElement = (EditText) popupView.findViewById(R.id.exam_name_value);
        EditText examDifficultyElement = (EditText) popupView.findViewById(R.id.difficulty_value);
        EditText minDurationElement = (EditText) popupView.findViewById(R.id.min_duration_value);
        EditText maxDurationElement = (EditText) popupView.findViewById(R.id.max_duration_value);

        String examName = examNameElement.getText().toString().trim();
        int examDifficulty = Integer.parseInt(examDifficultyElement.getText().toString().trim());
        int minDuration = Integer.parseInt(minDurationElement.getText().toString().trim());
        int maxDuration = Integer.parseInt(maxDurationElement.getText().toString().trim());





        Exam exam = new Exam(0, userId, examName, examDifficulty, minDuration, maxDuration);
        exam = dbHelper.insertExam(exam, questions);

        examsAdapter.addItem(exam);

        if (exam.getId() != 0){
            Toast.makeText(getContext(), String.format("Exam successfully saved."), Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(getContext(), String.format("Error on Saving Exam."), Toast.LENGTH_SHORT).show();
        }
    }

    public void editQuestionOnClick(View popupView, Question question) {

        EditText questionTextElement = (EditText) popupView.findViewById(R.id.question_text_input);
        EditText questionOptElement_A = (EditText) popupView.findViewById(R.id.question_A_content);
        EditText questionOptElement_B = (EditText) popupView.findViewById(R.id.question_B_content);
        EditText questionOptElement_C = (EditText) popupView.findViewById(R.id.question_C_content);
        EditText questionOptElement_D = (EditText) popupView.findViewById(R.id.question_D_content);
        EditText questionOptElement_E = (EditText) popupView.findViewById(R.id.question_E_content);


        String questionText = questionTextElement.getText().toString().trim();
        String questionOpt_A = questionOptElement_A.getText().toString().trim();
        String questionOpt_B = questionOptElement_B.getText().toString().trim();
        String questionOpt_C = questionOptElement_C.getText().toString().trim();
        String questionOpt_D = questionOptElement_D.getText().toString().trim();
        String questionOpt_E = questionOptElement_E.getText().toString().trim();
        String correctAnswer = "";

        QuestionMedia questionMedia = null;
        if (selectedContent != null) {
            questionMedia = new QuestionMedia(0, 0, selectedContentType, selectedContent);
        } else {
            questionMedia = question.getQuestionMedia();
        }

        RadioGroup radioGroup = (RadioGroup) popupView.findViewById(R.id.radioGroup);
        int selectedId = radioGroup.getCheckedRadioButtonId();
        RadioButton radioButton = (RadioButton) popupView.findViewById(selectedId);

        switch (radioButton.getId()) {
            case R.id.question_radio_A:
                correctAnswer = "A";
                break;
            case R.id.question_radio_B:
                correctAnswer = "B";
                break;

            case R.id.question_radio_C:
                correctAnswer = "C";
                break;

            case R.id.question_radio_D:
                correctAnswer = "D";
                break;

            case R.id.question_radio_E:
                correctAnswer = "E";
                break;
        }

        Question editedQuestion = new Question(question.getId(), question.getUserId(), questionText, questionOpt_A, questionOpt_B, questionOpt_C, questionOpt_D, questionOpt_E, correctAnswer, questionMedia);
        editedQuestion = dbHelper.editQuestion(question, editedQuestion);

        questionsAdapter.editItem(question, editedQuestion);

        if (question.getId() != 0){
            Toast.makeText(getContext(), String.format("Question successfully saved."), Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(getContext(), String.format("Error on Saving Question."), Toast.LENGTH_SHORT).show();
        }
    }

    public void sendExam2(View view, Exam exam) {
        String filename = exam.getId()+".txt";
        SerializableManager.saveSerializable(getContext(), exam, filename);
        Intent intent = new Intent(android.content.Intent.ACTION_SEND);
        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
        intent.setType("text/plain");
        String folder = getContext().getFilesDir().getAbsolutePath();
        File file = new File(folder + "/" + filename);
        Uri uri = FileProvider.getUriForFile(getContext(), getContext().getApplicationContext().getPackageName() + ".provider", file);
        Intent sharingIntent = new Intent(Intent.ACTION_SEND);
        sharingIntent.setType("text/*");
        sharingIntent.putExtra(Intent.EXTRA_STREAM, uri);
        startActivity(Intent.createChooser(sharingIntent, "share file with"));
    }


}