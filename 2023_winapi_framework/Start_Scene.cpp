#include "pch.h"
#include "Start_Scene.h"
#include "Button.h"
#include "Ground.h"
#include "Core.h"

void Start_Scene::Init()
{
	Button* btn = new Button(L"Play\nGame");
	btn->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	btn->SetScale(Vec2(300.f, 75.f));
	AddObject(btn, OBJECT_GROUP::UI);

	Vec2 vResolution = Core::GetInst()->GetResolution();
	Ground* pGround = nullptr;
	int iGround = 10; // 움직일 거리
	float fMonsterScale = 60.f;
	for (int i = 0; i < iGround; ++i)
	{
		pGround = new Ground;
		pGround->SetPos(Vec2(
			(fMonsterScale / 2.f) + i * 10, 300.f));
		pGround->SetScale(Vec2(fMonsterScale, fMonsterScale));
		AddObject(pGround, OBJECT_GROUP::GROUND);
	}
}

void Start_Scene::Update()
{
	Scene::Update();
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
}
