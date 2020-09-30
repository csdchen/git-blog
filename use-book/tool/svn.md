# SVN

## 账号密码
linux cd ~/.subversion/auth/svn.simple

## 简单用法
1. 检出
```
svn checkout http://路径 本地路径 --username 用户名
svn checkout svn://路径 本地路径 --username 用户名
```
2. 导出（导出一个干净不带.svn文件夹的目录树）
```
svn export [-r 版本号] http://路径 本地路径 --username 用户名
svn export [-r 版本号] svn://路径 本地路径 --username 用户名
svn export 本地检出的目录路径 本地路径
```
3. 添加新文件
```
svn add 文件
```
4. 提交
```
svn commit -m "备注" [-N] [--no-unlock] 文件
```
5. 更新文件
```
svn update
svn update -r 修正版本 文件名
svn update 文件名
```
6. 删除文件
```
svn delete 文件名
svn ci -m "备注"
```
7. 加锁/解锁
```
svn lock -m "备注" [--force] 文件名
svn unlock 文件名
```
8. 比较差异
```
svn diff 差异名
svn diff -r 修正版本号m:修正版本号n 文件名 [--summarize]
// [--summarize] 显示输出结果的概要
svn diff -rhead 文件名
```
9. 查看文件或者目录状态
```
svn st 目录名
svn status 目录名
```
* ? : 不在控制
* M : 内容修改
* C : 冲突
* A : 加入
* K : 锁定
10. 查看日志
```
svn log 文件名
svn log 文件名 -ln    // 查看最近N条记录
```
11. 查看文件详细信息
```
svn info 文件名
```
12. 查看版本库下的文件和目录列表
```
svn list svn://路径
svn ls svn://路径
```
13. 创建纳入版本控制下的新目录
```
svn mkdir 目录名
svn mkdir -m "备注" http://目录全路径
```
14. 恢复本地修改
```
svn revert [--recursive] 文件名
svn revert 
// [--recursive] 递归还原
```
15. 解决冲突
```
svn resolved [目录路径]
```
1.  查看URL文件内容
```
svn cat http://文件路径
```

## 查看
- 查看某段时间内提交记录
```
svn log -v -r {2019-8-11}:{2019-8-16} -l 30 | sed -n '/wangyue01/,/--$/ p'
其中：
-r {2018-9-10}:{2018-9-25}：通过-r来指定时间段
-v：表示显示详细信息
sed -n '/danni/,/--$/ p'：根据用户名筛选提交记录，其中wangyue01是我的svn用户
-l：表示查看日志的数量
```

## TortoisesSVN使用
### 错误信息
- 冲突
```
postpone 推迟
skip this conflict and leave it unresolved 跳过这个冲突，让它不被解决

mark as resloved 标记为已解决
accept current working copy state 接受当前工作副本状态

ignore incoming deletion 忽略传入删除
ignore the deletion of "xxx@xxx" 忽略删除

accept incoming deletion
ignore the deletion of "xxx" 接受传入删除
```
- unable to create pristine install stream
- can't create temporary file from template '...../.svn/tmp/svn-xxxxx': No space left on device
```
临时交换空间不足
```

[主目录](../../README.md)
