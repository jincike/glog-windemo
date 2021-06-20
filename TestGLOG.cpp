// TestGLOG.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "glog/logging.h"

int main(int argc, char* argv[])
{
	//初始化要打印日志的程序
	google::InitGoogleLogging(argv[0]); //初始化 glog

	//打印到窗口
	//FLAGS_logtostderr = google::ERROR;
	//FLAGS_stderrthreshold = google::ERROR;
	//FLAGS_alsologtostderr = google::ERROR;                   // 将实现日志信息输出到stderr，并且会记录到本地日志文件；
	
	//将日志文件输出到本地
	//FLAGS_log_dir = "D:\\log";                      

	//不同等级日志分开打印
	google::SetLogDestination(google::GLOG_INFO, "./log/info");//编码时，vcxproj在的目录下，日志保存在log文件夹下，以info开头的文件下
	google::SetLogDestination(google::GLOG_WARNING, "./log/war");
	
	google::SetLogDestination(google::GLOG_ERROR, "./LOG/err");//EXE目录下LOG文件夹下输出日志,error开头的文件
	/********以exe所在的位置，使用时如此来切换日志打印的位置*******/
	google::SetLogDestination(google::GLOG_FATAL, "../log/fat");//打日志到EXE所在的目录的上一级目录下得log文件下
	//最大输出日志等级
	FLAGS_minloglevel = google::GLOG_WARNING;                  //也会打印低等级的日志文件，只是里面没有低等级的日志输出，只有高等级的输出
	                                                           //因为，glog默认在低等级的日志里面也打印高等级的错误。
	//日志实时输出 
	FLAGS_logbufsecs = 0;
	//最大日志文件大小 10M
	FLAGS_max_log_size = 10; 

	int nTmp = 90;
	LOG(INFO) << "Hello, GOOGLE!";  //自动换行
	LOG(WARNING) << nTmp;
	LOG(ERROR) << "ERROR, GOOGLE!";  
	//LOG(FATAL) << "FATAL";
	google::ShutdownGoogleLogging();
	while (1)
	{

	}
}
