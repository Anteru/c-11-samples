#include <functional>
#include <iostream>

void Process (const int count,
	std::function<void (const int total, const int processed)> callback)
{
	for (int i = 0; i < count; ++i) {
		callback (count, i);
	}
}

void PrintProgress (const int total, const int finished)
{
	std::cout << finished << "/" << total << std::endl;
}

int main ()
{
	Process (23, PrintProgress);
}