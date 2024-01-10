package com.mapreduce.jobs.movieaverage;

import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reducer;
import org.apache.hadoop.mapred.Reporter;

public class MovieAverageReducer extends MapReduceBase implements Reducer<Text, IntWritable, Text, DoubleWritable> {
	public void reduce(Text key, Iterator<IntWritable> values, OutputCollector<Text, DoubleWritable> output, Reporter reporter) throws IOException {
		int total = 0;
		int count = 0;
		while (values.hasNext()) {
			IntWritable value = (IntWritable) values.next();
			total += value.get();
			count++;
		}
		output.collect(key, new DoubleWritable(total / (double) count));
	}
}
