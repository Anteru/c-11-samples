#include <memory>

struct ILogTarget
{
	virtual ~ILogTarget ()
	{
	}
};

std::unique_ptr<ILogTarget> CreateFileTarget ()
{
	class FileTarget : public ILogTarget
	{

	};

	return std::unique_ptr<ILogTarget> (new FileTarget ());
}

std::unique_ptr<ILogTarget> CreateConsoleTarget ()
{
	class ConsoleTarget : public ILogTarget
	{

	};

	return std::unique_ptr<ILogTarget> (new ConsoleTarget ());
}

int main ()
{
	// ok
	auto logTarget = CreateConsoleTarget ();

	// also possible
	std::shared_ptr<ILogTarget> sharedLog (CreateConsoleTarget ());
}