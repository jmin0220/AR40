#pragma once
#include <string>
#include <map>

// 설명 : 게임 자체의 시작점과 끝점, 실행중을 담당. 인터페이스만을 제공
class GameEngineLevel;
class GameEngine
{
public:
	// constrcuter destructer
	GameEngine();
	~GameEngine();

	// delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

protected:

private:
	// 퓨어 virtual
	// 게임 초기화
	virtual void GameInit() = 0;

	// 게임 실행
	virtual void GameLoop() = 0;

	// 게임 종료
	virtual void GameEnd() = 0;

	// 레벨 생성함수
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		//NewLevel->SetName(_Name);
		//NewLevel->Loading();
		//AllLevel_.insert(std::make_pair(_Name, NewLevel);
	}

	std::map<std::string, GameEngineLevel*> AllLevel_;
};

