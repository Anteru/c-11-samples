#include <iostream>
#include <vector>
#include <functional>

void Process (const int count,
	std::function<void (const int item)> func)
{
	for (int i = 0; i < count; ++i) {
		func (((i << 3) + 1317));
	}
}

void Print (const char* message, const std::vector<int>& v)
{
	std::cout << message << std::endl;

	for (auto it = v.begin (), end = v.end (); it != end; ++it) {
		std::cout << *it << std::endl;
	}
}

int main ()
{
	std::vector<int> container;

	Process (4, [&container] (const int i) -> void {
		container.push_back (i);
	});

	Print ("Container-by-ref", container);

	container.clear ();

	Process (4, [container] (const int i) mutable -> void {
		container.push_back (i);
	});

	Print ("Container-by-copy", container);

	container.clear ();

	Process (4, [&] (const int i) -> void {
		container.push_back (i);
	});

	Print ("Ref-all", container);
}