#include "pch.h"
#include "Ground.h"
#include "Collider.h"

Ground::Ground()
	:m_vColliderSize({ 10, 10 }),
	m_Scale({ 10, 10 }),
	GroundType(GROUND_TYPE::None),
	BlockType(OBJECT_GROUP::GROUND)
{
	SetScale(m_vScale);
	CreateCollider();
	GetCollider()->SetScale(m_vColliderSize);
}

Ground::~Ground()
{
}

void Ground::Render(HDC _dc)
{
	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
}

void Ground::Update()
{
}
