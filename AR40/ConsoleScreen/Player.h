#pragma once
#include"ConsoleMath.h"

// 설명 :
class Player
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	ConsoleVector GetPos()
	{
		return Pos;
	}

protected:

private:
	// 플레이어의 위치
	ConsoleVector Pos;

	// 플레이어의 표시정보(★)
	char Text[3];
};

