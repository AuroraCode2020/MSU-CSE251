# Step1: Getting Started
`pwd`打印当前目录
`ls`列出当前目录下所有文件（不包括隐藏文件）
`touch xxx`在当前目录新建xxx文件，如果xxx文件已经存在，则将该文件的时间和日期设置为当前
`ls -l`列出当前目录下所有文件的详细信息
`ls -a`列出当前目录下所有文件（包括隐藏文件）
`ls -F`列出当前目录下所有文件（不包括隐藏文件），后面带“/”，可以方便得知哪些是文件夹，哪些是文件
`rm xxx`删除当前目录下xxx文件
`mkdir xxx`在当前目录下新建xxx文件夹
`rmdir xxx`在当前目录下删除xxx文件夹
注意：rmdir命令只能删除空文件夹，使用`rm -r`来删除非空文件夹
`cd xxx`将当前目录设为xxx
`cd ..`移动到当前目录的父目录
`cd .`移动到当前目录
`cd ~`移动到主目录
`cd ~/xxx`移动到主目录下的xxx子目录
`cd ../xxx`移动到当前目录同级的xxx目录
测试：`cd ../cse251/.././cse251`表示什么意思？
`cp AAA xxx`把AAA文件从当前目录复制到xxx处
`gcc hello.c`编译hello.c，它会输出一个a.out文件
`mv hello.c myhello.c`把当前目录下的hello.c重命名成myhello.c
`cat myhello.c`显示myhello.c文件内容
`less myhello.c`显示myhello.c文件内容，可翻页查看，退出时按q
`man xxx`查看关于xxx命令的帮助，按q退出
`yelp &`启动帮助程序，&代表它会新建一个进程。
`gcc -o myhello myhello.c`-o意味着myhello.c编译运行后会得到一个myhello文件，而不是a.out
`top`查看当前所有进程运行情况
`ps u`查看正在运行的进程列表
`kill [PID]`杀死进程[PID]