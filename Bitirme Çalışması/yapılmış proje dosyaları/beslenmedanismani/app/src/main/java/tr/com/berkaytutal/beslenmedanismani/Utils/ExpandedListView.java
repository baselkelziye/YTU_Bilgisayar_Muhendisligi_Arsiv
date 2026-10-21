package tr.com.berkaytutal.beslenmedanismani.Utils;

/**
 * Created by berka on 9.06.2017.
 */

import android.content.Context;
import android.graphics.Canvas;
import android.util.AttributeSet;
import android.widget.ListView;

public class ExpandedListView extends ListView {

    private android.view.ViewGroup.LayoutParams params;
    private int old_count = 0;

    public ExpandedListView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    protected void onDraw(Canvas canvas) {

        if (getCount() != old_count) {
            old_count = getCount();
            params = getLayoutParams();

//            int height = 0;
//            for (int i = 0; i < getChildCount(); i++) {
//                height += getChildAt(i).getHeight();
//                height += getDividerHeight();
//            }
//            params.height = height;

            params.height = getCount() * (old_count > 0 ? getChildAt(0).getHeight()  : 0);
            setLayoutParams(params);
        }


        super.onDraw(canvas);
    }

}