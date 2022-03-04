#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    // ��üũ
    GameEngineDebug::LeakCheckOn();

    // ������ ����
    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "GameWIndow");

    // ������ �����ֱ�
    GameEngineWindow::GetInst().ShowGameWindow();

    GameEngineWindow::Destroy();
}