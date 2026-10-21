from pyspark.sql import SparkSession
from pyspark.sql.functions import when, col, round, avg
from operator import add
from functools import reduce
from cassandra.cluster import Cluster, BatchStatement, ConsistencyLevel

# This methods returns the names of columns related to primary-working-other activities according to pre-defined match structure
def classifiedColumns(sparkDataFrameColumnList):
    # The activity columns are started with these assigned values.
    primary_activities_columns = ["t01", "t03", "t11", "t1801", "t1803"]
    working_activities_columns = ["t05", "t1805"]
    other_activities_columns = ["t02", "t04", "t06", "t07", "t08", "t09", "t10", "t12", "t13", "t14", "t15", "t16","t18"]

    primary_column_names = []
    working_column_names = []
    other_column_names = []

    for column in sparkDataFrameColumnList:
        for primary_pattern in primary_activities_columns:
            if column.find(primary_pattern) == 0:
                primary_column_names.append(column)

        for working_pattern in working_activities_columns:
            if column.find(working_pattern) == 0:
                working_column_names.append(column)

        for other_pattern in other_activities_columns:
            if column.find(other_pattern) == 0:
                other_column_names.append(column)

    return primary_column_names, working_column_names, other_column_names

def timeUsageSummary(primaryNeedsColumns, workColumns, otherColumns, df):
    # teage : age
    # tesex : sex -> 1/2 | 1 : Male / 2 : Female
    # telfs : labor force status | 1 : employed - at work  / 2 : employed - absent / 3 : unemployed - on layoff / 4 : unemployed - looking / 5 : Not in labor force
    # print(df.select("t1801").take(10))

    df = df.withColumn("sex", when(df.tesex == 1,"male")
                                .otherwise("female"))

    df = df.withColumn("age", when(df.teage < 22, "young")
                       .when(df.teage < 55, "active")
                       .otherwise("elder"))

    df = df.withColumn("working_status", when(df.telfs == 1 | 2, "employed")
                       .otherwise("unemployed"))

    df = df.withColumn("primary_hours", reduce(add, [col(x) for x in primary_columns]) / 60)
    df = df.withColumn("working_hours", reduce(add, [col(x) for x in workColumns]) / 60)
    df = df.withColumn("others_hours" , reduce(add, [col(x) for x in otherColumns]) / 60)

    summary_dataframe = df.select("working_status","age","sex","primary_hours","working_hours","others_hours")

    return summary_dataframe

def timeUsageGrouped(summaried_dataset):
    summaried_dataset = summaried_dataset.groupBy("working_status", "age", "sex") \
        .avg("primary_hours", "working_hours", "others_hours") \
        .sort("working_status", "age", "sex")

    summaried_dataset = summaried_dataset.withColumn("primary_hours", round(col("avg(primary_hours)")))
    summaried_dataset = summaried_dataset.withColumn("working_hours", round(col("avg(working_hours)")))
    summaried_dataset = summaried_dataset.withColumn("others_hours", round(col("avg(others_hours)")))

    summaried_dataset = summaried_dataset.select("working_status", "age", "sex", "primary_hours", "working_hours",
                                                 "others_hours")

    return summaried_dataset

def dataWriteToCassandra(dataframe):
    cassandra_cluster = Cluster()
    session = cassandra_cluster.connect('bigdataproject')

    insert_user = session.prepare('INSERT INTO summarized_time_data (working_status, age, sex, other_hours, primary_hours, working_hours) values (?, ?, ?, ?, ?, ?)')
    batch = BatchStatement(consistency_level=ConsistencyLevel.QUORUM)

    for i in range(100):
        try:
            batch.add(insert_user,(dataframe.collect()[50+i][0],
                      dataframe.collect()[50+i][1],
                      dataframe.collect()[50+i][2],
                      dataframe.collect()[50+i][5],
                      dataframe.collect()[50+i][3],
                      dataframe.collect()[50+i][4]))
            print("Data inserted into the table!")
        except Exception as e:
            print("The Cassandra error : {}".format(e))

    session.execute(batch)


# Spark Session is created
spark = SparkSession.builder.\
    appName("BigDataAnalyticTermProject").\
    config("spark.cassandra.connection.host",'127.0.0.1').\
    config("spark.cassandra.connection.port","9042").\
    getOrCreate()

# The input data is read
df = spark.read.option("header", "true").option("inferSchema", "true").csv(
    "atussum.csv")


primary_columns, working_columns, other_columns = classifiedColumns(df.columns)
print("primary column names :")
print(primary_columns)
print("\n\n")
print("working column names : ")
print(working_columns)
print("\n\n")
print("other colum names : ")
print(other_columns)
print("\n\n\n\n")


summaried_dataset = timeUsageSummary(primary_columns,working_columns,other_columns,df)
print(summaried_dataset.count())
print(summaried_dataset.show(25))

print("\n\n\n")

grouped_summaried_dataset = timeUsageGrouped(summaried_dataset)

print(grouped_summaried_dataset.show(25))

def question_1(grouped_summaried_dataset):
    primary_total = grouped_summaried_dataset.agg(avg(col("primary_hours")))
    other_total = grouped_summaried_dataset.agg(avg(col("others_hours")))
    print("QUESTION 1 ANSWER : \n")
    print("The time we spend on primary need compared to other activities much more : {}".format(primary_total.collect()[0][0] - other_total.collect()[0][0]))
    print("\n\n")

def question_2(grouped_summaried_dataset):
    women_working = grouped_summaried_dataset.filter(grouped_summaried_dataset['sex'] == 'female').agg(avg(col("working_hours")))
    men_working = grouped_summaried_dataset.filter(grouped_summaried_dataset['sex'] == "male").agg(avg(col("working_hours")))
    print("QUESTION 2 ANSWER : \n")
    print("The working hour difference between women and man (women - men) is : {}".format(women_working.collect()[0][0] - men_working.collect()[0][0]))
    print("\n\n")

def question_3(grouped_summaried_dataset):
    elder_leisures = grouped_summaried_dataset.filter(grouped_summaried_dataset['age'] == 'elder').agg(avg(col("others_hours")))
    active_leisures = grouped_summaried_dataset.filter(grouped_summaried_dataset['age'] == 'active').agg(avg(col("others_hours")))
    print("QUESTION 3 ANSWER : \n")
    print("The time elder people allocate to leisure time compared to active people is : {}".format(elder_leisures.collect()[0][0] - active_leisures.collect()[0][0]))
    print("\n\n")

def question_4(grouped_summaried_dataset):
    employed_leisure = grouped_summaried_dataset.filter(grouped_summaried_dataset['working_status'] == "employed").agg(avg(col("others_hours")))
    unemployed_leisure = grouped_summaried_dataset.filter(grouped_summaried_dataset['working_status'] == "unemployed").agg(avg(col("others_hours")))
    print("QUESTION 4 ANSWER : \n")
    print("The time difference employed people leisure time spent from unemployed people leisure time spent is : {}".format(employed_leisure.collect()[0][0] - unemployed_leisure.collect()[0][0]))
    print("\n\n")

question_1(grouped_summaried_dataset)
question_2(grouped_summaried_dataset)
question_3(grouped_summaried_dataset)
question_4(grouped_summaried_dataset)

dataWriteToCassandra(summaried_dataset)



