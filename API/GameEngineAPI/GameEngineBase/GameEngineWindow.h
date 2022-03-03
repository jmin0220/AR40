#pragma once
#include <Windows.h>

// 설명 :
class GameEngineWindow
{
private:
	static GameEngineWindow* Inst_;

public:
	inline static GameEngineWindow& GetInst()
	{
		return *Inst_;
	}

	static GameEngineWindow& Destroy()
	{
		delete Inst_;
		Inst_ = nullptr;
	}

public:
	// 윈도우 생성
	void CreateGameWindow(HINSTANCE hInstance);
	// 윈도우 보여주기
	void ShowGameWindow();

protected:

private:
	HWND hWnd_;

	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;
};

