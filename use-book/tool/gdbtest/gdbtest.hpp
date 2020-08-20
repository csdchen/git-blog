#include "role.hpp"
#include <iostream>
using namespace std;

void gdbTest02()
{
	std::cout << "gdbTest02 start" << std::endl;

	int d_1 = 0;

	auto fun_test01 = [&d_1]()
	{
		d_1++;
	};

	auto fun_test02 = [&d_1]()
	{
		throw;
	};

	fun_test01();
	fun_test02();
}

void gdbTest01()
{
	std::cout << "gdbTest01 start" << std::endl;

	Role role;
	role.m_uid = 123;

	int value = 0;

	std::cout << "import 1" << std::endl;
	std::cin >> value;

	int a = 0;
	a++;
	a++;
	a++;
	a++;

	std::cout << "import 1" << std::endl;
	std::cout << "11111" << std::endl;

	std::cin >> value;

	a++;
	a++;
	a++;
	a++;

	std::cout << "import 1" << std::endl;
	std::cout << "22222" << std::endl;

	std::cin >> value;

	std::cout << "import 1" << std::endl;
	std::cout << "33333" << std::endl;

}

void gdbStart()
{
	std::cout << "<<<<< GDB Test Start >>>>>" << std::endl;

	std::cout << "1. cin 1 >> test gdbTest01" << std::endl;
	std::cout << "2, cin 2 >> test gdbTest02" << std::endl;

	int value = 0;
	std::cin >> value;

	if (value == 1)
	{
		gdbTest01();
	}
	else if (value == 2)
	{
		gdbTest02();
	}

	std::cout << "<<<<< GDB Test End   >>>>>" << std::endl;
}