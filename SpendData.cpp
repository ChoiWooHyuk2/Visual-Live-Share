#include "pch.h"
#include "SpendData.h"
//º»¤ÑÃ¼ 

SpendData::SpendData() : player(new Player(10,10))
{
	
}


SpendData::~SpendData()
{
}

int SpendData::PlayerPosx()
{
	return player->pos.xpos;
}

int SpendData::PlayerPosy()
{
	return player->pos.ypos;
}

void SpendData::RePosX(float x)
{
	player->pos.xpos = x;
}

void SpendData::RePosY(float y)
{
	player->pos.ypos = y;
}

SpendData* SpendData::Getinstance()
{
	static SpendData i;
	return &i;
}
void SpendData::PlayerJump()
{
	player->OnJump();
}

void SpendData::PlayerJumpCancel()
{
	player->OffJump();
}

void SpendData::OnUpdata()
{
	player->OnUpdate();
}

void SpendData::PlayerMove(char c)
{
	player->Move(c);
}