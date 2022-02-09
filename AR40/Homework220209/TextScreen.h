#pragma once
#include "ConsoleMath.h"
#include <assert.h>

// ���� :
class TextScreen
{
public:

	// constrcuter destructer
	TextScreen(int _Width, int _Height, const char* _DefaultValue);
	~TextScreen();

	// delete Function
	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;


	ConsoleVector GetSize()
	{
		return Size_;
	}

	// ȭ���� �׸� �Լ��� ����(����, ����, ä�� ����)
	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	void SettingScreen();

	// CreateScreen���� ������ ������ ȭ���� �׸�
	void PrintScreen();

	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _X, int _Y, const char* _DefaultValue);

protected:

private:
	ConsoleVector Size_;
	char** PixelData_;
	char DefaultPixel_[3];

};

