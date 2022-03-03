#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    // 윈도우 생성
    GameEngineWindow::GetInst().CreateGameWindow(hInstance);

    // 윈도우 보여주기
    GameEngineWindow::GetInst().ShowGameWindow();
}