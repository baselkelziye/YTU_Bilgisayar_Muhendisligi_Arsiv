# Question 2

Write a program that finds the annual average temperature from the data recorded by the National Climatic Data Center.

## Codes

* The application was developed using IntelliJ IDEA.
* Used maven to manage project dependencies.

### NCDCRecordParser Class
This is the parser class that uses in the parse National Climatic Data Center temperature measurements.

* Example Data (Negative Temperature):
002902907099999**1901**010220004+64333+023450FM-12+000599999V0201801N009819999999N0000001N9 **-0028**1+99999101751ADDGF108991999999999999999999

* Example Data (Positive Temperature):
0029227070999991901072606004+62167+030650FM-12+010299999V0200201N001019999999N0000001N9 **+0211**1+99999100991ADDGF100991999999999999999999

```Java
package com.gormezlergroup.rd.bigdata;

import org.apache.hadoop.io.Text;

public class NCDCRecordParser {

    private static final int MISSING_TEMPERATURE = 9999;
    private String year;
    private int airTemperature;
    private String quality;

    public void parse(String record) {
        year = record.substring(15, 19);
        String airTemperatureString;
        // Remove leading plus sign as parseInt doesn't like them (pre-Java 7)
        if (record.charAt(87) == '+')
            airTemperatureString = record.substring(88, 92);
        else
            airTemperatureString = record.substring(87, 92);

        airTemperature = Integer.parseInt(airTemperatureString);
        quality = record.substring(92, 93);
    }

    public void parse(Text record) {
        parse(record.toString());
    }

    public boolean isTemperatureValid() {
        return airTemperature != MISSING_TEMPERATURE && quality.matches("[01459]");
    }

    public String getYear() {
        return year;
    }

    public int getAirTemperature() {
        return airTemperature;
    }
}
```

### YearTemperatureMapper Class

```Java
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
```

### YearMeanTemperatureReducer Class

```Java
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

```
### Driver Program

```Java
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
```

## Build Artifact
* Necessary settings have been made to generate .jar file via IntelliJ IDEA.
* The MapReduce program is packaged with the name **MeanTemperature.jar**, containing all its dependencies.

