package com.example.barissemerci;


import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.TextView;

import androidx.annotation.NonNull;

import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class ExamRecyclerAdapter extends RecyclerView.Adapter<ExamRecyclerAdapter.PostHolder> {
    private ArrayList<Question> questions;
    public static int limitOfQuestions = 0;

    public static ArrayList<Question> selectedQuestions = new ArrayList<>();

    public ExamRecyclerAdapter(ArrayList<Question> questions) {
        this.questions = questions;
    }


    @NonNull
    @Override
    public ExamRecyclerAdapter.PostHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater layoutInflater = LayoutInflater.from(parent.getContext());
        View view = layoutInflater.inflate(R.layout.exam_recycler_row, parent, false);
        return new ExamRecyclerAdapter.PostHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ExamRecyclerAdapter.PostHolder holder, int position) {
        holder.editTextQuestion.setText(questions.get(position).getQuestion());
        holder.editTextOptionA.setText(questions.get(position).getOptionA());
        holder.editTextOptionB.setText(questions.get(position).getOptionB());
        holder.editTextOptionC.setText(questions.get(position).getOptionC());
        holder.editTextOptionD.setText(questions.get(position).getOptionD());
        holder.editTextOptionE.setText(questions.get(position).getOptionE());
        holder.checkBoxExam.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (holder.checkBoxExam.isChecked()) {
                    limitOfQuestions++;
                    selectedQuestions.add(MainActivity.persons.get(MainActivity.whichPerson).getQuestions().get(position));
                } else {
                    limitOfQuestions--;
                    selectedQuestions.remove(MainActivity.persons.get(MainActivity.whichPerson).getQuestions().get(position));
                }

            }
        });


        char rightAnswer = questions.get(position).getRightAnswer();

        if (rightAnswer == 'A') {
            holder.checkBoxA.setChecked(true);
            holder.checkBoxB.setChecked(false);
            holder.checkBoxC.setChecked(false);
            holder.checkBoxD.setChecked(false);
            holder.checkBoxE.setChecked(false);
        } else if (rightAnswer == 'B') {
            holder.checkBoxB.setChecked(true);
            holder.checkBoxA.setChecked(false);
            holder.checkBoxC.setChecked(false);
            holder.checkBoxD.setChecked(false);
            holder.checkBoxE.setChecked(false);
        } else if (rightAnswer == 'C') {
            holder.checkBoxC.setChecked(true);
            holder.checkBoxA.setChecked(false);
            holder.checkBoxB.setChecked(false);
            holder.checkBoxD.setChecked(false);
            holder.checkBoxE.setChecked(false);
        } else if (rightAnswer == 'D') {
            holder.checkBoxD.setChecked(true);
            holder.checkBoxA.setChecked(false);
            holder.checkBoxC.setChecked(false);
            holder.checkBoxB.setChecked(false);
            holder.checkBoxE.setChecked(false);
        } else if (rightAnswer == 'E') {
            holder.checkBoxE.setChecked(true);
            holder.checkBoxA.setChecked(false);
            holder.checkBoxC.setChecked(false);
            holder.checkBoxD.setChecked(false);
            holder.checkBoxB.setChecked(false);
        }
    }


    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public int getItemViewType(int position) {
        return position;
    }

    @Override
    public int getItemCount() {
        return questions.size();
    }

    class PostHolder extends RecyclerView.ViewHolder {
        TextView editTextQuestion;
        TextView editTextOptionA;
        TextView editTextOptionB;
        TextView editTextOptionC;
        TextView editTextOptionD;
        TextView editTextOptionE;
        CheckBox checkBoxA;
        CheckBox checkBoxB;
        CheckBox checkBoxC;
        CheckBox checkBoxD;
        CheckBox checkBoxE;
        CheckBox checkBoxExam;

        public PostHolder(@NonNull View itemView) {
            super(itemView);
            editTextQuestion = itemView.findViewById(R.id.editTextRecyclerExamQuestion);
            editTextOptionA = itemView.findViewById(R.id.editTextRecyclerExamOptionA);
            editTextOptionB = itemView.findViewById(R.id.editTextRecyclerExamOptionB);
            editTextOptionC = itemView.findViewById(R.id.editTextRecyclerExamOptionC);
            editTextOptionD = itemView.findViewById(R.id.editTextRecyclerExamOptionD);
            editTextOptionE = itemView.findViewById(R.id.editTextRecyclerExamOptionE);
            checkBoxA = itemView.findViewById(R.id.checkBoxAExamRecycler);

            checkBoxB = itemView.findViewById(R.id.checkBoxBExamRecycler);
            checkBoxC = itemView.findViewById(R.id.checkBoxCExamRecycler);
            checkBoxD = itemView.findViewById(R.id.checkBoxDExamRecycler);
            checkBoxE = itemView.findViewById(R.id.checkBoxEExamRecycler);
            checkBoxExam = itemView.findViewById(R.id.checkBoxExam);

        }


    }
}
