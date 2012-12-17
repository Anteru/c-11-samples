#include <unordered_map>
#include <iostream>

struct MyType
{
	MyType (const int a, const int b)
	: a (a)
	, b (b)
	{
	}

	bool operator== (const MyType& rhs) const
	{
		return a == rhs.a && b == rhs.b;
	}

	int a, b;
};

std::ostream& operator<< (std::ostream& str, const MyType& t)
{
	return str << t.a << ", " << t.b;
}

namespace std {
	template <>
	struct hash <MyType>
	{
		size_t operator () (const MyType& t) const
		{
			// or use boost::hash_combine
			return std::hash<int> () (t.a) ^ std::hash<int> () (t.b);
		}
	};
}

int main ()
{
	std::unordered_map<MyType, int> hashMap;

	hashMap [MyType (23, 12)] = 1;
	hashMap [MyType (42, 17)] = 2;
	hashMap [MyType (13, 37)] = 3;
	hashMap [MyType (47, 11)] = 4;

	for (auto it = hashMap.begin (), end = hashMap.end (); it != end; ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
}