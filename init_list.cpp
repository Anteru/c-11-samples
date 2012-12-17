#include <initializer_list>
#include <iostream>

template <typename T>
class Container
{
public:
	Container (const std::initializer_list<T>& d)
	: data_ (new T [d.size ()])
	, count_ (d.size ())
	{
		std::copy (d.begin (), d.end (), data_);
	}

	~Container ()
	{
		delete data_;
	}

	const T* begin () const
	{
		return data_;
	}

	const T* end () const
	{
		return data_ + count_;
	}

private:
	T* data_;
	size_t count_;
};

int main ()
{
	Container<int> c ({0, 8, 1, 5});

	for (auto i : c) {
		std::cout << i << std::endl;
	}
}