#include "ConsoleGlobalInst.h"

TextScreen GlobalStatic::MainScreen(10, 10, "��");
Monster* GlobalStatic::AllMonsters = nullptr;
Player GlobalStatic::MainPlayer(&MainScreen, "��");

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

	for (int i = 0; i < Monster::GetAllMonsterCount(); i++)
	{
		// ���� ���� ��ü�� ���
		Monster* IndexMonster = GlobalStatic::GetMonster(i);
		// ���� ������
		IndexMonster->SetRenderChar(_Text);
		// ���� ��ġ ����
		IndexMonster->SetPos({ i, 0 });
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