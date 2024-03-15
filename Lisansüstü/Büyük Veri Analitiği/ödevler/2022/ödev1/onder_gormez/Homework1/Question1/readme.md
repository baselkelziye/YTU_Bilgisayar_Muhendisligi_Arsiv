# Question 1
Implement the WordCount program to count the words in the file content.

## Steps
* The Hadoop collection is installed in a docker image as specified in the links below;
  * [How to set up a Hadoop cluster in Docker
](https://shortcut.com/developer-how-to/how-to-set-up-a-hadoop-cluster-in-docker)
  * Used [Big Data Europe Github Repository](https://github.com/big-data-europe/docker-hadoop)
* Docker image run as stated below

```sh
onder@debian-onder:~/Repos/docker-hadoop$ docker-compose up -d
```
* A compiled version of word count program was downloaded from [repo1.maven.org](https://repo1.maven.org/maven2/org/apache/hadoop/hadoop-mapreduce-examples/2.7.1/hadoop-mapreduce-examples-2.7.1-sources.jar).
* The downloaded .jar file is sent to the namenode as follows.

```sh
# First get container id for namenode
onder@debian-onder:~/Repos/docker-hadoop$ docker ps
# CONTAINER ID   IMAGE                                                    COMMAND                  CREATED       STATUS                       PORTS                                            NAMES
# 84fabc8f5ee8   bde2020/hadoop-namenode:2.0.0-hadoop3.2.1-java8          "/entrypoint.sh /run…"   2 hours ago   Up About an hour (healthy)   0.0.0.0:9000->9000/tcp, 0.0.0.0:9870->9870/tcp   namenode

# Copy .jar file
onder@debian-onder:~/Repos/docker-hadoop$ docker cp ~/Downloads/hadoop-mapreduce-examples-2.7.1-sources.jar 84fabc8f5ee8:hadoop-mapreduce-examples-2.7.1-sources.jar
```

* Use "fake news" dataset provided in the [archive link](https://www.kaggle.com/datasets/mrisdal/fake-news/download?datasetVersionNumber=1).
  * Source: [Meg Risdal: Fake News](https://www.kaggle.com/datasets/mrisdal/fake-news)
  * The original data set was modified to get a clear reducer result
    * **","** replaced with space character
    * **",** replaced with space character
    * **,"** replaced with space character
    * **"** replaced with space character
    * **,** replaced with space character

* The modified fake.csv file is sent to the namenode as follows.

```sh
onder@debian-onder:~/Repos/docker-hadoop$ docker cp ~/Downloads/modified_fake.csv namenode:modified_fake.csv
```

* Connect to namenode with interactive bash console

```sh
onder@debian-onder:~/Repos/docker-hadoop$ docker exec --interactive --tty namenode bash

# See copied hadoop-mapreduce-examples-2.7.1-sources.jar and modified_fake.csv files like below
root@84fabc8f5ee8:/$ ls
# KEYS  bin  boot  dev  entrypoint.sh  etc  hadoop  hadoop-data  hadoop-mapreduce-examples-2.7.1-sources.jar  home  lib  lib64  media  mnt  modified_fake.csv  opt  proc  root  run  run.sh  sbin  srv  sys  tmp  usr  var
root@84fabc8f5ee8:/$
```

* Create the modified_fake.csv file, copied to the namenode, in the Hadoop Distributed File System as follows;

```sh
# First create folder inside the Hadoop Distributed File System
root@84fabc8f5ee8:/$ hdfs dfs -mkdir input/

# Copy file
root@84fabc8f5ee8:/$ hadoop fs -put modified_fake.csv input/

# See copied file like below
root@84fabc8f5ee8:/$ hadoop fs -ls input/
# Found 1 items
# -rw-r--r--   3 root supergroup   56680002 2022-11-27 21:10 input/modified_fake.csv
root@84fabc8f5ee8:/$ 
```

* The word count program can be run with hadoop as follows.

```sh
root@84fabc8f5ee8:/$ hadoop jar hadoop-mapreduce-examples-2.7.1-sources.jar org.apache.hadoop.examples.WordCount input output
2022-11-27 21:23:09,587 INFO client.RMProxy: Connecting to ResourceManager at resourcemanager/172.20.0.5:8032
2022-11-27 21:23:09,999 INFO client.AHSProxy: Connecting to Application History server at historyserver/172.20.0.4:10200
# Other outputs...
2022-11-27 21:23:10,730 INFO input.FileInputFormat: Total input files to process : 1
# Other outputs...
2022-11-27 21:23:10,834 INFO mapreduce.JobSubmitter: number of splits:1
# Other outputs...
2022-11-27 21:23:11,997 INFO impl.YarnClientImpl: Submitted application application_1669581356891_0001
2022-11-27 21:23:12,106 INFO mapreduce.Job: The url to track the job: http://resourcemanager:8088/proxy/application_1669581356891_0001/
2022-11-27 21:23:12,108 INFO mapreduce.Job: Running job: job_1669581356891_0001
2022-11-27 21:23:21,379 INFO mapreduce.Job: Job job_1669581356891_0001 running in uber mode : false
2022-11-27 21:23:21,380 INFO mapreduce.Job:  map 0% reduce 0%
2022-11-27 21:23:39,619 INFO mapreduce.Job:  map 54% reduce 0%
2022-11-27 21:23:45,673 INFO mapreduce.Job:  map 100% reduce 0%
2022-11-27 21:23:53,744 INFO mapreduce.Job:  map 100% reduce 100%
2022-11-27 21:23:53,762 INFO mapreduce.Job: Job job_1669581356891_0001 completed successfully
2022-11-27 21:23:53,985 INFO mapreduce.Job: Counters: 54

        File System Counters
                FILE: Number of bytes read=7791903
                FILE: Number of bytes written=11695185
# Other outputs...
                HDFS: Number of bytes read=56680121
                HDFS: Number of bytes written=8791543
# Other outputs...

        Job Counters 
                Launched map tasks=1
                Launched reduce tasks=1
                Rack-local map tasks=1
# Other outputs...
        Map-Reduce Framework
                Map input records=170364
                Map output records=8554767
# Other outputs...
        Shuffle Errors
# Other outputs...
        File Input Format Counters 
                Bytes Read=56680002
        File Output Format Counters 
                Bytes Written=8791543
root@84fabc8f5ee8:/$
```

* See output files like below;

```sh
root@84fabc8f5ee8:/$ hdfs dfs -ls output/
# Found 2 items
# -rw-r--r--   3 root supergroup          0 2022-11-27 21:23 output/_SUCCESS
# -rw-r--r--   3 root supergroup    8791543 2022-11-27 21:23 output/part-r-00000
root@84fabc8f5ee8:/$
```
* Since the resulting file is a very large file, it is not suitable for examination on the console. For this reason, it should be pulled to the local computer with the following commands.

```sh
# Copied from HDFS to namenode
root@84fabc8f5ee8:/$ hadoop fs -get output/part-r-00000 result.txt
root@84fabc8f5ee8:/$ ls
hadoop-mapreduce-examples-2.7.1-sources.jar  home  modified_fake.csv  opt  result.txt  root ...
root@84fabc8f5ee8:/$ 

# Copied from namenode docker image to local pc
onder@debian-onder:~/Repos/docker-hadoop$ docker cp namenode:result.txt ~/Downloads/result.txt
onder@debian-onder:~/Repos/docker-hadoop$ ls -la ~/Downloads/result.txt 
-rw-r--r-- 1 onder onder 8791543 Nov 28 00:38 /home/onder/Downloads/result.txt
onder@debian-onder:~/Repos/docker-hadoop$
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

## Example Results
As an example, some results in the created file are shared. For more details, see the result.txt file.

```
0.996           3
0.997           3
0.998           3
...
Askari          1
Asked           115
Askeri          1
Askew           1
Asking          41
Asks            44
...
Assemble        19
Assembled       5
Assembly        135
Assembly.       17
...
Guest           174
Guests          6
...
Hemisphere      119
Hemisphere.     14
...
selloffs        3
sellos          3
sellout         13
...
يسيطرون         2
يشغلون          1
يشملهم          1
...
ядерную         4
ядерные         6
ядерный         4
בדומה           1
בדרום           1
בהגדרת          4
...
```

## Feature Works

The currently used program treats the same word as different words. Because it's assumes that uppercase and lowercase words are different words. This part can be overcome by converting all words to lowercase in the mapper.

## Troubleshooting

```sh
root@84fabc8f5ee8:/$ hadoop jar hadoop-mapreduce-examples-2.7.1-sources.jar org.apache.hadoop.examples.WordCount input output
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
