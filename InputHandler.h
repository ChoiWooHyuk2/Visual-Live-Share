#pragma once
#include "Command.h"
#include "JumpCommand.h"
#include "MovingCommand.h"
#define FWINPUT InputHandler::GetInstance()
#define RIGHT 77
#define LEFT 75
#define SPACE 32


class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void handleInput();
public:
	int GetMyKeyState(int vk);
	bool GetKeyDown(int vk);
	bool GetKeyPressed(int vk);
	bool GetKeyUp(int vk);
	void UpdateKeyState();
	static InputHandler* GetInstance();
private :
	bool lkey[256], rkey[256];
	JumpCommand* jump=nullptr;
	MovingCommand* Move = nullptr;
};

