 ///
 /// @file    file_io_stream.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 04:07:55
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int test(void)
{
	std::ifstream ifs("in_test.txt");  //定义并打开了一个ifstream对象
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}

#if 0
	std::string s;
	while(ifs >> s)
	{
		std::cout << s << std::endl;
	}
#endif

#if 1
	std::vector<std::string> vec_str;
	std::string line;
	while(getline(ifs,line))
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
