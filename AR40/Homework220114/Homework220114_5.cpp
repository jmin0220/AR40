#include<iostream>

// 5번
void Cut(const char* _Sorce, int _Start, int _End, char* _Result)
{
	// 결과배열 저장용 변수
	int j = 0;

	for (int i = _Start; i <= _End; i++)
	{
		_Result[j] = _Sorce[i];
		j++;
	}
}

int main()
{
	char Text[100] = { };
	Cut("0123456789", 2, 7, Text);
	// "234567"

	printf_s(Text);

	return 0;
}