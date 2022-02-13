#include "ConsoleGlobalInst.h"

TextScreen GlobalStatic::MainScreen(10, 10, "ㅁ");
Monster* GlobalStatic::AllMonsters = nullptr;
Player GlobalStatic::MainPlayer(&MainScreen, "★");

// 몬스터 메모리 해제
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
		// 만들 몬스터 객체를 취득
		Monster* IndexMonster = GlobalStatic::GetMonster(i);
		// 몬스터 렌더링
		IndexMonster->SetRenderChar(_Text);
		// 몬스터 위치 설정
		IndexMonster->SetPos({ i, 0 });
	}
}

Monster* GlobalStatic::GetMonster(unsigned int _Index)
{
	// 몬스터 수 범위 바깥의 인덱스를 참조하려 할 경우
	if (_Index >= Monster::GetAllMonsterCount())
	{
		return nullptr;
	}

	// 몬스터 객체 반환
	return &AllMonsters[_Index];
}