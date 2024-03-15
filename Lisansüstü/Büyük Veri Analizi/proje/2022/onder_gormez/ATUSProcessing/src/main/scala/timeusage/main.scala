package timeusage

import org.apache.spark.sql._
import org.apache.spark.sql.types._

import java.nio.file.Paths

/* IMPORTANT: This code copied and adapted from; */
/* https://github.com/dsp02/timeusage */
/** Main class */
object TimeUsage {

  import org.apache.spark.sql.SparkSession
  import org.apache.spark.sql.functions._

  val spark: SparkSession =
    SparkSession
      .builder()
      .appName("Time Usage")
      .config("spark.master", "local")
      .getOrCreate()

  // For implicit conversions like converting RDDs to DataFrames
  import spark.implicits._

  val PRIMARY_NEEDS_ACTIVITIES = "Primary Needs"
  val WORK_ACTIVITIES = "Work"
  val OTHER_ACTIVITIES = "Other"
  val WORKING = "Working"
  val SEX = "Sex"
  val AGE = "Age"

  /** Main function */
  def main(args: Array[String]): Unit = {
    timeUsageByLifePeriod()
  }

  def timeUsageByLifePeriod(): Unit = {
    // This means that: ProjectFolder/src/main/resources/timeusage/atussum.csv
    val (columns, initDf) = read("/timeusage/atussum.csv")
    val (primaryNeedsColumns, workColumns, otherColumns) = classifiedColumns(columns)
    val summaryDf = timeUsageSummary(primaryNeedsColumns, workColumns, otherColumns, initDf)
    val finalDf = timeUsageGrouped(summaryDf)
    finalDf.show()

    // 1. Answer the following questions based on the dataset:
    // a) How much time do we spend on primary needs compared to other activities?
    finalDf.select(PRIMARY_NEEDS_ACTIVITIES, OTHER_ACTIVITIES)
      .agg(functions.mean(PRIMARY_NEEDS_ACTIVITIES), functions.mean(OTHER_ACTIVITIES))
      .show()

    // b) Do women and men spend the same amount of time in working?
    finalDf.groupBy(SEX)
      .agg(functions.mean(WORK_ACTIVITIES))
      .show()

    // c) Does the time spent on primary needs change when people get older? In other words,
    //    how much time elder people allocate to leisure compared to active people?
    finalDf.groupBy(AGE)
      .agg(functions.mean(OTHER_ACTIVITIES))
      .where((finalDf(AGE) === "active") or (finalDf(AGE) === "elder"))
      .show()

    // d) How much time do employed people spend on leisure compared to unemployed people?
    finalDf.groupBy(WORKING)
      .agg(functions.mean(OTHER_ACTIVITIES))
      .show()
  }

  /** @return The read DataFrame along with its column names. */
  def read(resource: String): (List[String], DataFrame) = {
    val rdd = spark.sparkContext.textFile(fsPath(resource))

    val headerColumns = rdd.first().split(",").to(List)
    // Compute the schema based on the first line of the CSV file
    val schema = dfSchema(headerColumns)

    val data =
      rdd
        .mapPartitionsWithIndex((i, it) => if (i == 0) it.drop(1) else it) // skip the header line
        .map(_.split(",").to(List))
        .map(row)

    val dataFrame =
      spark.createDataFrame(data, schema)

    (headerColumns, dataFrame)
  }

  /** @return The filesystem path of the given resource */
  def fsPath(resource: String): String =
    Paths.get(getClass.getResource(resource).toURI).toString

  /** @return The schema of the DataFrame, assuming that the first given column has type String and all the others
   *         have type Double. None of the fields are nullable.
   * @param columnNames Column names of the DataFrame
   */
  def dfSchema(columnNames: List[String]): StructType = {

    val fields = columnNames.map(name => name match {
      case head if (name == columnNames.head) => StructField(head, StringType, nullable = false)
      case other => StructField(other, DoubleType, nullable = false)
    })
    StructType(fields)
  }


  /** @return An RDD Row compatible with the schema produced by `dfSchema`
   * @param line Raw fields
   */
  def row(line: List[String]): Row = {
    val row2 = Row.fromSeq((line.head :: line.tail.map(_.toDouble)))
    row2
  }

