# Project1: Intergral of sinc function
编写程序，计算下列函数的积分：
![399b4c15c3773e6b7fc7cc502e517ca4.png](../_resources/399b4c15c3773e6b7fc7cc502e517ca4.png)
累加公式如下：（应从n=10开始累加）

![c407536b4543d6c391a2558d5ddbce11.png](../_resources/c407536b4543d6c391a2558d5ddbce11.png)![18f27e3c897111566b635402a66501ce.png](../_resources/18f27e3c897111566b635402a66501ce.png)
![3c226711cefe411dc6d46f6541ee4e36.png](../_resources/3c226711cefe411dc6d46f6541ee4e36.png)
函数累加的停止条件有以下两个，满足其中之一即可停止：

1.  当n达到10^5时即可停止；
2.  当误差（即两次累加结果之差）小于10^-10时即可停止。