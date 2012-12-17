#include <iostream>

class BigFatData
{
};

class DataProcessor
{
public:
	void Consume (BigFatData&& data)
	{
		std::cout << "Win" << std::endl;
	}

	void Consume (const BigFatData& data)
	{
		std::cout << "Fail" << std::endl;
	}
};

void Process (DataProcessor& proc, BigFatData&& data)
{
	// Must use forward here, otherwise, the const T& overload is called
	proc.Consume (std::forward<BigFatData> (data));
}

BigFatData GetData ()
{
	return BigFatData ();
}

int main ()
{
	DataProcessor proc;
	Process (proc, GetData ());
}