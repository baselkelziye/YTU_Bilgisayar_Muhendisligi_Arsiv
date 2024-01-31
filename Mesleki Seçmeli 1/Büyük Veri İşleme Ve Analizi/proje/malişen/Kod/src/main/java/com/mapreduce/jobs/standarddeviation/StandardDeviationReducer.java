package com.mapreduce.jobs.standarddeviation;

import java.io.IOException;
import java.util.Iterator;
import java.util.stream.IntStream;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reducer;
import org.apache.hadoop.mapred.Reporter;

public class StandardDeviationReducer extends MapReduceBase
		implements Reducer<Text, IntWritable, Text, DoubleWritable> {
	public void reduce(Text key, Iterator<IntWritable> values, OutputCollector<Text, DoubleWritable> output, Reporter reporter) throws IOException {
		IntStream.Builder builder = IntStream.builder();
		int total = 0;
		int count = 0;
		while (values.hasNext()) {
			IntWritable value = (IntWritable) values.next();
			builder.add(value.get());
			total += value.get();
			count++;
		}
		double average = total / (double) count;
		output.collect(
			key,
			new DoubleWritable(
				count > 1
					? Math.sqrt(
						builder
							.build()
							.mapToDouble(i -> Math.pow(i - average, 2))
							.sum()
						/ (count - 1)
					)
					: 0
			)
		);
	}
}
