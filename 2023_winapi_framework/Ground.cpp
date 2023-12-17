#include "pch.h"
#include "Ground.h"
#include "Texture.h"
#include "PathMgr.h"
#include "Collider.h"
#include "ResMgr.h"

Ground::Ground()
	:m_vColliderSize({ 60, 60 }),
	m_pTex(nullptr),
	m_Scale({ 60, 60 }),
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
}

void Ground::Update()
{
}
