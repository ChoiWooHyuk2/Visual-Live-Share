#pragma once
#include "Command.h"
class JumpCommand :
	public Command
{
public:
	JumpCommand();
	~JumpCommand();

public:
	virtual void Action();
	virtual void CancelAction();
};

