#include <memory>

struct ILogTarget
{
	virtual ~ILogTarget ()
	{
	}
};

ILogTarget* CreateFileTarget ()
{
	class FileTarget : public ILogTarget
	{

	};

	return new FileTarget ();
}

ILogTarget* CreateConsoleTarget ()
{
	class ConsoleTarget : public ILogTarget
	{

	};

	return new ConsoleTarget ();
}

int main ()
{
	// ohoh
	auto logTarget = CreateConsoleTarget ();

	// better
	std::shared_ptr<ILogTarget> logSP (CreateConsoleTarget ());

	// Best solution: See unique_ptr_fix
}