# 查找
```sql
SELECT select_list [INTO new_table] FROM table_name
[WHERE search_condition] 
[GROUP BY group_by_experssion] 
[HAVING search_condition]
[ORDER BY order_experssion [ASC|DESC]];
```
```
参数说明
select_list : 查询的列
INTO new_table : 创建新表并奖查询行插入新表中
FROM table_name : 可以是基表，视图，连接表
WHERE search_condition : 搜索条件
GROUP BY group_by_experssion : 根据group_by_experssion列中的值将结果分组
HAVING子句从中间结果集对`行`进行筛选，这些中间结果集是用SELECT中的FROM,WHERE或GROUP BY子句创建的。HAVING子句通常与GROUP BY一起使用
```

## 使用别名
```sql
SELECT goods_name "商品名称" FROM goods;
SELECT goods_name AS "商品名称" FROM goods;
```
- 多表查询出现相同的列名
```sql
SELECT user_address.mobile AS "订单表是的电话号码",users.mobile AS "用户表中的电话号码" FROM user_address,users WHERE user_address.user_id = users.user_id;
```
- 计算结果设置别名
```
SELECT goods_name (market_price - cost_price) AS "商品盈利" FROM goods;
```
- 聚合函数的列设置别名
```sql
SELECT MAX(market_price) AS "市场最高价", MIN(market_price) AS "市场最低价" FROM goods;
```

## 删除重复数据
```sql
SELECT DISTINCT select_list FROM table_name;
```

## 限制查询结果
```sql
SELECT DISTINCT select_list FROM table_name LIMIT count;
SELECT DISTINCT select_list FROM table_name LIMIT count1, count2;
```
```
count=限制数量
第count1+1条数据到第count2条数据
第一个结果的记录编号是0，不是1
```
- 查看从第N条开始的记录
```sql
SELECT DISTINCT select_list FROM table_name LIMIT 2 OFFSET 3;
```
```
查看从第4条记录开始的2条数据信息
```

## 多表查
```sql
-- 查找 personrank(排行榜) 前十名的 login(登陆) 账号
select login.plat_user_name, personrank.uid, personrank.user_name from login, personrank
    where personrank.rank_index <= 10 and personrank.uid == login.role_id_1;
```

## WHERE
- between
```sql
SELECT goods_id FROM goods WHERE market_price BETWEEN 1000 AND 3000;
```
```
查询1000-3000之间的商品
```
- between日期
```sql
SELECT goods_id FROM goods WHERE goods_times BETWEEN '2017-1-1' AND '2018-1-1';
```
- 昨天和今天的信息
```sql
SELECT goods_id FROM goods WHERE goods_times BETWEEN DATEADD(DAY,-1,GETDATE()) AND GETDATE();
```
- not between
```sql
WHERE market_price NOT BETWEEN 2000 AND 3000;
```

## 连接列值
```sql
SELECT name + cat_name AS '品牌信息' FROM brand;
```

## 查找输出到文件
```sql
select *from role into outfile 'C:/1.xls';
```

## 清数据
```sql
update 'role_attr_detail_9' set role_query_data = '';
```

## 清表
```sql
truncate table role_attr_detail_9;
```

## 增长
```sql
alter table 'role_attr_detail_9' modify column 'role_query_data' varbinary(10240) NOT NULL default '' COMMENT '测试' after ''role_id;
```

## 改表
```sql
alter table 'role_attr_detail_9' modify column 'role_query_data' mediumblob NUT NULL default '' COMMENT '测试' after ''role_id;
```

## 查看表结构
desc tablename;

## 导出数据表结构
mysqldump -uroot -pmima --socket=/data/game/mysql/mysql-3306.sock -q -d test_cn | sed "s/AUTO_INCREMENT=[0-9]*//g" > table.sql

## 导入数据
LOAD DATA INFILE 'file' INTO TABLE table_name;
- running with the --secure-file-priv option
```
1. mysql文件的导入和导出路径有默认的设置，即 secure-file-priv,当传入的csv文件路径与默认的路径冲突时就会报错
2. 查看你的secure-file-priv设置
    show variables like ‘%secure%’;
```
- Row 1 was truncated; it contained more data than
```
1. 很可能是由于数据文件中的列数跟 MySQL 数据表字段数目没有完全匹配
```

