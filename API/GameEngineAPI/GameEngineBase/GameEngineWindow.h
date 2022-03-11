#pragma once
#include <Windows.h>
#include <string>

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
	// ������ ����
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title);
	// ������ �����ֱ�
	void ShowGameWindow();
	// �޼��� �Է´��
	void MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)());

	// ������ ����
	void Off();

	static inline HDC GETDC()
	{
		return Inst_->HDC_;
	}

protected:

private:
	// ���α׷� Ÿ��Ʋ
	std::string Title_;
	// ������ On/Off
	bool WindowOn_;

	// ������ �ν��Ͻ�
	HINSTANCE hInst_;
	// ������ �ڵ�
	HWND hWnd_;

	// �׸���
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

