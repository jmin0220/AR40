#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 스택에 n바이트가 할당되었을것이다
    TextScreen NewScreen(10, 10, "ㅁ");

    Player NewPlayer(&NewScreen, "★");

    NewScreen.SettingScreen();

    while (true)
    {
        NewScreen.SettingScreen();
        NewPlayer.Render();
        NewScreen.PrintScreen();
        NewPlayer.Update();
    }
}