## Steps
* The Hadoop collection is installed in a docker image as specified in the links below;
  * [How to set up a Hadoop cluster in Docker
](https://shortcut.com/developer-how-to/how-to-set-up-a-hadoop-cluster-in-docker)
  * Used [Big Data Europe Github Repository](https://github.com/big-data-europe/docker-hadoop)
* Docker image run as stated below

```sh
onder@debian-onder:~/Repos/docker-hadoop$ docker-compose up -d
```

* The compiled MeanTemperature.jar file is sent to the namenode as follows.

```sh
# Copy .jar file
onder@debian-onder:~/Repos/docker-hadoop$ docker cp ~/Repos/BLM5127_Big_Data_Analytics/02-Homeworks/Homework1/Question2/MeanTemperature/out/artifacts/MeanTemperature_jar/MeanTemperature.jar namenode:MeanTemperature.jar
```

* The 'NCDCTemperature' data file is sent to the namenode as follows.

```sh
onder@debian-onder:~/Repos/docker-hadoop$ docker cp ~/Repos/BLM5127_Big_Data_Analytics/02-Homeworks/Homework1/Question2/NCDCTemperature namenode:NCDCTemperature
```

* Connect to namenode with interactive bash console

```sh
onder@debian-onder:~/Repos/docker-hadoop$ docker exec --interactive --tty namenode bash

# See copied MeanTemperature.jar and 'NCDCTemperature' files like below
root@84fabc8f5ee8:/$ ls
# KEYS  MeanTemperature.jar  NCDCTemperature  bin  boot  dev  entrypoint.sh ...
root@84fabc8f5ee8:/$
```

* Create 'NCDCTemperature' data file, copied to the namenode, in the Hadoop Distributed File System as follows;

```sh
# First create folder inside the Hadoop Distributed File System
root@84fabc8f5ee8:/$ hdfs dfs -mkdir input/

# Copy file
root@84fabc8f5ee8:/$ hadoop fs -put NCDCTemperature input/

# See copied file like below
root@84fabc8f5ee8:/$ hadoop fs -ls input/
# Found 1 items
# -rw-r--r--   3 root supergroup    1777168 2022-11-29 20:07 input/NCDCTemperature
root@84fabc8f5ee8:/$
```

* The MeanTemperature program can be run with hadoop as follows.

```sh
root@84fabc8f5ee8:/$ hadoop jar MeanTemperature.jar input output
MapReduce started...
Argument Count: 2
Argument[0]: input
Argument[1]: output

Input Files Folder Path 1: input
Output File Folder Path: output

0 [main] INFO org.apache.hadoop.yarn.client.RMProxy  - Connecting to ResourceManager at resourcemanager/172.19.0.5:8032
612 [main] INFO org.apache.hadoop.yarn.client.AHSProxy  - Connecting to Application History server at historyserver/172.19.0.6:10200
# Other outputs...
2022-11-29 20:12:14,574 INFO input.FileInputFormat: Total input files to process : 1
# Other outputs...
2022-11-29 20:12:14,781 INFO mapreduce.JobSubmitter: number of splits:1
# Other outputs...
2022-11-29 20:12:16,464 INFO impl.YarnClientImpl: Submitted application application_1669588823445_0004
4026 [main] INFO org.apache.hadoop.yarn.client.api.impl.YarnClientImpl  - Submitted application application_1669588823445_0004
2022-11-29 20:12:16,586 INFO mapreduce.Job: The url to track the job: http://resourcemanager:8088/proxy/application_1669588823445_0004/
4148 [main] INFO org.apache.hadoop.mapreduce.Job  - The url to track the job: http://resourcemanager:8088/proxy/application_1669588823445_0004/
2022-11-29 20:12:16,588 INFO mapreduce.Job: Running job: job_1669588823445_0004
4150 [main] INFO org.apache.hadoop.mapreduce.Job  - Running job: job_1669588823445_0004
2022-11-29 20:12:31,045 INFO mapreduce.Job: Job job_1669588823445_0004 running in uber mode : false
# Other outputs...
2022-11-29 20:12:31,047 INFO mapreduce.Job:  map 0% reduce 0%
2022-11-29 20:12:40,290 INFO mapreduce.Job:  map 100% reduce 0%
2022-11-29 20:12:49,443 INFO mapreduce.Job:  map 100% reduce 100%
2022-11-29 20:12:49,467 INFO mapreduce.Job: Job job_1669588823445_0004 completed successfully
2022-11-29 20:12:49,654 INFO mapreduce.Job: Counters: 54
        File System Counters
                FILE: Number of bytes read=15797
                FILE: Number of bytes written=489767
# Other outputs...
                HDFS: Number of bytes read=1777285
                HDFS: Number of bytes written=44
# Other outputs...
        Job Counters 
                Launched map tasks=1
                Launched reduce tasks=1
                Rack-local map tasks=1
# Other outputs...
        Map-Reduce Framework
                Map input records=13130
                Map output records=13129
# Other outputs...
        Shuffle Errors
# Other outputs...
        File Input Format Counters 
                Bytes Read=1777168
        File Output Format Counters 
                Bytes Written=44

# Other outputs...
MapReduce finished!
root@84fabc8f5ee8:/$
```

* See output files like below;

```sh
root@84fabc8f5ee8:/$ hdfs dfs -ls output/
# Found 2 items
# -rw-r--r--   3 root supergroup          0 2022-11-29 20:12 output/_SUCCESS
# -rw-r--r--   3 root supergroup         44 2022-11-29 20:12 output/part-r-00000
root@84fabc8f5ee8:/$
```

* Docker image stop as stated below

```sh
onder@debian-onder:~/Repos/docker-hadoop$ docker-compose down
# Stopping namenode        ... done
# Stopping resourcemanager ... done
# Stopping historyserver   ... done
# Stopping datanode        ... done
# Stopping nodemanager     ... done
# Removing namenode        ... done
# Removing resourcemanager ... done
# Removing historyserver   ... done
# Removing datanode        ... done
# Removing nodemanager     ... done
# Removing network docker-hadoop_default
onder@debian-onder:~/Repos/docker-hadoop$
```

## Result Data

* Since the resulting data is very small, it can be observed on the console screen as follows.
* As expected, the average temperature values of the years included in the data set were calculated.

```sh
root@84fabc8f5ee8:/$ hadoop fs -cat output/part-r-00000
# 1901    4.6698507007922
# 1902    2.165955826351866
root@84fabc8f5ee8:/$
```

## Troubleshooting

```sh
root@84fabc8f5ee8:/$ hadoop jar MeanTemperature.jar input output
# Other outputs...
Exception in thread "main" org.apache.hadoop.mapred.FileAlreadyExistsException: Output directory hdfs://namenode:9000/user/root/output already exists
# Other outputs...
root@84fabc8f5ee8:/$ 

# Solution
root@84fabc8f5ee8:/$ hadoop dfs -rm -r output/
# Deleted output
root@84fabc8f5ee8:/$
```

## References

* [How to set up a Hadoop cluster in Docker](https://shortcut.com/developer-how-to/how-to-set-up-a-hadoop-cluster-in-docker)
* [Big Data Europe Github Repository](https://github.com/big-data-europe/docker-hadoop)
* [Wiki - National Climatic Data Center](https://en.wikipedia.org/wiki/National_Climatic_Data_Center)

# TODO: Proje ile ilgili veri dosyası NCDC ye ait olan bir yerden bulunarak eklenebilir.
