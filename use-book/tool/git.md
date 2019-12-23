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

## git错误信息
