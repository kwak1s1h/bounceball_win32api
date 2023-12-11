#include "pch.h"
#include "ButtonGround.h"
#include "Collider.h"
#include "Object.h"
#include "EventMgr.h"

ButtonGround::ButtonGround()
	: isActive(false),
	m_vColliderSize({ 11, 11 }),
	m_Scale({ 10, 10 }),
	GroundType(GROUND_TYPE::BUTTON),
	BlockType(OBJECT_GROUP::GROUND)
{
	SetScale(m_vScale);
	CreateCollider();
	GetCollider()->SetScale(m_vColliderSize);
}

ButtonGround::~ButtonGround()
{
}

void ButtonGround::Render(HDC _dc)
{
	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
}

void ButtonGround::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player") {
		isActive = !isActive;
	}
}

void ButtonGround::StayCollision(Collider* _pOther)
{
}

void ButtonGround::ExitCollision(Collider* _pOther)
{
}
