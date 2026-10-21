import java.io.IOException;
import java.text.NumberFormat;
import java.util.*;

import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class avgOfScore {

    public static class Map extends Mapper<LongWritable, Text, Text, DoubleWritable> {
        
        List<List<String>> records = new ArrayList<>();
        int index = 0;

        public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

            String words[] = value.toString().split("\n");                  // cvs'i satırlara böldüm.
            for(String word: words )                                        // satır satır aldım.
            {
                String[] ayrik = word.split(",");                           // virgüllerden ayırıp
                records.add(Arrays.asList(ayrik));                          // records içine attım [[1, XO Hotel, 6/24/2017,  South Korea , 3.8],...
                Text key1 =  new Text(records.get(index).get(1));                     // otel name
                Double number2 = Double.parseDouble(records.get(index).get(4)); // one otel score
                DoubleWritable number4 =  new DoubleWritable(number2);
                context.write(key1,number4);
                index++;
            }
        }
    }

 public static class Reduce extends Reducer<Text, DoubleWritable, Text, DoubleWritable> {

    public void reduce(Text key, Iterable<DoubleWritable> values, Context context) throws IOException, InterruptedException {
    
        int count = 0;
        double sum = 0;
        for (DoubleWritable val : values) {
            sum += val.get();
            count ++;     
        }
        double avg = sum/count;

        NumberFormat nf = NumberFormat.getInstance(); 
        nf.setMaximumFractionDigits(3); 
        avg =Double.parseDouble(nf.format(avg));
        //System.out.println(nf.format(avg));

        context.write(key, new DoubleWritable(avg));
    }
 }
 
    public static void main(String[] args) throws Exception {

        Configuration conf = new Configuration();

        @SuppressWarnings("deprecation")
        Job job = new Job(conf, "avgOfScore");
        job.setJarByClass(avgOfScore.class);

        job.setMapperClass(Map.class);
        job.setReducerClass(Reduce.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(DoubleWritable.class);

        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));

        job.waitForCompletion(true);
    }
 }
