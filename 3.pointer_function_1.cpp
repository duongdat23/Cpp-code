// 5.pointer_function_exe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 
int Foo()
{
	return 0;
}

int main()
{
	cout << Foo() << endl;
	int (*pfoo)() = Foo;
	cout << pfoo << endl; 

	return 0;
}