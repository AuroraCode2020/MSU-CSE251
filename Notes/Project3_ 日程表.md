# Project3: A Scheduling Program
1.当用户启动程序时，它将如下显示：
`cbowen@ubuntu:~/workspace251/Scheduler/Debug$ ./Scheduler `
`1 - Insert a new event`
`2 - Display all events`
`3 - Now?`
`4 - Delete expired`
`0 - Exit`
`Please select an option: `
每个菜单选项：
## 1 - Insert a new event
当用户选中菜单1时程序会如下显示：
`Please select an option: 1`
`What is the event: CSE 251`
`Event date: 4/14/2011`
`Start time: 3:00pm`
`End time: 4:50pm`
事件描述最多允许50个字符，包括空格。日期形式为“月/日/年”。用户必须使用完整年份（2011），而不是2个字符的年份（11）。另外，只有1970年以后的日期才有效。开始时间和结束时间是12小时格式，只有小时和分钟。
当新事件被加入时，应该和所有其他事件进行比较，如果出现重叠应该指出。如果事件A在事件B开始前结束或是A在B结束后开始，则两个事件不会重叠。
如果重叠，会产生如下输出：
`Please select an option: 1`
`What is the event: Afternoon Tea`
`Event date: 4/14/2011`
`Start time: 4:00pm`
`End time: 4:15pm`
`Warning, this event overlaps: `
` 4/14/2011  3:00PM  4:50PM CSE 251`
## 2 - Display all events
当用户选择这个菜单选项时，所有事件都会按开始时间顺序显示。例子如下：
`Schedule:`
` 4/14/2011  3:00PM  4:50PM CSE 251`
` 4/14/2011  4:00PM  4:15PM Afternoon Tea`
## 3 - How?
当用户选择这个菜单选项时，应显示当前活动的事件。如果当前时间大于等于一个活动开始时间且小于等于它的结束时间，则该活动处于活动状态。例子如下：
`Please select an option: 3`
`Currently active events: `
` 4/14/2011  2:00PM  3:00PM Prepare for CSE 251`
## 4 - Delete expired
如果用户选择这个选项，则所有已经过期了的事件，即在当前时间前结束的事件，都会被程序删除。被删除的事件应该被显示出来：
`Please select an option: 4`
`Deleting:`
` 4/14/2011 12:00PM  1:00PM Lunch`
## 一些提示：
### 健壮和安全的输入：
所有输入必须是安全和健壮的。如果用户输入了一个无效的值，再请求一次新的输入。除了提示重新输入选项外，不需要额外的详细提示。
### 日期和时间
`time_t`这个变量的值是Unix纪元（1970.1.1）以来的秒数。可以简单地用大于小于或等于号比较。
`struct tm`使用这个结构体来帮助你构建程序：
`struct tm`
`{`
`  int tm_sec;			/* Seconds.	[0-60] (1 leap second) */`
`  int tm_min;			/* Minutes.	[0-59] */`
 ` int tm_hour;			/* Hours.	[0-23] */`
`  int tm_mday;			/* Day.		[1-31] */`
`  int tm_mon;			/* Month.	[0-11] */`
`  int tm_year;			/* Year	- 1900.  */`
 ` int tm_wday;			/* Day of week.	[0-6] */`
`  int tm_yday;			/* Days in year.[0-365]	*/`
 ` int tm_isdst;			/* DST.		[-1/0/1]*/`
`};`
**使用转换函数：**
可以使用转换函数将time_t转化为struct tm：
localtime()函数：
`struct tm startTM;`
`    time_t start;`
`    /* ... */`
`    startTM = *localtime(&start);`
mktime()函数：
`struct tm startTM;`
`    time_t start;`
`    /* ... */`
`    start = mktime(&startTM);`
**如何输入一个日期：**
详细教程与代码见网页。
**如何输入一个时间：**
详细教程与代码见网页。
**如何输出一个time_t的值：**
将其转化为struct tm，再进行输出。
**ctime函数：**
函数ctime将一个time_t变量转化为以下字符串：
`Thu Apr 14 14:00:00 2011`
将ctime函数的输出转化回time_t变量，可以用以下代码：
`        struct tm tim;`
`        time_t startTime;`
`        fgets(buffer, sizeof(buffer), file);`
`        strptime(buffer, "%a %b %d %H:%M:%S %Y", &tim);`
`        startTime = mktime(&tim);`
**文件I/O：**
维护一个名为schedule.dat的文件，时间表存放在里面。每次有事件加入或者被删除时，用最新版本更新该文件。
当程序第一次启动时，读入该文件，不需要读写该文件的提示。
该文件的第一行是事件的数量。每个事件存储为三行，第一行是对事件的描述，第二行是由ctime函数输出的开始时间和日期，第三行是由ctime函数输出的结束时间和日期。
`3`
`Prepare for CSE 251`
`Thu Apr 14 14:00:00 2011`
`Thu Apr 14 15:00:00 2011`
`CSE 251`
`Thu Apr 14 15:00:00 2011`
`Thu Apr 14 16:50:00 2011`
`Afternoon Tea`
`Thu Apr 14 16:00:00 2011`
`Thu Apr 14 16:15:00 2011`
你应当想办法处理当第一行的数字为零时的情况。
**一些要求：**
你应该让你的程序模块化，不要把整个程序放入一个.c文件中。至少使用两个不同的.c文件（如果实现了文件I/O，则为三个）。合理将函数分组到文件和头文件中。
使用一个Makefile来构建你的程序。你的Makefile必须包含一个clean指令。
不允许使用全局变量。你应该使用指针来传递参数。