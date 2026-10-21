# Big Data Mapreduce applications.  

&nbsp;&nbsp;In our project we will use “515K Hotel Reviews Data in Europe” provided by a user who took time to scrape the data from Booking.com. This dataset contains 515,000 customer reviews and scoring of 1493 luxury hotels across Europe. Meanwhile, the geographical location of hotels are also provided for further analysis. The csv file contains 17 fields. It contains Hotel address, Reviews and Reviewers Scores and many other fields. We will apply 5 fonction on dataset. 

Link for dataset: https://www.kaggle.com/jiashenliu/515k-hotel-reviews-data-in-europe

Functions:
  1. Total numbers of reviews (sum)
  2. The average of scores by hotels (average)
  3. Lowest and highest score given (min,max)
  4. The months that most reviews  and least reviews are made through the years 
  5. Standart deviation of all scores 
  
# About Code:
**1. Import required library**

```
import java.io.IOException;
import java.util.*;

import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
```  
**2. Write Map Function**  
&nbsp;&nbsp;&nbsp;&nbsp;LongWritable, Text and IntWritable are a varible at mapreduce. Text is used for String, Intwritable is used for Int, Longwritable is used for Long and Doublewritable is used for Double variables.  
&nbsp;&nbsp;&nbsp;&nbsp;`Mapper<LongWritable, Text, Text, IntWritable>` This line say us the function's inputs are LongWritable and Text. function's outputs will be Text and IntWritable.  
&nbsp;&nbsp;&nbsp;&nbsp;`public void map(LongWritable key, Text value, Context context)` This line say us input's will be context. It contains 2 variable. One of them key(LongWritable) the others is value(Text). The value (Text) will our dataset (Hotel_reviews.csv). We doest have any key for input.  
&nbsp;&nbsp;&nbsp;&nbsp;Then we write out function with normal java. Firstly take input and split it line by line. Then put it a String. Then we read each strings line. When take string line we create a context which key is "Satir" and value is 1(int).  
&nbsp;&nbsp;&nbsp;&nbsp;In this code we calculate how many line is there. So tehre isn't important for us what string contains. We just calculate how many line are there. So we create a context for each line and the context contains: (satir, 1). The map partition is finished.
    
```
public class sumOfReviews {

   public static class Map extends Mapper<LongWritable, Text, Text, IntWritable> {
      private final static IntWritable one = new IntWritable(1);

      public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

         String words[] = value.toString().split("\n"); 
         for(String word: words )
         {
            context.write(new Text("Satir"), one);
         }
      }
   }
```  

**3. Write Reduce Function**  
&nbsp;&nbsp;&nbsp;&nbsp;`Reducer<Text, IntWritable, Text, IntWritable>` This function takes a context which containts Text and Intwritable (We create thats at map function. like (satir,1)). This function's output also Text and Intwiritable but output will be just one line like (satir, 515000).  `public void reduce(Text key, Iterable<IntWritable> values` This also say us what input will be. Iterable<IntWritable> is used to use foreach function. it isn't very important.  
&nbsp;&nbsp; &nbsp;&nbsp;Then, there is the normal java functions. But there is a important thing which is reduce functions jop: reduce functions take a same key and we sum the keys's value. İf you ask so we cant see any function to take same key? The answer is: The jop is done by reduce function. We think it is natural iteration. and reduce function will iterate for each unique key. in this example we just one key(satir) so this reduce function just iterate one time.  
&nbsp;&nbsp;&nbsp;&nbsp;If we have 2 key (key1: cat, key2: dog). The reduce function iterates 2 times. Fist time, it finds context which key is cat. And we use thats values. When keys of cat finish, first iterate also finish and the second one starts. The second one also is like first one.

```
   public static class Reduce extends Reducer<Text, IntWritable, Text, IntWritable> {
      public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {

         int sum = 0;
         for (IntWritable val : values) {
            sum += val.get();
         }
         context.write(key, new IntWritable(sum));
      }
   }
```  
**4. Write Main Function**
```  
   public static void main(String[] args) throws Exception {

      Configuration conf = new Configuration();
      @SuppressWarnings("deprecation")
      Job job = new Job(conf, "sumOfReviews");      // when program runs, this is written on the screen

      job.setJarByClass(sumOfReviews.class);        //main class name

      job.setMapperClass(Map.class);                // mapper class name 
      job.setReducerClass(Reduce.class);            // reducer class name 

      job.setOutputKeyClass(Text.class);            // output data type - satir
      job.setOutputValueClass(IntWritable.class);   // output data type - 515.000

      FileInputFormat.addInputPath(job, new Path(args[0]));
      FileOutputFormat.setOutputPath(job, new Path(args[1]));

      job.waitForCompletion(true);
   }
 }
