#include <iostream>

using namespace std;

class A
{
public:
	A() {}
	~A() {}
public:
	virtual void Parent()
	{
		cout << "Parent" << endl;
	}
};

class B : public A
{
public:
	B() {}
public:
	virtual void Parent() override
	{
		cout << "ChildeB" << endl;
	}
};

class C : public A
{

public:
	C() {}
	virtual void Parent() override
	{
		cout << "ChildeC" << endl;
	}
};

int main()
{
	A* test = new B;

	test->Parent();


	test = new C;

	test->Parent();


	test = new A;
	test->Parent();
}
