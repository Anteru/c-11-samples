#include <iostream>

void Printf (std::ostream& str)
{
	str << std::endl;
}

template <typename T, typename ...Params>
void Printf (std::ostream& str, const T& value, Params&&... params)
{
	str << value << " ";
	Printf (str, params...);
}

int main ()
{
	Printf (std::cout, "bla", "foo", 23);
}