#include "pch.h"
#include "MovingCommand.h"
#include "SpendData.h"

MovingCommand::MovingCommand()
{
}


MovingCommand::~MovingCommand()
{
}

void MovingCommand::Action()
{
	FWMAIN->PlayerMove('r');
}

void MovingCommand::LeftAction()
{
	FWMAIN->PlayerMove('l');
}