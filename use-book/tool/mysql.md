
# 索引和schema优化

# 锁
```
共享锁(shared lock)和排他锁(exclusive lock), 也叫读锁(read lock)和(write lock)
```
   - 写锁
   ```
   1. 会拒绝其他用户写入和读取正在写入的同一次源
   问题：若是用户在读取的时候，还能不能加和写锁？
   ```

   - 表锁(table lock)最基本的锁策略，开销最小
   ```
   写锁比读锁优先级高，写锁请求可能被插入到读锁队列的前面
   ```
   ```
   数据库一般在表上施加行级锁(row-level lock)
   ```
# ACID
```
ACID 原子性(atomicity) 一致性(consistency) 
隔离性(isolation) 持久性(durability)
```

- 读未提交 - 一个事务还没提交时，它做的变更就能被别的事务看到
- 读提交 - 一个事务提交之后，它做的变更才会被其他事务看到，Oracle默认隔离级别
- 可重复读 - 一个事务执行过程中看到的数据，总是跟这个事务在启动时看到的数据是一致的。当然在可重复读隔离级别下，未提交变更对其他事务也是不可见的，mysql默认隔离级别
- 可串行化 - 一个事务执行读写操作时，会锁定检索的数据行范围（范围锁），这种锁会阻止其他事务在本范围内的一切操作，并发性能低，容易死锁

# 死锁
```
两个及以上事务在同一资源相互占用，并请求锁定对方占用的资源，导致恶性循环
```
```
one:
START TRANSACTION;
update stock set close=10 where stock_id=4;
update stock set close=20 where stock_id=3;
commit;

two:
START TRANSACTION:
update stock set close=30 where stock_id=3;
update stock set close=40 where stock_id=4;
commit;
```
```
InnoDB处理死锁：将持有最少行级排他锁的事务进行回滚
```

# 事务日志
```
事务修改先修改存储引擎的内存拷贝再记录到硬盘上的事务日志中。事务日志持久后，在后台刷到磁盘中。
```
```
多版本并发控制（MVCC）， 只在 reperatable read 和 read committed 两个隔离级别下工作
read uncommitted总是读取最新的数据。SERIALIZABLE则会对所有读取的行都加锁
```
```
set transaction isolation level

execute Error: Lost connection to MySQL server during query
set global max_allowed_packet = 2*1024*1024*10
```
# sysbench - mysql基准测试工具
   - CHAR 类型是定长的
   ```
   存储CHAR值,MYSQL会删除所有的末尾空格
   定长的CHAR类型不容易产生碎片
   ```
   - VARCHAR
   ```
   使用VARCHAR(5) 和 VARCHAR(200) 存储'hello'的空间开销是一样的
   但MYSQL会分配固定大小的内存块保存值
   ```
   - BLOB和TEXT类型
   ```
   分别采用二进制和字符方式存储
   ```


# 性能剖析
```
1. 测量任务花费的时间
2. 对结果进行统计和排序，将重要的任务排到前面
```
   - 性能瓶颈因素
   ```
   1. 外部资源，如调用web服务或搜索引擎
   2. 应用处理大量的数量，如分析超大的XML文件
   3. 在循环中执行昂贵的操作，如滥用正则表达式
   4. 低效的算法，如使用暴力搜索算法查找列表中的项
   ```

# schema与数据类型优化
```
beginning database design书
```
   - 尽量避免NULL
   ```
   
   可为NULL的列使得索引，索引统计和值比较都更复杂
   可为NULL的列被索引时，每个索引记录需要一个额外的字节
   可为NULL的列改为NOT NULL，带来的性能提升比较小
   ```

# 性能优化
   ## 性能优化简介
   ```
   例如：‘每秒查询次数’ ‘CPU利用率’ ‘可扩展性’
   ```
   ```
   完成某件任务所需要的时间度量
   ```



# binlog - mysqlbinlog  
   ```
   binlog 的主要目的是复制和恢复
   ```
   ```
   https://mp.weixin.qq.com/s?__biz=MzI1NDU0MTE1NA==&mid=2247483875&idx=1&sn=2cdc232fa3036da52a826964996506a8&chksm=e9c2edeedeb564f891b34ef1e47418bbe6b8cb6dcb7f48b5fa73b15cf1d63172df1a173c75d0&scene=0&xtrack=1&key=e3977f8a79490c6345befb88d0bbf74cbdc6b508a52e61ea076c830a5b64c552def6c6ad848d4bcc7a1d21e53e30eb5c1ead33acdb97df779d0e6fa8a0fbe4bda32c04077ea0d3511bc9f9490ad0b46c&ascene=1&uin=MjI4MTc0ODEwOQ%3D%3D&devicetype=Windows+7&version=62060719&lang=zh_CN&pass_ticket=h8jyrQ71hQc872LxydZS%2F3aU1JXFbp4raQ1KvY908BcKBeSBtXFgBY9IS9ZaLEDi
   ```
   - MySQL主从复制：MySQL Replication在Master端开启binlog，Master把它的二进制日志传递给slaves来达到master-slave数据一致的目的

   - 数据恢复：通过使用 mysqlbinlog工具来使恢复数据

   - 查看日志是否开启
   ```sql
   show variables like 'log_bin';
   ```

   - 开启日志
   ```
   [mysqld]
   log_bin=ON
   ```

   - Binlog日志的三种模式
      1. Statement level
      ```
      每一条修改数据的sql都会记录到master的bin_log中，slave在复制的时候sql进程会解析成master端执行过的相同的sql在slave库上再次执行。
      ```
      2. Row Level模式
      ```
      日志中会记录成每一行数据修改的形式,会产生大量的日志内容
      ```
      ```
      不会出现某些特定情况下的存储过程，或fuction，以及trigger的调用或处罚无法被正确复制的问题
      ```
      3. Mixed模式（混合模式）
      ```
      mysql会根据执行的每一条具体的sql语句来区分对待记录的日志形式，也是在statement和row之间选择一种。
      ```
      4. 查看模式 - mysql默认是row
      ```sql
      show variables like "%binlog_format%";
      ```
      5. 模式设置
      ```
      [mysqld]
      log_bin=/var/lib/mysql/mysql-bin
      #binlog_format="ROW"
      binlog_format="MIXED"   #开启MIXED模式
      #binlog_format="STATEMENT"
      ```

   - mysqlbinlog解析日志  
      1. 二进制转成可读sql
      ```
      --base64-output=decode-rows –vv
      ```
      2. 时间范围
      ```
      --start-datetime='2019-04-11 00:00:00' --stop-datetime='2019-04-11 15:00:00'
      ```
      3. 数据库
      ```
      --database=数据库名
      ```
      4. ex
      ```
      mysqlbinlog --no-defaults --database=uc01_cn_s100  --base64-output=decode-rows -v --start-datetime='2019-04-11 00:00:00' --stop-datetime='2019-04-11 15:00:00'  mysql-bin.000007 > binlog007.sql
      ```
      ```
      grep -i -A 20 -B 10 "guild" binlog007.sql
      查找 ‘guild’ 前10行后20行内容
      ```

   
# 