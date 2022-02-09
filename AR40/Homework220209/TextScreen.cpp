#include<iostream>
#include "TextScreen.h"

TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	: PixelData_(nullptr)
	, Size_(0, 0)
	, DefaultPixel_() // ��� �����ʿ䰡 ����.
{
	CreateScreen(_Width, _Height, _DefaultValue);
}

TextScreen::~TextScreen() 
{
	// PixelData_�� �ʱ�ȭ
	// �����������̹Ƿ� �迭�� ���� ������� �ʱ�ȭ ��, PixelData_�� ���������� �ʱ�ȭ.
	for (int i = 0; i < Size_.y_; i++)
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
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	// ä�� ���ڿ��� 2����Ʈ�� ���̹Ƿ�, ���� ���� ���̴� 2���� ����� ������
	int RealWidth = Size_.x_ * 2;
	// \n�� null �߰�
	RealWidth += 2;

	// ���μ����� ��ü ũ�⸦ 2�����迭�� �ʱ�ȭ
	PixelData_ = new char* [Size_.y_];

	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}

// ȭ�鿡 �׸� �⺻ ������ ����
void TextScreen::SettingScreen()
{
	int RealWidth = Size_.x_ * 2;
	RealWidth += 1;

	for (int i = 0; i < Size_.y_; i++)
	{
		for (int j = 0; j < Size_.x_; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				PixelData_[i][(j * 2) + k] = DefaultPixel_[k];
			}
		}

		PixelData_[i][(Size_.x_ * 2)] = '\n';
		PixelData_[i][(Size_.x_ * 2) + 1] = 0;
	}
}

// ������ ȭ���� �׸��� �Լ�
void TextScreen::PrintScreen()
{
	system("cls");

	for (int i = 0; i < Size_.y_; i++)
	{
		printf_s(PixelData_[i]);
	}
}



void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}

// �÷��̾� ĳ������ �ȼ��� �׸���
void TextScreen::SetPixel(int _X, int _Y, const char* _DefaultValue)
{
	// �÷��̾��� ��ġ�� ���� �Ǵ� ȭ���� ������ ũ�⺸�� Ŭ ��� ���α׷��� ����
	if (Size_.x_ <= _X || Size_.y_ <= _Y || _X < 0 || _Y < 0)
	{
		assert(false);
	}

	for (int i = 0; i < 2; i++)
	{
		PixelData_[_Y][(_X * 2) + i] = _DefaultValue[i];
	}
}