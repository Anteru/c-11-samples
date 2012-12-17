#include <iostream>

#define ALLOW_MOVE 1

class Object
{
public:
	Object (const Object& object)
	: count_ (object.count_)
	{
		data_ = new int [count_];

		for (int i = 0; i < count_; ++i) {
			data_ [i] = object.data_ [i];
		}

		std::cout << "Copy-Constructor" << std::endl;
	}

#if ALLOW_MOVE
	Object (Object&& object)
	: count_ (object.count_)
	{
		data_ = object.data_;
		object.count_ = 0;
		object.data_ = nullptr;

		std::cout << "Move-Constructor" << std::endl;
	}
#endif

	Object (const int count)
	: count_ (count)
	{
		data_ = new int [count];

		std::cout << "Constructor" << std::endl;
	}

	Object& operator= (const Object& rhs)
	{
		delete [] data_;
		count_ = rhs.count_;
		data_ = new int [count_];

		for (int i = 0; i < count_; ++i) {
			data_ [i] = rhs.data_ [i];
		}

		std::cout << "Copy-Assignment" << std::endl;
		return *this;
	}

#if ALLOW_MOVE
	Object& operator= (Object&& rhs)
	{
		delete [] data_;
		count_ = rhs.count_;
		data_ = rhs.data_;

		rhs.data_ = nullptr;
		rhs.count_ = 0;

		std::cout << "Move-Assignment" << std::endl;
		return *this;
	}
#endif

	~Object ()
	{
		delete [] data_;
	}

	int GetCount () const
	{
		return count_;
	}

	int operator [] (const int index) const
	{
		return data_ [index];
	}

	int& operator [] (const int index)
	{
		return data_ [index];
	}

private:
	int* data_;
	int count_;
};

Object MakeObject ()
{
	Object o (4);
	o [0] = 3;
	o [1] = 5;
	o [2] = 7;
	o [3] = 11;

	return o;
}

int main ()
{
	Object o (23);

	o = MakeObject ();
}