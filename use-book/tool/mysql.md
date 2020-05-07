# mysql简单安装
   - [绿色版.zip 安装](#绿色版.zip安装)
   - [linux二进制安装](#linux二进制安装)
   - [ERROR](#ERROR)

## 查看mysql数据库用户密码
```
1. cmd 到bin目录下
2. taskkill /f /im mysqld.exe
   注: 关闭mysql
3. 执行 mysql --skip-grant-tables --skip-networking
   注: 这是跳过mysql的用户验证
4. 打开一个新的cmd 到bin目录下
5. mysql -u root
6. select host,user,password from mysql.user;
7. update mysql.user set password='12345' where user='root';
8. 退出重启 net start mysql
```

## 绿色版.zip安装
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

## linux二进制安装
- <a href='https://downloads.mysql.com/archives/community/'>下载地址</a>
- `linux-Generic`版本
- 下载解压
```
tar xf mysql-5.7.28-linux-glibc2.12-x86_64.tar.gz
mkdir /usr/local/mysql
mv mysql-5.7.28-linux-glibc2.12-x86_64 /usr/local/mysql
报错：tar: skipping to next header
tar: exiting with failure status due to previous errors
```
- 用户创建
```
rpm -qa | grep mysql   // 查看是否安装mysql
useradd /s /sbin/nollogin mysql
```
- `设置环境变量`
```
vim /etc/profile
export PATH=/application/mysql/bin:$PATH

source /etc/profile
mysql -v
```
- 初始化数据
```
mkdir /usr/local/mysql/data
mysqld --initialize --user=mysql --basedir=/usr/local/mysql --datadir=usr/local/mysql/data
```
- 无密码初始化
```
--initialize-insecure
```

## ERROR
- `install/remove` of the service denied
```
没有权限, 使用管理者打开cmd
```
- `本地登陆 Error 1130(HY000)`
  - 1. 改表法
   ```
   在localhost的那台电脑登入MySQL后，更改"MySQL"数据库"user"表里的"host"项，将"localhost"改成"%"
   ```
   ```
   1. cmd 到bin目录下
   2. taskkill /f /im mysqld.exe
   注: 关闭mysql
   1. 执行 mysql --skip-grant-tables
   注: 这是跳过mysql的用户验证
  1. 打开一个新的cmd 到bin目录下
  2. mysql -u root
  3. select host,user,password from mysql.user;
   注: 查看root用户信息
   ```
- error: `libaio.so`
```
rpm -qa | grep libaio
yum install libaio
ubuntu: 
sudo apt-get install -y libaio
sudo apt-get install -y libaio1
sudo apt-get install libaio-dev
```
- E: Invalid operation install
```
sudo apt-get update
```

## ubuntu 简单安装mysql
```
sudo apt-get install mysql-server
sudo apt-get isntall mysql-client
sudo apt-get install libmysqlclient-dev
```