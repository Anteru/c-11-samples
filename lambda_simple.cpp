#include <vector>
#include <iostream>
#include <string>

int main ()
{
	std::vector<std::string> items;

	items.push_back ("/foo/bar");
	items.push_back ("/foo/baz");
	items.push_back ("/tmp/item");

	items.erase (std::remove_if (items.begin (), items.end (),
		[] (const std::string& s) -> bool {
			return s.compare (0, 4, "/foo") == 0;
		}), items.end ());

	for (auto it = items.begin (), end = items.end (); it != end; ++it) {
		std::cout << *it << std::endl;
	}
}