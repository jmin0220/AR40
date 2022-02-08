#pragma once
#include "ConsoleMath.h"

// 설명 :
class TextScreen
{
public:
	int Width_;
	int Height_;
	char** PixelData_;
	char DefaultPixel_[3];

	// 화면을 그릴 함수를 선언(세로, 가로, 채울 문자)
	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	// CreateScreen에서 설정된 값으로 화면을 그림
	void PrintScreen();


	// constrcuter destructer
	TextScreen();
	~TextScreen();

	// delete Function
	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;

	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _X, int _Y, const char* _DefaultValue);
protected:

private:

};

