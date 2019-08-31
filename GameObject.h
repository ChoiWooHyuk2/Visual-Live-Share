#pragma once

typedef struct _Pos {
	float xpos;
	float ypos;
}Pos;

class GameObject
{
public:
	Pos pos;
	bool isJumping;
public:
	GameObject(float x, float y);
	GameObject();
	~GameObject();
public:
	virtual void OnUpdate()=0;
	void Gravity();
	void Jump();
};

