 ///
 /// @file    crea_heap_object_only.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-12 06:37:17
 ///

//只能生成堆对象，不能生成栈对象，亦即在创建栈对象时，不能调用构造函数或析构函数
//能想到的方法：
//>将构造函数放到private区域
//>将析构函数放到private区域

//由于，堆对象在创建时，也用到构造函数，故，把析构函数放到private区即可

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
		void destroy()
		{
		//	(*this).~Student();
			delete this;
		}
	private:  //不能生成栈对象
		~Student()
		{
			std::cout << "Student 析构函数被调用" << std::endl;
		}
};

class Teacher
{

};
 
int main()
{
	Student* pstu = new Student;
	pstu -> ild = 101;
	strcpy(pstu -> szName,"Tony");

	pstu -> destroy();
//	delete pstu;


	//Student stu;
	
	return 0;
}

