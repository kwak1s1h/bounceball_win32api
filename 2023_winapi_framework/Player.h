#pragma once
#include "Object.h"
class Texture;
class Player :
    public Object
{
public:
    Player();
    ~Player();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void EnterCollision(Collider* _pOther) override;

private:
    Texture* m_pTex;
};

