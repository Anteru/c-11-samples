#include <iostream>

int main ()
{
	const int arr [] = {1, 3, 3, 7};

	for (auto i : arr) {
		std::cout << i << std::endl;
	}
}