#pragma once
#include "ConsoleObject.h"

class GlobalStatic;

class Monster : public ConsoleObject
{
public:
	friend GlobalStatic;

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	void Update();

	// 모든 몬스터의 숫자를 취득
	static unsigned int GetAllMonsterCount();

protected:

private:
	// constrcuter destructer
	Monster();
	Monster(const char* _Text, const ConsoleVector& _Pos);
	~Monster();

	static unsigned int AllMonsterCount_;
};