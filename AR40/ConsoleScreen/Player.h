#pragma once
#include"ConsoleMath.h"

// ���� :
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
	// �÷��̾��� ��ġ
	ConsoleVector Pos;

	// �÷��̾��� ǥ������(��)
	char Text[3];
};

