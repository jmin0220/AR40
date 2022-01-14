#include<iostream>
#include<math.h>

// 2번
int ToInt(const char* input)
{
	int value = 0;
	int sizeInput = 0;

		
	/* 문자 -> 정수
	48 0
	49 1
	50 2
	51 3
	52 4
	53 5
	54 6
	55 7
	56 8
	57 9
	*/


	// input의 길이 측정
	for (int i = 1; input[i] != 0; i++)
	{
		sizeInput++;
	}


	// 정수형으로 변환
	// 정수형 += 숫자 * 10^자릿수
	for (int i = 0; input[i] != 0; i++)
	{
		switch (input[i])
		{
		case 48:
			value += 0 * pow(10, (sizeInput - i));
			break;
		case 49:
			value += 1 * pow(10, (sizeInput - i));
			break;
		case 50:
			value += 2 * pow(10, (sizeInput - i));
			break;
		case 51:
			value += 3 * pow(10, (sizeInput - i));
			break;
		case 52:
			value += 4 * pow(10, (sizeInput - i));
			break;
		case 53:
			value += 5 * pow(10, (sizeInput - i));
			break;
		case 54:
			value += 6 * pow(10, (sizeInput - i));
			break;
		case 55:
			value += 7 * pow(10, (sizeInput - i));
			break;
		case 56:
			value += 8 * pow(10, (sizeInput - i));
			break;
		case 57:
			value += 9 * pow(10, (sizeInput - i));
			break;
		default:
			break;
		}
	}

	return value;
}



int main()
{
	int value = 0;

	value = ToInt("1209481904");
	//      25815          문자열->정수형으로 변환

	std::cout << value;

	return 0;
}