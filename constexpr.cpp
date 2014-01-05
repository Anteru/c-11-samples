constexpr int Add (const int a, const int b)
{
	return a + b;
}

int main ()
{
	// Only valid because constexpr can be evaluated at compile time
	char buffer [Add (256, 128)] = {0};
}
