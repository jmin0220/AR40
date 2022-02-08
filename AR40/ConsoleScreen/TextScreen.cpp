#include<iostream>
#include "TextScreen.h"

TextScreen::TextScreen()
	: PixelData_(nullptr)
	, Width_(0)
	, Height_(0)
	, DefaultPixel_() // ��� �����ʿ䰡 ����.
{
}

TextScreen::~TextScreen() 
{
	// PixelData_�� �ʱ�ȭ
	// �����������̹Ƿ� �迭�� ���� ������� �ʱ�ȭ ��, PixelData_�� ���������� �ʱ�ȭ.
	for (int i = 0; i < Height_; i++)
	{
		if (nullptr != PixelData_)
		{
			delete[] PixelData_[i];
			PixelData_[i] = nullptr;
		}
	}

	if (nullptr != PixelData_)
	{
		delete[] PixelData_;
		PixelData_ = nullptr;
	}
}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	// �Ű������� ���� ���� ��ü�� ������ �����Ͽ� ����
	Width_ = _Width;
	Height_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	// ä�� ���ڿ��� 2����Ʈ�� ���̹Ƿ�, ���� ���� ���̴� 2���� ����� ������
	int RealWidth = Width_ * 2;
	// \n�� null �߰���
	RealWidth += 2;

	// ���μ����� ��ü ũ�⸦ 2�����迭�� �ʱ�ȭ
	PixelData_ = new char* [Height_];

	for (int i = 0; i < Height_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}

void TextScreen::PrintScreen()
{
	int RealWidth = Width_ * 2;
	RealWidth += 1;

	for (int i = 0; i < Height_; i++)
	{
		// ���� �� �׸���
		for (int j = 0; j < Width_; j++)
		{
			// �� 1�� �׸���
			for (int k = 0; k < 2; k++)
			{
				PixelData_[i][(j * 2) + k] = DefaultPixel_[k];
			}
		}

		// �� �迭�� ���� �ٹٲް� null�� ����
		PixelData_[i][(Width_ * 2)] = '\n';
		PixelData_[i][(Width_ * 2) + 1] = 0;
	}

	// �ٱ׸���
	for (int y = 0; y < Height_; y++)
	{
		// char*
		printf_s(PixelData_[y]);
	}
}



void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	SetPixel(_Pos.X, _Pos.Y, _DefaultValue);
}

void TextScreen::SetPixel(int _X, int _Y, const char* _DefaultValue)
{

}