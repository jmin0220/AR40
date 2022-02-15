#include "ConsoleGlobalInst.h"
#include "ConsoleRandom.h"
#include <time.h>

TextScreen GlobalStatic::MainScreen(10, 10, "ㅁ");
Monster* GlobalStatic::AllMonsters = nullptr;
Player GlobalStatic::MainPlayer(&MainScreen, "★");

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

	ConsoleRandom Random = ConsoleRandom(time(nullptr));

	for (int i = 0; i < Monster::GetAllMonsterCount(); i++)
	{
		// 만들 몬스터 객체를 취득
		Monster* IndexMonster = GlobalStatic::GetMonster(i);
		// 몬스터 렌더링
		IndexMonster->SetRenderChar(_Text);
		// 몬스터 위치 설정
		IndexMonster->SetPos(
			{ (int)Random.Next(MainScreen.GetSize().x_),
			(int)Random.Next(MainScreen.GetSize().y_) });
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