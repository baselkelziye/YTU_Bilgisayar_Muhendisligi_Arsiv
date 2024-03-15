# SCALA
## 1) Answer the following questions based on the dataset:

```
+-----------+------+------+-------------+----+-----+
|    Working|   Sex|   Age|Primary Needs|Work|Other|
+-----------+------+------+-------------+----+-----+
|not working|female|active|         12.4| 0.5| 10.8|
|not working|female| elder|         10.9| 0.4| 12.4|
|not working|female| young|         12.5| 0.2| 11.1|
|not working|  male|active|         11.4| 0.9| 11.4|
|not working|  male| elder|         10.7| 0.7| 12.3|
|not working|  male| young|         11.6| 0.2| 11.9|
|    working|female|active|         11.5| 4.2|  8.1|
|    working|female| elder|         10.6| 3.9|  9.3|
|    working|female| young|         11.6| 3.3|  8.9|
|    working|  male|active|         10.8| 5.2|  7.8|
|    working|  male| elder|         10.4| 4.8|  8.6|
|    working|  male| young|         10.9| 3.7|  9.2|
+-----------+------+------+-------------+----+-----+
```

### a) How much time do we spend on primary needs compared to other activities?
```
+------------------+----------+
|avg(Primary Needs)|avg(Other)|
+------------------+----------+
|11.274999999999999|     10.15|
+------------------+----------+
```

### b) Do women and men spend the same amount of time in working?

```
+------+------------------+
|   Sex|         avg(Work)|
+------+------------------+
|female|2.0833333333333335|
|  male|2.5833333333333335|
+------+------------------+
```

### c) Does the time spent on primary needs change when people get older? In other words, how much time elder people allocate to leisure compared to active people?
```
+------+----------+
|   Age|avg(Other)|
+------+----------+
|active|     9.525|
| elder|     10.65|
+------+----------+
```
### d) How much time do employed people spend on leisure compared to unemployed people?

```
+-----------+-----------------+
|    Working|       avg(Other)|
+-----------+-----------------+
|    working|8.649999999999999|
|not working|            11.65|
+-----------+-----------------+
```

# Execution Output

You can see the full output of the program in [output.md](output.md) file.
