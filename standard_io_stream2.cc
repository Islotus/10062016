 ///
 /// @file    standard_io_stream2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-13 03:55:31
 ///
 
#include <iostream>
#include <limits>

int main()
{
	int _ival;
	while(std::cin >> _ival, !std::cin.eof())
	{
		if(std::cin.bad())
		{
			std::cout << "IO stream corrupted!" << std::endl;
			return -1;
		}
		if(std::cin.fail())
		{
			std::cout << "data illegal, try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		std::cout << "_ival = " << _ival << std::endl;
	}

	return 0;

}

