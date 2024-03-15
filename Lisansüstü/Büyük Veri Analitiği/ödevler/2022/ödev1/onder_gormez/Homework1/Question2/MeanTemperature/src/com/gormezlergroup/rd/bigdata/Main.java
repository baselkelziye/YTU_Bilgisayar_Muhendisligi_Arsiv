package com.gormezlergroup.rd.bigdata;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;
import org.apache.log4j.BasicConfigurator;

public class Main {

    private static final int MINIMUM_ARGUMENT_COUNT = 2;
    private static final int EXIT_CODE_SUCCESS = 0;
    private static final int EXIT_CODE_ARGUMENT_COUNT_FAILURE = 1;
    private static final int EXIT_CODE_MAP_REDUCE_FAILURE = 2;

    public static void main(String[] args) throws Exception {

        System.out.println("MapReduce started...");

        BasicConfigurator.configure();
        Configuration conf = new Configuration();
        String[] otherArgs = new GenericOptionsParser(conf, args).getRemainingArgs();

        System.out.println("Argument Count: " + otherArgs.length);
        for (int i = 0; i < otherArgs.length; ++i) {
            System.out.println("Argument[" + i + "]: " + otherArgs[i]);
        }
        System.out.println();

        if (otherArgs.length < MINIMUM_ARGUMENT_COUNT) {
            System.err.println("Invalid argument count!");
            System.err.println(
                    "Usage: MeanTemperature.jar <InputFilesFolderPath> [<InputFilesFolderPath>...] <OutputFileFolderPath>");
            System.err.println("Example: MeanTemperature.jar input/ output/");

            System.exit(EXIT_CODE_ARGUMENT_COUNT_FAILURE);
        }

        Job job = new Job(conf, "Mean Temperature Calculator");
        job.setJarByClass(Main.class);
        job.setMapperClass(YearTemperatureMapper.class);
        // job.setCombinerClass();
        job.setReducerClass(YearMeanTemperatureReducer.class);
        // job.setMapOutputKeyClass(Text.class);
        // job.setMapOutputValueClass(IntWritable.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);

        for (int i = 0; i < otherArgs.length - 1; ++i) {
            FileInputFormat.addInputPath(job, new Path(otherArgs[i]));
            System.out.println("Input Files Folder Path " + (i + 1) + ": " + otherArgs[i]);
        }

        FileOutputFormat.setOutputPath(job, new Path(otherArgs[otherArgs.length - 1]));
        System.out.println("Output File Folder Path: " + otherArgs[otherArgs.length - 1]);

        boolean isSuccessful = job.waitForCompletion(true);
        System.out.println("MapReduce finished!");

        System.exit(isSuccessful ? EXIT_CODE_SUCCESS : EXIT_CODE_MAP_REDUCE_FAILURE);
    }
}
