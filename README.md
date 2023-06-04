# EnglishLeaning

这是一个终端下的Linux英语学习小工具，核心程序由cpp写成，从剪切板中获取单词加入单词表中的功能则由py写成

## 使用须知
该程序需要自己下载源代码编译，

##### 编译之前：
进入到word.cpp当中，将Word::Word()当中的this->path的值改成你的文件路径

> 运行pwd命令获取文件路径

进入到AddWord.py当中，将path的值改成你的文件路径

##### 编译方法：

运行终端下运行`make`即可，Main就是生成的可执行文件

##### 新单词
进入到MyWords.txt，找到字符串`<++>`，删除它并在它的位置上填写单词的中文
