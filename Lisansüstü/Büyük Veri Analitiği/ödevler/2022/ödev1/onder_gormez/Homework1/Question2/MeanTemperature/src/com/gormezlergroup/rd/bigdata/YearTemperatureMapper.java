package com.gormezlergroup.rd.bigdata;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class YearTemperatureMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
    private NCDCRecordParser parser = new NCDCRecordParser();

    @Override
    public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        parser.parse(value);

        // Discard invalid inputs
        if (!parser.isTemperatureValid())
            return;

        // Write as key and value pair (key: year, value: temperature)
        context.write(new Text(parser.getYear()), new IntWritable(parser.getAirTemperature()));
    }
}
