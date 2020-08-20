## 多表查
```sql
-- 查找 personrank(排行榜) 前十名的 login(登陆) 账号
select login.plat_user_name, personrank.uid, personrank.user_name from login, personrank
    where personrank.rank_index <= 10 and personrank.uid == login.role_id_1;
```