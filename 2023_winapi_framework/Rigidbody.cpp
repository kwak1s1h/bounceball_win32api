#include "pch.h"
#include "Rigidbody.h"
#include "TimeMgr.h"
#include "Object.h"

Rigidbody::Rigidbody() 
	: m_pOwner(nullptr)
	, m_fMass(1.f)
	, m_fFricCoeff(300.f)
	, m_fMaxSpeed(500.f)
{
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::FinalUpdate()
{
	float fForce = m_vForce.Length();

	if (fForce != 0.f)
	{
		m_vForce.Normalize();
		float fAccel = fForce / m_fMass;
		m_vAccel = m_vForce * fAccel;
		m_vVelocity += m_vAccel * fDT;
	}

	if (m_vVelocity.Length() > 0.f)
	{
		Vec2 velocity = m_vVelocity;
		Vec2 vFriction = -velocity.Normalize() * m_fFricCoeff * fDT;

		if (m_vVelocity.Length() <= vFriction.Length())
		{
			m_vVelocity.x = 0.f;
		}
		else
		{
			m_vVelocity.x += vFriction.x;
		}
	}

	if (m_vVelocity.Length() > m_fMaxSpeed)
	{
		m_vVelocity.Normalize();
		m_vVelocity *= m_fMaxSpeed;
	}

	m_vVelocity.y += 9.81f * 0.5f;

	Move();

	m_vForce = Vec2(0.f, 0.f);
}

void Rigidbody::Move()
{
	float fSpeed = m_vVelocity.Length();

	if (fSpeed != 0.f)
	{
		Vec2 vDir = m_vVelocity;
		vDir.Normalize();

		Vec2 vPos = m_pOwner->GetPos();
		vPos = vPos + m_vVelocity * fDT;
		m_pOwner->SetPos(vPos);
	}
}
