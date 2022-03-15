#include "GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineLevel.h"

std::map<std::string, GameEngineLevel*> GameEngine::AllLevel_;
GameEngineLevel* GameEngine::CurrentLevel_ = nullptr;
GameEngineLevel* GameEngine::NextLevel_    = nullptr;
GameEngine*      GameEngine::UserContents_ = nullptr;

GameEngine::GameEngine() 
{
}

GameEngine::~GameEngine() 
{
}

void GameEngine::GameInit() 
{

}

void GameEngine::GameLoop()
{

}

void GameEngine::GameEnd()
{

}

// 윈도우 창 생성
void GameEngine::WindowCreate()
{
	GameEngineWindow::GetInst().CreateGameWindow(nullptr, "GameWindow");
	GameEngineWindow::GetInst().ShowGameWindow();
	GameEngineWindow::GetInst().MessageLoop(EngineInit, EngineLoop);
}

void GameEngine::EngineInit()
{
	UserContents_->GameInit();
}

void GameEngine::EngineLoop()
{
	// 1프레임
	UserContents_->GameLoop();

	// 레벨 전환
	if (nullptr != NextLevel_)
	{
		if (nullptr != CurrentLevel_)
		{
			CurrentLevel_->SceneChangeEnd();
		}

		CurrentLevel_ = NextLevel_;

		if (nullptr != CurrentLevel_)
		{
			CurrentLevel_->SceneChangeStart();
		}

		NextLevel_ = nullptr;
	}

		// 에러 판정
	if (nullptr == CurrentLevel_)
	{
		MsgBoxAssert("Current Level is NULL => GameEngine Loop Error");
	}

	CurrentLevel_->Update();
	CurrentLevel_->ActorUpdate();
	CurrentLevel_->ActorRender();
}

// 프로그램 종료
void GameEngine::EngineEnd()
{
	UserContents_->GameEnd();

	std::map<std::string, GameEngineLevel*>::iterator StartIter = AllLevel_.begin();
	std::map<std::string, GameEngineLevel*>::iterator EndIter  = AllLevel_.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr == StartIter->second)
		{
			continue;
		}

		delete StartIter->second;
	}

	GameEngineWindow::Destroy();
}

// 레벨 전환
void GameEngine::ChangeLevel(const std::string& _Name)
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevel_.find(_Name);

	if (AllLevel_.end() == FindIter)
	{
		MsgBoxAssert("Level Find Error");
		return;
	}

	NextLevel_ = FindIter->second;
}