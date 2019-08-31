#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(float x, float y);
	Player();
	~Player();
	void OnUpdate();

private:
	int PlayerHp;
	int PlayerState;
	bool isJumping;
	int JumpCount;
public:
	void Gravity();
	void Move(char c);
	void OnJump();
	void OffJump();
};

