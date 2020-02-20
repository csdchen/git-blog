# mysql简单安装


## 查看mysql数据库用户密码
```
1. cmd 到bin目录下
2. taskkill /f /im mysqld.exe
   注: 关闭mysql
3. 执行 mysql --skip-grant-tables
   注: 这是跳过mysql的用户验证
4. 打开一个新的cmd 到bin目录下
5. mysql -u root
6. select host,user,password from mysql.user;
7. update mysql.user set password='12345' where user='root';
```

## ERROR
- install/remove of the service denied
```
没有权限, 使用管理者打开cmd
```

## 绿色版.zip 安装
```
1. 解压myql----winx64.zip
2. 把bin添加到环境变量
3. 解压目录下新建目录data
4. 解压目录下新建 my.ini
[mysqld]
basedir = 解压目录
datadir = 解压目录\data
port = 3306
default_authentication_plugin=mysql_native_password
[client]
port = 3306
default-character-set=utf8

5. 管理模式cmd bin目录下
6. mysqld --install 服务名-默认mysql
7. mysqld --initialize-insecure
8. net start 服务名
9. 登录修改密码
alter user 'root'@'localhost' identified with mysql_native_password by '新密码';
flush privileges;
```
