#include "pch.h"
#include "InputHandler.h"

InputHandler::InputHandler()
{
	jump = new JumpCommand();
	Move = new MovingCommand();
}


InputHandler::~InputHandler()
{
}

void InputHandler::handleInput()
{
	if(_kbhit())
	{
		int key = _getch();
		rkey[key] = true;
		switch(key)
		{
		case RIGHT:
				Move->Action();
			break;
		case LEFT:
				Move->LeftAction();
			break;
		case SPACE:
			if(GetKeyDown(SPACE))
				jump->Action();
			break;
		}
		if (GetKeyUp(SPACE))
			jump->CancelAction();
	}

}

int InputHandler::GetMyKeyState(int vk)
{
	if (lkey[vk] && rkey[vk]) return 2; //�Ʊ �������� ���ݵ� ���������� ��
	if (!lkey[vk] && rkey[vk]) return 1; //�Ʊ�� �ƴ����� ������ ����������
	if (lkey[vk] && !rkey[vk]) return -1; //������ ������
	UpdateKeyState();
	return 0;
}

bool InputHandler::GetKeyDown(int vk)
{
	return (GetMyKeyState(vk) == 1) ? true : false;
}

bool InputHandler::GetKeyPressed(int vk)
{
	return (GetMyKeyState(vk) == 2) ? true : false;
}

bool InputHandler::GetKeyUp(int vk)
{
	return (GetMyKeyState(vk) == -1) ? true : false;
}

void InputHandler::UpdateKeyState()
{
	for (int i = 0; i < 256; i++)
	{
		lkey[i] = rkey[i];
	}
}

InputHandler* InputHandler::GetInstance()
{
	static InputHandler i;
	return &i;
}