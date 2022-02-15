#pragma once
#include "ConsoleMath.h"
#include "TextScreen.h"
#include "ConsoleObject.h"

// ���� :
class Player : public ConsoleObject
{
public:
	// constrcuter destructer
	Player();
	Player(TextScreen* _Screen, const char* _Text);
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	int Update();

protected:

private:
	void PlayerMove(ConsoleVector _Vector);
};

