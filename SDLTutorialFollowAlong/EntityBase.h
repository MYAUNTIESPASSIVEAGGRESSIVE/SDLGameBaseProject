#ifndef _ENTITYBASE_H
#define _ENTITYBASE_H

#include "MathHelper.h"

// base class for all entities
// including: Texture/Sprites/GameObjects
class EntityBase
{

// public vars
public:
	// tells if dealing with local or world space
	enum SPACE {local = 0, world = 1};

// private vars
private:
	// entities position and rotation
	Vector2 _ePos;
	float _eRotation;

	// bool for if entity is active
	bool _eActive;

	// pointer allowing for childing and parenting objects
	EntityBase* _eParent;

// public funcs
public:

	// const + dest
	EntityBase(float x = 0.0f, float y = 0.0f);
	~EntityBase();

	// set/get position
	void SetPos(Vector2 pos);
	Vector2 GetPos(SPACE space = world);
	
	// set/get rot
	void SetRotation(float rotation);
	float GetRotation(SPACE space = world);

	// set/get Active
	void SetActive(bool active);
	bool GetActive();

	// set/get parentobj
	void SetParent(EntityBase* parent);
	EntityBase* Parent();

	// allows movement
	void Translate(Vector2 vec);

	// update and render functions for time and rendering
	// these functions can be overwritten by children to do their own logic
	virtual void Update();
	virtual void Render();
};
#endif // !_ENTITYBASE_H

