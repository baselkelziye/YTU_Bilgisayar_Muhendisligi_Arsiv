package com.mapreduce;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.mapred.JobClient;

public class Singletons {
	public static JobClient jobClient = new JobClient();
	public static FileSystem fileSystem;

	static {
		Configuration configuration = new Configuration();
		configuration.set("fs.defaultFS", "hdfs://master:9000");
		try {
			fileSystem = FileSystem.get(configuration);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
