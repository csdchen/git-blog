## 多表查
```sql
-- 查找 personrank(排行榜) 前十名的 login(登陆) 账号
select login.plat_user_name, personrank.uid, personrank.user_name from login, personrank
    where personrank.rank_index <= 10 and personrank.uid == login.role_id_1;
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

## 查找输出到文件
```sql
select *from role into outfile 'C:/1.xls';
```

