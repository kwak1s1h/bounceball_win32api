#include "pch.h"
#include "OperatingGround.h"
#include "Collider.h"
#include "Object.h"
#include "GameMgr.h"
#include "Core.h"

OperatingGround::OperatingGround()
	:m_vColliderSize({ 60, 60 }),
	m_Scale({ 60, 60 }),
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
	
}

void OperatingGround::Update()
{
	if (GameMgr::GetInst()->GetBtnActive() == false) {
		m_pCollider->SetScale({ 0, 0 });
	}
	if (GameMgr::GetInst()->GetBtnActive() == true) {
		m_pCollider->SetScale(m_vColliderSize);
	}
}
