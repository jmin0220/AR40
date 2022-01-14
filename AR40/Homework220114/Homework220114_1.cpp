#include<iostream>

// 1¹ø
void ToUpper(const char* _Left, char* _Right)
{
	for (int i = 0; _Left[i] != 0 ; i++)
	{
		if (97 <= _Left[i] && _Left[i] <= 122)
		{
			_Right[i] = _Left[i] - 32;
		}
		else
		{
			_Right[i] = _Left[i];
		}
	}
}

int main()
{
	char Text[100] = {};

	ToUpper("asdfoihloiuwahfliuewbai!;1231467ÇÑ±Û", Text);

	printf_s(Text);

	return 0;
}