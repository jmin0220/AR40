#include<iostream>

// �Լ�ȣ��Ծ� Ű����
// ��� �Լ����� �پ����� -> �پ������ʴٸ� �����Ǿ�����

// __cdecl �����Լ��� �ڵ����� ����
// ȣ���ڿ� ��ȣ���ڰ��� �޸� ���� ��Ģ�� �����ϰ� �ְ� ���������� ���� �޶���(�ڵ����� ó����)
// __stdcall 

// (const char)         (* const)
// �ٲ� �� ���� char��    �ٲ� �� �ִ� �ּҰ�
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
		// �ٲ� �� ���� char��    �ٲ� �� �ִ� �ּҰ�
		const int Value1 = 0;
		const int Value2 = 0;

		// const int���� �����ͷ� ���尡�� ���氡��
		const int* aa = &Value1;
		aa = &Value2;

		// const int���� �����ͷ� ���尡�� ����Ұ���
		const int* const bb = &Value1;
		//bb = &Value2;
	}


	printf_s("aaa");
	MyPrintf("aaa");

	return 0;
}