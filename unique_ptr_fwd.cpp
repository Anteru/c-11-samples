#include <memory>
#include <iostream>

class Object
{
public:
	Object (const Object& object)
	{
		std::cout << "Copy-Constructor" << std::endl;
	}

	Object (Object&& object)
	{
		std::cout << "Move-Constructor" << std::endl;
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

// Use variadic template to perfect forward all parameters
template <typename T, typename U>
std::unique_ptr<T> make_unique (U&& u)
{
	return std::unique_ptr<T> (new T (std::forward<U> (u)));
}

Object MakeObject ()
{
	return Object ();
}

int main ()
{
	auto up = make_unique<Object> (MakeObject ());
}