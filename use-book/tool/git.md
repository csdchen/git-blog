# git

## git简单用法
* 生成密钥ssh
```
cd ~/.ssh
ssh-keygen -t rsa -C "your_email@youremail.com" // 直接回车跳过操作
// 把.pub加到github里
ssh -T git@github.com   // 验证是否配对成功
```
* 配置用户主目录下 个人的用户名称和电子邮件地址
```
git config --global user.name "runoob"
git config --global user.email test@runoob.com
```
* 查看配置信息
```
git config --list
```
* 初始化仓库
```
git init // 初始化当前目录
git init <newdir>
```
* 克隆项目
```
git clone Git仓库
git clone Git仓库 本地目录
```
* 查看项目的当前状态
```
git status -s
```
* 添加远程库
```
git remote add [本地名] url     // 一般本地名都通用使用 origin
git remote -v   // 查看保存的路径
```
* 将文件添加到缓存
```
git add <文件>...
```
* 查看修改
    + 尚未缓存的改动：git diff
    + 查看已缓存的改动： git diff --cached
    + 查看已缓存的与未缓存的所有改动：git diff HEAD
    + 显示摘要而非整个 diff：git diff --stat  
* 提交
```
git commit -m "备注"
git show    // 查看commit内容
git show commitHashID [filename] // 查看指定commit hashID的[文件]修改
```
* 查看提交历史
```
git log
     --oneline // 查看历史记录的简洁的版本
     --reverse // 逆向显示所有日志
     --author=用户名
     -数字     // 查看多少条信息
```
* 更新
```
git pull <repository> <refspec> // 从一个仓库或者本地的分支拉取并且整合代码
git fetch origin        // 查看是否有变更
git merge origin/master // 合并分支
```
* 推送
```
git push [本地名] 远程分支名
- git push origin master
```
* 不提交的文件加入 .gitgnore
## git错误信息
* git add 一个错误文件
```
git reset filename // 撤销指定文件
git reset // 撤销所有文件

```
// 若提示 fatal: Failed to resolve 'HEAD' as a valid ref.  
// 未能将'HEAD'解析为有效引用
```
git rm --cached .    // 删除文件
git rm -r --cached . // 删除文件和目录
```
* git commit 错误提交
```
git reset HEAD~1    // 只撤销commit操作，保留文件
git reset --hard HEAD~1     // 撤销commit操作，删除变化
```

# 错误提示
```
ERROR: You must verify your email address.
- 一般要重新验证邮箱，上github查看邮箱设置是不是有提示
- 例如：Please verify your email address to access all of GitHub’s features
```

[主目录](../../README.md)