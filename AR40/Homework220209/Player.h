#pragma once
#include "ConsoleMath.h"
#include "TextScreen.h"

// 설명 :
class Player
{
public:
	// constrcuter destructer
	Player(TextScreen* _Screen, const char* _Text);
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	ConsoleVector GetPos()
	{
		return Pos_;
	}

	void SetPos(ConsoleVector _Value)
	{
		Pos_ = _Value;
	}

	void Render();
	void Update();

protected:

private:
	// Has a
	// 플레이어가 스크린의 데이터를 가지게 함.
	TextScreen* Screen_;
	
	// 플레이어의 위치
	ConsoleVector Pos_;

	// 플레이어의 표시정보(★)
	char Text_[3];
};

