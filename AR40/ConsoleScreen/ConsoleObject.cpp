#include "ConsoleObject.h"

ConsoleObject::ConsoleObject()
{

}

ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
)
	: Screen_(_Screen)
	, Pos_(_Pos)
{
	SetRenderChar(_Text);
}

ConsoleObject::~ConsoleObject()
{
}

// 캐릭터 렌더링
void ConsoleObject::Render()
{
	if (nullptr == Screen_)
	{
		assert(false);
	}

	Screen_->SetPixel(Pos_, Text_);
}

// 그려야할 캐릭터의 렌더데이터 설정
void ConsoleObject::SetRenderChar(const char* _Text)
{

	if (nullptr == _Text)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}