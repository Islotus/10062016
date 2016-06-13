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
	std::fstream outfile("test1.txt",std::ios::out|std::ios::in);
	if(!outfile)
	{
		std::cout << "fstream error" << std::endl;
		return -1;
	}
	int _ival;
	for(int idx = 0; idx != 10; ++idx)
	{
		std::cin >> _ival;
		outfile << _ival << ' ';
	}
	std::cout << outfile.tellp() << std::endl;

	outfile.seekg(0,std::ios::beg);

	for(int idx = 0; idx != 10; ++idx)
	{
		outfile >>_ival;
		std::cout <<_ival << ' ';
	}
	outfile.close();

	return 0;
}




