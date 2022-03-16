#include "GameEngineActor.h"
#include <GameEngineBase/GameEngineWindow.h>

GameEngineActor::GameEngineActor() 
	: Level_(nullptr)
{
}

GameEngineActor::~GameEngineActor() 
{
}


void GameEngineActor::DebugRectRender()
{
	GameEngineRect DebugRect(Position_, Scale_);

	Rectangle(
		GameEngineWindow::GetHDC(), 
		DebugRect.CenterLeft(),
		DebugRect.CenterTop(),
		DebugRect.CenterRight(),
		DebugRect.CenterBot()
	);
}