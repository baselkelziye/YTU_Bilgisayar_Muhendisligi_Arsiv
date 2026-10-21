package tr.edu.yildiz.payci.soner.helpers;

import android.content.Context;
import android.graphics.Color;
import android.graphics.Typeface;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.TextView;
import tr.edu.yildiz.payci.soner.R;
import java.util.ArrayList;
import java.util.List;

import tr.edu.yildiz.payci.soner.model.Question;

public class QuestionSpinnerAdapter extends ArrayAdapter<Question> {
    private Context mContext;
    private ArrayList<Question> listState;
    private QuestionSpinnerAdapter questionSpinnerAdapter;
    private boolean isFromView = false;

    public QuestionSpinnerAdapter(Context context, int resource, List<Question> objects) {
        super(context, resource, objects);
        this.mContext = context;
        this.listState = (ArrayList<Question>) objects;
        this.questionSpinnerAdapter = this;
    }

    @Override
    public View getDropDownView(int position, View convertView,
                                ViewGroup parent) {
        return getCustomView(position, convertView, parent);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        return getCustomView(position, convertView, parent);
    }

    public View getCustomView(final int position, View convertView,
                              ViewGroup parent) {

        final ViewHolder holder;
        if (convertView == null) {
            LayoutInflater layoutInflator = LayoutInflater.from(mContext);
            convertView = layoutInflator.inflate(R.layout.spinner_item, null);
            holder = new ViewHolder();
            holder.questionTextView = (TextView) convertView.findViewById(R.id.spinner_question_text);
            holder.question_A_TextView = (TextView) convertView.findViewById(R.id.spinner_question_A);
            holder.question_B_TextView = (TextView) convertView.findViewById(R.id.spinner_question_B);
            holder.question_C_TextView = (TextView) convertView.findViewById(R.id.spinner_question_C);
            holder.question_D_TextView = (TextView) convertView.findViewById(R.id.spinner_question_D);
            holder.question_E_TextView = (TextView) convertView.findViewById(R.id.spinner_question_E);
            holder.questionCheckBox = (CheckBox) convertView.findViewById(R.id.spinner_checkbox);
            convertView.setTag(holder);
        } else {
            holder = (ViewHolder) convertView.getTag();
        }

        holder.questionTextView.setText(listState.get(position).getText());
        holder.question_A_TextView.setText(listState.get(position).getA());
        holder.question_B_TextView.setText(listState.get(position).getB());
        holder.question_C_TextView.setText(listState.get(position).getC());
        holder.question_D_TextView.setText(listState.get(position).getD());
        holder.question_E_TextView.setText(listState.get(position).getE());

        // To check weather checked event fire from getview() or user input
        isFromView = true;
        holder.questionCheckBox.setChecked(listState.get(position).getIsSelected());
        isFromView = false;


        holder.questionCheckBox.setTag(position);
        holder.questionCheckBox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {

            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                int getPosition = (Integer) buttonView.getTag();

                if (!isFromView) {
                    listState.get(position).setIsSelected(isChecked);
                }
            }
        });
        return convertView;
    }

    private class ViewHolder {
        private TextView questionTextView;
        private TextView question_A_TextView;
        private TextView question_B_TextView;
        private TextView question_C_TextView;
        private TextView question_D_TextView;
        private TextView question_E_TextView;
        private CheckBox questionCheckBox;
    }
}