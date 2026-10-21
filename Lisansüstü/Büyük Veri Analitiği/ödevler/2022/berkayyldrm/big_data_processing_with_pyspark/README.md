# Big-Data-Processing-with-PySpark
YTU MSc Big Data Analytics Course

## Instructions For Project
### Downloading data
First download the folder in the zip file attached to this assignment: timeusage.zip.

For this assignment, you also need to download the data (164 MB):

http://alaska.epfl.ch/~dockermoocs/bigdata/atussum.csv

and place it in the folder src/main/resources/timeusage/ in your project directory.

### The problem
The dataset is provided by Kaggle and is documented here:

https://www.kaggle.com/bls/american-time-use-survey

The file uses the comma-separated values format: the first line is a header defining the field names of each column, and every following line contains an information record, which is itself made of several columns. It contains information about how people spend their time (e.g., sleeping, eating, working, etc.).

Our goal is to identify three groups of activities:

* primary needs (sleeping and eating),

* work,

* other (leisure).

And then to observe how do people allocate their time between these three kinds of activities, and if we can see differences between men and women, employed and unemployed people, and young (less than 22 years old), active (between 22 and 55 years old) and elder people.

To answer the questions below, first read the dataset with Spark, transform it into an intermediate dataset which will be easier to work with, and finally compute information that will answer the questions.

### Read-in Data:
The simplest way to create a DataFrame consists in reading a file and letting Spark-sql infer the underlying schema. However this approach does not work well with CSV files, because the inferred column types are always String.

In our case, the first column contains a String value identifying the respondent but all the other columns contain numeric values. Since this schema will not be correctly inferred by Spark-sql, we will define it programmatically. However, the number of columns is huge. So, instead of manually enumerating all the columns we can rely on the fact that, in the CSV file, the first line contains the name of all the columns of the dataset.

Our first task consists in turning this first line into a Spark-sql StructType. This is the purpose of the dfSchema method. This method returns a StructType describing the schema of the CSV file, where the first column has type StringType and all the others have type DoubleType. None of these columns are nullable.

```def dfSchema(columnNames: List[String]): StructType```

The second step is to be able to effectively read the CSV file is to turn each line into a Spark-sql Row containing columns that match the schema returned by dfSchema. That’s the job of the row method.
```def row(line: List[String]): Row```

### Project info:
The initial dataset contains lots of information that are not needed to answer the questions, and even the columns that contain useful information are too detailed. For instance, we are not interested in the exact age of each respondent, but just whether she was “young”, “active” or “elder”.

Also, the time spent on each activity is very detailed (there are more than 50 reported activities). Again, this level of detail is not needed; only interested in three activities: primary needs, work and other. With this initial dataset it would a bit hard to express the queries that would give the answers.

The second part of this assignment consists in transforming the initial dataset into a format that will be easier to work with.

A first step in this direction is to identify which columns are related to the same activity. Based on the description of the activity corresponding to each column (given in https://www.kaggle.com/bls/american-time-use-survey), we deduce the following rules:

“primary needs” activities (sleeping, eating, etc.) are reported in columns starting with “t01”, “t03”, “t11”, “t1801” and “t1803” ;

working activities are reported in columns starting with “t05” and “t1805” ;

other activities (leisure) are reported in columns starting with “t02”, “t04”, “t06”, “t07”, “t08”, “t09”, “t10”, “t12”, “t13”, “t14”, “t15”, “t16” and “t18” (only those which are not part of the previous groups).

Then your work consists in implementing the classifiedColumns method, which classifies the given list of column names into three Column groups (primary needs, work or other). This method should return a triplet containing the “primary needs” columns list, the “work” columns list and the “other” columns list.

```def classifiedColumns(columnNames: List[String]):```

```(List[Column],List[Column], List[Column])```

The second step is to implement the timeUsageSummary method, which projects the detailed dataset into a summarized dataset. This summary will contain only 6 columns: the working status of the respondent, sex, age, the amount of daily hours spent on primary needs activities, the amount of daily hours spent on working and the amount of daily hours spent on other activities.

```def timeUsageSummary(```

```primaryNeedsColumns: List[Column],```

```workColumns: List[Column],```

```otherColumns: List[Column],```

```df: DataFrame```

```): DataFrame```

Each “activity column” will contain the sum of the columns related to the same activity of the initial dataset. Note that time amounts are given in minutes in the initial dataset, whereas in our resulting dataset we want them to be in hours.

The columns describing the work status, the sex and the age, will contain simplified information compared to the initial dataset.

Last, people that are not employable will be filtered out of the resulting dataset.

The comment on top of the timeUsageSummary method will give you more specific information about what is expected in each column.

### Aggregate Results
Compare the average time spent on each activity, for all the combinations of working status, sex and age.

Implement the timeUsageGrouped method which computes the average number of hours spent on each activity, grouped by working status (employed or unemployed), sex and age (young, active or elder), and also ordered by working status, sex and age. The values will be rounded to the nearest tenth.

```def timeUsageGrouped(summed: DataFrame): DataFrame```

Now you can run the project and see what the final DataFrame contains.

### Cassandra
Finally, save the dataframe timeUsageSummary that you generated into Cassandra Database. Also, try getting the same aggregate results in the previous step now by using Cassandra.

## Questions
1. Answer the following questions based on the dataset:

a) How much time do we spend on primary needs compared to other activities?

b) Do women and men spend the same amount of time in working?

c) Does the time spent on primary needs change when people get older? In other words, how much time elder people allocate to leisure compared to active people?

d) How much time do employed people spend on leisure compared to unemployed people?

## Requirements

-	Python 2.7.17.
-	PySpark 2.4.7
-	Apache-cassandra-3.11.11
-	Openjdk version "1.8.0_312"
