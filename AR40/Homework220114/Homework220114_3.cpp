#include<iostream>

// 3��
void CharChange(char* input, char a, char b)
{
	// a���ڿ� ���ٸ� b���ڷ� ��ü. �ٸ� ���ڴ� �״��.
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