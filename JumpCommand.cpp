#include "pch.h"
#include "JumpCommand.h"
#include "SpendData.h"

JumpCommand::JumpCommand()
{
}


JumpCommand::~JumpCommand()
{
}

void JumpCommand::Action()
{
	FWMAIN->PlayerJump();
}

void JumpCommand::CancelAction()
{
	FWMAIN->PlayerJumpCancel();
}

