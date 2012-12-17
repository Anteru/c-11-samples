class Test
{
public:
	Test () = default;
	Test (const Test& t) = delete;
	Test& operator= (const Test& t) = delete;
};

int main ()
{
	Test t;
	// nope
	t = Test ();
}