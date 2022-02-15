#include "ConsoleGlobalInst.h"
#include "ConsoleRandom.h"
#include <time.h>

TextScreen GlobalStatic::MainScreen(10, 10, "��");
Monster* GlobalStatic::AllMonsters = nullptr;
Player GlobalStatic::MainPlayer(&MainScreen, "��");

Monster* GlobalStatic::GetMonster(const ConsoleVector& _Pos)
{
	for (size_t i = 0; i < Monster::GetAllMonsterCount(); i++)
	{
		if (AllMonsters[i].GetPos() == _Pos
			&& AllMonsters[i].GetIsDeath() == false)
		{
			return &AllMonsters[i];
		}
	}

	return nullptr;
}

// ���� �޸� ����
void GlobalStatic::Release()
{
	if (nullptr != AllMonsters)
	{
		delete[] AllMonsters;
		AllMonsters = nullptr;
	}
}

void GlobalStatic::MonsterCreate(unsigned int _Count, const char* _Text)
{
	AllMonsters = new Monster[_Count];

	ConsoleRandom Random = ConsoleRandom(time(nullptr));

	for (int i = 0; i < Monster::GetAllMonsterCount(); i++)
	{
		// ���� ���� ��ü�� ���
		Monster* IndexMonster = GlobalStatic::GetMonster(i);
		// ���� ������
		IndexMonster->SetRenderChar(_Text);
		// ���� ��ġ ����
		IndexMonster->SetPos(
			{ (int)Random.Next(MainScreen.GetSize().x_),
			(int)Random.Next(MainScreen.GetSize().y_) });
	}
}

Monster* GlobalStatic::GetMonster(unsigned int _Index)
{
	// ���� �� ���� �ٱ��� �ε����� �����Ϸ� �� ���
	if (_Index >= Monster::GetAllMonsterCount())
	{
		return nullptr;
	}

	// ���� ��ü ��ȯ
	return &AllMonsters[_Index];
}