#include "pch.h"
#include "Object.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Animator.h"
Object::Object()
	: m_pCollider(nullptr)
	, m_vPos{}
	, m_vScale{}
	, m_IsAlive(true)
	, m_pAnimator(nullptr)
{
}

Object::~Object()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;

}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pOwner = this;
}

void Object::CreateAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pOwner = this;
}

void Object::FinalUpdate()
{
	if (m_pCollider)
		m_pCollider->FinalUpdate();
}


void Object::EnterCollision(Collider* _pOther)
{
}

void Object::ExitCollision(Collider* _pOther)
{
}

void Object::StayCollision(Collider* _pOther)
{

}

void Object::Component_Render(HDC _dc)
{
	if (nullptr != m_pCollider)
		m_pCollider->Render(_dc);
	if (nullptr != m_pAnimator)
		m_pAnimator->Render(_dc);

}

