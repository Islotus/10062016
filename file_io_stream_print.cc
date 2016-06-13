 ///
 /// @file    file_io_stream.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 04:07:55
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void)  //输入到输出缓冲区
{
	std::ifstream ifs("in_test.txt");  //定义并打开了一个ifstream对象
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}

#if 0
	std::string s;
	while(ifs >> s)  //见到空格就换行
	{
		std::cout << s << std::endl;
	}
#endif

#if 1
	std::vector<std::string> vec_str;
	std::string line;
	while(getline(ifs,line))  //获取一行
	{
		//std::cout << line << std::endl;
		vec_str.push_back(line);
	}

	std::vector<std::string>::iterator sit = vec_str.begin();
	for(; sit != vec_str.end(); ++sit)
	{
		std::cout << *sit << std::endl;
	}
#endif

	ifs.close();

	return 0;
}

#if 0
int main()
{
	std::ifstream ifs("in_test.txt");
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}

	std::ofstream ofs("out_test.txt");
	std::string line;
	while(getline(ifs,line))
	{
		ofs << line << std::endl;
	}

	return 0;
}
#endif
