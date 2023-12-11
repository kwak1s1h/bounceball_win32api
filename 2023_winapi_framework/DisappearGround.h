#pragma once
#include "Object.h"
class DisappearGround : public Object
{
public:
	DisappearGround();
	~DisappearGround();
public:
	void Render(HDC _dc) override;
	void EnterCollision(Collider* _pOther);
	void StayCollision(Collider* _pOther);
	void ExitCollision(Collider* _pOther);
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
public:
	OBJECT_GROUP BlockType;
	GROUND_TYPE GroundType;

	Vec2 m_vColliderSize;
	Vec2 m_vPos;
	Vec2 m_Scale;
	//Rigidbody m_rb;
	bool m_UseRigidbody;
};