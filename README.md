
# 功能介绍
	设计UI界面，实现打开文件对话框，选中一个text文件，读取文件内容并显示。
	
# 实现技术
	
- 本案例主要是为了测试 QtRO模块，通过LPC或RPC，在其他进程或者远程执行任务。
	但是特殊的地方在于经过QtRO模块，能让你透明的执行这些任务，就像这些任务就是在本进程一样。
	
- 本案例将读取文件作为任务。在replica程序选择一个文件，通过LPC将文件路径发送给source程序。
	source程序中读取文件内容，再通过LPC发送回replica程序，但是这个过程QtRO封装好了。就像replica程序
	自己执行的一样，直接获取读取文件的结果，然后显示出来。
	
- 主要：为了测试QtRO 传输大数据量的速度，程序中故意在读取文件的函数中返回了1G大小的图片。
	正常只需要返回读取是否成功。在我的测试环境下1G的图片传输需要3秒钟左右。
	
	
# 参数资料
[QtRO简介](https://zhuanlan.zhihu.com/p/36501814)
	
	