#include<iostream>
#include "TextScreen.h"

int main()
{
	TextScreen textScreen;

	textScreen.CreateScreen(10, 10, "бр");

	textScreen.PrintScreen();

	return 0;
}