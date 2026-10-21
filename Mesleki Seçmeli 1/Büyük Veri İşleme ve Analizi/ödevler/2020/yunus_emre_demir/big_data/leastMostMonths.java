import java.io.IOException;
import java.util.*;

import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class leastMostMonths {

    public static int[] aylars = new int[12];

    public static class Map extends Mapper<LongWritable, Text, Text, IntWritable> {
        
        //private final static IntWritable one = new IntWritable(1);
        List<List<String>> tarihler = new ArrayList<>();
        int index = 0;

        public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

                String words[] = value.toString().split("\n"); 
                for(String word: words )
                {
                    String[] ayrik = word.split(",");                           // virgüllerden ayırıp stringe aldım
                    String[] tarih = ayrik[2].split("/");                       // "ayrik" stringinin 2. dizininde tarih bilgisi mahfuz 07/25/20 gibi bunuda ayırdım. 
                                                                                // tarih adlı stringe koydum [07 , 25 , 20] oldu şimdi elimde
                    if (tarih[0].equals("01"))      { tarih[0] = "1"; }         // csv deki bazı 01,02 gibi yanlış bilgileri düzenledim.
                    else if (tarih[0].equals("02")) { tarih[0] = "2"; }
                    else if (tarih[0].equals("03")) { tarih[0] = "3"; }
                    else if (tarih[0].equals("04")) { tarih[0] = "4"; }
                    else if (tarih[0].equals("05")) { tarih[0] = "5"; }
                    else if (tarih[0].equals("06")) { tarih[0] = "6"; }
                    else if (tarih[0].equals("07")) { tarih[0] = "7"; }
                    else if (tarih[0].equals("08")) { tarih[0] = "8"; }
                    else if (tarih[0].equals("09")) { tarih[0] = "9"; }
                              
                    tarihler.add(Arrays.asList(tarih));                           // tarihler adlı arrayde sadece tarih bilgisi mahfuz. [[5,25,20],[10,30,20]]
    /*
                    for ( int j = 0; j < 12; j++) {                                    
                        if (tarihler.get(index).get(0).equals(Integer.toString(j+1))) {  
                            Text key1 = new Text(Integer.toString(j));                   
*/                  
                    int a = Integer.parseInt(tarihler.get(index).get(0));       // Burada sadece aylara bakıp eğer 0 se key 1 ay 1, 2 ise key 1 value 1, 
                    a = a-1;                                                    // 3 ise key 2 value 0 diye mapledim
                    Text key1 = new Text(Integer.toString(a));                  // 0-11 arası 12 sayı olacak ayları temsilen. // aybul(j)

                    context.write(key1, new IntWritable(1));                   // one mounth score
                    index++;

                }

        }
    }

    public static class Reduce extends Reducer<Text, IntWritable, Text, IntWritable> {

        public int maxValue = Integer.MIN_VALUE;              // max = -23554546.. 
        public int minValue = Integer.MAX_VALUE;              // min = +23554546..
        public String minay;
        public String maxay;

        public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
            
            int sum = 0;
            for (IntWritable val : values) {
                sum += val.get();
            }

            for ( int j=0; j<12; j++) {        // max min i ve ilgili ayını bulma fonksiyonum. 
                if (sum < minValue) {
                    minValue = sum;
                    String ay = key.toString();
                    minay = aybul(Integer.parseInt(ay));
                }
                if (sum > maxValue) {
                    maxValue = sum;
                    String ay = key.toString();
                    maxay = aybul(Integer.parseInt(ay));
                }
            }

            context.write(new Text(maxay), new IntWritable(maxValue));       
            context.write(new Text(minay), new IntWritable(minValue));  
        }
        
        private java.lang.String aybul(final int j) {
            if (j == 0 ) { return "January"; }
            else if (j== 1 ) { return "February"; }
            else if (j == (2)) { return "March"; }
            else if (j == (3)) { return "April"; }
            else if (j == (4)) { return "May"; }
            else if (j == (5)) { return "June"; }
            else if (j == (6)) { return "July"; }
            else if (j == (7)) { return "Agust"; }
            else if (j == (8)) { return "September"; }
            else if (j == (9)) { return "October"; }
            else if (j == (10)) { return "November"; }
            else if (j == (11)) { return "December"; }
            else return null;
        }
    }


    public static void main(String[] args) throws Exception {

        Configuration conf = new Configuration();

        @SuppressWarnings("deprecation")
        Job job = new Job(conf, "leastMostMonths");

        job.setJarByClass(leastMostMonths.class);

        job.setMapperClass(Map.class);
        job.setReducerClass(Reduce.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);

        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));

        job.waitForCompletion(true);
    }
}
