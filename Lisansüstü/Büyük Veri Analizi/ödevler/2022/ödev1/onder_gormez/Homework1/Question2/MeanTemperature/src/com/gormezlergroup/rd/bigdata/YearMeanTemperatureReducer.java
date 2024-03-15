package com.gormezlergroup.rd.bigdata;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class YearMeanTemperatureReducer extends Reducer<Text, IntWritable, Text, DoubleWritable> {

    @Override
    public void reduce(Text key, Iterable<IntWritable> values, Context context)
            throws IOException, InterruptedException {
        Double sum = 0.0;
        Integer temperatureEntryCount = 0;

        for (IntWritable value : values) {
            sum += value.get();
            temperatureEntryCount++;
        }

        Double meanValue = Double.valueOf(sum / temperatureEntryCount);
        // 215 means that 21.5 °C
        meanValue /= 10;

        context.write(key, new DoubleWritable(meanValue));
    }
}
