#pragma once
#include "Object.h"
class Texture;
class Ground : public Object
{
public:
	Ground();
	~Ground();
public:
	void Render(HDC _dc) override;
	void Update();
	void EnterCollision(Collider* _pOther) override;

	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
public:
	OBJECT_GROUP BlockType;
	GROUND_TYPE GroundType;

private:
	vector<Collider*> m_cols;

	Vec2 m_vColliderThickness;
	Vec2 m_vPos;
	Vec2 m_Scale;
	Texture* m_pTex;
};

