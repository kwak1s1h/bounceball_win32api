#include "pch.h"
#include "OperatingGround.h"
#include "Collider.h"
#include "Object.h"
#include "EventMgr.h"
#include "Core.h"

OperatingGround::OperatingGround()
	: isActive(false),
	m_vColliderSize({ 10, 10 }),
	m_Scale({ 10, 10 }),
	GroundType(GROUND_TYPE::OPERATING),
	BlockType(OBJECT_GROUP::GROUND)
{
	SetScale(m_vScale);
	CreateCollider();
	GetCollider()->SetScale(m_vColliderSize);
}

OperatingGround::~OperatingGround()
{
}

void OperatingGround::Render(HDC _dc)
{
	if (!isActive) {
	}
	if (isActive) {
	}
}
