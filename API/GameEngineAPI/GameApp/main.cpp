#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineContents/StardewContents.h>

StardewContents MyGame;

// �ؽ��� �ε� �غ� ������Ʈ �������
void GameInit()
{

}


// ���� ����
void GameLoop()
{
    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);
}

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

    GameEngineWindow::GetInst().MessageLoop(nullptr, GameLoop);

    GameEngineWindow::Destroy();

    MyGame.GameEnd();
}