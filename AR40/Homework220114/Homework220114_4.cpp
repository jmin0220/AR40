#include<iostream>

// 4번
void Rervers(const char* input, char* _Result)
{
	int sizeInput = 0;

	// input의 길이 측정
	for (int i = 1; input[i] != 0; i++)
	{
		sizeInput++;
	}

	// 뒤집개
	for (int i = sizeInput; 0 <= i; i--)
	{
		_Result[sizeInput - i] = input[i];
	}
}

int main()
{
	char Text[100] = { };
	Rervers("01234567899876543210123456789", Text);

	printf_s(Text);

	return 0;
}