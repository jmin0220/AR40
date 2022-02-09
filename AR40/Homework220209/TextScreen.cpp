#include<iostream>
#include "TextScreen.h"

TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	: PixelData_(nullptr)
	, Size_(0, 0)
	, DefaultPixel_() // 사실 해줄필요가 없다.
{
	CreateScreen(_Width, _Height, _DefaultValue);
}

TextScreen::~TextScreen() 
{
	// PixelData_를 초기화
	// 이중포인터이므로 배열을 먼저 순서대로 초기화 후, PixelData_를 마지막으로 초기화.
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
	// 매개변수로 받은 값을 객체의 변수에 저장하여 보존
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	// 채울 문자열은 2바이트의 ㅁ이므로, 실제 세로 길이는 2배의 배수로 설정함
	int RealWidth = Size_.x_ * 2;
	// \n과 null 추가
	RealWidth += 2;

	// 가로세로의 전체 크기를 2차원배열로 초기화
	PixelData_ = new char* [Size_.y_];

	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}

// 화면에 그릴 기본 바탕을 설정
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

// 실제로 화면을 그리는 함수
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

// 플레이어 캐릭터의 픽셀을 그리기
void TextScreen::SetPixel(int _X, int _Y, const char* _DefaultValue)
{
	// 플레이어의 위치가 음수 또는 화면의 지정된 크기보다 클 경우 프로그램을 종료
	if (Size_.x_ <= _X || Size_.y_ <= _Y || _X < 0 || _Y < 0)
	{
		assert(false);
	}

	for (int i = 0; i < 2; i++)
	{
		PixelData_[_Y][(_X * 2) + i] = _DefaultValue[i];
	}
}