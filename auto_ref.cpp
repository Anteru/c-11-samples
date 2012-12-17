#include <iostream>

struct Object
{
	Object (const Object& object)
	{
		std::cout << "Copy-Constructor" << std::endl;
	}

	Object ()
	{
		std::cout << "Constructor" << std::endl;
	}

	Object& operator= (const Object& rhs)
	{
		std::cout << "Assignment" << std::endl;
		return *this;
	}
};

class Container
{
public:
	const Object& Get () const
	{
		return object_;
	}

private:
	Object object_;
};

int main ()
{
	std::cout << "Start" << std::endl;
	Container c;

	std::cout << "---" << std::endl;
	auto o = c.Get ();

	std::cout << "---" << std::endl;
	const auto& oc = c.Get ();

	std::cout << "End" << std::endl;
}