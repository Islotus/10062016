 ///
 /// @file    standard_io_stream.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 03:38:48
 ///
 
#include <iostream>
#include <string>
#include <limits>
void printCin()
{
	std::cout << "bad = " << std::cin.bad() << std::endl;
	std::cout << "fail = " << std::cin.fail() << std::endl;
	std::cout << "eof = " << std::cin.eof() << std::endl;
	std::cout << "good = " << std::cin.good() << std::endl
		<< std::endl;
}

int main()
{
	int _inum;
	printCin();

	while(std::cin >> _inum)
	{
		std::cout << _inum << std::endl;
	}

	printCin();

	std::cin.clear();
	printCin();
	//std::cin.ignore(1024,'\n');
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	
	std::string s;
	std::cin >> s;
	std::cout << s << std::endl;

	return 0;

}
