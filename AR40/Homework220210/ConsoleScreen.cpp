#include <iostream>
#include <crtdbg.h>
#include "TextScreen.h"
#include "Player.h"
#include "Monster.h"
#include "ConsoleGlobalInst.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    MainScreen.SettingScreen();

    while (true)
    {
        MainScreen.SettingScreen();
        MainPlayer.Render();
        // NewMonster.Render();
        MainScreen.PrintScreen();

        MainPlayer.Update();
        // NewMonster.Update();
    }
}