  /** @return The initial data frame columns partitioned in three groups: primary needs (sleeping, eating, etc.),
   *         work and other (leisure activities)
   *
   * @see https://www.kaggle.com/bls/american-time-use-survey
   *
   * The dataset contains the daily time (in minutes) people spent in various activities. For instance, the column
   * “t010101” contains the time spent sleeping, the column “t110101” contains the time spent eating and drinking, etc.
   *
   * This method groups related columns together:
   * 1. “primary needs” activities (sleeping, eating, etc.). These are the columns starting with “t01”, “t03”, “t11”,
   *    “t1801” and “t1803”.
   * 2. working activities. These are the columns starting with “t05” and “t1805”.
   * 3. other activities (leisure). These are the columns starting with “t02”, “t04”, “t06”, “t07”, “t08”, “t09”,
   *    “t10”, “t12”, “t13”, “t14”, “t15”, “t16” and “t18” (those which are not part of the previous groups only).
   */
  def classifiedColumns(columnNames: List[String]): (List[Column], List[Column], List[Column]) = {

    //    def columnNameStartsWithKey(columnIds: String): Array[Column] = columnIds.split(",").map(new Column(_))

    def columnNameStartsWithKey(colName: String, keys: List[String]):Boolean = !keys.filter(key => colName.startsWith(key)).isEmpty

    val primaryNeedsKeys = List("t01", "t03", "t11", "t1801", "t1803")
    val primaryNeedsCols = columnNames.filter(col =>  columnNameStartsWithKey(col, primaryNeedsKeys))

    val workingActivitiesKeys = List("t05", "t1805")
    val workingActivitiesCols = columnNames.filter(col => columnNameStartsWithKey(col, workingActivitiesKeys))

    val otherActivitiesKeys = List("t02", "t04", "t06", "t07", "t08", "t09", "t10", "t12", "t13", "t14", "t15", "t16", "t18")
    val otherActivitiesCols = columnNames
      .filter(col => columnNameStartsWithKey(col, otherActivitiesKeys)) diff primaryNeedsCols diff workingActivitiesCols

    (primaryNeedsCols map(new Column(_)), workingActivitiesCols map (new Column(_)), otherActivitiesCols map (new Column(_)))
  }

  /** @return a projection of the initial DataFrame such that all columns containing hours spent on primary needs
   *         are summed together in a single column (and same for work and leisure). The “teage” column is also
   *         projected to three values: "young", "active", "elder".
   *
   * @param primaryNeedsColumns List of columns containing time spent on “primary needs”
   * @param workColumns List of columns containing time spent working
   * @param otherColumns List of columns containing time spent doing other activities
   * @param df DataFrame whose schema matches the given column lists
   *
   * This methods builds an intermediate DataFrame that sums up all the columns of each group of activity into
   * a single column.
   *
   * The resulting DataFrame should have the following columns:
   * - working: value computed from the “telfs” column of the given DataFrame:
   *   - WORKING if 1 <= telfs < 3
   *   - "not working" otherwise
   * - sex: value computed from the “tesex” column of the given DataFrame:
   *   - "male" if tesex = 1, "female" otherwise
   * - age: value computed from the “teage” column of the given DataFrame:
   *   - "young" if 15 <= teage <= 22,
   *   - "active" if 23 <= teage <= 55,
   *   - "elder" otherwise
   * - primaryNeeds: sum of all the `primaryNeedsColumns`, in hours
   * - work: sum of all the `workColumns`, in hours
   * - other: sum of all the `otherColumns`, in hours
   *
   * Finally, the resulting DataFrame should exclude people that are not employable (ie telfs = 5).
   *
   * Note that the initial DataFrame contains time in ''minutes''. You have to convert it into ''hours''.
   */
  def timeUsageSummary(
                        primaryNeedsColumns: List[Column],
                        workColumns: List[Column],
                        otherColumns: List[Column],
                        df: DataFrame
                      ): DataFrame = {
    // Transform the data from the initial dataset into data that make
    // more sense for our use case
    // Hint: you can use the `when` and `otherwise` Spark functions
    // Hint: don’t forget to give your columns the expected name with the `as` method
    val workingStatusProjection: Column = when($"telfs" < 3.0 && $"telfs" >= 1.0, "working").otherwise("not working").as(WORKING)
    val sexProjection: Column = when($"tesex" === 1.0, "male").otherwise("female").as(SEX)
    val ageProjection: Column = when($"teage" >= 15.0  && $"teage" <= 22.0, "young")
      .when($"teage" >= 23.0  && $"teage" <= 55.0, "active")
      .otherwise("elder")
      .as(AGE)

    // Create columns that sum columns of the initial dataset
    // Hint: you want to create a complex column expression that sums other columns
    //       by using the `+` operator between them
    // Hint: don’t forget to convert the value to hours
    val primaryNeedsProjection: Column = (primaryNeedsColumns.reduce(_+_)/60.0).as(PRIMARY_NEEDS_ACTIVITIES)
    val workProjection: Column = (workColumns.reduce(_+_)/60.0).as(WORK_ACTIVITIES)
    val otherProjection: Column = (otherColumns.reduce(_+_)/60.0).as(OTHER_ACTIVITIES)
    df
      .select(workingStatusProjection, sexProjection, ageProjection, primaryNeedsProjection, workProjection, otherProjection)
      .where($"telfs" <= 4) // Discard people who are not in labor force
  }

