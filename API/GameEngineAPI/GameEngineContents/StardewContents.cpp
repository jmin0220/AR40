#include "StardewContents.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "EndingLevel.h"

StardewContents::StardewContents() 
{
}

StardewContents::~StardewContents() 
{
}

void StardewContents::GameInit()
{
	// ���� ����
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");

	// ���� ����
	ChangeLevel("Title");
}

void StardewContents::GameLoop()
{

}

void StardewContents::GameEnd()
{

}