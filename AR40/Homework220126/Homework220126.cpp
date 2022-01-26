#include<iostream>

class MyInt
{
public:
	int value;

public:
	MyInt(int _myInt)
		: value(_myInt)
	{
		
	}

public:
	MyInt& operator+=(const MyInt& _value)
	{
		this->value = this->value + _value.value;

		return *this;
	}

	MyInt& operator-=(const MyInt& _value)
	{
		this->value = this->value - _value.value;

		return *this;
	}


	// https://stackoverflow.com/questions/49711535/c2676-binary-does-not-define-this-operator
	MyInt& operator++() // prefix ++: no parameter, returns a reference
	{
		this->value = this->value + 1;

		return *this;
	}

	MyInt operator++(int _value) // postfix ++: dummy parameter, returns a value
	{
		_value = this->value;
		this->value = this->value + 1;

		return _value;
	}

	MyInt& operator--() // prefix ++: no parameter, returns a reference
	{
		this->value = this->value - 1;

		return *this;
	}

	MyInt operator--(int _value) // postfix ++: dummy parameter, returns a value
	{
		_value = this->value;
		this->value = this->value - 1;

		return _value;
	}
};

int main()
{
	MyInt a = 10 + 5;
	std::cout << "a > " << a.value << "\n";

	a += 10;
	std::cout << "a > " << a.value << "\n";

	a -= 10;
	std::cout << "a > " << a.value << "\n";

	// ++연산자
	MyInt b = ++a;
	std::cout << "a > " << a.value << "\n";
	std::cout << "b > " << b.value << "\n";

	// 실행 확인
	int aa = 15;
	int bb = ++aa;
	std::cout << "aa > " << a.value << "\n";
	std::cout << "bb > " << b.value << "\n";

	b = a++;
	std::cout << "a > " << a.value << "\n";
	std::cout << "b > " << b.value << "\n";

	// 실행 확인
	bb = aa++;
	std::cout << "aa > " << a.value << "\n";
	std::cout << "bb > " << b.value << "\n";

	// --연산자
	b = --a;
	std::cout << "a > " << a.value << "\n";
	std::cout << "b > " << b.value << "\n";

	// 실행 확인
	bb = --aa;
	std::cout << "aa > " << a.value << "\n";
	std::cout << "bb > " << b.value << "\n";

	b = a--;
	std::cout << "a > " << a.value << "\n";
	std::cout << "b > " << b.value << "\n";

	// 실행 확인
	bb = aa--;
	std::cout << "aa > " << a.value << "\n";
	std::cout << "bb > " << b.value << "\n";

	return 0;
}