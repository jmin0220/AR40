#pragma once

// ¼³¸í :
class ConsoleMath
{
public:
	// constrcuter destructer
	ConsoleMath();
	~ConsoleMath();

	// delete Function
	ConsoleMath(const ConsoleMath& _Other) = delete;
	ConsoleMath(ConsoleMath&& _Other) noexcept = delete;
	ConsoleMath& operator=(const ConsoleMath& _Other) = delete;
	ConsoleMath& operator=(ConsoleMath&& _Other) noexcept = delete;

protected:

private:

};

class ConsoleVector
{
public:
	// ÁÂÇ¥°è
	int X;
	int Y;

public:
	ConsoleVector operator+(const ConsoleVector& _Other)
	{
		ConsoleVector Result;

		Result.X = _Other.X;
		Result.Y = _Other.Y;

		return Result;
	}

	ConsoleVector& operator+=(const ConsoleVector& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;

		return *this;
	}
};