#include<iostream>

// 함수호출규약 키워드
// 모든 함수에는 붙어있음 -> 붙어있지않다면 생략되어있음

// __cdecl 전역함수에 자동으로 붙음
// 호출자와 피호출자간의 메모리 정리 규칙을 정의하고 있고 기계어적으로 조금 달라짐(자동으로 처리됨)
// __stdcall 

// (const char)         (* const)
// 바꿀 수 없는 char의    바꿀 수 있는 주소값
int __cdecl MyPrintf(const char* const _text)
{
	int count = 0;
	for (int i = 0; ; i++)
	{
		if (_text[i] == 0)
		{
			count = i;
			break;
		}

		putchar(_text[i]);
	}

	return count;
}

int main()
{
	{
		// (const char)         (* const)
		// 바꿀 수 없는 char의    바꿀 수 있는 주소값
		const int Value1 = 0;
		const int Value2 = 0;

		// const int형을 포인터로 저장가능 변경가능
		const int* aa = &Value1;
		aa = &Value2;

		// const int형을 포인터로 저장가능 변경불가능
		const int* const bb = &Value1;
		//bb = &Value2;
	}


	printf_s("aaa");
	MyPrintf("aaa");

	return 0;
}