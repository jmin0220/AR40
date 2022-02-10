#include "Player.h"
#include <conio.h>
#include "ConsoleGlobalInst.h"

Player::Player(TextScreen* _Screen, const char* _Text)
	: ConsoleObject(_Screen, _Text, _Screen->GetSize().GetHalfVector())
{

}

Player::~Player() 
{
}

void Player::Update()
{
	// 키보드입력을 대기
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		SetMove({ -1, 0 });
		break;
	case 'd':
	case 'D':
		SetMove({ 1, 0 });
		break;
	case 'w':
	case 'W':
		SetMove({ 0, -1 });
		break;
	case 's':
	case 'S':
		SetMove({ 0, 1 });
		break;
	// 게임이 종료된다.
	case 'q':
	case 'Q':
		assert(false);
		break;
	default:
		break;
	}
}