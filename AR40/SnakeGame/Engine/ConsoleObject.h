#pragma once
#include "ConsoleMath.h"
#include "ConsoleScreen.h"



// 설명 :
class ConsoleObject
{
public:
	ConsoleObject();

	// constrcuter destructer
	ConsoleObject(
		const char* _Text, 
		const ConsoleVector& _Pos);

	// ConsoleObject* NewHead = new Head(); 처럼 자식클래스를 동적으로 부모클래스 포인터를 선언할때는, 
	// delete NewHead의 형태로 삭제할 경우 자식의 클래스만 삭제됨.
	// 오버라이딩을 위하여 부모/자식의 소멸자를 virtual로 선언하면 부모/자식클래스가 모두 소멸됨.
	virtual ~ConsoleObject();

	// delete Function
	ConsoleObject(const ConsoleObject& _Other) = delete;
	ConsoleObject(ConsoleObject&& _Other) noexcept = delete;
	ConsoleObject& operator=(const ConsoleObject& _Other) = delete;
	ConsoleObject& operator=(ConsoleObject&& _Other) noexcept = delete;

	inline ConsoleVector GetPos() const
	{
		return Pos_;
	}

	inline void SetPos(const ConsoleVector& _Value)
	{
		Pos_ = _Value;
	}

	inline void SetMove(const ConsoleVector& _Value)
	{
		Pos_ += _Value;
	}


	virtual void Update();
	virtual void Render();
	virtual void OverLap(ConsoleObject* _Other);
	bool OverLapCheck(const ConsoleObject* _Other);


	void SetRenderChar(const char* _Text);
	void InScreenMovement(const ConsoleVector& _Vector);


	inline void Init(const ConsoleVector& _Value, const char* _Text)
	{
		SetPos(_Value);
		SetRenderChar(_Text);
	}

	inline void Death() 
	{
		IsDeath_ = true;
	}

	inline bool GetIsDeath()
	{
		return IsDeath_;
	}

	virtual void Destroy();

protected:

private:
	bool IsDeath_;
	// Has a 개념이라고 합니다.
	// 플레이어는 어차피 너무나도 많이 
	// 만약 이 개념이 각자의 것을 가져야 한다면
	// 값이나 동적할당된 자신만의 메모리를 가져야 한다.

	ConsoleVector Pos_;
	// 내가 별이다.
	char Text_[3];
};

