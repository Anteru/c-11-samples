#include <functional>
#include <iostream>

void Process (const int count,
	std::function<void (const int processed)> callback)
{
	for (int i = 0; i < count; ++i) {
		callback (i);
	}
}

struct ProgressHandler
{
	ProgressHandler (const int total)
	: total_ (total)
	{
	}

	void Print (const int finished) const
	{
		std::cout << finished << "/" << total_ << std::endl;
	}

	int total_;
};

int main ()
{
	ProgressHandler progress (23);
	// Bind to member function "Print" of object instance "progress"
	// First parameter is passed through
	Process (23, std::bind (
		&ProgressHandler::Print, &progress, std::placeholders::_1));
}