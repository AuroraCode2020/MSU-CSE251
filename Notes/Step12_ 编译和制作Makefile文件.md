# Step12: Compilation and Makefil包含# Step12: Compilation and Makefiles
## 1. 编译和制作Makefile文件
`gcc -c hanoi.c`
生成一个hanio.o（联系CSAPP第一章内容）
`gcc -o hanoi hanoi.o`
生成一个hanio（可执行文件）（联系CSAPP第一章内容）
构建一个可执行文件分为两步：第一步是编译所有的.c文件，第二步是将编译结果全部链接成一个可执行文件。
`hanoi:	hanoi.o`
`	gcc -o hanoi hanoi.o`
Makefile文件的制作有三点需要明确的：
- 目标：我们想要得到什么东西；（即：hanoi）
- 原料：我们需要加工的东西；（即：hanoi.o）
- 命令：我们如何由原料得到目标。（即gcc -o hanoi hanoi.o）
`clean:`
`	rm -f *.o hanoi`
删除所有.o文件和hanoi。
### #ifndef和#endif的使用
用法：用#ifndef和#endif把头文件内容包括起来，可以防止重复编译
`#ifndef xxx`
`xxx`
`xxx`
`#endif`
## 小作业
1. 创建一个新头文件autosolve.h。这个文件被hanoi.c所包含。在Makefile中正确编写相关编译代码。
注意：autosolve.h中包含hanoi.h。
2. 创建一个新的autosolve.c文件，它包含autosolve.h。将Autosolve和AutoMove函数移动到autosolve.c中，将Autosolve和AutoMove函数的声明放到autosolve.h中。
注意：hanoi.c包含autosolve.h。
3. 前面两项做完后，做以下工作：
- 编写一个make clean来删除可执行文件和中间文件；
- 向上移动目录并使用以下命令：
`tar cvzf hanoi.tar.gz hanoi`
这个命令将会将文件夹hanoi打包。
注意：不要把NumPins、NumDisks和MaxDiskSize的#defines放在autosolve.h中。