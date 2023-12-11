#include "pch.h"
#include "Ground.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Texture.h"

Ground::Ground()
	:m_vColliderSize({ 60, 60 }),
	m_Scale({ 10, 10 }),
	GroundType(GROUND_TYPE::None),
	BlockType(OBJECT_GROUP::GROUND)
{
	SetScale(m_vScale);
	m_pTex = ResMgr::GetInst()->TexLoad(L"Ground", L"Texture\\\Ground.bmp");
	CreateCollider();
	GetCollider()->SetOffSetPos({ -20.f, -20.f });
	GetCollider()->SetScale(m_vColliderSize);
}

Ground::~Ground()
{
}

void Ground::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
}

void Ground::Update()
{
}
