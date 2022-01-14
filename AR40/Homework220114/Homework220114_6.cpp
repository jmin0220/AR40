#include<iostream>

// 6번
void TextChange(char* _Text, const char* _Prev, const char* _Next)
{
	int lengthPrev = 0;
	int lengthNext = 0;
	int gapPrevNext = 0;

	// 교체될 문자열의 길이
	for (int i = 0; _Prev[i] != 0; i++)
	{
		lengthPrev++;
	}

	// 교체할 문자열의 길이
	for (int i = 0; _Next[i] != 0; i++)
	{
		lengthNext++;
	}

	// 길이의 차이를 저장
	if (lengthNext < lengthPrev)
	{
		gapPrevNext = lengthPrev - lengthNext;
	}
	else
	{
		gapPrevNext = lengthNext -lengthPrev;
	}

	for (int i = 0; _Text[i] != 0; i++)
	{

	}
}

int main()
{
	char Text[100] = "aa, bb, aa, bb aa aa aa aaaaaaa ccdffeds";

	TextChange(Text, "aa", "fff");
	// "fff, bb, fff, bb fff fff fff fffffffffa ccdffeds";
	// aa| bb| cc| dd
	printf_s(Text);

	return 0;
}