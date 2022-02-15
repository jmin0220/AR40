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

void Player::PlayerMove(ConsoleVector _Vector)
{
	int PlayerMoveX = (GetPos() + _Vector).x_;
	int PlayerMoveY = (GetPos() + _Vector).y_;

	int ScreenX = GlobalStatic::MainScreen.GetSize().x_;
	int ScreenY = GlobalStatic::MainScreen.GetSize().y_;

	if (0 > PlayerMoveX)
	{
		return;
	}

	if (0 > PlayerMoveY)
	{
		return;
	}

	if (PlayerMoveX >= ScreenX)
	{
		return;
	}

	if (PlayerMoveY >= ScreenY)
	{
		return;
	}

	// ���� ������ ���� ���Ͱ� �־�!
	Monster* FindMonster =
		GlobalStatic::GetMonster({ PlayerMoveX , PlayerMoveY });

	if (nullptr != FindMonster)
	{
		FindMonster->Death();
		return;
	}

	SetMove(_Vector);
}

int Player::Update()
{
	// Ű�����Է��� ���
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		PlayerMove({ -1, 0 });
		break;
	case 'd':
	case 'D':
		PlayerMove({ 1, 0 });
		break;
	case 'w':
	case 'W':
		PlayerMove({ 0, -1 });
		break;
	case 's':
	case 'S':
		PlayerMove({ 0, 1 });
		break;
	// ������ ����ȴ�.
	case 'q':
	case 'Q':
		return -1;
		break;
	default:
		break;
	}

	return 1;
}