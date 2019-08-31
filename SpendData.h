#pragma once
#include "Player.h"
#define FWMAIN SpendData::Getinstance()

class SpendData
{
private:
	Player* player=nullptr;
public:
	SpendData();
	~SpendData();
	int PlayerPosx();//spands
	int PlayerPosy();
public:
	void OnUpdata();
	void PlayerJump();
	void PlayerJumpCancel();
	void PlayerMove(char c);
	void RePosX(float x);//get
	void RePosY(float y);
	static SpendData* Getinstance();
};

