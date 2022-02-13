#include <iostream>
#include <crtdbg.h>
#include "TextScreen.h"
#include "Player.h"
#include "Monster.h"
#include "ConsoleGlobalInst.h"

int main()
{
    // 메모리릭 검출
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 화면의 바탕 설정
    GlobalStatic::MainScreen.SettingScreen();

    // 몬스터 생성
    GlobalStatic::MonsterCreate(3, "■");

    while (true)
    {
        // 화면의 바탕설정
        GlobalStatic::MainScreen.SettingScreen();
        // 메인플레이어캐릭터 렌더
        GlobalStatic::MainPlayer.Render();

        for (size_t i = 0; i < Monster::GetAllMonsterCount(); i++)
        {
            Monster* IndexMonster = GlobalStatic::GetMonster(i);
            IndexMonster->Render();
        }

        GlobalStatic::MainScreen.PrintScreen();

        // 종료판단
        int Quit = GlobalStatic::MainPlayer.Update();

        if (Quit == -1)
        {
            break;
        }
        // NewMonster.Update();
    }

    // 해제
    GlobalStatic::Release;
}
