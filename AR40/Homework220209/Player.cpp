#include "Player.h"
#include <conio.h>

Player::Player(TextScreen* _Screen, const char* _Text)
	: Screen_(_Screen)
	, Pos_(_Screen->GetSize().GetHalfVector())
	// assert 테스트 코드
	//, Pos_(100, 100)
	//, Pos_(100, 0)
	//, Pos_(0, 10)
	//, Pos_(-1, 10)
	, Text_()
{
	if (nullptr == _Screen)
	{
		assert(false);
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}

Player::~Player() 
{
}

void Player::Update()
{
	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		Pos_.x_ -= 1;
		break;
	case 'd':
	case 'D':
		Pos_.x_ += 1;
		break;
	case 'w':
	case 'W':
		Pos_.y_ -= 1;
		break;
	case 's':
	case 'S':
		Pos_.y_ += 1;
		break;
	default:
		break;
	}


}

void Player::Render()
{
	Screen_->SetPixel(Pos_, Text_);
}