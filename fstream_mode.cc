 ///
 /// @file    file_io_stream_mode.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 05:20:49
 ///

//文件模式：
//ios::in  打开文件做读操作
//ios::out  打开文件做写操作，会删除原有文件
//ios::app  在每次写之前找到文件尾
//ios::trunc  打开文件时清空已存在的文件流
//ios::ate  打开文件后立即定位到文件末尾
//ios::binary  以二进制模式进行IO操作

#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream ofs("test.txt",std::ios::ate|std::ios::app);
//	std::ofstream ofs("test.txt",std::ios::ate);
//	std::ofstream ofs("test.txt",std::ios::app);
	if(!ofs)
	{
		std::cout << "ofstream error!" << std::endl;
		return -1;
	}

	std::cout << ofs.tellp() << std::endl;

	ofs << "that's new" << std::endl;

	ofs.close();
	
	return 0;
}




