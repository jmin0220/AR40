#include <iostream>
#include <crtdbg.h>
#include "TextScreen.h"
#include "Player.h"
#include "Monster.h"
#include "ConsoleGlobalInst.h"

int main()
{
    // �޸𸮸� ����
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // ȭ���� ���� ����
    GlobalStatic::MainScreen.SettingScreen();

    // ���� ����
    GlobalStatic::MonsterCreate(3, "��");

    while (true)
    {
        // ȭ���� ��������
        GlobalStatic::MainScreen.SettingScreen();
        // �����÷��̾�ĳ���� ����
        GlobalStatic::MainPlayer.Render();

        for (size_t i = 0; i < Monster::GetAllMonsterCount(); i++)
        {
            Monster* IndexMonster = GlobalStatic::GetMonster(i);
            IndexMonster->Render();
        }

        GlobalStatic::MainScreen.PrintScreen();

        // �����Ǵ�
        int Quit = GlobalStatic::MainPlayer.Update();

        if (Quit == -1)
        {
            break;
        }
        // NewMonster.Update();
    }

    // ����
    GlobalStatic::Release;
}
