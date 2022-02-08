#include<iostream>
#include "TextScreen.h"

TextScreen::TextScreen()
	: PixelData_(nullptr)
	, Width_(0)
	, Height_(0)
	, DefaultPixel_() // 사실 해줄필요가 없다.
{
}

TextScreen::~TextScreen() 
{
	// PixelData_를 초기화
	// 이중포인터이므로 배열을 먼저 순서대로 초기화 후, PixelData_를 마지막으로 초기화.
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
	// 매개변수로 받은 값을 객체의 변수에 저장하여 보존
	Width_ = _Width;
	Height_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	// 채울 문자열은 2바이트의 ㅁ이므로, 실제 세로 길이는 2배의 배수로 설정함
	int RealWidth = Width_ * 2;
	// \n과 null 추가용
	RealWidth += 2;

	// 가로세로의 전체 크기를 2차원배열로 초기화
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
		// 세로 줄 그리기
		for (int j = 0; j < Width_; j++)
		{
			// ㅁ 1개 그리기
			for (int k = 0; k < 2; k++)
			{
				PixelData_[i][(j * 2) + k] = DefaultPixel_[k];
			}
		}

		// 각 배열의 끝에 줄바꿈과 null을 삽입
		PixelData_[i][(Width_ * 2)] = '\n';
		PixelData_[i][(Width_ * 2) + 1] = 0;
	}

	// 줄그리기
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