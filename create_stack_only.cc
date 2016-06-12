 ///
 /// @file    create_stack_only.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-12 05:57:23
 ///

//只能生成栈对象，不能生成堆对象，亦即不能通过new表达式来生成对象
//方法：
//>将构造函数放入private区域
//>operator new函数放入到private区域

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
using std::cin;
using std::cout;
using std::endl;
#endif

class Student
{
	public:
		int ild;
		char szName[10];
	public:
		Student()
		{
			std::cout << "Student构造函数被调用" << std::endl;
		}
		~Student()
		{
			std::cout << "Student析构函数被调用" << std::endl;
		}

	private:
		static void* operator new(std::size_t nSize);
		static void operator delete(void* pVoid);

#if 0
		static void* operator new(std::size_t nSize)
		{
			std::cout << "new 操作符被调用，size = " << nSize << std::endl;
			//void* pRet = new char[nSize];
			void* pRet = malloc(nSize);
			return pRet;
		}
		static void operator delete(void* pVoid)
		{
			std::cout << "delete 操作符被调用." << std::endl;
			free(pVoid);
		}
#endif
};

int main()
{
#if 0  //生成堆对象的语句
	Student* pstu = new Student;
	pstu -> ild = 101;
	strcpy(pstu -> szName,"Tony");
	std::cout << std::endl;
	delete pstu;
#endif

#if 1
	Student* pstu = new Student[3];
	std::cout << "堆对象数组已被创建" << std::endl;
	delete pstu;
	pstu = NULL;

#endif

#if 0  //生成栈对象的语句
	Student stu;
	stu.ild = 101;
	strcpy(stu.szName,"Tony");
	std::cout << "栈对象已被创建" << std::endl;
#endif
	//std::cout << std::endl;
	//Teacher* pt = new Teacher();

	//delete pt;
	
	return 0;
}
