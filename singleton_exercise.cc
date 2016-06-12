 ///
 /// @file    singlet_exercise.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-12 07:07:01
 ///

//单例模式自己有单独练习了一遍
//单例设计模式：
//1.将构造函数私有化
//2.在类中定义一个静态的指针对象（可私，可公），并在类外初始化为空
//3.定义一个返回值为类指针的静态成员函数。如果2中的指针对象为空，则初始化对象。以后再有对象调用该静态成员函数的
//时候，不再初始化为对象，而是直接返回对象，保证内存中只有一个实例。

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class CA
{
	public:
		static CA* getInstance(int x, int y)
		{
			if(pCA == NULL)
			{
				pCA = new CA(x, y);
			}
			cout << "static CA* getInstance called" << endl;
			return pCA;
		}
		void print() const
		{
			cout << "_x: " << _x << ",_y" << _y << endl;
		}

	private:
		int _x;
		int _y;
		static CA* pCA;
		CA(int x, int y)
		:_x(x)
		,_y(y)
		{
			cout << "constructor called" << endl;
		}	
};
CA* CA::pCA = NULL;  //静态成员要在外面初始化
int main()
{
	CA* p1 = CA::getInstance(3, 4);
	CA* p2 = CA::getInstance(2, 1);
	CA* p3 = CA::getInstance(6, 2);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	p1 -> print();
	p2 -> print();
	p3 -> print();

	return 0;
}

