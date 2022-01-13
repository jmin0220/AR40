#include<iostream>

int main()
{
	int Arr[10] = {};
	int Index = 0;
	int i = 0;

	while (i < 10)
	{
		// 0부터 시작해서
		// 배열이 가득찰때까지 짝수로만 채워주세요
		if (Index % 2 == 0)
		{
			Arr[i] = Index;
			i++;
		}

		Index++;
	}

	// 브레이크 포인트 용
	int a = 1;

	i = 0;
	Index = 0;
	while (i < 10)
	{
		// 0부터 시작해서
		// 배열이 가득찰때까지 홀수로만 채워주세요
		if (Index % 2 == 1)
		{
			Arr[i] = Index;
			i++;
		}

		Index++;
	}

	// 브레이크 포인트 용
	int b = 1;
}