#pragma once
#include <Windows.h>

// ���� :
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
	// ������ ����
	void CreateGameWindow(HINSTANCE hInstance);
	// ������ �����ֱ�
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

