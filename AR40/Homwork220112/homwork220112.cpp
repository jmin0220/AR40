#include<iostream>

int main()
{
	int Arr[10] = {};
	int Index = 0;
	int i = 0;

	while (i < 10)
	{
		// 0���� �����ؼ�
		// �迭�� ������������ ¦���θ� ä���ּ���
		if (Index % 2 == 0)
		{
			Arr[i] = Index;
			i++;
		}

		Index++;
	}

	// �극��ũ ����Ʈ ��
	int a = 1;

	i = 0;
	Index = 0;
	while (i < 10)
	{
		// 0���� �����ؼ�
		// �迭�� ������������ Ȧ���θ� ä���ּ���
		if (Index % 2 == 1)
		{
			Arr[i] = Index;
			i++;
		}

		Index++;
	}

	// �극��ũ ����Ʈ ��
	int b = 1;
}