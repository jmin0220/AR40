#include<iostream>

void StringTrimRemove(const char* inputString, char* outputString)
{
	int trimCount = 0;

	for (int i = 0; ; i++)
	{
		if (inputString[i] == 0)
		{
			break;
		}

		if (inputString[i] != ' ')
		{
			outputString[trimCount] = inputString[i];
			trimCount++;
		}
	}
}


int main()
{
	char stringA[1024] = {};
	char inputString[1024] = "The Quick Brown Fox Jumps Over The Lazy Dog";

	StringTrimRemove(inputString, stringA);

	printf_s(inputString);
	printf_s(stringA);

	return 0;
}