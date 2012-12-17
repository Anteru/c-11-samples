#include <iostream>

void foo (void* f)
{
	std::cout << "void foo (void*)" << std::endl;
}

void foo (int f)
{
	std::cout << "void foo (int)" << std::endl;
}

int main ()
{
	foo (nullptr);
}