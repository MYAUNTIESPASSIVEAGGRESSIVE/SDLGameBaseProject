#include "EntityBase.h"

// constructor
EntityBase::EntityBase(float x, float y)
{
	// set _ePos vector to default values
	_ePos.x = x;
	_ePos.y = y;
	_eRotation = 0.0f;

	// set active to true
	_eActive = true;

	// set no parent
	_eParent = NULL;
}

// destructor
EntityBase::~EntityBase() 
{
	// sets parent to null in case of changes
	_eParent = NULL;
}

// set positon
void EntityBase::SetPos(Vector2 pos)
{
	_ePos = pos;
}

// get position
Vector2 EntityBase::GetPos(SPACE space)
{
	// if space is local or parent is null then return position
	if (space == local || _eParent == NULL) 
		return _ePos;

	// if not then return parents world pos + the local rotation of parent with child pos
	return _eParent->GetPos(world) + RotateVector(_ePos, _eParent->GetRotation(local));
}

// set rotation
void EntityBase::SetRotation(float r)
{
	//rotation is set to r
	_eRotation = r;


	// keeps rotation going above 360
	if (_eRotation > 360.0f) 
	{
		int mul = _eRotation / 360;
		_eRotation -= 360.0f * mul;
	}
	else if (_eRotation < 0.0f) 
	{
		int mul = (_eRotation / 360) - 1;
		_eRotation -= 360.0f * mul;
	}

}

// get rotation
float EntityBase::GetRotation(SPACE space)
{
	if (space == local || _eParent == NULL)
		return _eRotation;

	// if parent != null then get parent world rotation + rotation
	return _eParent->GetRotation(world) + _eRotation;
}

// set active
void EntityBase::SetActive(bool active) 
{
	_eActive = active;
}

// get active
bool EntityBase::GetActive()
{
	return _eActive;
}

// set parent
void EntityBase::SetParent(EntityBase* parent)
{
	// position is child world pos - parent world pos
	_ePos = GetPos(world) - parent->GetPos(world);

	_eParent = parent;
}

// get parent
EntityBase* EntityBase::Parent()
{
	return _eParent;
}

void EntityBase::Translate(Vector2 vec)
{
	_ePos += vec;
}

void EntityBase::Update()
{

}

void EntityBase::Render()
{

}