#pragma once
#include <string>
#include <map>

// ���� : ���� ��ü�� �������� ����, �������� ���. �������̽����� ����
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
	// ǻ�� virtual
	// ���� �ʱ�ȭ
	virtual void GameInit() = 0;

	// ���� ����
	virtual void GameLoop() = 0;

	// ���� ����
	virtual void GameEnd() = 0;

	// ���� �����Լ�
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

