#pragma once
#include <Windows.h>
#include <string>

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

	static void Destroy()
	{
		if (Inst_ != nullptr)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}

public:
	void RegClass(HINSTANCE _hInst);
	// 윈도우 생성
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title);
	// 윈도우 보여주기
	void ShowGameWindow();
	// 메세지 입력대기
	void MessageLoop(void(*_LoopFunction)());

	// 윈도우 종료
	void Off();

	static inline HDC GETDC()
	{
		return Inst_->HDC_;
	}

protected:

private:
	// 프로그램 타이틀
	std::string Title_;
	// 윈도우 On/Off
	bool WindowOn_;

	// 윈도우 인스턴스
	HINSTANCE hInst_;
	// 윈도우 핸들
	HWND hWnd_;

	// 그리기
	HDC HDC_;

	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;
};

