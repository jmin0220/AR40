#pragma once
#include "TextScreen.h"
#include "Monster.h"
#include "Player.h"

extern TextScreen MainScreen;
extern Monster* AllMonsters;
extern Player MainPlayer;

class GlobalStatic
{
public:

	static TextScreen MainScreen;
	static Player MainPlayer;

	static void MonsterCreate(unsigned int _Count, const char* _Text);
	static void Release();

	// 몬스터는 절대로 중간에 삭제가 되어서는 안된다.
	// 지우면 안됩니다.
	static Monster* GetAllMonsters();

	static Monster* GetMonster(unsigned int _Index);

private:
	static Monster* AllMonsters;
};

