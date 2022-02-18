# Step2: Introducing C
`gcc -o step2 step2.c`
`gcc -o step2 step2.c -lm`编译时，除了加上头文件，还需要链接额外的库

### 一些修饰符
一些修饰符可以放在%和f之间：
-：左对齐；
+：在数字前总是有符号（+或-）
0：使用前导零
nn：输出的宽度
.n：精度（小数点后几位）
