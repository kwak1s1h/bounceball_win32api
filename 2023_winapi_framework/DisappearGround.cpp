#include "pch.h"
#include "DisappearGround.h"
#include "Collider.h"
#include "EventMgr.h"
#include "Object.h"

DisappearGround::DisappearGround():
	m_vColliderSize({ 56, 56 }),
	m_Scale({ 60, 60 }),
	GroundType(GROUND_TYPE::DISAPPEAR),
	BlockType(OBJECT_GROUP::GROUND)
{
	SetScale(m_vScale);
	CreateCollider();
	GetCollider()->SetScale(m_vColliderSize);
}

DisappearGround::~DisappearGround()
{
}

void DisappearGround::Render(HDC _dc)
{
	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
}

void DisappearGround::EnterCollision(Collider* _pOther)
{
}

void DisappearGround::StayCollision(Collider* _pOther)
{
}

void DisappearGround::ExitCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player") {
		EventMgr::GetInst()->DeleteObject(this);
	}
}

void DisappearGround::Update()
{
}
