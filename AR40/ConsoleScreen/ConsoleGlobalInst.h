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

	// ���� ����
	static void MonsterCreate(unsigned int _Count, const char* _Text);
	// ���� �޸� ����
	static void Release();

	// ��� ������ ������ ���
	static Monster* GetAllMonsters();
	// 1��ü�� ���� ������ ���
	static Monster* GetMonster(unsigned int _Index);

private:
	static Monster* AllMonsters;
};

