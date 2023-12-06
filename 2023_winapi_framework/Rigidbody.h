#pragma once
class Object;
class Rigidbody
{
public:
	Rigidbody();
	~Rigidbody();

	void FinalUpdate();

	void AddForce(const Vec2 _vF) { m_vForce = m_vForce + _vF; }

	void SetMass(float _fMass) { m_fMass = _fMass; }
	const float& GetMass() const { return m_fMass; }

	void SetVelocity(Vec2 _v) { m_vVelocity = _v; };
	void SetMaxVelocity(float _speed) { m_fMaxSpeed = _speed; };


	friend class Object;

private:
	void Move();

private:

	Object* m_pOwner;

	Vec2 m_vForce;
	Vec2 m_vAccel;
	float m_fMass;

	Vec2 m_vVelocity;
	float m_fMaxSpeed;
	float m_fFricCoeff;

};