#pragma once
#include "Command.h"
class MovingCommand :
	public Command
{
public:
	MovingCommand();
	~MovingCommand();
public:
	virtual void Action();//right
	void LeftAction();
};

