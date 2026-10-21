import java.io.IOException;
import java.text.NumberFormat;
import java.util.*;

import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class stdDeviation {

    public static class Map extends Mapper<LongWritable, Text, Text, DoubleWritable> {
        
        List<List<String>> records = new ArrayList<>();
        int index = 0;

        public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

            String words[] = value.toString().split("\n");                  // cvs'i satırlara böldüm.
            for(String word: words )                                        // satır satır aldım.
            {
                String[] ayrik = word.split(",");                           // virgüllerden ayırıp
                records.add(Arrays.asList(ayrik));                          // records içine attım [[1, XO Hotel, 6/24/2017,  South Korea , 3.8],...

                Double number2 = Double.parseDouble(records.get(index).get(4)); // one otel score
                DoubleWritable number4 =  new DoubleWritable(number2);
                
                context.write(new Text("skor"),number4);
                index++;
            }
        }
    }

 public static class Reduce extends Reducer<Text, DoubleWritable, Text, DoubleWritable> {

    List<Double> cache = new ArrayList<Double>();

    public void reduce(Text key, Iterable<DoubleWritable> values, Context context) throws IOException, InterruptedException {
    
        int count = 0;
        double avg = 0, stdDerivation = 0, sum = 0;

        for (DoubleWritable val : values) {
            Double forcache = val.get();
            sum += val.get();
            count ++;     
            cache.add(forcache);
        }
        avg = sum/++count;

        for (Double val : cache) {
            stdDerivation += Math.pow(val - avg, 2);           // 2. Çıkart : value -= avg
                                                               // 3. sonuçların karelerini al topla 
        }                                                      // 4. count-1'e böl
        stdDerivation = Math.sqrt(stdDerivation / (count - 1));

        NumberFormat nf = NumberFormat.getInstance(); 
        nf.setMaximumFractionDigits(3); 
        stdDerivation =Double.parseDouble(nf.format(stdDerivation));
        System.out.println(nf.format(stdDerivation));
        
        context.write(new Text("Standart derivation"), new DoubleWritable(stdDerivation));
    }
 }

    public static void main(String[] args) throws Exception {

        Configuration conf = new Configuration();

        @SuppressWarnings("deprecation")
        Job job = new Job(conf, "stdDeviation");

        job.setJarByClass(stdDeviation.class);

        job.setMapperClass(Map.class);
        job.setReducerClass(Reduce.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(DoubleWritable.class);

        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));

        //Executing our job.
        job.waitForCompletion(true);
    }
 }
