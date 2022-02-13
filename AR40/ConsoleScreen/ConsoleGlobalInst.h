#pragma once
#include "TextScreen.h"
#include "Monster.h"
#include "Player.h"

//extern TextScreen MainScreen;
//extern Monster* AllMonsters;
//extern Player MainPlayer;

class GlobalStatic
{
public:
	static TextScreen MainScreen;
	static Player MainPlayer;

	// 몬스터 생성
	static void MonsterCreate(unsigned int _Count, const char* _Text);
	// 몬스터 메모리 해제
	static void Release();

	// 모든 몬스터의 정보를 취득
	static Monster* GetAllMonsters();
	// 1객체의 몬스터 정보를 취득
	static Monster* GetMonster(unsigned int _Index);

private:
	static Monster* AllMonsters;
};

