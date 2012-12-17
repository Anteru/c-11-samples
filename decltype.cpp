#include <iostream>
#include <type_traits>

template <typename T>
class Wrapper
{
private:
	T t_;

public:
	Wrapper (const T t)
	: t_ (t)
	{
	}

	typedef T Type;

	template <typename U>
	auto operator* (const U u) -> Wrapper<decltype (T() * U())>
	{
		typedef decltype(T() * U()) ResultType;

		const auto result = u * t_;
		return Wrapper<ResultType> (result);
	}

	T Get () const
	{
		return t_;
	}
};

int main ()
{
	Wrapper<int> iWrap (23);
	// result is now of type Wrapper<float>
	const auto result = iWrap * 2.37f;

	std::cout << result.Get () << std::endl;
}