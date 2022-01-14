#include<iostream>

// 3번
void CharChange(char* input, char a, char b)
{
	// a문자와 같다면 b문자로 교체. 다른 문자는 그대로.
	for (int i = 1; input[i] != 0; i++)
	{
		if (input[i] == a)
		{
			input[i] = b;
		}
	}
}

int main()
{
	char Text[100] = "aa, bb, cc, dd--";

	CharChange(Text, ',', '+');
	// aa| bb| cc| dd

	printf_s(Text);

	CharChange(Text, '+', '!');
	printf_s(Text);

	return 0;
}