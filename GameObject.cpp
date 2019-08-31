#include "pch.h"
#include "GameObject.h"
#include "SpendData.h"

GameObject::GameObject(float x, float y)
{
	pos = { x,y };
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Gravity()
{
}

void GameObject::Jump()
{
}
