# Step13: struct, typedef, malloc, realloc
## 1.结构体
### 小任务：
1. 使用InputPositiveValue函数改变t1.icmax的输入；
2. 创建一个安全健壮的函数来输入晶体管类型，它应该看起来像这样：
`int InputTransistorType(char *prompt)`
`{`
`    /* ... */`
`}`
在InputTransistor里面这样使用它：
`t1.type = InputTransistorType("Input type: ");`
3. 添加代码显示case style；
4. 创建一个安全健壮的函数来输入晶体管的外壳样式。
## 2.typedef
## 3.malloc()和free()的使用
## 4.realloc()的使用
`trans = realloc(trans, sizeof(Tran) * (numTrans + 1));`
用途：给已经分配好内存的变量扩大内存。
## 小作业：
1. 完成前面提到的所有任务；
2. 确保Makefile里有一个clean规则用于清除transistors和.o文件；
3. 在main中输入代码，输入任意数量的晶体管。在用户输入每个晶体管后，程序应该问用户这个问题：
`Would you like to enter another transistor (Y/N)? `
4. 如果用户输入“Y”或者“y”，进行下一个晶体管的输入；如果用户输入“N”或者“n”，显示所有已经输入的晶体管。确保对yes或no输入安全和健壮。
完成以上所有工作后，做以下工作：
A：make clean清除可执行文件和中间文件；
B：输入以下命令：
`cd ..`
`tar cvzf transistors.tar.gz transistors`