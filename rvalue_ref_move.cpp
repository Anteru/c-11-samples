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
		std::cout << "Copy-Assignment" << std::endl;
		return *this;
	}

	Object& operator= (Object&& rhs)
	{
		std::cout << "Move-Assignment" << std::endl;
		return *this;
	}

	~Object ()
	{
		std::cout << "Destructor" << std::endl;
	}
};

void Consume (Object&& object)
{
	Object obj (std::forward<Object> (object));
}

int main ()
{
	Object o;

	// Must use std::move here to actually move the object
	Consume (std::move (o));

	std::cout << "After consume" << std::endl;
}