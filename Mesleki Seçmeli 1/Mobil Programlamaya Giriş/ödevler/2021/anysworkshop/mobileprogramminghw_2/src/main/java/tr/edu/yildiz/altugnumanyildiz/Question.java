package tr.edu.yildiz.altugnumanyildiz;

import android.os.Parcel;
import android.os.Parcelable;

public class Question implements Parcelable {

    private String questionText;
    private String optionA;
    private String optionB;
    private String optionC;
    private String optionD;
    private String optionE;
    private String correctAnswer;
    private int teacherID;
    private byte[] byteArrays;
    private String dataType;
    private int questionID;

    protected Question(Parcel in) {
        questionText = in.readString();
        optionA = in.readString();
        optionB = in.readString();
        optionC = in.readString();
        optionD = in.readString();
        optionE = in.readString();
        correctAnswer = in.readString();
        teacherID = in.readInt();
        byteArrays = in.createByteArray();
        dataType = in.readString();
        questionID = in.readInt();
    }

    public static final Creator<Question> CREATOR = new Creator<Question>() {
        @Override
        public Question createFromParcel(Parcel in) {
            return new Question(in);
        }

        @Override
        public Question[] newArray(int size) {
            return new Question[size];
        }
    };

    public int getQuestionID() {
        return questionID;
    }

    public void setQuestionID(int questionID) {
        this.questionID = questionID;
    }

    public Question(){

    }

    public Question(int questionID,String questionText, String optionA, String optionB, String optionC, String optionD, String optionE, String correctAnswer, int teacherID, byte[] byteArrays, String dataType) {
        this.questionID = questionID;
        this.questionText = questionText;
        this.optionA = optionA;
        this.optionB = optionB;
        this.optionC = optionC;
        this.optionD = optionD;
        this.optionE = optionE;
        this.correctAnswer = correctAnswer;
        this.teacherID = teacherID;
        this.byteArrays = byteArrays;
        this.dataType = dataType;
    }

    public String getQuestionText() {
        return questionText;
    }

    public void setQuestionText(String questionText) {
        this.questionText = questionText;
    }

    public String getOptionA() {
        return optionA;
    }

    public void setOptionA(String optionA) {
        this.optionA = optionA;
    }

    public String getOptionB() {
        return optionB;
    }

    public void setOptionB(String optionB) {
        this.optionB = optionB;
    }

    public String getOptionC() {
        return optionC;
    }

    public void setOptionC(String optionC) {
        this.optionC = optionC;
    }

    public String getOptionD() {
        return optionD;
    }

    public void setOptionD(String optionD) {
        this.optionD = optionD;
    }

    public String getOptionE() {
        return optionE;
    }

    public void setOptionE(String optionE) {
        this.optionE = optionE;
    }

    public String getCorrectAnswer() {
        return correctAnswer;
    }

    public void setCorrectAnswer(String correctAnswer) {
        this.correctAnswer = correctAnswer;
    }

    public int getTeacherID() {
        return teacherID;
    }

    public void setTeacherID(int teacherID) {
        this.teacherID = teacherID;
    }

    public String getDataType() {
        return dataType;
    }

    public void setDataType(String dataType) {
        this.dataType = dataType;
    }

    public byte[] getByteArrays() {
        return byteArrays;
    }

    public void setByteArrays(byte[] byteArrays) {
        this.byteArrays = byteArrays;
    }

    public String toStringID() {
        return String.valueOf(questionID);
    }


    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel parcel, int i) {
        parcel.writeString(questionText);
        parcel.writeString(optionA);
        parcel.writeString(optionB);
        parcel.writeString(optionC);
        parcel.writeString(optionD);
        parcel.writeString(optionE);
        parcel.writeString(correctAnswer);
        parcel.writeInt(teacherID);
        parcel.writeByteArray(byteArrays);
        parcel.writeString(dataType);
        parcel.writeInt(questionID);
    }
}
