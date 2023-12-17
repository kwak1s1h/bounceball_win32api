#include "pch.h"
#include "StarItem.h"
#include "Collider.h"
#include "EventMgr.h"
#include "Object.h"

StarItem::StarItem()
	: m_vColliderSize({60, 60}),
	m_Scale({60, 60}),
	ItemType({ITEM_TYPE::STAR})
{
	SetScale(m_vScale);
	CreateCollider();
	GetCollider()->SetScale(m_vColliderSize);
}

StarItem::~StarItem()
{
}

void StarItem::Render(HDC _dc)
{
}

void StarItem::EnterCollision(Collider* _pOther)
{
	EventMgr::GetInst()->CollectStar(this);
}

void StarItem::StayCollision(Collider* _pOther)
{
}

void StarItem::ExitCollision(Collider* _pOther)
{
}

void StarItem::Update()
{
}
