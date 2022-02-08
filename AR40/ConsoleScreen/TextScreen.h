#pragma once
#include "ConsoleMath.h"

// ���� :
class TextScreen
{
public:
	int Width_;
	int Height_;
	char** PixelData_;
	char DefaultPixel_[3];

	// ȭ���� �׸� �Լ��� ����(����, ����, ä�� ����)
	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	// CreateScreen���� ������ ������ ȭ���� �׸�
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

