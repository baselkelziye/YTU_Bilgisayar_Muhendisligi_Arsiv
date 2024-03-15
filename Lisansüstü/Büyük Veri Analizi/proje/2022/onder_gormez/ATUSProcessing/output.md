# Execution Output

```
/usr/lib/jvm/default-java/bin/java -javaagent:/home/onder/.local/share/JetBrains/Toolbox/apps/IDEA-C/ch-0/223.8214.52/lib/idea_rt.jar=46249:/home/onder/.local/share/JetBrains/Toolbox/apps/IDEA-C/ch-0/223.8214.52/bin -Dfile.encoding=UTF-8 -classpath /home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes:/home/onder/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.8/scala-library-2.13.8.jar:/home/onder/.m2/repository/org/apache/spark/spark-core_2.13/3.2.0/spark-core_2.13-3.2.0.jar:/home/onder/.m2/repository/org/scala-lang/modules/scala-parallel-collections_2.13/1.0.3/scala-parallel-collections_2.13-1.0.3.jar:/home/onder/.m2/repository/org/apache/avro/avro/1.10.2/avro-1.10.2.jar:/home/onder/.m2/repository/com/fasterxml/jackson/core/jackson-core/2.12.2/jackson-core-2.12.2.jar:/home/onder/.m2/repository/org/apache/commons/commons-compress/1.20/commons-compress-1.20.jar:/home/onder/.m2/repository/org/apache/avro/avro-mapred/1.10.2/avro-mapred-1.10.2.jar:/home/onder/.m2/repository/org/apache/avro/avro-ipc/1.10.2/avro-ipc-1.10.2.jar:/home/onder/.m2/repository/org/tukaani/xz/1.8/xz-1.8.jar:/home/onder/.m2/repository/com/twitter/chill_2.13/0.10.0/chill_2.13-0.10.0.jar:/home/onder/.m2/repository/com/esotericsoftware/kryo-shaded/4.0.2/kryo-shaded-4.0.2.jar:/home/onder/.m2/repository/com/esotericsoftware/minlog/1.3.0/minlog-1.3.0.jar:/home/onder/.m2/repository/org/objenesis/objenesis/2.5.1/objenesis-2.5.1.jar:/home/onder/.m2/repository/com/twitter/chill-java/0.10.0/chill-java-0.10.0.jar:/home/onder/.m2/repository/org/apache/xbean/xbean-asm9-shaded/4.20/xbean-asm9-shaded-4.20.jar:/home/onder/.m2/repository/org/apache/hadoop/hadoop-client-api/3.3.1/hadoop-client-api-3.3.1.jar:/home/onder/.m2/repository/org/apache/hadoop/hadoop-client-runtime/3.3.1/hadoop-client-runtime-3.3.1.jar:/home/onder/.m2/repository/org/apache/htrace/htrace-core4/4.1.0-incubating/htrace-core4-4.1.0-incubating.jar:/home/onder/.m2/repository/commons-logging/commons-logging/1.1.3/commons-logging-1.1.3.jar:/home/onder/.m2/repository/org/apache/spark/spark-launcher_2.13/3.2.0/spark-launcher_2.13-3.2.0.jar:/home/onder/.m2/repository/org/apache/spark/spark-kvstore_2.13/3.2.0/spark-kvstore_2.13-3.2.0.jar:/home/onder/.m2/repository/org/fusesource/leveldbjni/leveldbjni-all/1.8/leveldbjni-all-1.8.jar:/home/onder/.m2/repository/com/fasterxml/jackson/core/jackson-annotations/2.12.3/jackson-annotations-2.12.3.jar:/home/onder/.m2/repository/org/apache/spark/spark-network-common_2.13/3.2.0/spark-network-common_2.13-3.2.0.jar:/home/onder/.m2/repository/com/google/crypto/tink/tink/1.6.0/tink-1.6.0.jar:/home/onder/.m2/repository/com/google/protobuf/protobuf-java/3.14.0/protobuf-java-3.14.0.jar:/home/onder/.m2/repository/com/google/code/gson/gson/2.8.6/gson-2.8.6.jar:/home/onder/.m2/repository/org/apache/spark/spark-network-shuffle_2.13/3.2.0/spark-network-shuffle_2.13-3.2.0.jar:/home/onder/.m2/repository/org/apache/spark/spark-unsafe_2.13/3.2.0/spark-unsafe_2.13-3.2.0.jar:/home/onder/.m2/repository/javax/activation/activation/1.1.1/activation-1.1.1.jar:/home/onder/.m2/repository/org/apache/curator/curator-recipes/2.13.0/curator-recipes-2.13.0.jar:/home/onder/.m2/repository/org/apache/curator/curator-framework/2.13.0/curator-framework-2.13.0.jar:/home/onder/.m2/repository/org/apache/curator/curator-client/2.13.0/curator-client-2.13.0.jar:/home/onder/.m2/repository/com/google/guava/guava/16.0.1/guava-16.0.1.jar:/home/onder/.m2/repository/org/apache/zookeeper/zookeeper/3.6.2/zookeeper-3.6.2.jar:/home/onder/.m2/repository/commons-lang/commons-lang/2.6/commons-lang-2.6.jar:/home/onder/.m2/repository/org/apache/zookeeper/zookeeper-jute/3.6.2/zookeeper-jute-3.6.2.jar:/home/onder/.m2/repository/org/apache/yetus/audience-annotations/0.5.0/audience-annotations-0.5.0.jar:/home/onder/.m2/repository/jakarta/servlet/jakarta.servlet-api/4.0.3/jakarta.servlet-api-4.0.3.jar:/home/onder/.m2/repository/commons-codec/commons-codec/1.15/commons-codec-1.15.jar:/home/onder/.m2/repository/org/apache/commons/commons-lang3/3.12.0/commons-lang3-3.12.0.jar:/home/onder/.m2/repository/org/apache/commons/commons-math3/3.4.1/commons-math3-3.4.1.jar:/home/onder/.m2/repository/org/apache/commons/commons-text/1.6/commons-text-1.6.jar:/home/onder/.m2/repository/commons-io/commons-io/2.8.0/commons-io-2.8.0.jar:/home/onder/.m2/repository/commons-collections/commons-collections/3.2.2/commons-collections-3.2.2.jar:/home/onder/.m2/repository/com/google/code/findbugs/jsr305/3.0.0/jsr305-3.0.0.jar:/home/onder/.m2/repository/org/slf4j/slf4j-api/1.7.30/slf4j-api-1.7.30.jar:/home/onder/.m2/repository/org/slf4j/jul-to-slf4j/1.7.30/jul-to-slf4j-1.7.30.jar:/home/onder/.m2/repository/org/slf4j/jcl-over-slf4j/1.7.30/jcl-over-slf4j-1.7.30.jar:/home/onder/.m2/repository/log4j/log4j/1.2.17/log4j-1.2.17.jar:/home/onder/.m2/repository/org/slf4j/slf4j-log4j12/1.7.30/slf4j-log4j12-1.7.30.jar:/home/onder/.m2/repository/com/ning/compress-lzf/1.0.3/compress-lzf-1.0.3.jar:/home/onder/.m2/repository/org/xerial/snappy/snappy-java/1.1.8.4/snappy-java-1.1.8.4.jar:/home/onder/.m2/repository/org/lz4/lz4-java/1.7.1/lz4-java-1.7.1.jar:/home/onder/.m2/repository/com/github/luben/zstd-jni/1.5.0-4/zstd-jni-1.5.0-4.jar:/home/onder/.m2/repository/org/roaringbitmap/RoaringBitmap/0.9.0/RoaringBitmap-0.9.0.jar:/home/onder/.m2/repository/org/roaringbitmap/shims/0.9.0/shims-0.9.0.jar:/home/onder/.m2/repository/commons-net/commons-net/3.1/commons-net-3.1.jar:/home/onder/.m2/repository/org/scala-lang/modules/scala-xml_2.13/1.2.0/scala-xml_2.13-1.2.0.jar:/home/onder/.m2/repository/org/scala-lang/scala-library/2.13.5/scala-library-2.13.5.jar:/home/onder/.m2/repository/org/scala-lang/scala-reflect/2.13.5/scala-reflect-2.13.5.jar:/home/onder/.m2/repository/org/json4s/json4s-jackson_2.13/3.7.0-M11/json4s-jackson_2.13-3.7.0-M11.jar:/home/onder/.m2/repository/org/json4s/json4s-core_2.13/3.7.0-M11/json4s-core_2.13-3.7.0-M11.jar:/home/onder/.m2/repository/org/json4s/json4s-ast_2.13/3.7.0-M11/json4s-ast_2.13-3.7.0-M11.jar:/home/onder/.m2/repository/org/json4s/json4s-scalap_2.13/3.7.0-M11/json4s-scalap_2.13-3.7.0-M11.jar:/home/onder/.m2/repository/org/glassfish/jersey/core/jersey-client/2.34/jersey-client-2.34.jar:/home/onder/.m2/repository/jakarta/ws/rs/jakarta.ws.rs-api/2.1.6/jakarta.ws.rs-api-2.1.6.jar:/home/onder/.m2/repository/org/glassfish/hk2/external/jakarta.inject/2.6.1/jakarta.inject-2.6.1.jar:/home/onder/.m2/repository/org/glassfish/jersey/core/jersey-common/2.34/jersey-common-2.34.jar:/home/onder/.m2/repository/jakarta/annotation/jakarta.annotation-api/1.3.5/jakarta.annotation-api-1.3.5.jar:/home/onder/.m2/repository/org/glassfish/hk2/osgi-resource-locator/1.0.3/osgi-resource-locator-1.0.3.jar:/home/onder/.m2/repository/org/glassfish/jersey/core/jersey-server/2.34/jersey-server-2.34.jar:/home/onder/.m2/repository/jakarta/validation/jakarta.validation-api/2.0.2/jakarta.validation-api-2.0.2.jar:/home/onder/.m2/repository/org/glassfish/jersey/containers/jersey-container-servlet/2.34/jersey-container-servlet-2.34.jar:/home/onder/.m2/repository/org/glassfish/jersey/containers/jersey-container-servlet-core/2.34/jersey-container-servlet-core-2.34.jar:/home/onder/.m2/repository/org/glassfish/jersey/inject/jersey-hk2/2.34/jersey-hk2-2.34.jar:/home/onder/.m2/repository/org/glassfish/hk2/hk2-locator/2.6.1/hk2-locator-2.6.1.jar:/home/onder/.m2/repository/org/glassfish/hk2/external/aopalliance-repackaged/2.6.1/aopalliance-repackaged-2.6.1.jar:/home/onder/.m2/repository/org/glassfish/hk2/hk2-api/2.6.1/hk2-api-2.6.1.jar:/home/onder/.m2/repository/org/glassfish/hk2/hk2-utils/2.6.1/hk2-utils-2.6.1.jar:/home/onder/.m2/repository/org/javassist/javassist/3.25.0-GA/javassist-3.25.0-GA.jar:/home/onder/.m2/repository/io/netty/netty-all/4.1.68.Final/netty-all-4.1.68.Final.jar:/home/onder/.m2/repository/com/clearspring/analytics/stream/2.9.6/stream-2.9.6.jar:/home/onder/.m2/repository/io/dropwizard/metrics/metrics-core/4.2.0/metrics-core-4.2.0.jar:/home/onder/.m2/repository/io/dropwizard/metrics/metrics-jvm/4.2.0/metrics-jvm-4.2.0.jar:/home/onder/.m2/repository/io/dropwizard/metrics/metrics-json/4.2.0/metrics-json-4.2.0.jar:/home/onder/.m2/repository/io/dropwizard/metrics/metrics-graphite/4.2.0/metrics-graphite-4.2.0.jar:/home/onder/.m2/repository/io/dropwizard/metrics/metrics-jmx/4.2.0/metrics-jmx-4.2.0.jar:/home/onder/.m2/repository/com/fasterxml/jackson/core/jackson-databind/2.12.3/jackson-databind-2.12.3.jar:/home/onder/.m2/repository/com/fasterxml/jackson/module/jackson-module-scala_2.13/2.12.3/jackson-module-scala_2.13-2.12.3.jar:/home/onder/.m2/repository/com/thoughtworks/paranamer/paranamer/2.8/paranamer-2.8.jar:/home/onder/.m2/repository/org/apache/ivy/ivy/2.5.0/ivy-2.5.0.jar:/home/onder/.m2/repository/oro/oro/2.0.8/oro-2.0.8.jar:/home/onder/.m2/repository/net/razorvine/pyrolite/4.30/pyrolite-4.30.jar:/home/onder/.m2/repository/net/sf/py4j/py4j/0.10.9.2/py4j-0.10.9.2.jar:/home/onder/.m2/repository/org/apache/spark/spark-tags_2.13/3.2.0/spark-tags_2.13-3.2.0.jar:/home/onder/.m2/repository/org/apache/commons/commons-crypto/1.1.0/commons-crypto-1.1.0.jar:/home/onder/.m2/repository/org/spark-project/spark/unused/1.0.0/unused-1.0.0.jar:/home/onder/.m2/repository/org/apache/spark/spark-sql_2.13/3.2.1/spark-sql_2.13-3.2.1.jar:/home/onder/.m2/repository/org/rocksdb/rocksdbjni/6.20.3/rocksdbjni-6.20.3.jar:/home/onder/.m2/repository/com/univocity/univocity-parsers/2.9.1/univocity-parsers-2.9.1.jar:/home/onder/.m2/repository/org/apache/spark/spark-sketch_2.13/3.2.1/spark-sketch_2.13-3.2.1.jar:/home/onder/.m2/repository/org/apache/spark/spark-core_2.13/3.2.1/spark-core_2.13-3.2.1.jar:/home/onder/.m2/repository/org/apache/spark/spark-launcher_2.13/3.2.1/spark-launcher_2.13-3.2.1.jar:/home/onder/.m2/repository/org/apache/spark/spark-kvstore_2.13/3.2.1/spark-kvstore_2.13-3.2.1.jar:/home/onder/.m2/repository/org/apache/spark/spark-network-common_2.13/3.2.1/spark-network-common_2.13-3.2.1.jar:/home/onder/.m2/repository/org/apache/spark/spark-network-shuffle_2.13/3.2.1/spark-network-shuffle_2.13-3.2.1.jar:/home/onder/.m2/repository/org/apache/spark/spark-unsafe_2.13/3.2.1/spark-unsafe_2.13-3.2.1.jar:/home/onder/.m2/repository/net/sf/py4j/py4j/0.10.9.3/py4j-0.10.9.3.jar:/home/onder/.m2/repository/org/apache/spark/spark-catalyst_2.13/3.2.1/spark-catalyst_2.13-3.2.1.jar:/home/onder/.m2/repository/org/scala-lang/modules/scala-parser-combinators_2.13/1.1.2/scala-parser-combinators_2.13-1.1.2.jar:/home/onder/.m2/repository/org/codehaus/janino/janino/3.0.16/janino-3.0.16.jar:/home/onder/.m2/repository/org/codehaus/janino/commons-compiler/3.0.16/commons-compiler-3.0.16.jar:/home/onder/.m2/repository/org/antlr/antlr4-runtime/4.8/antlr4-runtime-4.8.jar:/home/onder/.m2/repository/javax/xml/bind/jaxb-api/2.2.11/jaxb-api-2.2.11.jar:/home/onder/.m2/repository/org/apache/arrow/arrow-vector/2.0.0/arrow-vector-2.0.0.jar:/home/onder/.m2/repository/org/apache/arrow/arrow-format/2.0.0/arrow-format-2.0.0.jar:/home/onder/.m2/repository/org/apache/arrow/arrow-memory-core/2.0.0/arrow-memory-core-2.0.0.jar:/home/onder/.m2/repository/com/google/flatbuffers/flatbuffers-java/1.9.0/flatbuffers-java-1.9.0.jar:/home/onder/.m2/repository/org/apache/arrow/arrow-memory-netty/2.0.0/arrow-memory-netty-2.0.0.jar:/home/onder/.m2/repository/org/apache/spark/spark-tags_2.13/3.2.1/spark-tags_2.13-3.2.1.jar:/home/onder/.m2/repository/org/apache/orc/orc-core/1.6.12/orc-core-1.6.12.jar:/home/onder/.m2/repository/org/apache/orc/orc-shims/1.6.12/orc-shims-1.6.12.jar:/home/onder/.m2/repository/com/google/protobuf/protobuf-java/2.5.0/protobuf-java-2.5.0.jar:/home/onder/.m2/repository/io/airlift/aircompressor/0.21/aircompressor-0.21.jar:/home/onder/.m2/repository/org/jetbrains/annotations/17.0.0/annotations-17.0.0.jar:/home/onder/.m2/repository/org/threeten/threeten-extra/1.5.0/threeten-extra-1.5.0.jar:/home/onder/.m2/repository/org/apache/orc/orc-mapreduce/1.6.12/orc-mapreduce-1.6.12.jar:/home/onder/.m2/repository/org/apache/hive/hive-storage-api/2.7.2/hive-storage-api-2.7.2.jar:/home/onder/.m2/repository/org/apache/parquet/parquet-column/1.12.2/parquet-column-1.12.2.jar:/home/onder/.m2/repository/org/apache/parquet/parquet-common/1.12.2/parquet-common-1.12.2.jar:/home/onder/.m2/repository/org/apache/parquet/parquet-encoding/1.12.2/parquet-encoding-1.12.2.jar:/home/onder/.m2/repository/org/apache/parquet/parquet-hadoop/1.12.2/parquet-hadoop-1.12.2.jar:/home/onder/.m2/repository/org/apache/parquet/parquet-format-structures/1.12.2/parquet-format-structures-1.12.2.jar:/home/onder/.m2/repository/org/apache/parquet/parquet-jackson/1.12.2/parquet-jackson-1.12.2.jar:/home/onder/.m2/repository/com/fasterxml/jackson/core/jackson-core/2.12.3/jackson-core-2.12.3.jar timeusage.TimeUsage
Using Spark's default log4j profile: org/apache/spark/log4j-defaults.properties
23/01/02 21:59:02 WARN Utils: Your hostname, Onder-Dell-G15-5520 resolves to a loopback address: 127.0.1.1; using 192.168.5.10 instead (on interface wlp0s20f3)
23/01/02 21:59:02 WARN Utils: Set SPARK_LOCAL_IP if you need to bind to another address
WARNING: An illegal reflective access operation has occurred
WARNING: Illegal reflective access by org.apache.spark.unsafe.Platform (file:/home/onder/.m2/repository/org/apache/spark/spark-unsafe_2.13/3.2.0/spark-unsafe_2.13-3.2.0.jar) to constructor java.nio.DirectByteBuffer(long,int)
WARNING: Please consider reporting this to the maintainers of org.apache.spark.unsafe.Platform
WARNING: Use --illegal-access=warn to enable warnings of further illegal reflective access operations
WARNING: All illegal access operations will be denied in a future release
23/01/02 21:59:02 INFO SparkContext: Running Spark version 3.2.0
23/01/02 21:59:02 WARN NativeCodeLoader: Unable to load native-hadoop library for your platform... using builtin-java classes where applicable
23/01/02 21:59:02 INFO ResourceUtils: ==============================================================
23/01/02 21:59:02 INFO ResourceUtils: No custom resources configured for spark.driver.
23/01/02 21:59:02 INFO ResourceUtils: ==============================================================
23/01/02 21:59:02 INFO SparkContext: Submitted application: Time Usage
23/01/02 21:59:02 INFO ResourceProfile: Default ResourceProfile created, executor resources: Map(cores -> name: cores, amount: 1, script: , vendor: , memory -> name: memory, amount: 1024, script: , vendor: , offHeap -> name: offHeap, amount: 0, script: , vendor: ), task resources: Map(cpus -> name: cpus, amount: 1.0)
23/01/02 21:59:02 INFO ResourceProfile: Limiting resource is cpu
23/01/02 21:59:02 INFO ResourceProfileManager: Added ResourceProfile id: 0
23/01/02 21:59:02 INFO SecurityManager: Changing view acls to: onder
23/01/02 21:59:02 INFO SecurityManager: Changing modify acls to: onder
23/01/02 21:59:02 INFO SecurityManager: Changing view acls groups to: 
23/01/02 21:59:02 INFO SecurityManager: Changing modify acls groups to: 
23/01/02 21:59:02 INFO SecurityManager: SecurityManager: authentication disabled; ui acls disabled; users  with view permissions: Set(onder); groups with view permissions: Set(); users  with modify permissions: Set(onder); groups with modify permissions: Set()
23/01/02 21:59:02 INFO Utils: Successfully started service 'sparkDriver' on port 36823.
23/01/02 21:59:02 INFO SparkEnv: Registering MapOutputTracker
23/01/02 21:59:02 INFO SparkEnv: Registering BlockManagerMaster
23/01/02 21:59:02 INFO BlockManagerMasterEndpoint: Using org.apache.spark.storage.DefaultTopologyMapper for getting topology information
23/01/02 21:59:02 INFO BlockManagerMasterEndpoint: BlockManagerMasterEndpoint up
23/01/02 21:59:02 INFO SparkEnv: Registering BlockManagerMasterHeartbeat
23/01/02 21:59:02 INFO DiskBlockManager: Created local directory at /tmp/blockmgr-a0aaba18-6ebc-4a6d-9a51-5e81dd45ab70
23/01/02 21:59:02 INFO MemoryStore: MemoryStore started with capacity 2.1 GiB
23/01/02 21:59:02 INFO SparkEnv: Registering OutputCommitCoordinator
23/01/02 21:59:02 INFO Utils: Successfully started service 'SparkUI' on port 4040.
23/01/02 21:59:03 INFO SparkUI: Bound SparkUI to 0.0.0.0, and started at http://192.168.5.10:4040
23/01/02 21:59:03 INFO Executor: Starting executor ID driver on host 192.168.5.10
23/01/02 21:59:03 INFO Utils: Successfully started service 'org.apache.spark.network.netty.NettyBlockTransferService' on port 40211.
23/01/02 21:59:03 INFO NettyBlockTransferService: Server created on 192.168.5.10:40211
23/01/02 21:59:03 INFO BlockManager: Using org.apache.spark.storage.RandomBlockReplicationPolicy for block replication policy
23/01/02 21:59:03 INFO BlockManagerMaster: Registering BlockManager BlockManagerId(driver, 192.168.5.10, 40211, None)
23/01/02 21:59:03 INFO BlockManagerMasterEndpoint: Registering block manager 192.168.5.10:40211 with 2.1 GiB RAM, BlockManagerId(driver, 192.168.5.10, 40211, None)
23/01/02 21:59:03 INFO BlockManagerMaster: Registered BlockManager BlockManagerId(driver, 192.168.5.10, 40211, None)
23/01/02 21:59:03 INFO BlockManager: Initialized BlockManager: BlockManagerId(driver, 192.168.5.10, 40211, None)
23/01/02 21:59:03 INFO MemoryStore: Block broadcast_0 stored as values in memory (estimated size 219.7 KiB, free 2.1 GiB)
23/01/02 21:59:03 INFO MemoryStore: Block broadcast_0_piece0 stored as bytes in memory (estimated size 32.1 KiB, free 2.1 GiB)
23/01/02 21:59:03 INFO BlockManagerInfo: Added broadcast_0_piece0 in memory on 192.168.5.10:40211 (size: 32.1 KiB, free: 2.1 GiB)
23/01/02 21:59:03 INFO SparkContext: Created broadcast 0 from textFile at main.scala:71
23/01/02 21:59:03 INFO FileInputFormat: Total input files to process : 1
23/01/02 21:59:03 INFO SparkContext: Starting job: first at main.scala:73
23/01/02 21:59:03 INFO DAGScheduler: Got job 0 (first at main.scala:73) with 1 output partitions
23/01/02 21:59:03 INFO DAGScheduler: Final stage: ResultStage 0 (first at main.scala:73)
23/01/02 21:59:03 INFO DAGScheduler: Parents of final stage: List()
23/01/02 21:59:03 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:03 INFO DAGScheduler: Submitting ResultStage 0 (/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv MapPartitionsRDD[1] at textFile at main.scala:71), which has no missing parents
23/01/02 21:59:03 INFO MemoryStore: Block broadcast_1 stored as values in memory (estimated size 5.0 KiB, free 2.1 GiB)
23/01/02 21:59:03 INFO MemoryStore: Block broadcast_1_piece0 stored as bytes in memory (estimated size 2.9 KiB, free 2.1 GiB)
23/01/02 21:59:03 INFO BlockManagerInfo: Added broadcast_1_piece0 in memory on 192.168.5.10:40211 (size: 2.9 KiB, free: 2.1 GiB)
23/01/02 21:59:03 INFO SparkContext: Created broadcast 1 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:03 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 0 (/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv MapPartitionsRDD[1] at textFile at main.scala:71) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:03 INFO TaskSchedulerImpl: Adding task set 0.0 with 1 tasks resource profile 0
23/01/02 21:59:03 INFO TaskSetManager: Starting task 0.0 in stage 0.0 (TID 0) (192.168.5.10, executor driver, partition 0, PROCESS_LOCAL, 7538 bytes) taskResourceAssignments Map()
23/01/02 21:59:03 INFO Executor: Running task 0.0 in stage 0.0 (TID 0)
23/01/02 21:59:03 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:0+33554432
23/01/02 21:59:03 INFO Executor: Finished task 0.0 in stage 0.0 (TID 0). 4690 bytes result sent to driver
23/01/02 21:59:03 INFO TaskSetManager: Finished task 0.0 in stage 0.0 (TID 0) in 75 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:03 INFO TaskSchedulerImpl: Removed TaskSet 0.0, whose tasks have all completed, from pool 
23/01/02 21:59:03 INFO DAGScheduler: ResultStage 0 (first at main.scala:73) finished in 0.111 s
23/01/02 21:59:03 INFO DAGScheduler: Job 0 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:03 INFO TaskSchedulerImpl: Killing all running tasks in stage 0: Stage finished
23/01/02 21:59:03 INFO DAGScheduler: Job 0 finished: first at main.scala:73, took 0.130363 s
23/01/02 21:59:03 INFO BlockManagerInfo: Removed broadcast_1_piece0 on 192.168.5.10:40211 in memory (size: 2.9 KiB, free: 2.1 GiB)
23/01/02 21:59:03 INFO SharedState: Setting hive.metastore.warehouse.dir ('null') to the value of spark.sql.warehouse.dir.
23/01/02 21:59:03 INFO SharedState: Warehouse path is 'file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/spark-warehouse'.
23/01/02 21:59:05 WARN package: Truncated the string representation of a plan since it was too large. This behavior can be adjusted by setting 'spark.sql.debug.maxToStringFields'.
23/01/02 21:59:05 INFO CodeGenerator: Code generated in 115.909125 ms
23/01/02 21:59:05 INFO DAGScheduler: Registering RDD 10 (show at main.scala:43) as input to shuffle 0
23/01/02 21:59:05 INFO DAGScheduler: Got map stage job 1 (show at main.scala:43) with 5 output partitions
23/01/02 21:59:05 INFO DAGScheduler: Final stage: ShuffleMapStage 1 (show at main.scala:43)
23/01/02 21:59:05 INFO DAGScheduler: Parents of final stage: List()
23/01/02 21:59:05 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:05 INFO DAGScheduler: Submitting ShuffleMapStage 1 (MapPartitionsRDD[10] at show at main.scala:43), which has no missing parents
23/01/02 21:59:05 INFO MemoryStore: Block broadcast_2 stored as values in memory (estimated size 305.4 KiB, free 2.1 GiB)
23/01/02 21:59:05 INFO MemoryStore: Block broadcast_2_piece0 stored as bytes in memory (estimated size 45.5 KiB, free 2.1 GiB)
23/01/02 21:59:05 INFO BlockManagerInfo: Added broadcast_2_piece0 in memory on 192.168.5.10:40211 (size: 45.5 KiB, free: 2.1 GiB)
23/01/02 21:59:05 INFO SparkContext: Created broadcast 2 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:05 INFO DAGScheduler: Submitting 5 missing tasks from ShuffleMapStage 1 (MapPartitionsRDD[10] at show at main.scala:43) (first 15 tasks are for partitions Vector(0, 1, 2, 3, 4))
23/01/02 21:59:05 INFO TaskSchedulerImpl: Adding task set 1.0 with 5 tasks resource profile 0
23/01/02 21:59:05 INFO TaskSetManager: Starting task 0.0 in stage 1.0 (TID 1) (192.168.5.10, executor driver, partition 0, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:05 INFO Executor: Running task 0.0 in stage 1.0 (TID 1)
23/01/02 21:59:05 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:0+33554432
23/01/02 21:59:05 INFO CodeGenerator: Code generated in 121.985816 ms
23/01/02 21:59:05 INFO CodeGenerator: Code generated in 5.091885 ms
23/01/02 21:59:05 INFO CodeGenerator: Code generated in 38.781577 ms
23/01/02 21:59:05 INFO CodeGenerator: Code generated in 5.71661 ms
23/01/02 21:59:05 INFO CodeGenerator: Code generated in 4.157461 ms
23/01/02 21:59:06 INFO CodeGenerator: Code generated in 5.673103 ms
23/01/02 21:59:06 INFO CodeGenerator: Code generated in 4.029831 ms
23/01/02 21:59:06 INFO CodeGenerator: Code generated in 216.353387 ms
23/01/02 21:59:09 INFO Executor: Finished task 0.0 in stage 1.0 (TID 1). 2676 bytes result sent to driver
23/01/02 21:59:09 INFO TaskSetManager: Starting task 1.0 in stage 1.0 (TID 2) (192.168.5.10, executor driver, partition 1, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:09 INFO Executor: Running task 1.0 in stage 1.0 (TID 2)
23/01/02 21:59:09 INFO TaskSetManager: Finished task 0.0 in stage 1.0 (TID 1) in 3851 ms on 192.168.5.10 (executor driver) (1/5)
23/01/02 21:59:09 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:33554432+33554432
23/01/02 21:59:10 INFO Executor: Finished task 1.0 in stage 1.0 (TID 2). 2676 bytes result sent to driver
23/01/02 21:59:10 INFO TaskSetManager: Starting task 2.0 in stage 1.0 (TID 3) (192.168.5.10, executor driver, partition 2, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:10 INFO TaskSetManager: Finished task 1.0 in stage 1.0 (TID 2) in 959 ms on 192.168.5.10 (executor driver) (2/5)
23/01/02 21:59:10 INFO Executor: Running task 2.0 in stage 1.0 (TID 3)
23/01/02 21:59:10 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:67108864+33554432
23/01/02 21:59:11 INFO Executor: Finished task 2.0 in stage 1.0 (TID 3). 2676 bytes result sent to driver
23/01/02 21:59:11 INFO TaskSetManager: Starting task 3.0 in stage 1.0 (TID 4) (192.168.5.10, executor driver, partition 3, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:11 INFO TaskSetManager: Finished task 2.0 in stage 1.0 (TID 3) in 838 ms on 192.168.5.10 (executor driver) (3/5)
23/01/02 21:59:11 INFO Executor: Running task 3.0 in stage 1.0 (TID 4)
23/01/02 21:59:11 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:100663296+33554432
23/01/02 21:59:11 INFO Executor: Finished task 3.0 in stage 1.0 (TID 4). 2676 bytes result sent to driver
23/01/02 21:59:11 INFO TaskSetManager: Starting task 4.0 in stage 1.0 (TID 5) (192.168.5.10, executor driver, partition 4, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:11 INFO TaskSetManager: Finished task 3.0 in stage 1.0 (TID 4) in 837 ms on 192.168.5.10 (executor driver) (4/5)
23/01/02 21:59:11 INFO Executor: Running task 4.0 in stage 1.0 (TID 5)
23/01/02 21:59:11 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:134217728+29836130
23/01/02 21:59:12 INFO Executor: Finished task 4.0 in stage 1.0 (TID 5). 2676 bytes result sent to driver
23/01/02 21:59:12 INFO TaskSetManager: Finished task 4.0 in stage 1.0 (TID 5) in 752 ms on 192.168.5.10 (executor driver) (5/5)
23/01/02 21:59:12 INFO TaskSchedulerImpl: Removed TaskSet 1.0, whose tasks have all completed, from pool 
23/01/02 21:59:12 INFO DAGScheduler: ShuffleMapStage 1 (show at main.scala:43) finished in 7.259 s
23/01/02 21:59:12 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:12 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:12 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:12 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:12 INFO ShufflePartitionsUtil: For shuffle(0), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:12 INFO CodeGenerator: Code generated in 7.123937 ms
23/01/02 21:59:12 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:12 INFO CodeGenerator: Code generated in 6.391804 ms
23/01/02 21:59:12 INFO SparkContext: Starting job: show at main.scala:43
23/01/02 21:59:12 INFO DAGScheduler: Got job 2 (show at main.scala:43) with 1 output partitions
23/01/02 21:59:12 INFO DAGScheduler: Final stage: ResultStage 3 (show at main.scala:43)
23/01/02 21:59:12 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 2)
23/01/02 21:59:12 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:12 INFO DAGScheduler: Submitting ResultStage 3 (MapPartitionsRDD[14] at show at main.scala:43), which has no missing parents
23/01/02 21:59:12 INFO MemoryStore: Block broadcast_3 stored as values in memory (estimated size 355.4 KiB, free 2.1 GiB)
23/01/02 21:59:12 INFO MemoryStore: Block broadcast_3_piece0 stored as bytes in memory (estimated size 53.2 KiB, free 2.1 GiB)
23/01/02 21:59:12 INFO BlockManagerInfo: Added broadcast_3_piece0 in memory on 192.168.5.10:40211 (size: 53.2 KiB, free: 2.1 GiB)
23/01/02 21:59:12 INFO SparkContext: Created broadcast 3 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:12 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 3 (MapPartitionsRDD[14] at show at main.scala:43) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:12 INFO TaskSchedulerImpl: Adding task set 3.0 with 1 tasks resource profile 0
23/01/02 21:59:12 INFO TaskSetManager: Starting task 0.0 in stage 3.0 (TID 6) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:12 INFO Executor: Running task 0.0 in stage 3.0 (TID 6)
23/01/02 21:59:12 INFO ShuffleBlockFetcherIterator: Getting 5 (8.3 KiB) non-empty blocks including 5 (8.3 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:12 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 4 ms
23/01/02 21:59:12 INFO Executor: Finished task 0.0 in stage 3.0 (TID 6). 7319 bytes result sent to driver
23/01/02 21:59:12 INFO TaskSetManager: Finished task 0.0 in stage 3.0 (TID 6) in 37 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:12 INFO TaskSchedulerImpl: Removed TaskSet 3.0, whose tasks have all completed, from pool 
23/01/02 21:59:12 INFO DAGScheduler: ResultStage 3 (show at main.scala:43) finished in 0.050 s
23/01/02 21:59:12 INFO DAGScheduler: Job 2 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:12 INFO TaskSchedulerImpl: Killing all running tasks in stage 3: Stage finished
23/01/02 21:59:12 INFO DAGScheduler: Job 2 finished: show at main.scala:43, took 0.058145 s
23/01/02 21:59:12 INFO CodeGenerator: Code generated in 3.306351 ms
23/01/02 21:59:12 INFO CodeGenerator: Code generated in 2.62455 ms
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

23/01/02 21:59:12 INFO BlockManagerInfo: Removed broadcast_3_piece0 on 192.168.5.10:40211 in memory (size: 53.2 KiB, free: 2.1 GiB)
23/01/02 21:59:13 INFO CodeGenerator: Code generated in 9.359106 ms
23/01/02 21:59:13 INFO DAGScheduler: Registering RDD 19 (show at main.scala:48) as input to shuffle 1
23/01/02 21:59:13 INFO DAGScheduler: Got map stage job 3 (show at main.scala:48) with 5 output partitions
23/01/02 21:59:13 INFO DAGScheduler: Final stage: ShuffleMapStage 4 (show at main.scala:48)
23/01/02 21:59:13 INFO DAGScheduler: Parents of final stage: List()
23/01/02 21:59:13 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:13 INFO DAGScheduler: Submitting ShuffleMapStage 4 (MapPartitionsRDD[19] at show at main.scala:48), which has no missing parents
23/01/02 21:59:13 INFO MemoryStore: Block broadcast_4 stored as values in memory (estimated size 301.7 KiB, free 2.1 GiB)
23/01/02 21:59:13 INFO MemoryStore: Block broadcast_4_piece0 stored as bytes in memory (estimated size 44.5 KiB, free 2.1 GiB)
23/01/02 21:59:13 INFO BlockManagerInfo: Added broadcast_4_piece0 in memory on 192.168.5.10:40211 (size: 44.5 KiB, free: 2.1 GiB)
23/01/02 21:59:13 INFO SparkContext: Created broadcast 4 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:13 INFO DAGScheduler: Submitting 5 missing tasks from ShuffleMapStage 4 (MapPartitionsRDD[19] at show at main.scala:48) (first 15 tasks are for partitions Vector(0, 1, 2, 3, 4))
23/01/02 21:59:13 INFO TaskSchedulerImpl: Adding task set 4.0 with 5 tasks resource profile 0
23/01/02 21:59:13 INFO TaskSetManager: Starting task 0.0 in stage 4.0 (TID 7) (192.168.5.10, executor driver, partition 0, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:13 INFO Executor: Running task 0.0 in stage 4.0 (TID 7)
23/01/02 21:59:13 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:0+33554432
23/01/02 21:59:13 INFO CodeGenerator: Code generated in 12.170217 ms
23/01/02 21:59:13 INFO CodeGenerator: Code generated in 1.9323 ms
23/01/02 21:59:13 INFO CodeGenerator: Code generated in 1.868604 ms
23/01/02 21:59:13 INFO Executor: Finished task 0.0 in stage 4.0 (TID 7). 2676 bytes result sent to driver
23/01/02 21:59:13 INFO TaskSetManager: Starting task 1.0 in stage 4.0 (TID 8) (192.168.5.10, executor driver, partition 1, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:13 INFO TaskSetManager: Finished task 0.0 in stage 4.0 (TID 7) in 907 ms on 192.168.5.10 (executor driver) (1/5)
23/01/02 21:59:13 INFO Executor: Running task 1.0 in stage 4.0 (TID 8)
23/01/02 21:59:13 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:33554432+33554432
23/01/02 21:59:14 INFO Executor: Finished task 1.0 in stage 4.0 (TID 8). 2676 bytes result sent to driver
23/01/02 21:59:14 INFO TaskSetManager: Starting task 2.0 in stage 4.0 (TID 9) (192.168.5.10, executor driver, partition 2, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:14 INFO Executor: Running task 2.0 in stage 4.0 (TID 9)
23/01/02 21:59:14 INFO TaskSetManager: Finished task 1.0 in stage 4.0 (TID 8) in 901 ms on 192.168.5.10 (executor driver) (2/5)
23/01/02 21:59:14 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:67108864+33554432
23/01/02 21:59:15 INFO Executor: Finished task 2.0 in stage 4.0 (TID 9). 2676 bytes result sent to driver
23/01/02 21:59:15 INFO TaskSetManager: Starting task 3.0 in stage 4.0 (TID 10) (192.168.5.10, executor driver, partition 3, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:15 INFO TaskSetManager: Finished task 2.0 in stage 4.0 (TID 9) in 844 ms on 192.168.5.10 (executor driver) (3/5)
23/01/02 21:59:15 INFO Executor: Running task 3.0 in stage 4.0 (TID 10)
23/01/02 21:59:15 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:100663296+33554432
23/01/02 21:59:16 INFO Executor: Finished task 3.0 in stage 4.0 (TID 10). 2676 bytes result sent to driver
23/01/02 21:59:16 INFO TaskSetManager: Starting task 4.0 in stage 4.0 (TID 11) (192.168.5.10, executor driver, partition 4, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:16 INFO TaskSetManager: Finished task 3.0 in stage 4.0 (TID 10) in 840 ms on 192.168.5.10 (executor driver) (4/5)
23/01/02 21:59:16 INFO Executor: Running task 4.0 in stage 4.0 (TID 11)
23/01/02 21:59:16 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:134217728+29836130
23/01/02 21:59:17 INFO Executor: Finished task 4.0 in stage 4.0 (TID 11). 2676 bytes result sent to driver
23/01/02 21:59:17 INFO TaskSetManager: Finished task 4.0 in stage 4.0 (TID 11) in 949 ms on 192.168.5.10 (executor driver) (5/5)
23/01/02 21:59:17 INFO TaskSchedulerImpl: Removed TaskSet 4.0, whose tasks have all completed, from pool 
23/01/02 21:59:17 INFO DAGScheduler: ShuffleMapStage 4 (show at main.scala:48) finished in 4.451 s
23/01/02 21:59:17 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:17 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:17 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:17 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:17 INFO ShufflePartitionsUtil: For shuffle(1), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:17 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 5.056092 ms
23/01/02 21:59:17 INFO SparkContext: Starting job: show at main.scala:48
23/01/02 21:59:17 INFO DAGScheduler: Got job 4 (show at main.scala:48) with 1 output partitions
23/01/02 21:59:17 INFO DAGScheduler: Final stage: ResultStage 6 (show at main.scala:48)
23/01/02 21:59:17 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 5)
23/01/02 21:59:17 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:17 INFO DAGScheduler: Submitting ResultStage 6 (MapPartitionsRDD[24] at show at main.scala:48), which has no missing parents
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_5 stored as values in memory (estimated size 349.8 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_5_piece0 stored as bytes in memory (estimated size 51.5 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO BlockManagerInfo: Added broadcast_5_piece0 in memory on 192.168.5.10:40211 (size: 51.5 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO SparkContext: Created broadcast 5 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:17 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 6 (MapPartitionsRDD[24] at show at main.scala:48) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:17 INFO TaskSchedulerImpl: Adding task set 6.0 with 1 tasks resource profile 0
23/01/02 21:59:17 INFO TaskSetManager: Starting task 0.0 in stage 6.0 (TID 12) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:17 INFO Executor: Running task 0.0 in stage 6.0 (TID 12)
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Getting 5 (7.6 KiB) non-empty blocks including 5 (7.6 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 2.936686 ms
23/01/02 21:59:17 INFO Executor: Finished task 0.0 in stage 6.0 (TID 12). 4777 bytes result sent to driver
23/01/02 21:59:17 INFO TaskSetManager: Finished task 0.0 in stage 6.0 (TID 12) in 24 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:17 INFO TaskSchedulerImpl: Removed TaskSet 6.0, whose tasks have all completed, from pool 
23/01/02 21:59:17 INFO DAGScheduler: ResultStage 6 (show at main.scala:48) finished in 0.033 s
23/01/02 21:59:17 INFO DAGScheduler: Job 4 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:17 INFO TaskSchedulerImpl: Killing all running tasks in stage 6: Stage finished
23/01/02 21:59:17 INFO DAGScheduler: Job 4 finished: show at main.scala:48, took 0.036028 s
23/01/02 21:59:17 INFO DAGScheduler: Registering RDD 25 (show at main.scala:48) as input to shuffle 2
23/01/02 21:59:17 INFO DAGScheduler: Got map stage job 5 (show at main.scala:48) with 1 output partitions
23/01/02 21:59:17 INFO DAGScheduler: Final stage: ShuffleMapStage 8 (show at main.scala:48)
23/01/02 21:59:17 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 7)
23/01/02 21:59:17 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:17 INFO DAGScheduler: Submitting ShuffleMapStage 8 (MapPartitionsRDD[25] at show at main.scala:48), which has no missing parents
23/01/02 21:59:17 INFO BlockManagerInfo: Removed broadcast_5_piece0 on 192.168.5.10:40211 in memory (size: 51.5 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_6 stored as values in memory (estimated size 350.8 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_6_piece0 stored as bytes in memory (estimated size 51.9 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO BlockManagerInfo: Added broadcast_6_piece0 in memory on 192.168.5.10:40211 (size: 51.9 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO SparkContext: Created broadcast 6 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:17 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 8 (MapPartitionsRDD[25] at show at main.scala:48) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:17 INFO TaskSchedulerImpl: Adding task set 8.0 with 1 tasks resource profile 0
23/01/02 21:59:17 INFO TaskSetManager: Starting task 0.0 in stage 8.0 (TID 13) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:17 INFO Executor: Running task 0.0 in stage 8.0 (TID 13)
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Getting 5 (7.6 KiB) non-empty blocks including 5 (7.6 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:17 INFO Executor: Finished task 0.0 in stage 8.0 (TID 13). 3893 bytes result sent to driver
23/01/02 21:59:17 INFO TaskSetManager: Finished task 0.0 in stage 8.0 (TID 13) in 17 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:17 INFO TaskSchedulerImpl: Removed TaskSet 8.0, whose tasks have all completed, from pool 
23/01/02 21:59:17 INFO DAGScheduler: ShuffleMapStage 8 (show at main.scala:48) finished in 0.028 s
23/01/02 21:59:17 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:17 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:17 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:17 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:17 INFO ShufflePartitionsUtil: For shuffle(2), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 8.261532 ms
23/01/02 21:59:17 INFO DAGScheduler: Registering RDD 28 (show at main.scala:48) as input to shuffle 3
23/01/02 21:59:17 INFO DAGScheduler: Got map stage job 6 (show at main.scala:48) with 1 output partitions
23/01/02 21:59:17 INFO DAGScheduler: Final stage: ShuffleMapStage 11 (show at main.scala:48)
23/01/02 21:59:17 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 10)
23/01/02 21:59:17 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:17 INFO DAGScheduler: Submitting ShuffleMapStage 11 (MapPartitionsRDD[28] at show at main.scala:48), which has no missing parents
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_7 stored as values in memory (estimated size 352.1 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_7_piece0 stored as bytes in memory (estimated size 52.3 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO BlockManagerInfo: Added broadcast_7_piece0 in memory on 192.168.5.10:40211 (size: 52.3 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO SparkContext: Created broadcast 7 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:17 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 11 (MapPartitionsRDD[28] at show at main.scala:48) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:17 INFO TaskSchedulerImpl: Adding task set 11.0 with 1 tasks resource profile 0
23/01/02 21:59:17 INFO TaskSetManager: Starting task 0.0 in stage 11.0 (TID 14) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:17 INFO Executor: Running task 0.0 in stage 11.0 (TID 14)
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Getting 1 (1441.0 B) non-empty blocks including 1 (1441.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 3.964356 ms
23/01/02 21:59:17 INFO Executor: Finished task 0.0 in stage 11.0 (TID 14). 5127 bytes result sent to driver
23/01/02 21:59:17 INFO TaskSetManager: Finished task 0.0 in stage 11.0 (TID 14) in 29 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:17 INFO TaskSchedulerImpl: Removed TaskSet 11.0, whose tasks have all completed, from pool 
23/01/02 21:59:17 INFO DAGScheduler: ShuffleMapStage 11 (show at main.scala:48) finished in 0.039 s
23/01/02 21:59:17 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:17 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:17 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:17 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 6.457127 ms
23/01/02 21:59:17 INFO SparkContext: Starting job: show at main.scala:48
23/01/02 21:59:17 INFO DAGScheduler: Got job 7 (show at main.scala:48) with 1 output partitions
23/01/02 21:59:17 INFO DAGScheduler: Final stage: ResultStage 15 (show at main.scala:48)
23/01/02 21:59:17 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 14)
23/01/02 21:59:17 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:17 INFO DAGScheduler: Submitting ResultStage 15 (MapPartitionsRDD[31] at show at main.scala:48), which has no missing parents
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_8 stored as values in memory (estimated size 15.4 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_8_piece0 stored as bytes in memory (estimated size 6.9 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO BlockManagerInfo: Added broadcast_8_piece0 in memory on 192.168.5.10:40211 (size: 6.9 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO SparkContext: Created broadcast 8 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:17 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 15 (MapPartitionsRDD[31] at show at main.scala:48) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:17 INFO TaskSchedulerImpl: Adding task set 15.0 with 1 tasks resource profile 0
23/01/02 21:59:17 INFO TaskSetManager: Starting task 0.0 in stage 15.0 (TID 15) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:17 INFO Executor: Running task 0.0 in stage 15.0 (TID 15)
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Getting 1 (80.0 B) non-empty blocks including 1 (80.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:17 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:17 INFO Executor: Finished task 0.0 in stage 15.0 (TID 15). 2767 bytes result sent to driver
23/01/02 21:59:17 INFO TaskSetManager: Finished task 0.0 in stage 15.0 (TID 15) in 10 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:17 INFO TaskSchedulerImpl: Removed TaskSet 15.0, whose tasks have all completed, from pool 
23/01/02 21:59:17 INFO DAGScheduler: ResultStage 15 (show at main.scala:48) finished in 0.014 s
23/01/02 21:59:17 INFO DAGScheduler: Job 7 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:17 INFO TaskSchedulerImpl: Killing all running tasks in stage 15: Stage finished
23/01/02 21:59:17 INFO DAGScheduler: Job 7 finished: show at main.scala:48, took 0.016331 s
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 3.221699 ms
+------------------+----------+
|avg(Primary Needs)|avg(Other)|
+------------------+----------+
|11.274999999999999|     10.15|
+------------------+----------+

23/01/02 21:59:17 INFO CodeGenerator: Code generated in 13.193051 ms
23/01/02 21:59:17 INFO DAGScheduler: Registering RDD 36 (show at main.scala:53) as input to shuffle 4
23/01/02 21:59:17 INFO DAGScheduler: Got map stage job 8 (show at main.scala:53) with 5 output partitions
23/01/02 21:59:17 INFO DAGScheduler: Final stage: ShuffleMapStage 16 (show at main.scala:53)
23/01/02 21:59:17 INFO DAGScheduler: Parents of final stage: List()
23/01/02 21:59:17 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:17 INFO DAGScheduler: Submitting ShuffleMapStage 16 (MapPartitionsRDD[36] at show at main.scala:53), which has no missing parents
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_9 stored as values in memory (estimated size 292.7 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO MemoryStore: Block broadcast_9_piece0 stored as bytes in memory (estimated size 41.4 KiB, free 2.1 GiB)
23/01/02 21:59:17 INFO BlockManagerInfo: Added broadcast_9_piece0 in memory on 192.168.5.10:40211 (size: 41.4 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO SparkContext: Created broadcast 9 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:17 INFO DAGScheduler: Submitting 5 missing tasks from ShuffleMapStage 16 (MapPartitionsRDD[36] at show at main.scala:53) (first 15 tasks are for partitions Vector(0, 1, 2, 3, 4))
23/01/02 21:59:17 INFO TaskSchedulerImpl: Adding task set 16.0 with 5 tasks resource profile 0
23/01/02 21:59:17 INFO TaskSetManager: Starting task 0.0 in stage 16.0 (TID 16) (192.168.5.10, executor driver, partition 0, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:17 INFO Executor: Running task 0.0 in stage 16.0 (TID 16)
23/01/02 21:59:17 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:0+33554432
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 7.364891 ms
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 2.485805 ms
23/01/02 21:59:17 INFO CodeGenerator: Code generated in 2.606963 ms
23/01/02 21:59:17 INFO BlockManagerInfo: Removed broadcast_8_piece0 on 192.168.5.10:40211 in memory (size: 6.9 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO BlockManagerInfo: Removed broadcast_7_piece0 on 192.168.5.10:40211 in memory (size: 52.3 KiB, free: 2.1 GiB)
23/01/02 21:59:17 INFO BlockManagerInfo: Removed broadcast_6_piece0 on 192.168.5.10:40211 in memory (size: 51.9 KiB, free: 2.1 GiB)
23/01/02 21:59:19 INFO Executor: Finished task 0.0 in stage 16.0 (TID 16). 2676 bytes result sent to driver
23/01/02 21:59:19 INFO TaskSetManager: Starting task 1.0 in stage 16.0 (TID 17) (192.168.5.10, executor driver, partition 1, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:19 INFO TaskSetManager: Finished task 0.0 in stage 16.0 (TID 16) in 1444 ms on 192.168.5.10 (executor driver) (1/5)
23/01/02 21:59:19 INFO Executor: Running task 1.0 in stage 16.0 (TID 17)
23/01/02 21:59:19 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:33554432+33554432
23/01/02 21:59:20 INFO Executor: Finished task 1.0 in stage 16.0 (TID 17). 2676 bytes result sent to driver
23/01/02 21:59:20 INFO TaskSetManager: Starting task 2.0 in stage 16.0 (TID 18) (192.168.5.10, executor driver, partition 2, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:20 INFO TaskSetManager: Finished task 1.0 in stage 16.0 (TID 17) in 1420 ms on 192.168.5.10 (executor driver) (2/5)
23/01/02 21:59:20 INFO Executor: Running task 2.0 in stage 16.0 (TID 18)
23/01/02 21:59:20 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:67108864+33554432
23/01/02 21:59:22 INFO Executor: Finished task 2.0 in stage 16.0 (TID 18). 2676 bytes result sent to driver
23/01/02 21:59:22 INFO TaskSetManager: Starting task 3.0 in stage 16.0 (TID 19) (192.168.5.10, executor driver, partition 3, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:22 INFO Executor: Running task 3.0 in stage 16.0 (TID 19)
23/01/02 21:59:22 INFO TaskSetManager: Finished task 2.0 in stage 16.0 (TID 18) in 1408 ms on 192.168.5.10 (executor driver) (3/5)
23/01/02 21:59:22 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:100663296+33554432
23/01/02 21:59:23 INFO Executor: Finished task 3.0 in stage 16.0 (TID 19). 2676 bytes result sent to driver
23/01/02 21:59:23 INFO TaskSetManager: Starting task 4.0 in stage 16.0 (TID 20) (192.168.5.10, executor driver, partition 4, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:23 INFO Executor: Running task 4.0 in stage 16.0 (TID 20)
23/01/02 21:59:23 INFO TaskSetManager: Finished task 3.0 in stage 16.0 (TID 19) in 1404 ms on 192.168.5.10 (executor driver) (4/5)
23/01/02 21:59:23 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:134217728+29836130
23/01/02 21:59:24 INFO Executor: Finished task 4.0 in stage 16.0 (TID 20). 2676 bytes result sent to driver
23/01/02 21:59:24 INFO TaskSetManager: Finished task 4.0 in stage 16.0 (TID 20) in 1260 ms on 192.168.5.10 (executor driver) (5/5)
23/01/02 21:59:24 INFO TaskSchedulerImpl: Removed TaskSet 16.0, whose tasks have all completed, from pool 
23/01/02 21:59:24 INFO DAGScheduler: ShuffleMapStage 16 (show at main.scala:53) finished in 6.941 s
23/01/02 21:59:24 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:24 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:24 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:24 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:24 INFO ShufflePartitionsUtil: For shuffle(4), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:24 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:24 INFO CodeGenerator: Code generated in 8.357013 ms
23/01/02 21:59:24 INFO SparkContext: Starting job: show at main.scala:53
23/01/02 21:59:24 INFO DAGScheduler: Got job 9 (show at main.scala:53) with 1 output partitions
23/01/02 21:59:24 INFO DAGScheduler: Final stage: ResultStage 18 (show at main.scala:53)
23/01/02 21:59:24 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 17)
23/01/02 21:59:24 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:24 INFO DAGScheduler: Submitting ResultStage 18 (MapPartitionsRDD[41] at show at main.scala:53), which has no missing parents
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_10 stored as values in memory (estimated size 318.1 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_10_piece0 stored as bytes in memory (estimated size 46.5 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO BlockManagerInfo: Added broadcast_10_piece0 in memory on 192.168.5.10:40211 (size: 46.5 KiB, free: 2.1 GiB)
23/01/02 21:59:24 INFO SparkContext: Created broadcast 10 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:24 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 18 (MapPartitionsRDD[41] at show at main.scala:53) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:24 INFO TaskSchedulerImpl: Adding task set 18.0 with 1 tasks resource profile 0
23/01/02 21:59:24 INFO TaskSetManager: Starting task 0.0 in stage 18.0 (TID 21) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:24 INFO Executor: Running task 0.0 in stage 18.0 (TID 21)
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Getting 5 (7.0 KiB) non-empty blocks including 5 (7.0 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:24 INFO Executor: Finished task 0.0 in stage 18.0 (TID 21). 4777 bytes result sent to driver
23/01/02 21:59:24 INFO TaskSetManager: Finished task 0.0 in stage 18.0 (TID 21) in 13 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:24 INFO TaskSchedulerImpl: Removed TaskSet 18.0, whose tasks have all completed, from pool 
23/01/02 21:59:24 INFO DAGScheduler: ResultStage 18 (show at main.scala:53) finished in 0.018 s
23/01/02 21:59:24 INFO DAGScheduler: Job 9 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:24 INFO TaskSchedulerImpl: Killing all running tasks in stage 18: Stage finished
23/01/02 21:59:24 INFO DAGScheduler: Job 9 finished: show at main.scala:53, took 0.019465 s
23/01/02 21:59:24 INFO DAGScheduler: Registering RDD 42 (show at main.scala:53) as input to shuffle 5
23/01/02 21:59:24 INFO DAGScheduler: Got map stage job 10 (show at main.scala:53) with 1 output partitions
23/01/02 21:59:24 INFO DAGScheduler: Final stage: ShuffleMapStage 20 (show at main.scala:53)
23/01/02 21:59:24 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 19)
23/01/02 21:59:24 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:24 INFO DAGScheduler: Submitting ShuffleMapStage 20 (MapPartitionsRDD[42] at show at main.scala:53), which has no missing parents
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_11 stored as values in memory (estimated size 319.0 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_11_piece0 stored as bytes in memory (estimated size 46.9 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO BlockManagerInfo: Added broadcast_11_piece0 in memory on 192.168.5.10:40211 (size: 46.9 KiB, free: 2.1 GiB)
23/01/02 21:59:24 INFO SparkContext: Created broadcast 11 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:24 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 20 (MapPartitionsRDD[42] at show at main.scala:53) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:24 INFO TaskSchedulerImpl: Adding task set 20.0 with 1 tasks resource profile 0
23/01/02 21:59:24 INFO TaskSetManager: Starting task 0.0 in stage 20.0 (TID 22) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:24 INFO Executor: Running task 0.0 in stage 20.0 (TID 22)
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Getting 5 (7.0 KiB) non-empty blocks including 5 (7.0 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:24 INFO Executor: Finished task 0.0 in stage 20.0 (TID 22). 3893 bytes result sent to driver
23/01/02 21:59:24 INFO TaskSetManager: Finished task 0.0 in stage 20.0 (TID 22) in 15 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:24 INFO TaskSchedulerImpl: Removed TaskSet 20.0, whose tasks have all completed, from pool 
23/01/02 21:59:24 INFO DAGScheduler: ShuffleMapStage 20 (show at main.scala:53) finished in 0.021 s
23/01/02 21:59:24 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:24 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:24 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:24 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:24 INFO ShufflePartitionsUtil: For shuffle(5), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:24 INFO CodeGenerator: Code generated in 7.649145 ms
23/01/02 21:59:24 INFO DAGScheduler: Registering RDD 45 (show at main.scala:53) as input to shuffle 6
23/01/02 21:59:24 INFO DAGScheduler: Got map stage job 11 (show at main.scala:53) with 1 output partitions
23/01/02 21:59:24 INFO DAGScheduler: Final stage: ShuffleMapStage 23 (show at main.scala:53)
23/01/02 21:59:24 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 22)
23/01/02 21:59:24 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:24 INFO DAGScheduler: Submitting ShuffleMapStage 23 (MapPartitionsRDD[45] at show at main.scala:53), which has no missing parents
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_12 stored as values in memory (estimated size 327.6 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_12_piece0 stored as bytes in memory (estimated size 50.1 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO BlockManagerInfo: Added broadcast_12_piece0 in memory on 192.168.5.10:40211 (size: 50.1 KiB, free: 2.1 GiB)
23/01/02 21:59:24 INFO SparkContext: Created broadcast 12 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:24 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 23 (MapPartitionsRDD[45] at show at main.scala:53) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:24 INFO TaskSchedulerImpl: Adding task set 23.0 with 1 tasks resource profile 0
23/01/02 21:59:24 INFO TaskSetManager: Starting task 0.0 in stage 23.0 (TID 23) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:24 INFO Executor: Running task 0.0 in stage 23.0 (TID 23)
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Getting 1 (1360.0 B) non-empty blocks including 1 (1360.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:24 INFO CodeGenerator: Code generated in 4.26709 ms
23/01/02 21:59:24 INFO CodeGenerator: Code generated in 3.016016 ms
23/01/02 21:59:24 INFO Executor: Finished task 0.0 in stage 23.0 (TID 23). 5329 bytes result sent to driver
23/01/02 21:59:24 INFO TaskSetManager: Finished task 0.0 in stage 23.0 (TID 23) in 30 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:24 INFO TaskSchedulerImpl: Removed TaskSet 23.0, whose tasks have all completed, from pool 
23/01/02 21:59:24 INFO DAGScheduler: ShuffleMapStage 23 (show at main.scala:53) finished in 0.037 s
23/01/02 21:59:24 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:24 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:24 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:24 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:24 INFO ShufflePartitionsUtil: For shuffle(6), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:24 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:24 INFO CodeGenerator: Code generated in 4.145809 ms
23/01/02 21:59:24 INFO SparkContext: Starting job: show at main.scala:53
23/01/02 21:59:24 INFO DAGScheduler: Got job 12 (show at main.scala:53) with 1 output partitions
23/01/02 21:59:24 INFO DAGScheduler: Final stage: ResultStage 27 (show at main.scala:53)
23/01/02 21:59:24 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 26)
23/01/02 21:59:24 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:24 INFO DAGScheduler: Submitting ResultStage 27 (MapPartitionsRDD[48] at show at main.scala:53), which has no missing parents
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_13 stored as values in memory (estimated size 325.5 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO MemoryStore: Block broadcast_13_piece0 stored as bytes in memory (estimated size 49.1 KiB, free 2.1 GiB)
23/01/02 21:59:24 INFO BlockManagerInfo: Added broadcast_13_piece0 in memory on 192.168.5.10:40211 (size: 49.1 KiB, free: 2.1 GiB)
23/01/02 21:59:24 INFO SparkContext: Created broadcast 13 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:24 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 27 (MapPartitionsRDD[48] at show at main.scala:53) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:24 INFO TaskSchedulerImpl: Adding task set 27.0 with 1 tasks resource profile 0
23/01/02 21:59:24 INFO TaskSetManager: Starting task 0.0 in stage 27.0 (TID 24) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:24 INFO Executor: Running task 0.0 in stage 27.0 (TID 24)
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Getting 1 (160.0 B) non-empty blocks including 1 (160.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:24 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:24 INFO Executor: Finished task 0.0 in stage 27.0 (TID 24). 6012 bytes result sent to driver
23/01/02 21:59:24 INFO TaskSetManager: Finished task 0.0 in stage 27.0 (TID 24) in 11 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:24 INFO TaskSchedulerImpl: Removed TaskSet 27.0, whose tasks have all completed, from pool 
23/01/02 21:59:24 INFO DAGScheduler: ResultStage 27 (show at main.scala:53) finished in 0.017 s
23/01/02 21:59:24 INFO DAGScheduler: Job 12 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:24 INFO TaskSchedulerImpl: Killing all running tasks in stage 27: Stage finished
23/01/02 21:59:24 INFO DAGScheduler: Job 12 finished: show at main.scala:53, took 0.018554 s
23/01/02 21:59:24 INFO CodeGenerator: Code generated in 2.404262 ms
+------+------------------+
|   Sex|         avg(Work)|
+------+------------------+
|female|2.0833333333333335|
|  male|2.5833333333333335|
+------+------------------+

23/01/02 21:59:24 INFO BlockManagerInfo: Removed broadcast_13_piece0 on 192.168.5.10:40211 in memory (size: 49.1 KiB, free: 2.1 GiB)
23/01/02 21:59:24 INFO BlockManagerInfo: Removed broadcast_12_piece0 on 192.168.5.10:40211 in memory (size: 50.1 KiB, free: 2.1 GiB)
23/01/02 21:59:24 INFO BlockManagerInfo: Removed broadcast_10_piece0 on 192.168.5.10:40211 in memory (size: 46.5 KiB, free: 2.1 GiB)
23/01/02 21:59:24 INFO BlockManagerInfo: Removed broadcast_11_piece0 on 192.168.5.10:40211 in memory (size: 46.9 KiB, free: 2.1 GiB)
23/01/02 21:59:25 INFO DAGScheduler: Registering RDD 53 (show at main.scala:60) as input to shuffle 7
23/01/02 21:59:25 INFO DAGScheduler: Got map stage job 13 (show at main.scala:60) with 5 output partitions
23/01/02 21:59:25 INFO DAGScheduler: Final stage: ShuffleMapStage 28 (show at main.scala:60)
23/01/02 21:59:25 INFO DAGScheduler: Parents of final stage: List()
23/01/02 21:59:25 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:25 INFO DAGScheduler: Submitting ShuffleMapStage 28 (MapPartitionsRDD[53] at show at main.scala:60), which has no missing parents
23/01/02 21:59:25 INFO MemoryStore: Block broadcast_14 stored as values in memory (estimated size 297.8 KiB, free 2.1 GiB)
23/01/02 21:59:25 INFO MemoryStore: Block broadcast_14_piece0 stored as bytes in memory (estimated size 43.2 KiB, free 2.1 GiB)
23/01/02 21:59:25 INFO BlockManagerInfo: Added broadcast_14_piece0 in memory on 192.168.5.10:40211 (size: 43.2 KiB, free: 2.1 GiB)
23/01/02 21:59:25 INFO SparkContext: Created broadcast 14 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:25 INFO DAGScheduler: Submitting 5 missing tasks from ShuffleMapStage 28 (MapPartitionsRDD[53] at show at main.scala:60) (first 15 tasks are for partitions Vector(0, 1, 2, 3, 4))
23/01/02 21:59:25 INFO TaskSchedulerImpl: Adding task set 28.0 with 5 tasks resource profile 0
23/01/02 21:59:25 INFO TaskSetManager: Starting task 0.0 in stage 28.0 (TID 25) (192.168.5.10, executor driver, partition 0, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:25 INFO Executor: Running task 0.0 in stage 28.0 (TID 25)
23/01/02 21:59:25 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:0+33554432
23/01/02 21:59:25 INFO CodeGenerator: Code generated in 5.387594 ms
23/01/02 21:59:25 INFO CodeGenerator: Code generated in 22.97393 ms
23/01/02 21:59:25 INFO BlockManagerInfo: Removed broadcast_2_piece0 on 192.168.5.10:40211 in memory (size: 45.5 KiB, free: 2.1 GiB)
23/01/02 21:59:25 INFO BlockManagerInfo: Removed broadcast_4_piece0 on 192.168.5.10:40211 in memory (size: 44.5 KiB, free: 2.1 GiB)
23/01/02 21:59:25 INFO BlockManagerInfo: Removed broadcast_9_piece0 on 192.168.5.10:40211 in memory (size: 41.4 KiB, free: 2.1 GiB)
23/01/02 21:59:26 INFO Executor: Finished task 0.0 in stage 28.0 (TID 25). 2676 bytes result sent to driver
23/01/02 21:59:26 INFO TaskSetManager: Starting task 1.0 in stage 28.0 (TID 26) (192.168.5.10, executor driver, partition 1, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:26 INFO TaskSetManager: Finished task 0.0 in stage 28.0 (TID 25) in 1623 ms on 192.168.5.10 (executor driver) (1/5)
23/01/02 21:59:26 INFO Executor: Running task 1.0 in stage 28.0 (TID 26)
23/01/02 21:59:26 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:33554432+33554432
23/01/02 21:59:27 INFO Executor: Finished task 1.0 in stage 28.0 (TID 26). 2676 bytes result sent to driver
23/01/02 21:59:27 INFO TaskSetManager: Starting task 2.0 in stage 28.0 (TID 27) (192.168.5.10, executor driver, partition 2, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:27 INFO TaskSetManager: Finished task 1.0 in stage 28.0 (TID 26) in 1034 ms on 192.168.5.10 (executor driver) (2/5)
23/01/02 21:59:27 INFO Executor: Running task 2.0 in stage 28.0 (TID 27)
23/01/02 21:59:27 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:67108864+33554432
23/01/02 21:59:28 INFO Executor: Finished task 2.0 in stage 28.0 (TID 27). 2676 bytes result sent to driver
23/01/02 21:59:28 INFO TaskSetManager: Starting task 3.0 in stage 28.0 (TID 28) (192.168.5.10, executor driver, partition 3, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:28 INFO TaskSetManager: Finished task 2.0 in stage 28.0 (TID 27) in 829 ms on 192.168.5.10 (executor driver) (3/5)
23/01/02 21:59:28 INFO Executor: Running task 3.0 in stage 28.0 (TID 28)
23/01/02 21:59:28 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:100663296+33554432
23/01/02 21:59:29 INFO Executor: Finished task 3.0 in stage 28.0 (TID 28). 2676 bytes result sent to driver
23/01/02 21:59:29 INFO TaskSetManager: Starting task 4.0 in stage 28.0 (TID 29) (192.168.5.10, executor driver, partition 4, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:29 INFO TaskSetManager: Finished task 3.0 in stage 28.0 (TID 28) in 832 ms on 192.168.5.10 (executor driver) (4/5)
23/01/02 21:59:29 INFO Executor: Running task 4.0 in stage 28.0 (TID 29)
23/01/02 21:59:29 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:134217728+29836130
23/01/02 21:59:30 INFO Executor: Finished task 4.0 in stage 28.0 (TID 29). 2676 bytes result sent to driver
23/01/02 21:59:30 INFO TaskSetManager: Finished task 4.0 in stage 28.0 (TID 29) in 756 ms on 192.168.5.10 (executor driver) (5/5)
23/01/02 21:59:30 INFO TaskSchedulerImpl: Removed TaskSet 28.0, whose tasks have all completed, from pool 
23/01/02 21:59:30 INFO DAGScheduler: ShuffleMapStage 28 (show at main.scala:60) finished in 5.079 s
23/01/02 21:59:30 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:30 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:30 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:30 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:30 INFO ShufflePartitionsUtil: For shuffle(7), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:30 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:30 INFO SparkContext: Starting job: show at main.scala:60
23/01/02 21:59:30 INFO DAGScheduler: Got job 14 (show at main.scala:60) with 1 output partitions
23/01/02 21:59:30 INFO DAGScheduler: Final stage: ResultStage 30 (show at main.scala:60)
23/01/02 21:59:30 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 29)
23/01/02 21:59:30 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:30 INFO DAGScheduler: Submitting ResultStage 30 (MapPartitionsRDD[58] at show at main.scala:60), which has no missing parents
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_15 stored as values in memory (estimated size 342.1 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_15_piece0 stored as bytes in memory (estimated size 49.7 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO BlockManagerInfo: Added broadcast_15_piece0 in memory on 192.168.5.10:40211 (size: 49.7 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO SparkContext: Created broadcast 15 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:30 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 30 (MapPartitionsRDD[58] at show at main.scala:60) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:30 INFO TaskSchedulerImpl: Adding task set 30.0 with 1 tasks resource profile 0
23/01/02 21:59:30 INFO TaskSetManager: Starting task 0.0 in stage 30.0 (TID 30) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:30 INFO Executor: Running task 0.0 in stage 30.0 (TID 30)
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Getting 5 (4.7 KiB) non-empty blocks including 5 (4.7 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:30 INFO Executor: Finished task 0.0 in stage 30.0 (TID 30). 4466 bytes result sent to driver
23/01/02 21:59:30 INFO TaskSetManager: Finished task 0.0 in stage 30.0 (TID 30) in 7 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:30 INFO TaskSchedulerImpl: Removed TaskSet 30.0, whose tasks have all completed, from pool 
23/01/02 21:59:30 INFO DAGScheduler: ResultStage 30 (show at main.scala:60) finished in 0.014 s
23/01/02 21:59:30 INFO DAGScheduler: Job 14 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:30 INFO TaskSchedulerImpl: Killing all running tasks in stage 30: Stage finished
23/01/02 21:59:30 INFO DAGScheduler: Job 14 finished: show at main.scala:60, took 0.016244 s
23/01/02 21:59:30 INFO DAGScheduler: Registering RDD 59 (show at main.scala:60) as input to shuffle 8
23/01/02 21:59:30 INFO DAGScheduler: Got map stage job 15 (show at main.scala:60) with 1 output partitions
23/01/02 21:59:30 INFO DAGScheduler: Final stage: ShuffleMapStage 32 (show at main.scala:60)
23/01/02 21:59:30 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 31)
23/01/02 21:59:30 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:30 INFO DAGScheduler: Submitting ShuffleMapStage 32 (MapPartitionsRDD[59] at show at main.scala:60), which has no missing parents
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_16 stored as values in memory (estimated size 342.7 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_16_piece0 stored as bytes in memory (estimated size 50.1 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO BlockManagerInfo: Added broadcast_16_piece0 in memory on 192.168.5.10:40211 (size: 50.1 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO SparkContext: Created broadcast 16 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:30 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 32 (MapPartitionsRDD[59] at show at main.scala:60) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:30 INFO TaskSchedulerImpl: Adding task set 32.0 with 1 tasks resource profile 0
23/01/02 21:59:30 INFO TaskSetManager: Starting task 0.0 in stage 32.0 (TID 31) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:30 INFO Executor: Running task 0.0 in stage 32.0 (TID 31)
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Getting 5 (4.7 KiB) non-empty blocks including 5 (4.7 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:30 INFO Executor: Finished task 0.0 in stage 32.0 (TID 31). 3889 bytes result sent to driver
23/01/02 21:59:30 INFO TaskSetManager: Finished task 0.0 in stage 32.0 (TID 31) in 8 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:30 INFO TaskSchedulerImpl: Removed TaskSet 32.0, whose tasks have all completed, from pool 
23/01/02 21:59:30 INFO DAGScheduler: ShuffleMapStage 32 (show at main.scala:60) finished in 0.016 s
23/01/02 21:59:30 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:30 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:30 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:30 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:30 INFO ShufflePartitionsUtil: For shuffle(8), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:30 INFO CodeGenerator: Code generated in 8.787892 ms
23/01/02 21:59:30 INFO BlockManagerInfo: Removed broadcast_15_piece0 on 192.168.5.10:40211 in memory (size: 49.7 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO BlockManagerInfo: Removed broadcast_16_piece0 on 192.168.5.10:40211 in memory (size: 50.1 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO DAGScheduler: Registering RDD 62 (show at main.scala:60) as input to shuffle 9
23/01/02 21:59:30 INFO DAGScheduler: Got map stage job 16 (show at main.scala:60) with 1 output partitions
23/01/02 21:59:30 INFO DAGScheduler: Final stage: ShuffleMapStage 35 (show at main.scala:60)
23/01/02 21:59:30 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 34)
23/01/02 21:59:30 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:30 INFO DAGScheduler: Submitting ShuffleMapStage 35 (MapPartitionsRDD[62] at show at main.scala:60), which has no missing parents
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_17 stored as values in memory (estimated size 351.5 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_17_piece0 stored as bytes in memory (estimated size 53.3 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO BlockManagerInfo: Added broadcast_17_piece0 in memory on 192.168.5.10:40211 (size: 53.3 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO SparkContext: Created broadcast 17 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:30 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 35 (MapPartitionsRDD[62] at show at main.scala:60) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:30 INFO TaskSchedulerImpl: Adding task set 35.0 with 1 tasks resource profile 0
23/01/02 21:59:30 INFO TaskSetManager: Starting task 0.0 in stage 35.0 (TID 32) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:30 INFO Executor: Running task 0.0 in stage 35.0 (TID 32)
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Getting 1 (903.0 B) non-empty blocks including 1 (903.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:30 INFO Executor: Finished task 0.0 in stage 35.0 (TID 32). 5372 bytes result sent to driver
23/01/02 21:59:30 INFO TaskSetManager: Finished task 0.0 in stage 35.0 (TID 32) in 19 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:30 INFO TaskSchedulerImpl: Removed TaskSet 35.0, whose tasks have all completed, from pool 
23/01/02 21:59:30 INFO DAGScheduler: ShuffleMapStage 35 (show at main.scala:60) finished in 0.027 s
23/01/02 21:59:30 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:30 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:30 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:30 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:30 INFO ShufflePartitionsUtil: For shuffle(9), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:30 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:30 INFO BlockManagerInfo: Removed broadcast_14_piece0 on 192.168.5.10:40211 in memory (size: 43.2 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO SparkContext: Starting job: show at main.scala:60
23/01/02 21:59:30 INFO DAGScheduler: Got job 17 (show at main.scala:60) with 1 output partitions
23/01/02 21:59:30 INFO DAGScheduler: Final stage: ResultStage 39 (show at main.scala:60)
23/01/02 21:59:30 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 38)
23/01/02 21:59:30 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:30 INFO DAGScheduler: Submitting ResultStage 39 (MapPartitionsRDD[65] at show at main.scala:60), which has no missing parents
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_18 stored as values in memory (estimated size 349.4 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO BlockManagerInfo: Removed broadcast_17_piece0 on 192.168.5.10:40211 in memory (size: 53.3 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_18_piece0 stored as bytes in memory (estimated size 51.9 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO BlockManagerInfo: Added broadcast_18_piece0 in memory on 192.168.5.10:40211 (size: 51.9 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO SparkContext: Created broadcast 18 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:30 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 39 (MapPartitionsRDD[65] at show at main.scala:60) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:30 INFO TaskSchedulerImpl: Adding task set 39.0 with 1 tasks resource profile 0
23/01/02 21:59:30 INFO TaskSetManager: Starting task 0.0 in stage 39.0 (TID 33) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:30 INFO Executor: Running task 0.0 in stage 39.0 (TID 33)
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Getting 1 (160.0 B) non-empty blocks including 1 (160.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:30 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:30 INFO Executor: Finished task 0.0 in stage 39.0 (TID 33). 6015 bytes result sent to driver
23/01/02 21:59:30 INFO TaskSetManager: Finished task 0.0 in stage 39.0 (TID 33) in 6 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:30 INFO TaskSchedulerImpl: Removed TaskSet 39.0, whose tasks have all completed, from pool 
23/01/02 21:59:30 INFO DAGScheduler: ResultStage 39 (show at main.scala:60) finished in 0.019 s
23/01/02 21:59:30 INFO DAGScheduler: Job 17 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:30 INFO TaskSchedulerImpl: Killing all running tasks in stage 39: Stage finished
23/01/02 21:59:30 INFO DAGScheduler: Job 17 finished: show at main.scala:60, took 0.020811 s
+------+----------+
|   Age|avg(Other)|
+------+----------+
|active|     9.525|
| elder|     10.65|
+------+----------+

23/01/02 21:59:30 INFO BlockManagerInfo: Removed broadcast_18_piece0 on 192.168.5.10:40211 in memory (size: 51.9 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO DAGScheduler: Registering RDD 70 (show at main.scala:65) as input to shuffle 10
23/01/02 21:59:30 INFO DAGScheduler: Got map stage job 18 (show at main.scala:65) with 5 output partitions
23/01/02 21:59:30 INFO DAGScheduler: Final stage: ShuffleMapStage 40 (show at main.scala:65)
23/01/02 21:59:30 INFO DAGScheduler: Parents of final stage: List()
23/01/02 21:59:30 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:30 INFO DAGScheduler: Submitting ShuffleMapStage 40 (MapPartitionsRDD[70] at show at main.scala:65), which has no missing parents
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_19 stored as values in memory (estimated size 297.1 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO MemoryStore: Block broadcast_19_piece0 stored as bytes in memory (estimated size 42.9 KiB, free 2.1 GiB)
23/01/02 21:59:30 INFO BlockManagerInfo: Added broadcast_19_piece0 in memory on 192.168.5.10:40211 (size: 42.9 KiB, free: 2.1 GiB)
23/01/02 21:59:30 INFO SparkContext: Created broadcast 19 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:30 INFO DAGScheduler: Submitting 5 missing tasks from ShuffleMapStage 40 (MapPartitionsRDD[70] at show at main.scala:65) (first 15 tasks are for partitions Vector(0, 1, 2, 3, 4))
23/01/02 21:59:30 INFO TaskSchedulerImpl: Adding task set 40.0 with 5 tasks resource profile 0
23/01/02 21:59:30 INFO TaskSetManager: Starting task 0.0 in stage 40.0 (TID 34) (192.168.5.10, executor driver, partition 0, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:30 INFO Executor: Running task 0.0 in stage 40.0 (TID 34)
23/01/02 21:59:30 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:0+33554432
23/01/02 21:59:32 INFO Executor: Finished task 0.0 in stage 40.0 (TID 34). 2676 bytes result sent to driver
23/01/02 21:59:32 INFO TaskSetManager: Starting task 1.0 in stage 40.0 (TID 35) (192.168.5.10, executor driver, partition 1, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:32 INFO TaskSetManager: Finished task 0.0 in stage 40.0 (TID 34) in 1559 ms on 192.168.5.10 (executor driver) (1/5)
23/01/02 21:59:32 INFO Executor: Running task 1.0 in stage 40.0 (TID 35)
23/01/02 21:59:32 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:33554432+33554432
23/01/02 21:59:33 INFO Executor: Finished task 1.0 in stage 40.0 (TID 35). 2676 bytes result sent to driver
23/01/02 21:59:33 INFO TaskSetManager: Starting task 2.0 in stage 40.0 (TID 36) (192.168.5.10, executor driver, partition 2, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:33 INFO TaskSetManager: Finished task 1.0 in stage 40.0 (TID 35) in 1512 ms on 192.168.5.10 (executor driver) (2/5)
23/01/02 21:59:33 INFO Executor: Running task 2.0 in stage 40.0 (TID 36)
23/01/02 21:59:33 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:67108864+33554432
23/01/02 21:59:35 INFO Executor: Finished task 2.0 in stage 40.0 (TID 36). 2676 bytes result sent to driver
23/01/02 21:59:35 INFO TaskSetManager: Starting task 3.0 in stage 40.0 (TID 37) (192.168.5.10, executor driver, partition 3, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:35 INFO TaskSetManager: Finished task 2.0 in stage 40.0 (TID 36) in 1509 ms on 192.168.5.10 (executor driver) (3/5)
23/01/02 21:59:35 INFO Executor: Running task 3.0 in stage 40.0 (TID 37)
23/01/02 21:59:35 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:100663296+33554432
23/01/02 21:59:36 INFO Executor: Finished task 3.0 in stage 40.0 (TID 37). 2676 bytes result sent to driver
23/01/02 21:59:36 INFO TaskSetManager: Starting task 4.0 in stage 40.0 (TID 38) (192.168.5.10, executor driver, partition 4, PROCESS_LOCAL, 7527 bytes) taskResourceAssignments Map()
23/01/02 21:59:36 INFO TaskSetManager: Finished task 3.0 in stage 40.0 (TID 37) in 1508 ms on 192.168.5.10 (executor driver) (4/5)
23/01/02 21:59:36 INFO Executor: Running task 4.0 in stage 40.0 (TID 38)
23/01/02 21:59:36 INFO HadoopRDD: Input split: file:/home/onder/Repos/BLM5127_Big_Data_Analytics/03-Project/ATUSProcessing/target/scala-2.13/classes/timeusage/atussum.csv:134217728+29836130
23/01/02 21:59:38 INFO Executor: Finished task 4.0 in stage 40.0 (TID 38). 2676 bytes result sent to driver
23/01/02 21:59:38 INFO TaskSetManager: Finished task 4.0 in stage 40.0 (TID 38) in 1363 ms on 192.168.5.10 (executor driver) (5/5)
23/01/02 21:59:38 INFO TaskSchedulerImpl: Removed TaskSet 40.0, whose tasks have all completed, from pool 
23/01/02 21:59:38 INFO DAGScheduler: ShuffleMapStage 40 (show at main.scala:65) finished in 7.455 s
23/01/02 21:59:38 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:38 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:38 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:38 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:38 INFO ShufflePartitionsUtil: For shuffle(10), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:38 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:38 INFO SparkContext: Starting job: show at main.scala:65
23/01/02 21:59:38 INFO DAGScheduler: Got job 19 (show at main.scala:65) with 1 output partitions
23/01/02 21:59:38 INFO DAGScheduler: Final stage: ResultStage 42 (show at main.scala:65)
23/01/02 21:59:38 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 41)
23/01/02 21:59:38 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:38 INFO DAGScheduler: Submitting ResultStage 42 (MapPartitionsRDD[75] at show at main.scala:65), which has no missing parents
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_20 stored as values in memory (estimated size 340.5 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_20_piece0 stored as bytes in memory (estimated size 49.4 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO BlockManagerInfo: Added broadcast_20_piece0 in memory on 192.168.5.10:40211 (size: 49.4 KiB, free: 2.1 GiB)
23/01/02 21:59:38 INFO SparkContext: Created broadcast 20 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:38 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 42 (MapPartitionsRDD[75] at show at main.scala:65) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:38 INFO TaskSchedulerImpl: Adding task set 42.0 with 1 tasks resource profile 0
23/01/02 21:59:38 INFO TaskSetManager: Starting task 0.0 in stage 42.0 (TID 39) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:38 INFO Executor: Running task 0.0 in stage 42.0 (TID 39)
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Getting 5 (7.1 KiB) non-empty blocks including 5 (7.1 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:38 INFO Executor: Finished task 0.0 in stage 42.0 (TID 39). 4777 bytes result sent to driver
23/01/02 21:59:38 INFO TaskSetManager: Finished task 0.0 in stage 42.0 (TID 39) in 11 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:38 INFO TaskSchedulerImpl: Removed TaskSet 42.0, whose tasks have all completed, from pool 
23/01/02 21:59:38 INFO DAGScheduler: ResultStage 42 (show at main.scala:65) finished in 0.018 s
23/01/02 21:59:38 INFO DAGScheduler: Job 19 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:38 INFO TaskSchedulerImpl: Killing all running tasks in stage 42: Stage finished
23/01/02 21:59:38 INFO DAGScheduler: Job 19 finished: show at main.scala:65, took 0.020162 s
23/01/02 21:59:38 INFO DAGScheduler: Registering RDD 76 (show at main.scala:65) as input to shuffle 11
23/01/02 21:59:38 INFO DAGScheduler: Got map stage job 20 (show at main.scala:65) with 1 output partitions
23/01/02 21:59:38 INFO DAGScheduler: Final stage: ShuffleMapStage 44 (show at main.scala:65)
23/01/02 21:59:38 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 43)
23/01/02 21:59:38 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:38 INFO DAGScheduler: Submitting ShuffleMapStage 44 (MapPartitionsRDD[76] at show at main.scala:65), which has no missing parents
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_21 stored as values in memory (estimated size 341.4 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_21_piece0 stored as bytes in memory (estimated size 49.8 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO BlockManagerInfo: Added broadcast_21_piece0 in memory on 192.168.5.10:40211 (size: 49.8 KiB, free: 2.1 GiB)
23/01/02 21:59:38 INFO SparkContext: Created broadcast 21 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:38 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 44 (MapPartitionsRDD[76] at show at main.scala:65) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:38 INFO TaskSchedulerImpl: Adding task set 44.0 with 1 tasks resource profile 0
23/01/02 21:59:38 INFO TaskSetManager: Starting task 0.0 in stage 44.0 (TID 40) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:38 INFO Executor: Running task 0.0 in stage 44.0 (TID 40)
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Getting 5 (7.1 KiB) non-empty blocks including 5 (7.1 KiB) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:38 INFO Executor: Finished task 0.0 in stage 44.0 (TID 40). 3893 bytes result sent to driver
23/01/02 21:59:38 INFO TaskSetManager: Finished task 0.0 in stage 44.0 (TID 40) in 7 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:38 INFO TaskSchedulerImpl: Removed TaskSet 44.0, whose tasks have all completed, from pool 
23/01/02 21:59:38 INFO DAGScheduler: ShuffleMapStage 44 (show at main.scala:65) finished in 0.015 s
23/01/02 21:59:38 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:38 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:38 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:38 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:38 INFO ShufflePartitionsUtil: For shuffle(11), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:38 INFO CodeGenerator: Code generated in 6.869493 ms
23/01/02 21:59:38 INFO DAGScheduler: Registering RDD 79 (show at main.scala:65) as input to shuffle 12
23/01/02 21:59:38 INFO DAGScheduler: Got map stage job 21 (show at main.scala:65) with 1 output partitions
23/01/02 21:59:38 INFO DAGScheduler: Final stage: ShuffleMapStage 47 (show at main.scala:65)
23/01/02 21:59:38 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 46)
23/01/02 21:59:38 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:38 INFO DAGScheduler: Submitting ShuffleMapStage 47 (MapPartitionsRDD[79] at show at main.scala:65), which has no missing parents
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_22 stored as values in memory (estimated size 350.0 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_22_piece0 stored as bytes in memory (estimated size 52.9 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO BlockManagerInfo: Added broadcast_22_piece0 in memory on 192.168.5.10:40211 (size: 52.9 KiB, free: 2.1 GiB)
23/01/02 21:59:38 INFO SparkContext: Created broadcast 22 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:38 INFO DAGScheduler: Submitting 1 missing tasks from ShuffleMapStage 47 (MapPartitionsRDD[79] at show at main.scala:65) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:38 INFO TaskSchedulerImpl: Adding task set 47.0 with 1 tasks resource profile 0
23/01/02 21:59:38 INFO TaskSetManager: Starting task 0.0 in stage 47.0 (TID 41) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7388 bytes) taskResourceAssignments Map()
23/01/02 21:59:38 INFO Executor: Running task 0.0 in stage 47.0 (TID 41)
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Getting 1 (1360.0 B) non-empty blocks including 1 (1360.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:38 INFO Executor: Finished task 0.0 in stage 47.0 (TID 41). 5329 bytes result sent to driver
23/01/02 21:59:38 INFO TaskSetManager: Finished task 0.0 in stage 47.0 (TID 41) in 13 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:38 INFO TaskSchedulerImpl: Removed TaskSet 47.0, whose tasks have all completed, from pool 
23/01/02 21:59:38 INFO DAGScheduler: ShuffleMapStage 47 (show at main.scala:65) finished in 0.020 s
23/01/02 21:59:38 INFO DAGScheduler: looking for newly runnable stages
23/01/02 21:59:38 INFO DAGScheduler: running: HashSet()
23/01/02 21:59:38 INFO DAGScheduler: waiting: HashSet()
23/01/02 21:59:38 INFO DAGScheduler: failed: HashSet()
23/01/02 21:59:38 INFO ShufflePartitionsUtil: For shuffle(12), advisory target size: 67108864, actual target size 1048576, minimum partition size: 1048576
23/01/02 21:59:38 INFO HashAggregateExec: spark.sql.codegen.aggregate.map.twolevel.enabled is set to true, but current version of codegened fast hashmap does not support this aggregate.
23/01/02 21:59:38 INFO SparkContext: Starting job: show at main.scala:65
23/01/02 21:59:38 INFO DAGScheduler: Got job 22 (show at main.scala:65) with 1 output partitions
23/01/02 21:59:38 INFO DAGScheduler: Final stage: ResultStage 51 (show at main.scala:65)
23/01/02 21:59:38 INFO DAGScheduler: Parents of final stage: List(ShuffleMapStage 50)
23/01/02 21:59:38 INFO DAGScheduler: Missing parents: List()
23/01/02 21:59:38 INFO DAGScheduler: Submitting ResultStage 51 (MapPartitionsRDD[82] at show at main.scala:65), which has no missing parents
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_23 stored as values in memory (estimated size 347.9 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO MemoryStore: Block broadcast_23_piece0 stored as bytes in memory (estimated size 51.6 KiB, free 2.1 GiB)
23/01/02 21:59:38 INFO BlockManagerInfo: Added broadcast_23_piece0 in memory on 192.168.5.10:40211 (size: 51.6 KiB, free: 2.1 GiB)
23/01/02 21:59:38 INFO SparkContext: Created broadcast 23 from broadcast at DAGScheduler.scala:1427
23/01/02 21:59:38 INFO DAGScheduler: Submitting 1 missing tasks from ResultStage 51 (MapPartitionsRDD[82] at show at main.scala:65) (first 15 tasks are for partitions Vector(0))
23/01/02 21:59:38 INFO TaskSchedulerImpl: Adding task set 51.0 with 1 tasks resource profile 0
23/01/02 21:59:38 INFO TaskSetManager: Starting task 0.0 in stage 51.0 (TID 42) (192.168.5.10, executor driver, partition 0, NODE_LOCAL, 7399 bytes) taskResourceAssignments Map()
23/01/02 21:59:38 INFO Executor: Running task 0.0 in stage 51.0 (TID 42)
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Getting 1 (177.0 B) non-empty blocks including 1 (177.0 B) local and 0 (0.0 B) host-local and 0 (0.0 B) push-merged-local and 0 (0.0 B) remote blocks
23/01/02 21:59:38 INFO ShuffleBlockFetcherIterator: Started 0 remote fetches in 0 ms
23/01/02 21:59:38 INFO Executor: Finished task 0.0 in stage 51.0 (TID 42). 6032 bytes result sent to driver
23/01/02 21:59:38 INFO TaskSetManager: Finished task 0.0 in stage 51.0 (TID 42) in 5 ms on 192.168.5.10 (executor driver) (1/1)
23/01/02 21:59:38 INFO TaskSchedulerImpl: Removed TaskSet 51.0, whose tasks have all completed, from pool 
23/01/02 21:59:38 INFO DAGScheduler: ResultStage 51 (show at main.scala:65) finished in 0.013 s
23/01/02 21:59:38 INFO DAGScheduler: Job 22 is finished. Cancelling potential speculative or zombie tasks for this job
23/01/02 21:59:38 INFO TaskSchedulerImpl: Killing all running tasks in stage 51: Stage finished
23/01/02 21:59:38 INFO DAGScheduler: Job 22 finished: show at main.scala:65, took 0.014645 s
23/01/02 21:59:38 INFO SparkContext: Invoking stop() from shutdown hook
23/01/02 21:59:38 INFO SparkUI: Stopped Spark web UI at http://192.168.5.10:4040
23/01/02 21:59:38 INFO MapOutputTrackerMasterEndpoint: MapOutputTrackerMasterEndpoint stopped!
+-----------+-----------------+
|    Working|       avg(Other)|
+-----------+-----------------+
|    working|8.649999999999999|
|not working|            11.65|
+-----------+-----------------+

23/01/02 21:59:38 INFO MemoryStore: MemoryStore cleared
23/01/02 21:59:38 INFO BlockManager: BlockManager stopped
23/01/02 21:59:38 INFO BlockManagerMaster: BlockManagerMaster stopped
23/01/02 21:59:38 INFO OutputCommitCoordinator$OutputCommitCoordinatorEndpoint: OutputCommitCoordinator stopped!
23/01/02 21:59:38 INFO SparkContext: Successfully stopped SparkContext
23/01/02 21:59:38 INFO ShutdownHookManager: Shutdown hook called
23/01/02 21:59:38 INFO ShutdownHookManager: Deleting directory /tmp/spark-3768c34a-94b7-4d1d-828f-46dce100dd94

Process finished with exit code 0

```
