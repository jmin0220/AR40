#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>

// 설명 :
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject
{
public:
	friend GameEngineLevel;

	// constrcuter destructer
	GameEngineActor();
	~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

protected:
	virtual void Start() = 0;
	virtual void Update() {};
	virtual void Render() {};

private:
	// 현재 액터가 생성되어있는 레벨
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	// 액터가 생성된 레벨의 정보를 설정
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}
};

