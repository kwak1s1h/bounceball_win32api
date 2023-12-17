#include "pch.h"
#include "ElectricObstacle.h"
#include "Collider.h"
#include "EventMgr.h"
#include "Object.h"

ElectricObstacle::ElectricObstacle()
	:m_vColliderSize({ 56, 56 }),
	m_Scale({ 60, 60 }),
	ObstacleType(OBSTACLE_TYPE::ELECTRIC),
	BlockType(OBJECT_GROUP::OBSTACLE)
{
	SetScale(m_vScale);
	CreateCollider();
	GetCollider()->SetScale(m_vColliderSize);
}

ElectricObstacle::~ElectricObstacle()
{
}

void ElectricObstacle::Render(HDC _dc)
{
	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
}

void ElectricObstacle::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player") {
		EventMgr::GetInst()->DeleteObject();
	}
}

void ElectricObstacle::StayCollision(Collider* _pOther)
{
}

void ElectricObstacle::ExitCollision(Collider* _pOther)
{
}

void ElectricObstacle::Update()
{
}
