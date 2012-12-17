#include <vector>
#include <iostream>

int main ()
{
	std::vector<std::vector<std::pair<int, int>>> nestedVector;

	nestedVector.push_back (std::vector<std::pair<int, int>> ());
	nestedVector [0].push_back (std::make_pair (23, 42));

	for (auto it = nestedVector.begin (), end = nestedVector.end (); it != end; ++it) {
		for (auto jit = it->begin (), jend = it->end (); jit != jend; ++jit) {
			std::cout << jit->first << ", " << jit->second << std::endl;
		}
	}
}