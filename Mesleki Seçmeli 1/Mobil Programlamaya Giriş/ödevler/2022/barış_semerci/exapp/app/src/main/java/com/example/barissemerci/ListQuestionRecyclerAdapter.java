package com.example.barissemerci;

import android.content.Context;

import android.view.ContextMenu;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;


import android.widget.TextView;


import androidx.annotation.NonNull;

import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.RecyclerView;


import java.util.ArrayList;

public class ListQuestionRecyclerAdapter extends RecyclerView.Adapter<ListQuestionRecyclerAdapter.PostHolder> {
    private ArrayList<Question> questions;
    private Context mContext;
    int positionItem;

    public ListQuestionRecyclerAdapter(ArrayList<Question> questions, Context mContext) {
        this.questions = questions;
        this.mContext = mContext;
    }


    @NonNull
    @Override
    public PostHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater layoutInflater = LayoutInflater.from(parent.getContext());
        View view = layoutInflater.inflate(R.layout.recycler_row, parent, false);
        return new PostHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull PostHolder holder, int position) {
        positionItem = position;


        holder.editTextQuestion.setText(questions.get(position).getQuestion());
        holder.editTextOptionA.setText(questions.get(position).getOptionA());
        holder.editTextOptionB.setText(questions.get(position).getOptionB());
        holder.editTextOptionC.setText(questions.get(position).getOptionC());
        holder.editTextOptionD.setText(questions.get(position).getOptionD());
        holder.editTextOptionE.setText(questions.get(position).getOptionE());
        holder.textViewNumber.setText("Question no: " + (position + 1));


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
    public int getItemCount() {
        return questions.size();
    }

    class PostHolder extends RecyclerView.ViewHolder implements View.OnCreateContextMenuListener {
        TextView editTextQuestion;
        TextView editTextOptionA;
        TextView editTextOptionB;
        TextView editTextOptionC;
        TextView textViewNumber;
        TextView editTextOptionD;
        TextView editTextOptionE;
        CheckBox checkBoxA;
        CheckBox checkBoxB;
        CheckBox checkBoxC;
        CheckBox checkBoxD;
        CheckBox checkBoxE;
        CardView cardview;


        public PostHolder(@NonNull View itemView) {
            super(itemView);
            editTextQuestion = itemView.findViewById(R.id.editTextRecyclerQuestion);
            editTextOptionA = itemView.findViewById(R.id.editTextRecyclerOptionA);
            editTextOptionB = itemView.findViewById(R.id.editTextRecyclerOptionB);
            editTextOptionC = itemView.findViewById(R.id.editTextRecyclerOptionC);
            editTextOptionD = itemView.findViewById(R.id.editTextRecyclerOptionD);
            editTextOptionE = itemView.findViewById(R.id.editTextRecyclerOptionE);
            checkBoxA = itemView.findViewById(R.id.checkBoxARecycler);
            textViewNumber = itemView.findViewById(R.id.textViewNumber);
            checkBoxB = itemView.findViewById(R.id.checkBoxBRecycler);
            checkBoxC = itemView.findViewById(R.id.checkBoxCRecycler);
            checkBoxD = itemView.findViewById(R.id.checkBoxDRecycler);
            checkBoxE = itemView.findViewById(R.id.checkBoxERecycler);
            cardview = itemView.findViewById(R.id.mCardView);


            cardview.setOnCreateContextMenuListener(this);

        }


        @Override
        public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
            menu.setHeaderTitle("Do you want?");
            menu.add(this.getAdapterPosition(), 121, 0, "Delete this question.");
            menu.add(this.getAdapterPosition(), 122, 1, "Update this question.");

        }
    }

    public void deleteQuestion(int questionPosition, int personPosition) {

        MainActivity.persons.get(personPosition).getQuestions().remove(questionPosition);
        notifyDataSetChanged();
    }

}