  /** @return the average daily time (in hours) spent in primary needs, working or leisure, grouped by the different
   *         ages of life (young, active or elder), sex and working status.
   * @param summed DataFrame returned by `timeUsageSumByClass`
   *
   * The resulting DataFrame should have the following columns:
   * - working: the “working” column of the `summed` DataFrame,
   * - sex: the “sex” column of the `summed` DataFrame,
   * - age: the “age” column of the `summed` DataFrame,
   * - primaryNeeds: the average value of the “primaryNeeds” columns of all the people that have the same working
   *   status, sex and age, rounded with a scale of 1 (using the `round` function),
   * - work: the average value of the “work” columns of all the people that have the same working status, sex
   *   and age, rounded with a scale of 1 (using the `round` function),
   * - other: the average value of the “other” columns all the people that have the same working status, sex and
   *   age, rounded with a scale of 1 (using the `round` function).
   *
   * Finally, the resulting DataFrame should be sorted by working status, sex and age.
   */
  def timeUsageGrouped(summed: DataFrame): DataFrame =
    summed.groupBy(WORKING, SEX, AGE)
      .agg(round(avg(PRIMARY_NEEDS_ACTIVITIES),1).as(PRIMARY_NEEDS_ACTIVITIES),
        round(avg(WORK_ACTIVITIES),1).as(WORK_ACTIVITIES),
        round(avg(OTHER_ACTIVITIES),1).as(OTHER_ACTIVITIES))
      .sort(WORKING, SEX, AGE)

  /**
   * @return Same as `timeUsageGrouped`, but using a plain SQL query instead
   * @param summed DataFrame returned by `timeUsageSumByClass`
   */
  def timeUsageGroupedSql(summed: DataFrame): DataFrame = {
    val viewName = s"summed"
    summed.createOrReplaceTempView(viewName)
    spark.sql(timeUsageGroupedSqlQuery(viewName))
  }

  /** @return SQL query equivalent to the transformation implemented in `timeUsageGrouped`
   * @param viewName Name of the SQL view to use
   */
  def timeUsageGroupedSqlQuery(viewName: String): String = {
    val query = "SELECT working, sex, age, avg(primaryNeeds) as primaryNeeds," +
      "avg(work) as work, avg(other) as other from " + viewName +
      " GROUP BY working, sex, age" +
      "ORDER BY working, sex, age"

    query
  }


  /**
   * @return A `Dataset[TimeUsageRow]` from the “untyped” `DataFrame`
   * @param timeUsageSummaryDf `DataFrame` returned by the `timeUsageSummary` method
   *
   * Hint: you should use the `getAs` method of `Row` to look up columns and
   * cast them at the same time.
   */
  def timeUsageSummaryTyped(timeUsageSummaryDf: DataFrame): Dataset[TimeUsageRow] = {

    timeUsageSummaryDf.map(row => TimeUsageRow(row.getAs[String](WORKING), row.getAs[String](SEX), row.getAs[String](AGE),
      row.getAs[Double](PRIMARY_NEEDS_ACTIVITIES), row.getAs[Double](WORK_ACTIVITIES), row.getAs[Double](OTHER_ACTIVITIES)))
  }

  /**
   * @return Same as `timeUsageGrouped`, but using the typed API when possible
   * @param summed Dataset returned by the `timeUsageSummaryTyped` method
   *
   * Note that, though they have the same type (`Dataset[TimeUsageRow]`), the input
   * dataset contains one element per respondent, whereas the resulting dataset
   * contains one element per group (whose time spent on each activity kind has
   * been aggregated).
   *
   * Hint: you should use the `groupByKey` and `typed.avg` methods.
   */
  def timeUsageGroupedTyped(summed: Dataset[TimeUsageRow]): Dataset[TimeUsageRow] = {
    import org.apache.spark.sql.expressions.scalalang.typed

    val averages: Dataset[((String, String, String), Double, Double, Double)] =
      summed.groupByKey((time: TimeUsageRow) => (time.working, time.sex, time.age))
        .agg(typed.avg(_.primaryNeeds), typed.avg(_.work), typed.avg(_.other))

    val convertToTimeUsageRow:Dataset[TimeUsageRow] = averages.map {
      case ((timeWorking, timeSex, timeAge), avgTimePrimaryNeeds, avgTimeWork, avgTimeOther) =>
        TimeUsageRow(timeWorking, timeSex, timeAge, avgTimePrimaryNeeds, avgTimeWork, avgTimeOther)
    }
    convertToTimeUsageRow.orderBy("timeWorking", "timeSex", "timeAge")
  }
}

/**
 * Models a row of the summarized data set
 * @param working Working status (either "working" or "not working")
 * @param sex Sex (either "male" or "female")
 * @param age Age (either "young", "active" or "elder")
 * @param primaryNeeds Number of daily hours spent on primary needs
 * @param work Number of daily hours spent on work
 * @param other Number of daily hours spent on other activities
 */
case class TimeUsageRow(
                         working: String,
                         sex: String,
                         age: String,
                         primaryNeeds: Double,
                         work: Double,
                         other: Double
                       )
