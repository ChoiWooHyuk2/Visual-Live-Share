#include "pch.h"
#include "Player.h"
#include "GameObject.h"
#include "SpendData.h"

Player::Player(float x, float y):GameObject(x,y), isJumping(false),JumpCount(3)
{
}

Player::Player()
{
}


Player::~Player()
{
}

void Player::OnUpdate()
{
	Gravity();
}

void Player::Gravity()
{
	//ÁßÃ¸ ¹®Á¦
	if(isJumping)
	{
		if (pos.ypos < 0 || JumpCount <= 0)
		{
			isJumping = false;
			return;
		}
		JumpCount--;
		pos.ypos -= 0.6f;
	}
	if(!isJumping && pos.ypos < 18)//gravity
	{
		JumpCount = 7;
		pos.ypos += 0.2f;
	}
}

void Player::OnJump()
{
	if (pos.ypos < 18)
		return;
	isJumping = true;
}

void Player::OffJump()
{
	isJumping = false;
}

void Player::Move(char c)
{
	if(c=='r')
	{
		pos.xpos += 2;
	}
	if(c=='l')
	{
		pos.xpos -= 2;
	}
}